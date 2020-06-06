#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	char str[100];
	int i = 0, word = 0;
	
	cin.getline(str,100,'.');
	
	while(str[i] != '/0'){
		if(str[i]=='0')
			word++;
	}
	
	cout << "\n word = " << word;
	
	
}
