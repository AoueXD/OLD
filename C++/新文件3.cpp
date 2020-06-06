#include <iostream>

using namespace std;

int main(){
	char arr[80];
	int i=0,j=0;
	bool test = true;
	cin>>arr;
	
	while(arr[i]!='\0'){
		cout<<arr[i++];
		
	}
	for(j=0;j<(i/2)&&test;j++)
	if(arr[j] != arr[--i])
	test = false;

	
	cout<<endl;
	
	if(test == true)
	cout<<"NO";
	else
	cout<<"YES";
	
} 
