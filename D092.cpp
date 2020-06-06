#include <iostream>

using namespace std;

int main() {
	
	string arr;
	cin >> arr;
	int key;
	int length;
	
	 char ch[20];
	 cout<<"enter a sentence:"<<endl;
	 cin.get(ch,10,'\\n');//«ü©w?¦æ²Å??¤î¦r²Å
	 cout<<ch<<endl;
	 
	while(cin >> arr) {
		 cin.get(ch,10,'\\n');
		for(int i = 0; i < length; i--) {
			if((arr[i] - arr[i + 1]) < 0) 
				key = (arr[i] - arr[i + 1]) * - 1; 
				
			if(key != i + 1 || key != length - i)
				break;
			else
				cout << key; 
				
			
		} 
	}
} 
