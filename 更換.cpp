#include <iostream>
#include <cstring>

using namespace std;

void replace(char A[], int size, char B[]);

int main(){
	
	int i=0,j=0;
	char inputstring[20],tempstring[80],newstring[10],replacechar;
	bool instring=false;
	
	cout << "Please input a value: ";
	cin.getline(inputstring,20);
	cout << "changed word: ";
	cin >> replacechar;
	cout << "which word: ";
	cin >> newstring;
	
	while(inputstring[i]!='\0'){
		if(inputstring[i] == replacechar){
			instring = true;
			j = replace(tempstring,j,newstring)
		}
		else{
			tempstring[j] = inputstring[i];
			j++;
		}
		i++;	
	}
	return 0;
} 

void replace(char A[], int size, char B[]){
	int i = 0;
	while(B[i] != '\0'){
		A[size+1] = B[i];
		i++;
	}
	return size +i;
}
