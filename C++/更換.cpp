#include<iostream>
#include<cstring>
using namespace std;
int replace(char a[],int size,char b[]);
int main(){
	int i=0,j=0;
	char inputstring[40],tmepstring[80],newstring[10],replacechar;
	bool instring=false;
	cout<<"輸入一串英文字 ";
	cin.getline(inputstring,40);
	cout<<"哪個字要換掉? ";
	cin>>replacechar;
	cout<<"用什麼換?";
	cin>>newstring;
	while(inputstring[i]!='\0'){
		if(inputstring[i]==replacechar){
			instring=true;
			j=replace(tmepstring,j,newstring);
			
		}
		else{
			tmepstring[j]=inputstring[i];
			j++;
		}
		i++;
	}
	if(instring==false)
	cout<<"部隊"<<endl;
	tmepstring[j]='\0';
	cout<<tmepstring<<endl;
	
	return 0;
	
}
int replace(char A[], int size, char B[]) {
	int i = 0;
	while(B[i] != '\0') {
		A[size + i] = B[i];
		i++;
	}
		return size + i;
}
