#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class MyMatrix {
public:
	MyMatrix(double a, double b, double c, double d);
	MyMatrix(int a); //let number became (a, 0)
	MyMatrix();
	const MyMatrix operator +(const MyMatrix& A) const;
	const MyMatrix operator -(const MyMatrix& A) const;
	const MyMatrix operator -() const;
	const MyMatrix operator *(const MyMatrix& A) const;
	bool operator ==(const MyMatrix& A) const;
	void output();
private:
	double a11, a12, a21, a22;
};

int main(){
	MyMatrix A, B, C;
	int a[4], i;
	srand(time(0));
	
	for(i = 0; i < 4; i++)
		a[i] = (rand() % 17);
	
	cout << endl << "Test A ++ B? ";
	if(A == B)
		cout << "A = B." << endl;
	else
		cout << "A != B." << endl;
		
	cout << endl << "Perform the matrix addition: ";
	
	C = A + B;
	C.output();
	cout << endl << "Perfrm the matrix substraction: ";
	C = A - B;
	C.output();
	cout << endl << "Perform the matrix unary substraction: ";
	C = -B;
	C.output();
	cout << endl << "Perform the matrix production: ";
	C = A * B;
	C.output();
	
	return 0;
}

MyMatrix::MyMatrix(double a, double b, double c, double d) {	
	a = a11;
	b = a12;
	c = a21;
	d = a22;
}

MyMatrix::MyMatrix(int a) {
	a11 = a;
	a12 = 0;
	 
}
MyMatrix::MyMatrix() {a11 = 0; a12 = 0; a21 = 0; a22 = 0;};

//int MyMatrix::getA11() const {return a11;};

void MyMatrix::output() {
	cout << "a = " << setw(2) << a11 << endl;
	cout << "b = " << setw(2) << a12 << endl;
	cout << "c = " << setw(2) << a21 << endl;
	cout << "d = " << setw(2) << a22 << endl;
	cout << endl;
	cout << "a11, a12 = (" << a11 << ", " << a12 << ")\n";
	cout << "a21, a22 = (" << a21 << ", " << a22 << ")\n";
}

const MyMatrix operator +(const MyMatrix& A) const {
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = a11 + A.a11;
	a12 = a12 + A.a12;
	a21 = a21 + A.a21;
	a22 = a22 + A.a22;
	
	C = MyMatrix(a11, a12, a21, a22);
	
	return C;
}

const MyMatrix operator-(const MyMatrix& A)const {
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = a11 - A.a11;
	a12 = a12 - A.a12;
	a21 = a21 - A.a21;
	a22 = a22 - A.a22;
	
	C = MyMatrix(a11, a12, a21, a22);
	
	return C;
}

const MyMatrix operator-(const MyMatrix& A) {
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = -A.a11; 
	a12 = -A.a12;
	a21 = -A.a21;
	a22 = -A.a22;
	
	C = MyMatrix(a11, a12, a21, a22);
	
	return C;
}

const MyMatrix operator *(const MyMatrix& A, const MyMatrix& B) {
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = a11 * A.a12 + A.a11 * A.a21;
	a12 = a11 * A.a12 + A.a11 * A.a21;
	a21 = a11 * A.a12 + A.a11 * A.a21;
	a22 = a11 * A.a12 + A.a11 * A.a21;
	
	C = MyMatrix(a11, a12 , a21, a22);
	
	return C;
}

bool operator ==(const MyMatrix& A) {
	bool C;
	if (a11 == A.a11 && a12 == A.a12 && a21 == A.a21 && a22 == A.a22)
		return true;
	else 
		return false;
}
