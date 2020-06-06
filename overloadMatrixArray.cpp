#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int size = 4;

class MyMatrix {
public:
	MyMatrix(int a[], int size);
	MyMatrix();
	friend const MyMatrix operator +(const MyMatrix& A, const MyMatrix& B);
	friend const MyMatrix operator -(const MyMatrix& A, const MyMatrix& B);
	friend const MyMatrix operator -(const MyMatrix& A);
	friend const MyMatrix operator *(const MyMatrix& A, const MyMatrix& B);
	friend ostream& operator <<(ostream& outputStream, const MyMatrix& A);
	friend istream& operator >>(istream& inputStream, MyMatrix& A);
private:
	int A[4];
};

int main(){
	srand(time(0));
	MyMatrix A, B, C;
	
	cout << "Cin A:\n";	
	cin >> A;
	cout << "Matrix A is \n" << A << endl;
	
	cout << "Cin B:\n";	
	cin >> B;
	cout << "Matrix B is \n" << B << endl;
	
	cout << endl << "Matrix A is ";

	cout << endl << "Perform the matrix addition: ";
	C = A + B;
	cout << C;
	
	cout << endl << "Perform the matrix substraction: ";
	C = A - B;
	cout << C;


	cout << endl << "Perform the matrix unary substraction: ";
	C = -B;
	cout << C;
	
	cout << endl << "Perform the matrix production: ";
	C = A * B;
	cout << C;

    return 0;
}

MyMatrix::MyMatrix(int a[], int size) {
	for(int i = 0; i < size; i++)
		A[i] = a[i];
}

MyMatrix::MyMatrix() {
	for(int i = 0; i < size; i++)
		A[i] = 0;
}

const MyMatrix operator +(const MyMatrix& A, const MyMatrix& B) {
	int a[size], i;

	for(i = 0; i < size; i++)
		a[i] = A.A[i] + B.A[i]; 
		
	return MyMatrix(a, size); 
}

const MyMatrix operator -(const MyMatrix& A, const MyMatrix& B) {
	int a[size], i;

	for(i = 0; i < size; i++)
		a[i] = A.A[i] - B.A[i]; 
		
	return MyMatrix(a, size); 
}

const MyMatrix operator -(const MyMatrix& A) {
	int a[size], i;

	for(i = 0; i < size; i++)
		a[i] = -A.A[i];
		
	return MyMatrix(a, size); 
}
const MyMatrix operator *(const MyMatrix& A, const MyMatrix& B) {
	MyMatrix C;
	int a[size];

	a[0] = A.A[0] * B.A[0] + A.A[1] * B.A[2];
	a[1] = A.A[0] * B.A[1] + A.A[1] * B.A[3];
	a[2] = A.A[2] * B.A[0] + A.A[3] * B.A[2];
	a[3] = A.A[2] * B.A[1] + A.A[3] * B.A[3];

	return MyMatrix(a, size); 
}

istream& operator >>(istream& inputStream, MyMatrix& A) {

	for(int i = 0; i < size; i++) 
		cin >> A.A[i]; // 可以直接CIN 不用CIN a 然後A.A[i] = a 

	return inputStream;
}

ostream& operator <<(ostream& outputStream, const MyMatrix& A) {
	
	cout << " | ";
	for(int i = 0; i < size; i++) {
		cout << A.A[i];
		if((i+1) % 2 == 0)
			cout << " | \n";
			if((i+1) % 4 != 0)
				cout << " | ";
	}
		
	return outputStream;
}
