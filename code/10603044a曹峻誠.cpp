//10603044a±ä®m¸Û
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class xyzSpace {
public:
     xyzSpace(double a, double b, double c);
     xyzSpace( );
     xyzSpace add(xyzSpace U);
     double inner(xyzSpace U) {return x * U.x + y * U.y + z * U.z;};
     double getX( ) {return x;};
     double getY( ) {return y;};
     double getZ( ) {return z;};
     bool equal(xyzSpace U);
     void output( ) {cout<< setw(4) << x << setw(4) << y << setw(4) << z;};
private:
     double x, y, z;
};

class MyMatrix {
public:
     MyMatrix(xyzSpace r1, xyzSpace r2, xyzSpace r3);
     MyMatrix( );
     MyMatrix add(MyMatrix B);
     MyMatrix product(MyMatrix B);
     MyMatrix transport( );
     bool equal(MyMatrix B);
     double det( );
     void output( );
private:
     xyzSpace R1, R2, R3;
};

int main( ){
	xyzSpace r1(1, 2, 3), r2(4, 5, 6), r3(7, 8, 9);
	MyMatrix A(r1, r2, r3), B(r3, r2, r1), C;
	double determinant;

	cout << "Matrix A is ";
	A.output( );
	cout << endl << endl << "Matrix B is ";
	B.output( );
	cout << endl << endl << "Matrix C is ";
	C.output( );
		
	cout << endl << endl << "Test A == B? ";
	if(A.equal(B))
		cout << "A = B." << endl;
	else
		cout << "A != B." << endl;
	
	cout << endl << "A + B =  ";
	C = A.add(B);
	C.output( );
	
	cout << endl << endl << "A * B = ";
	C = A.product(B);
	C.output( );
	
	cout << endl << endl << "det(A) = ";
	determinant = A.det( );
	
	cout << endl << "Transport of A:";
	C = A.transport( );
	C.output( );
	
    return 0;
}


xyzSpace::xyzSpace (double a, double b, double c) {
	x = a;
	y = b;
	z = c;
};

xyzSpace::xyzSpace( ): x(0), y(1), z(2) {};

xyzSpace xyzSpace::add(xyzSpace U){//
	xyzSpace p;
	
	p.x = U.x + x;
	p.y = U.y + x;
	p.z = U.z + x;
	
	return p;
}

bool xyzSpace::equal(xyzSpace U) {//
	xyzSpace p;
	
	if(x == U.x && y == U.y && z == U.z)
		return true;
	else
		return false;
}

MyMatrix::MyMatrix(xyzSpace r1, xyzSpace r2, xyzSpace r3){//
	R1 = r1;
	R2 = r2;
	R3 = r3;
}

MyMatrix::MyMatrix( ) {
	xyzSpace i, j, k;
	MyMatrix A, B;
	
	R1 = i;
	R2 = j;
	R3 = k;
}

MyMatrix MyMatrix::add(MyMatrix B) {-*-*
	MyMatrix p;
	xyzSpace i, j, k;
	i.getX();
	p.R2 = i , j;
	p.R3 = R3 + B.R3;
	
	return p;
}

MyMatrix MyMatrix::product(MyMatrix B) {
	MyMatrix p;
	
	p.R1 = B.R1 * R1;
}

MyMatrix MyMatrix::transport( ) {//
	MyMatrix p;
	
	p.R1.getY() = p.R2.getX();
	p.R2.getX() = p.R1.getY();
	
	p.R1.getZ() = p.R3.getX();
	p.R3.getX() = p.R1.getZ();
	
	p.R2.getZ() = p.R3.getY();
	p.R3.getZ() = p.R2.getZ();
	
	return p;
	 
}

bool MyMatrix::equal(MyMatrix B) {//
	if(R1 == B.R1 && R2 == B.R2 && R3 == B.R3)
		return true;
	else 
		return false;
}

double MyMatrix::det( ) {
	MyMatrix p;
	
	
}

void MyMatrix::output( );


