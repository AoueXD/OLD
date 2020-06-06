#include <iostream>

using namespace std;

int main(){
	int a;
	bool sw = true;
	cout << "今日天氣是？ 1.晴天 2.雨天 3.陰天 " << endl; 
	
	do{
		cin>>a;
		switch(a){
			case 1: 
				cout<<"今天是晴天，注意防曬"<<endl<<endl;
				sw=false; 
				break;
			case 2:
				cout<<"今天是雨天，準備雨具"<<endl<<endl;
				sw=false; 
				break;
			case 3:
				cout<<"今天是陰天，注意保暖"<<endl<<endl;
				sw=false; 
				break;

			default:
				cout <<"選項無效，請重新輸入"<<endl<<endl;
				 
		}
	}while(sw);
	
	
	return 0;
}
