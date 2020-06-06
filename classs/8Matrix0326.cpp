#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class MyMatrix {
public:
	MyMatrix(int a, int b, int c, int d);
	MyMatrix();
	int getA11() const {return a11;};
	int getA12() const {return a12;};
	int getA21() const {return a21;};
	int getA22() const {return a22;};
	void output();
private:
	int a11, a12, a21, a22;
};

const MyMatrix operator +(const MyMatrix& A, const MyMatrix& B);
const MyMatrix operator -(const MyMatrix& A, const MyMatrix& B);
const MyMatrix operator -(const MyMatrix& A);
const MyMatrix operator *(const MyMatrix& A, const MyMatrix& B);
bool operator ==(const MyMatrix& A, const MyMatrix& B);

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

MyMatrix::MyMatrix(int a, int b, int c, int d) {	
	a = a11;
	b = a12;
	c = a21;
	d = a22;
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

const MyMatrix operator +(const MyMatrix& A, const MyMatrix& B) {//const
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = A.getA11() + B.getA11();
	a12 = A.getA12() + B.getA12();
	a21 = A.getA21() + B.getA21();
	a22 = A.getA22() + B.getA22();
	
	C = MyMatrix(a11, a12, a21, a22);
	
	return C;
}

const MyMatrix operator-(const MyMatrix& A, const MyMatrix& B) {//const
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = A.getA11() - B.getA11();
	a12 = A.getA12() - B.getA12();
	a21 = A.getA21() - B.getA21();
	a22 = A.getA22() - B.getA22();
	
	C = MyMatrix(a11, a12, a21, a22);
	
	return C;
}

const MyMatrix operator-(const MyMatrix& A) {
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = -A.getA11(); 
	a12 = -A.getA12();
	a21 = -A.getA21();
	a22 = -A.getA22();
	
	C = MyMatrix(a11, a12, a21, a22);
	
	return C;
}

const MyMatrix operator *(const MyMatrix& A, const MyMatrix& B) {
	MyMatrix C;
	int a11, a12, a21, a22;
	
	a11 = A.getA11() * B.getA11();
	a12 = A.getA12() * B.getA12();
	a21 = A.getA21() * B.getA21();
	a22 = A.getA22() * B.getA22();
	
	C = MyMatrix(a11, a12 , a21, a22);
	
	return C;
}

bool operator ==(const MyMatrix& A, const MyMatrix& B) {
	bool C;
	if (A.getA11() == B.getA11() && A.getA12() == B.getA12() && A.getA21() == B.getA21() && A.getA22() == B.getA22())
		return true;
	else 
		return false;
}
