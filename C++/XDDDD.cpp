#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip> 

using namespace std;

void InsertSortedArray(int A[], int size);
void couut(int A[], int size);

int main(){
	int i, size, A[20];
	
	srand(time(0));
	
	cout << "The source array is: " << endl;
	
	for(i = 0; i < 20; i++){
		A[i] = (rand()%47) + 1;
		cout << " A[" << i << "] = " << A[i] << endl;
	}
	
	InsertSortedArray(A, size);

    cout << endl << "After Insertion sort: " << endl;
    
	couut(A, 0);
	
	return 0;
}

void InsertSortedArray(int A[], int size) {
	int i = 0, x;
	for(size = 1;size < 20; size++)
	{
		x = A[i];
		for(i=size; i>=0 && A[i]>x; i--)
		{
	    	A[i+1] = A[i];
			A[i+1] = x;
		}
	}
	       return;
}

void couut(int A[], int i = 0){
	for(i = 0; i < 20; i++) {
		cout << " A[" << setw(2) << i << "] = "<< setw(2) << A[i];
		if((i + 1) % 5 == 0) // 每五個換行 
		    cout << endl;
	}
}


