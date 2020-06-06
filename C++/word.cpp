#include <iostream>

using namespace std;

int main(){
	char str[100];
	int i=0,word=0;
	cin.getline(str,100,'#');
	
	while(str[i]!='\0'){
		if((65<=str[i]&&str[i]<=90)||(97<=str[i]&&str[i]<=122)){
			if(str[i+1]==' '||str[i+1]=='\n'||str[i+1]=='\0'){
				word++;
			}	
		}
		cout<<str[i++];	
	}
	cout<<endl<<"word="<<word<<endl;
	
	return 0;
} 
