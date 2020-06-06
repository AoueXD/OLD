#include<iomanip>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
struct examrecord{
	int idnumber;
	int score[3];
	double average;
	char grade;
};
int main(){
	examrecord student[20];
	int i=0,j=0,k=0,l=0,size=20,c[5];
	srand(time(0));
	for(i=0;i<20;i++){
		student[i].idnumber=105*100+i;
		student[i].score[0]=(rand()%100);
		student[i].score[1]=(rand()%100);
		student[i].score[2]=(rand()%100);
		student[i].average=(student[i].score[0]+student[i].score[1]+student[i].score[2])/3;
	}
	for(i=0;i<size;i++){
		if(student[i].average>=90&&student[i].average<=100)
		student[i].grade='a';
			if(student[i].average>=80&&student[i].average<=90)
		student[i].grade='b';
			if(student[i].average>=70&&student[i].average<=80)
		student[i].grade='c';
			if(student[i].average>=60&&student[i].average<=70)
		student[i].grade='d';
			if(student[i].average<60)
		student[i].grade='f';
	}
	cout<<"idnumber"<<" score 1"<<" score 2"<<" score 3"<<" average"<<" grade"<<endl;
	for(i=0;i<size;i++){
		cout<<setw(6)<<student[i].idnumber
			<<setw(8)<<student[i].score[0]
			<<setw(8)<<student[i].score[1]
			<<setw(8)<<student[i].score[2]
			<<setw(8)<<student[i].average
			<<setw(7)<<student[i].grade<<endl;
	}
	for(i=0;i<size;i++){
		if(student[i].grade=='a')c[0]++;
		if(student[i].grade=='b')c[1]++;
		if(student[i].grade=='c')c[2]++;
		if(student[i].grade=='d')c[3]++;
		if(student[i].grade=='f')c[4]++;
	}
	cout<<"===================================================================="<<endl;
	for(i=0;i<20;i++){
	if(student[i].score[0]>=60)
	j++;

	}
	for(i=0;i<20;i++){
	if(student[i].score[1]>=60)
	k++;

	}
	for(i=0;i<20;i++){
	if(student[i].score[2]>=60)
	l++;

	}
	cout<<"及格"; 
	cout<<setw(10)<<j<<"人";
	cout<<setw(6)<<k<<"人";
	cout<<setw(6)<<l<<"人"<<endl;
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	
	for(size=20;size>1;size--){
		for(i=0;i<size;i++){
			if(student[i].average>student[i+1].average){
				swap(student[i].average,student[i+1].average);
				swap(student[i].score[0],student[i+1].score[0]);
				swap(student[i].score[1],student[i+1].score[1]);
				swap(student[i].score[2],student[i+1].score[2]);
				swap(student[i].idnumber,student[i+1].idnumber);
				swap(student[i].grade,student[i+1].grade);
			}
		}
	}
	size = 20;
	for(i=0;i<size;i++){
		cout<<setw(6)<<student[i].idnumber
			<<setw(8)<<student[i].score[0]
			<<setw(8)<<student[i].score[1]
			<<setw(8)<<student[i].score[2]
			<<setw(8)<<student[i].average
			<<setw(7)<<student[i].grade<<endl;
		}
	
	
	
	
	
	return 0;
}
