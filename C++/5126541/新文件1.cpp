#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	int i;
	char str[60], name[16], cha[100];
	ifstream EmailBook;
	
	cout << "��J�ɮצW��(���i�W�L16�Ӧr)";
	cin >> name;
	
	//EmailBook.open("EmailBook.txt");//�������}
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
