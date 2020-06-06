#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void BS(int A[],int size);
void AS(int A[], int size);

int main() {
	
	int i, A[10], B[10], C[20], size = 10;
	srand(time(0));
	
	BS(A,10);
	BS(B,10);
	
	cout << "\n";
	
	AS(C,10);

	//隨機數列完排列
	//或
	//數列即是累加產生(一樣隨機; 
	
}

void BS(int A[],int size){
	
	int i = 0;
	do{
		A[i] = A[i-1] + (rand()%5)+2;
		cout << A[i] << "  ";
		i++;
	}while(i<size);
	cout << "\n";
}


void AS(int A[], int size){
	int i, j;
	
	for(i=0; i<10; i++){
		A[i] = (rand()% 100);
	}
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			if(A[j] < A[j-1])
				swap(A[j], A[j-1]);
		}
	}
	for(i=0; i<10; i++){
		cout << A[i] << "	";
	}
}
