#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void FillArray(int size, int A[]);
void OutputArray(int size, int A[]);
void SelectionSort (int size, int A[]);

int size;

int main() {
	srand(time(0));
	
	int A[size];
	
	cout << "size = ";
	cin >> size;
  
	FillArray(size, A);
	OutputArray(size, A);
	cout << endl;

	SelectionSort(size, A);
	OutputArray(size, A);
	
	return 0;
}

void FillArray(int size, int A[]) {
	int i;
	
	for(i = 0; i < size; i++) {
		A[i] = 0;
		A[i] = (rand () % 7) + 2;
	}
}
void OutputArray(int size, int A[]) {
	int i;
	
	for(i = 0; i < size; i++)
		cout << A[i] << "  ";
}
void SelectionSort (int size, int A[]) {
	int i, j, pos;
	
	
	for(i = size - 1; i > 0; i--) {
    	pos = 0;
    	for(j = 1; j < size; j++) {
    		if(A[j] < A[pos])
    		pos = j;
    	}
    	swap(A[i - 1], A[pos]);
	}
}

