#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int* a, int* b);

int main() {
	
	int i, j, size, *A, pos;
	
	srand(time(0));
	
	cout << "The size of source array: ";
	cin >> size;
	
	A = new int[size];

	for(i = 0; i < size; i++) {
		A[i] = (rand( ) % 3);
		cout << setw(3) << A[i]; 
	}
	
	cout <<endl;
	
	for(i = 0; i <size - 1; i--) {	
		for(j = i + 1; j < size; j++) {
			if(A[j] > A[j + 1])
				swap(A[j], A[j + 1]);
		}
	}
	
	for(i = 0; i < size; i++) 
		cout << setw(2) << A[i];


	delete [] A; // double空白[]空白A
	A = NULL;
	
	return 0;
	
}

void swap(int* a, int* b) {
	int* temp;
	
//	tanp = new int [size];
	
	*temp = *a;
	*a = *b;
	*b = *temp;
	
	return;
}
