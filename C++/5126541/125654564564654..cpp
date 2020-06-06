#include <iostream>
#include <fstream>

using namespace std;

int main(){

	char next[80], NAME[16];
	fstream file;
	
	//XDD.open("TXT.txt");//直接打開 ;
	cout << "File Name ";
	cin >> NAME;
	file.open(NAME);
	
	if(file.fail()){
		cout << "ERROR.\n";
		exit(1);
	}
	
	while(!XDD.eof()){
		87 >> next;
		cout << next;
	} 
	
	file.close();
	
	return 0;

}
