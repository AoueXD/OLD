#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a,b,c;
	bool sw=true; 
	cout <<"��J�T�Ӽ�a,b,c \n\n"
		 <<"a�̤j�A��X a��b����+c \n\n"
		 <<"b�̤j�A��X b����-(a����+c����) \n\n"
		 <<"c�̤j�A��X (a+b)*c/2 " 
		 <<"�Y������Ƥ@�ˤj�A���s��J�@��" <<endl<<endl;
	do{
		cin >>a>>b>>c;
		cout <<endl<<"a = "<<a<<endl<<endl;
		cout <<"b = "<<b<<endl<<endl;
		cout <<"c = "<<c<<endl<<endl<<endl;
		if(a==b||a==c||b==c){
			cout<<"�����ƪ��ơA�Э��s��J�@��"<<endl<<endl; 
		} 
		if(a>b&&a>c&&b!=c){
			cout <<"���׬O"<<pow(a,b)+c<<endl<<endl;
			sw=false;
		}
		if(b>a&&b>c&&a!=c){
			cout<<"���׬O"<<b*b-(a*a+c*c)<<endl<<endl;
			sw=false;
		}
		if(c>a&&c>b&&a!=b){
			cout<<"���׬O"<<	(a+b)*c/2 <<endl<<endl;
			sw=false;
		}
	}while(sw);
	
	system("pause"); 
	return 0;
} 
