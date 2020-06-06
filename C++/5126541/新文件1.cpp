#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	int i;
	char str[60], name[16], cha[100];
	ifstream EmailBook;
	
	cout << "輸入檔案名稱(不可超過16個字)";
	cin >> name;
	
	//EmailBook.open("EmailBook.txt");//直接打開
	EmailBook.open(name);
	if(EmailBook.fail()){
		cout  << "FILE ERROR !";
		exit(1);
	}
	
	
	
	while(!EmailBook.eof()){
		EmailBook >> cha;
		cout << cha;
	}
	
	EmailBook.close();
	
	return 0;

}
