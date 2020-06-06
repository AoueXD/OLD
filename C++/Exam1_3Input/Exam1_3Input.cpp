#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

void operation();
int Insertion(int idNum[], int score[][50], int size);
void Modification(int idNum[], int score[][50], int size);
int Deletion(int idNum[], int score[][50], int size);
void output(int idNum[], int score[][50], string header, int size);

int main(){
	int i, j, size = 20, idNum[50], score[3][50];
	char GoOn;
	string Header;

	ifstream RawIn;

	RawIn.open("Exam1_3Input.txt");
	    
	getline(RawIn, Header);
	
	for(i = 0; i < 50; i++) {
		idNum[i] = 0;
		score[0][i] = 0;
		score[1][i] = 0;
		score[2][i] = 0;
	}

	i = 0;
	while(!RawIn.eof()) {
		RawIn >> idNum[i] >> score[0][i] >> score[1][i] >> score[2][i];
		i++;
	}

	output(idNum, score, Header, size);

	do {
		operation();
		cin >> GoOn;
		
		j = size;
		switch(GoOn) {	
			case 'i': 
				size = Insertion(idNum, score, j);
				output(idNum, score, Header, size);
			break;
			case 'm': 
				Modification(idNum, score, j);
			break;
			case 'd': 
				size = Deletion(idNum, score, j);
				output(idNum, score, Header, size);
 		    break;		  
			default: break;			 
		}
	} while(GoOn != 'q');
	RawIn.close();
	
	return 0;
}

void operation() {
	cout<<"-----------------------------------------"<<endl;
	cout<<"  Type 'i' for Insertion." << endl;
	cout<<"  Type 'm' for Modification."<< endl;
	cout<<"  Type 'd' for Deletion."<< endl;
 	cout<<"  Type 'q' for End of program."<< endl;
 	cout<<"-----------------------------------------"<<endl;
 	cout<<"Operation: ";
}

int Insertion(int idNum[], int score[][50], int size){
	int i, j, IdNum;
	
	cout << "idnum: (10601 ~ 10650) ";
	cin >> IdNum;

	if(10600 < IdNum && IdNum < 10651) {
		i = 0;
		while(i < size && IdNum != idNum[i])
			i++;
		
		if(i < size) {
			cout << "The idNum had exists!\n";
			return size;
		}
		else {
			for(j = size - 1; j >= 0 && IdNum < idNum[j]; j--) {
				idNum[j + 1] = idNum[j];
				score[0][j + 1] = score[0][j];
				score[1][j + 1] = score[1][j];
				score[2][j + 1] = score[2][j];
			}

			idNum[j + 1] = IdNum;
			
			cout << "score 1: ";
			cin >> score[0][j + 1];
			cout << "score 2: ";
			cin >> score[1][j + 1];
			cout << "score 3: ";
			cin >> score[2][j + 1];

			return (size + 1);
		}			
	}
	else {
		cout << "Out of Range!\n";
		return size;
	}
}

void Modification(int idNum[], int score[][50], int size){
	int IdNum, i, j, NewScore;

	cout << "Input the modified idNum: ";
	cin >> IdNum;

	if(10600 < IdNum && IdNum < 10651) {
		i = 0;
		while(i < size && IdNum != idNum[i])
			i++;
		
		if(i < size) {
			cout << "Modified score 1, 2, or 3 (only one digit): ";
			cin >> j;
			cout << "The new score: ";
			cin >> NewScore;
			score[j - 1][i] = NewScore;
		}
		else
			cout << "The idNum does not exist!\n";
	}
	else
		cout << "Out of Range!\n";
}

int Deletion(int idNum[], int score[][50], int size){
	int IdNum, i, j;

	cout << "Input the idNum: ";
	cin >> IdNum;
	
	if(10600 < IdNum && IdNum < 10651) {
		i = 0;
		while(i < size && IdNum != idNum[i])
			i++;

		if(i < size) {
			for(j = i + 1; j < size; j++) {
				idNum[j - 1] = idNum[j];
				score[0][j - 1] = score[0][j];
				score[1][j - 1] = score[1][j];
				score[2][j - 1] = score[2][j];
			}
			
			return (size - 1);
		}
		else {
			cout << "The idNum does not exist!\n";
			return size;
		}
	}
}

void output(int idNum[], int score[][50], string header, int size){
	cout << "    " << header << endl;
	for(int i = 0; i < size; i++) {
		cout << "(" << setw(2) << i + 1 << ")" << setw(6) << idNum[i] 
			 << setw(8) << score[0][i]
			 << setw(8) << score[1][i] 
			 << setw(8) << score[2][i] << endl;
	}
}
