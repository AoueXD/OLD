#include <iostream>
#include <ctime>

#include <Algorithm>

using namespace std;

int main() {
	
	srand(time(0));
	
	
	int size;
	
	cin >> size;
	
	int *a = new int[size];
	
	for(int i = 0; i < size; i++) {
		a[i] = (rand() % 99999) + 0;
	}
	
	cout << sizeof(a) << endl << sizeof(a[size]) << endl;
		
}
