#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

class ExamRecord {
public:
	void indivStudent(int i);
	void OutputScore();
	void ChangeScore(int i);
	void AddStudent(int i);
private:
	int idNumber;
	int score[3];
	double average;
	char grade;
};

void OutputHeader();
char Grade(double avscore);

int main(){
	ExamRecord *student, *AddStudent, NewStudent;
	int i, j, size;
	
	srand(time(0));
	
	cout << "Input the number of students: ";
	cin >> size;
	
	student = new ExamRecord[size];
	AddStudent = new ExamRecord;
	
	for(i = 0; i < size; i++)
		student[i].indivStudent(i);
	
	OutputHeader();
	
	for(i = 0; i < size; i++)
		student[i].OutputScore();
    
	cout << "Add Score: " << endl;
	AddStudent -> AddStudent(size);
	NewStudents = new ExamRecord[size + 1];
	
	OutputHeader();
		
	for(i = 0; i < size + 1; i++)
		NewStudent[i] = student[i];
		NewStudent[i].OutputScore();
		
	AddStudent = OutputScore();
	NewStudent[size] = *AddStudent;
	

		
    return 0;
}

void ExamRecord::indivStudent(int i) {
	idNumber = 103 * 100 + i;
	score[0] = (rand( ) % 100);
	score[1] = (rand( ) % 100);
	score[2] = (rand( ) % 100);
	average = (score[0] + score[1] + score[2])/3;
	grade = Grade(average);
	
}
char Grade(double avscore) {
	if(avscore >= 90 && avscore <= 100)	
		return 'A';
	if(avscore >= 80 && avscore < 90)	
		return 'B';
	if(avscore >= 70 && avscore < 80)	
		return 'C';
	if(avscore >= 60 && avscore < 70)	
		return 'D';
	if(avscore < 60)	
		return 'F';
}

void OutputHeader() {
	cout << "idNumber  " << "score 1" << " score 2" << " score 3" << " Average" << " Grade" << endl;
}

void ExamRecord::OutputScore() {
	cout << setw(6) << idNumber 
		 << setw(8) << score[0]
		 << setw(8) << score[1] 
		 << setw(8) << score[2]
		 << setw(8) << average
		 << setw(7) << grade << endl;
}

void ExamRecord::ChangeScore(int i) {
	cout << "score[1] = ";
	cin >> score[0];
	cout << "score[2] = ";
	cin >> score[1];
	cout << "score[3] = ";
	cin >> score[2];
	average = (score[0] + score[1] + score[2])/3;
	grade = Grade(average);
}

void ExamRecord::AddStudent(int i) {
		cout << "score[1] = ";
	cin >> score[0];
	cout << "score[2] = ";
	cin >> score[1];
	cout << "score[3] = ";
	cin >> score[2];
	average = (score[0] + score[1] + score[2])/3;
	grade = Grade(average);
}
