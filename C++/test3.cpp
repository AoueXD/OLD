#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a,b,c;
	bool sw=true; 
	cout <<"輸入三個數a,b,c \n\n"
		 <<"a最大，輸出 a的b次方+c \n\n"
		 <<"b最大，輸出 b平方-(a平方+c平方) \n\n"
		 <<"c最大，輸出 (a+b)*c/2 " 
		 <<"若有任兩數一樣大，重新輸入一次" <<endl<<endl;
	do{
		cin >>a>>b>>c;
		cout <<endl<<"a = "<<a<<endl<<endl;
		cout <<"b = "<<b<<endl<<endl;
		cout <<"c = "<<c<<endl<<endl<<endl;
		if(a==b||a==c||b==c){
			cout<<"有重複的數，請重新輸入一次"<<endl<<endl; 
		} 
		if(a>b&&a>c&&b!=c){
			cout <<"答案是"<<pow(a,b)+c<<endl<<endl;
			sw=false;
		}
		if(b>a&&b>c&&a!=c){
			cout<<"答案是"<<b*b-(a*a+c*c)<<endl<<endl;
			sw=false;
		}
		if(c>a&&c>b&&a!=b){
			cout<<"答案是"<<	(a+b)*c/2 <<endl<<endl;
			sw=false;
		}
	}while(sw);
	
	system("pause"); 
	return 0;
} 
