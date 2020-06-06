#include<iostream>
#include<cstring>
using namespace std;
int replace(char a[],int size,char b[]);
int main(){
	int i=0,j=0;
	char inputstring[40],tmepstring[80],newstring[10],replacechar;
	bool instring=false;
	cout<<"块﹃璣ゅ ";
	cin.getline(inputstring,40);
	cout<<"璶传奔? ";
	cin>>replacechar;
	cout<<"ノぐ或传?";
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
	cout<<"场钉"<<endl;
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
