#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

class MyArray{
public:
	MyArray(int a[], int size);
	MyArray();
	int getI(int i) const;
	void output();
private:
	int A[size];
};

const MyArray operator+(const MyArray& A, const MyArray& B);
const MyArray operator-(const MyArray& A, const MyArray& B);
const MyArray operator-(const MyArray& A);
bool operator == (const MyArray& A, const MyArray& B);

int main() {
	srand(time(0));
	int A[size], result, i, index;
	MyArray arrayA, arrayB, arrayC, temp;
	
	for(i = 0; i < size; i++)
		A[i] = rand() % 18;

	arrayA = MyArray(A, size);
	
	for(i=0; i<size; i++) 
		B[i] = (rand() % 26);

	arrayB = MyArray(B, size);
	
	cout << "Array A is \n";
	arrayA.output();
	cout << endl << "Array B is \n" ;
	arrayB.ouyput();
	cout << endl;
	
	temp = arrayA + arrayB;
	cout << "A + B = " << temp;
	temp.output();
	cout <<endl;
	
	temp = arrayA - arrayB;
	cout << "A - B = " << temp;
	temp.output();
	cout << endl;
	
	temp = -arrayA;
	cout << "-A = \n";
	temp.output();
	cout << endl;
	
	if(arrayA == arrayB)
		cout << "A is equal to B.\n";
	else
		cout << "A isn't equal to B.\n";
		
	return 0;
}

MyArray::MyArray(int a[], int size) {
	int A[size];
	for(int i=0; i<size)
		A[size] = a[i];
} 
MyArray::MyArray() {
	MyArray A[i];
	int i;
	for(i=0; i<size; i++){
		A[i] = (rand() % 26);
	}
}

const MyArray operator+(const MyArray& A, const MyArray& B) {
	MyArray C;
	int size = 20
	for(int i=0; i<size; i++)
		C[i] = A[i] + B[i];
	
	return C;
}

const MyArray operator-(const MyArray& A, const MyArray& B) {
	MyArray C;
	int size = 20;
	
	for(int i=0; i<size; i++)
		C[i] = A[i] - B[i];
	
	return C;
}

const MyArray operator-(const MyArray& A) {
	int size;
	
	for(int i=0; i<size; i++)
		A[i] = -A[i];
		
	return A;
}

bool operator == (const MyArray& A, const MyArray& B) {
	
}
