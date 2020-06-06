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
    friend ostream& operator <<(ostream& outputstream , const MyMatrix& A);
    friend istream& operator >>(istream& inputstream ,MyMatrix& A);
private:
	int A[4];
};

int main(){
	srand(time(0));
	MyMatrix A, B, C;
	
	cin >> A;
	cout << endl << "Matrix A is " << endl << A;
	
	cin >> B;
	cout << endl << "Matrix B is " << endl << B;
	
	C = A + B;
	cout << endl << "Perform Matrix A and Matrix B addition: " << endl << C;
	
	C = A - B;
	cout << endl << "Perform Matrix A and Matrix B substraction: " << endl << C;
	
	C = -B;
	cout << endl << "Perform Matrix B unary substraction: " << endl << C;
	
	C = A * B;
	cout << endl << "Perform  Matrix A and Matrix B production: " << endl << C;

    return 0;
}

MyMatrix::MyMatrix(int a[], int size) {
	int i;
	
	for(i = 0; i < size; i++)
		A[i] = a[i];
}

MyMatrix::MyMatrix() {
	int i;
	
	for(i = 0; i < size; i++)
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

ostream& operator <<(ostream& outputstream , const MyMatrix& A){
	
	cout << "¢x" << setw(3) << A.A[0] << setw(6) << A.A[1] << " ¢x" << endl << "¢x" << setw(3) << A.A[2] << setw(6) << A.A[3] << " ¢x" << endl;
	
	return outputstream;
}

istream& operator >>(istream& inputstream ,MyMatrix& A){
	
	for (int i=0 ; i<4 ; i++){
		A.A[i] = rand()%17 - 5;
	}
	
	return inputstream;
}

