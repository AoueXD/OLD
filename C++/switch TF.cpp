#include <iostream>

using namespace std;

int main(){
	int a;
	bool sw = true;
	cout << "����Ѯ�O�H 1.���� 2.�B�� 3.���� " << endl; 
	
	do{
		cin>>a;
		switch(a){
			case 1: 
				cout<<"���ѬO���ѡA�`�N����"<<endl<<endl;
				sw=false; 
				break;
			case 2:
				cout<<"���ѬO�B�ѡA�ǳƫB��"<<endl<<endl;
				sw=false; 
				break;
			case 3:
				cout<<"���ѬO���ѡA�`�N�O�x"<<endl<<endl;
				sw=false; 
				break;

			default:
				cout <<"�ﶵ�L�ġA�Э��s��J"<<endl<<endl;
				 
		}
	}while(sw);
	
	
	return 0;
}
