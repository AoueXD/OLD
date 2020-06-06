#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct ExamRecord { 
	int idNumber;
	int score[3];
	double average;
	char grade; // 級分 ABCDEF 
};

int main(){
	ExamRecord student[20];
	int i, j, size = 20, C[5]; //size-總數; C-統計及分數 
	
	srand(time(0));
	
	for(i=0; i<size; i++){
		student[i].idNumber = 10500 + i;
		student[i].score[0] = (rand()% 100);
		student[i].score[1] = (rand()% 100);
		student[i].score[2] = (rand()% 100);
		student[i].average = (student[i].score[0] + student[i].score[1] + student[i].score[2])/3;
	}
	
	for(i = 0; i < 5; i++){
		C[i] = 0;
	} //C ARRAY先歸零 
	
	for(i = 0; i < size; i++){
		if(student[i].average >= 90 && student[i].average <= 100){
			student[i].grade = 'A';
			C[0]++;
		}
		if(student[i].average >= 80 && student[i].average < 90){
			student[i].grade = 'B';
			C[1]++;
		}
		if(student[i].average >= 70 && student[i].average < 80){
			student[i].grade = 'C';
			C[2]++;
		}
		if(student[i].average >= 60 && student[i].average < 70){
			student[i].grade = 'D';
			C[3]++;
		}
		if(student[i].average < 60){
			student[i].grade = 'F';
			C[4]++;
		}
	}
	//打完了 接下來要輸出
	
	cout << "idNumber " << "score 1" << "score 2" << "score 3" << " Average" << " Grade" << endl;
	
	// setw空格 == 6 8 8 8 8 7
	 
	for(i = 0; i < size; i++){
		cout << setw(6) << student[i].idNumber;
		cout << setw(8) << student[i].score[0];
		cout << setw(8) << student[i].score[1];
		cout << setw(8) << student[i].score[2];
		cout << setw(8) << student[i].average;
		cout << setw(7) << student[i].grade << endl;
	}
	
	cout << "A	B	C	D	F : \n";
	for(i = 0; i < 5; i++){
		cout << C[i] << "	";
	}
	
}
