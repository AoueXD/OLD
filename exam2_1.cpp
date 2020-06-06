#include <iostream>
#include <iomanip>

using namespace std;

class xySpace {
public:
	xySpace(double a, double b, double c);
	xySpace();
	xySpace add(xySpace U);
	double inner(xySpace U) {return x * U.x + y * U.y + z * U.z;};
	double getX() {return x;};
	double getY() {return y;};
	double getZ() {return z;};
	bool equal(xySpace U);
	void output() {cout<< setw(4) << x << setw(4) << y << setw(4) << z;};
private:
	double x, y, z;
};

class MyMatrix {
public:
	MyMatrix(xySpace r1, xySpace r2, xySpace r3) {R1 = r1; R2 = r2; R3 = r3;};
	MyMatrix();
	MyMatrix add(MyMatrix B);
	MyMatrix product(MyMatrix B);
	MyMatrix transport();
	bool equal(MyMatrix B);
	double det();
	void output();
private:
	xySpace R1, R2, R3;
};

int main(){
	xySpace r1(1, 2, 3), r2(4, 5, 6), r3(7, 8, 9);
	MyMatrix A(r1, r2, r3), B(r3, r2, r1), C;
	double determinant;

	cout << "Matrix A is ";
	A.output();
	cout << endl << endl << "Matrix B is ";
	B.output();
	cout << endl << endl << "Matrix C is ";
	C.output();
		
	cout << endl << endl << "Test A == B? ";
	if(A.equal(B))
		cout << "A = B." << endl;
	else
		cout << "A != B." << endl;

	cout << endl << "A + B =  ";
	C = A.add(B);
	C.output();
	
	cout << endl << endl << "A * B = ";
	C = A.product(B);
	C.output();
	
	cout << endl << endl << "det(A) = ";
	determinant = A.det();
	
	cout << endl << "Transport of A:";
	C = A.transport();
	C.output();
	
    return 0;
}

xySpace::xySpace(double a, double b, double c): x(a), y(b), z(c) {}

xySpace::xySpace(): x(0), y(0), z(0) {}

xySpace xySpace::add(xySpace C) {
	xySpace u;

	u.x = x + C.x;
	u.y = y + C.y;
	u.z = z + C.z;
	
	return u;
}

bool xySpace::equal(xySpace C) {
	if(x == C.x && y == C.y && z == C.z)
		return true;
	else
		return false;
}

MyMatrix::MyMatrix(): R1(1, 0, 0), R2(0, 1, 0), R3(0, 0, 1) {}

void MyMatrix::output() {
	cout << endl;
	R1.output();
	cout << endl;
	R2.output(); 
	cout << endl;
	R3.output(); 
}

MyMatrix MyMatrix::add(MyMatrix B) {
	MyMatrix C;

	C.R1 = B.R1.add(R1);
	C.R2 = B.R2.add(R2);
	C.R3 = B.R3.add(R3);

	return C;
}

MyMatrix MyMatrix::product(MyMatrix B) {
	MyMatrix C;
	xySpace c1, c2, c3;

	c1 = xySpace(B.R1.getX(), B.R2.getX(), B.R3.getX());
	c2 = xySpace(B.R1.getY(), B.R2.getY(), B.R3.getY());
	c3 = xySpace(B.R1.getZ(), B.R2.getZ(), B.R3.getZ());
	
	C.R1 = xySpace(R1.inner(c1), R1.inner(c2), R1.inner(c3));
	C.R2 = xySpace(R2.inner(c1), R2.inner(c2), R1.inner(c3));
	C.R3 = xySpace(R3.inner(c1), R3.inner(c2), R1.inner(c3));
	
	return C;
}

bool MyMatrix::equal(MyMatrix B) {
	if(R1.equal(B.R1) && R2.equal(B.R2) && R3.equal(B.R3))
		return true;
	else
		return false;
}

double MyMatrix::det() {
	double result;

	result = R1.getX() * (R2.getY() * R3.getZ() - R2.getZ() * R3.getY()) 
			- R1.getY() * (R2.getX() * R3.getZ() - R2.getZ() * R3.getX())
			+ R1.getZ() * (R2.getX() * R3.getY() - R2.getY() * R3.getX());
	cout << "the determinant is " << result << "." << endl;
	return result;
}

MyMatrix MyMatrix::transport() {
	MyMatrix C;
	xySpace c1, c2, c3;
	
	c1 = xySpace(R1.getX(), R2.getX(), R3.getX());
	c2 = xySpace(R1.getY(), R2.getY(), R3.getY());
	c3 = xySpace(R1.getZ(), R2.getZ(), R3.getZ());
	
	C = MyMatrix(c1, c2, c3);
	
	return C; 
}
