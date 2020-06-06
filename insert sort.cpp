#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(0));
	int size = 20, A[20], pos;
	
	for(int i = 0; i < size; i++) {
		A[i] = (rand() % 80) + 20;
	}
	
	for(int i = size; i > 0; i--) {
		pos = 0;
		for(int j = 1; j < i; j++) {
			if(A[j] > A[pos])
				pos = j;
		}
		swap(A[i-1], A[pos]);
	}
	
	for(int i = 0; i < size; i++) {
		cout << A[i] << endl;
	}
} 
