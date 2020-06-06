#include <iostream>
#include <fstream>
#include <ctime> // 
#include <cstdlib>
#include <iomainp>
using namespace std;

int main(){
	
	int i = 0, idNumber, score1, score2, score3;
	ofstream ofscore;
	char name[16], grade;
	
	cin >> name;
	ofscore.open(name);
	srand(time(0));
	
	cout << "	idNumber score_1 score_2 score_3 AVERE"; 
	for(i = 0; i < 20; i++){
		cout << (time (0) % 15) +100;
		
	}

	
	for(i = 0; i < 20; i++){
		cout << "(" << i << ")";
		cout <<  score1 << setw(6) << score2 << 
	}

}
