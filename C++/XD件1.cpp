#include <iostream>

using namespace std;

main(){
	
	int n;
	
	cout << "Please input a mouth.";
	
	cin >> n;
	
	if (n<1||n>12)
	
	cout << "ERROR";
	
	switch (n)
	{
		case 2 :
		case 3 :
		case 4 :
			cout << "¬K©u"; 
			break;
		case 5 :
		case 6 :
		case 7 :
			cout << "®L©u";
			break;
		case 8 :
		case 9 :
		case 10 :
			cout << "¬î©u";
			break;
		case 11 :
		case 12 :
		case 1 :
			cout << "¥V©u";
			break; 
	}

	return 0;
} 
