#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	int i;
	char str[60], name[16], cha[100];
	ifstream EmailBook;//fin
	ofstream fout;
	
	cout << "��J�ɮצW��(���i�W�L16�Ӧr)";
	cin >> name;
	
	//EmailBook.open("EmailBook.txt");//�������} �n " "; 
	EmailBook.open(name);//������ ���� " "; 
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

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int n, i=2;
	bool state = true;
	cin >> n;
	
	while(i<n&&state){
		if(n%i == 0)
		state = false;
		
		i++;
	}
	
	if(state)
		cout << "�Ӿ�";
	else
		cout << "NO�Ӿ�" ;
			
}
