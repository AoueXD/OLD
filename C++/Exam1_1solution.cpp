#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, m, n, i, j, sum = 0, flag;
    double result;

	cout << "flag = ";
	cin >> flag;

	switch(flag) {
		case 1:
			cout << "case 1:\n read three integers a, b, and c.\n";
			cout << "if a < b < c, compute b^2 - sqrt(4ac)\n";
			cout <<"else compute b^3 + 4ac\n";
			cout << "a = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			cout << "c = ";
    		cin >> c;
			if(a < b && b < c) {
				cout << "\n a < b < c: ";
				if(a * c >= 0)
					cout << " result = " << b * b - sqrt(4 * a * c);
				else
					cout << " result = " << b * b - sqrt(-4 * a * c);
			}
			else {
				cout << "\n!(a < b < c): ";
				cout << "result = " << pow(b, 3) + 4 * a * c;
			}
			break;

		case 2:
			cout << "case 2:\n read an integer n.\n";
			cout << " if n is odd, compute 1 + 3 + 5 + ... + n\n";
			cout << " else compute 2 + 4 + 6 + ... + n.\n n = ";
			cin >> n;

			if(n % 2 == 0) {
				i = 0;
				while(i <= n) {
					sum = sum + i;
					i = i + 2;
				}
				cout << " n is even: 2 + 4 + 6 + ... + n = " << sum;
			}
			else {
				i = 1;
				do {
					sum = sum + i;
					i = i + 2;
				} while(i <= n);
				cout << " n is odd: 1 + 3 + 5 + ... + n = " << sum;
			}
			cout << endl;
			break;

		default:
			cout << "odd m = ";
			cin >> m;
			cout << "odd n = ";
			cin >> n;
			int k = m - n;
	 
	   		 for(i = 0; i < k / 2; i++){
    			for(j = 0; j < m; j++)
					cout << " * ";
				cout << endl;
			}	
	
   			for(i = 0; i < m - k; i++){
				for(j = 0; j < k / 2; j++)
    				cout << " * ";
				for(j = 0; j < n; j++)
    				cout << "   ";
    			for(j = 0; j < k / 2; j++)
    			cout << " * ";
    			cout << endl;
   			}
	
			for(i = 0; i < k / 2; i++){
    			for(j = 0; j < m; j++)
				cout << " * ";
				cout << endl;
			}	
  
	}
   
    return 0;
}   
