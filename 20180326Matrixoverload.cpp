#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class MyMatrix {
public:
	MyMatrix(int a11,int b12,int c21,int d22);
	MyMatrix();
	int GetA11() const {return a;};
	int GetA12() const {return b;};
	int GetA21() const {return c;};
	int GetA22() const {return d;};
	void output();
private:
	int a, b, c, d;
};

const MyMatrix operator +(const MyMatrix& A ,const MyMatrix& B);
const MyMatrix operator -(const MyMatrix& A ,const MyMatrix& B);
const MyMatrix operator -(const MyMatrix& A);
const MyMatrix operator *(const MyMatrix& A ,const MyMatrix& B);
bool operator ==(const MyMatrix& A,const MyMatrix& B);

int main(){
	MyMatrix A(1,2,3,4),B(5,6,7,8),C;
	
	srand(time(0));
	int a[4];
	
	for(int i=0;i<4;i++)
	{
		
	}
	
	cout << endl << "Matrix A is "<<endl;
	A.output();
	cout << endl << "Matrix B is "<<endl;
	B.output();
	cout << endl << "Matrix C is "<<endl;
	C.output();
	
	cout << endl << "Test A == B? "<<endl;
    if(A == B)
    {
		cout << "A = B." << endl;
	}
	else
	{
		cout << "A != B." << endl;
	}
	
    cout << endl << "Perform the matrix addition: "<<endl;
    C = A + B;
    C.output( );
    cout << endl << "Perform the matrix substraction: "<<endl;
    C = A - B;
    C.output( );
    cout << endl << "Perform the matrix unary substraction: "<<endl;
    C = -B;
    C.output( );
    cout << endl << "Perform the matrix production: "<<endl;
    C = A * B;
    C.output( );
    
    return 0;
}

MyMatrix::MyMatrix(int a11,int b12,int c21,int d22)
{
	a=a11;
	b=b12;
	c=c21;
	d=d22;
}

MyMatrix::MyMatrix()
{
	a=1;
	b=1;
	c=1;
	d=1;
}

void MyMatrix::output()
{
	cout<<"a == "<<a<<endl;
	cout<<"b == "<<b<<endl;
	cout<<"c == "<<c<<endl;
	cout<<"d == "<<d<<endl;
	cout<<endl;
	cout<<"| a = "<<a<<", b = "<<b<<" |"<<endl;
	cout<<"| c = "<<c<<", d = "<<d<<" |"<<endl;
}

const MyMatrix operator +(const MyMatrix& A ,const MyMatrix& B)
{
	MyMatrix C;
	int a11,b12,c21,d22;
	
	a11=A.GetA11()+B.GetA11();
	b12=A.GetA12()+B.GetA12();
	c21=A.GetA21()+B.GetA21();
	d22=A.GetA22()+B.GetA22();
	
	C = MyMatrix(a11,b12,c21,d22);
	
	return C;
}

const MyMatrix operator -(const MyMatrix& A ,const MyMatrix& B)
{
	MyMatrix C;
	int a11,b12,c21,d22;
	
	a11=A.GetA11()-B.GetA11();
	b12=A.GetA12()-B.GetA12();
	c21=A.GetA21()-B.GetA21();
	d22=A.GetA22()-B.GetA22();
	
	C = MyMatrix(a11,b12,c21,d22);
	
	return C;
}

const MyMatrix operator -(const MyMatrix& A)
{
	MyMatrix C;
	int a11,b12,c21,d22;
	
	a11=-A.GetA11();
	b12=-A.GetA12();
	c21=-A.GetA21();
	d22=-A.GetA22();
	
	C = MyMatrix(a11,b12,c21,d22);
	
	return C;
}

const MyMatrix operator *(const MyMatrix& A ,const MyMatrix& B)
{
	MyMatrix C;
	int a11,b12,c21,d22;
	
	a11=A.GetA11()*B.GetA11()+A.GetA12()*B.GetA21();
	b12=A.GetA11()*B.GetA12()+A.GetA12()*B.GetA22();
	c21=A.GetA21()*B.GetA11()+A.GetA22()*B.GetA21();
	d22=A.GetA21()*B.GetA12()+A.GetA22()*B.GetA22();
	
	C = MyMatrix(a11,b12,c21,d22);
	
	return C;
}

bool operator ==(const MyMatrix& A,const MyMatrix& B)
{
	if(A.GetA11()==B.GetA11() && A.GetA12()==B.GetA12() && A.GetA21()==B.GetA21() && A.GetA22()==B.GetA22())
	{
		return true;
	}
	else
	{
		return false;
	}
}
