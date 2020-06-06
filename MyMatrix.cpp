#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

class MyMatrix {
public:
	MyMatrix(double a, double b, double c, double d);
	MyMatrix();
	const MyMatrix operator +(const MyMatrix& A) const;
	const MyMatrix operator -(const MyMatrix& A) const;
	const MyMatrix operator -()const;
	const MyMatrix operator *(const MyMatrix& A) const;
	bool operator ==(const MyMatrix& A) const;
	void output();
private:
	double a11, a12, a21, a22;
};

int main() {
	MyMatrix A, B, C;
	int a[4], i;
	
	srand(time(0));
	
	for(i = 0; i < 4; i++)
		a[i] = (rand() % 17) + 1;
	
	A = MyMatrix(a[0], a[1], a[2], a[3]);
	
	cout << endl << "MyMatrix A is ";
	A.output();
	
	for(i = 0; i < 4; i++)
		a[i] = (rand() % 19) + 1;
	
	B = MyMatrix (a[0], a[1], a[2], a[3]);
	cout << endl << "MyMatrix B is ";
} 
