#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

const int size = 9; 

class MyMatrix33 {
public:
    MyMatrix33(int a[ ], int size);
    MyMatrix33( );
    int geti(int i) const;
    void seti(int i,int e);
    int& operator[ ](int index);
private:
    int A[size];
};
  
const MyMatrix33 operator *(const MyMatrix33& A, const MyMatrix33& B);
const MyMatrix33 operator +(const MyMatrix33& A, const MyMatrix33& B);
const MyMatrix33 operator ++(const MyMatrix33& A);
const MyMatrix33 operator -(const MyMatrix33& A);
istream& operator >>(istream& inputstream, MyMatrix33& B); 
ostream& operator <<(ostream& outputstream, const MyMatrix33& B);

int main( ) {
    srand(time(0));
	
    int A[size], result, i, index;
    MyMatrix33 arrayA, arrayB, temp;
    
     cin >> arrayA;
     cout << "Array A is " << endl << arrayA << endl;
	
     cin >> arrayB;
     cout << "Array B is " << endl << arrayB << endl;
    
     temp = arrayA + arrayB;
     cout << "A + B = " << endl << temp << endl;
     
     temp = ++arrayA;
     cout << "A++ = " << endl << temp << endl;
    
     temp = -arrayA;
     cout << "-A = " << endl << temp << endl;
	 temp = arrayA * arrayB;
     cout << "A * B = " << endl << temp << endl;

     cout << "Overloading []" << endl;
     cout << "Input the index: ";
     cin >> index;
     cout << arrayA[index];

     return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int MyMatrix33::geti(int i) const { return A[i];};

MyMatrix33::MyMatrix33(int a[ ], int size) {
	for(int i = 0; i < size; i++)
		*(A+i)= a[i]; //A[i] = array[i];
}

MyMatrix33::MyMatrix33() {
	for(int i = 0; i < size; i++)
		*(A + i) = 0; 
}

int& MyMatrix33::operator[ ](int index) {
	if(index < 0 || index > 19)
		cout << "Error index! " << endl;
	else
		return A[index];
}

const MyMatrix33 operator *(const MyMatrix33& A, const MyMatrix33& B) {
	int *C;
	MyMatrix33 R;
	C = new int[size];

	C[0] = A.geti(0) * B.geti(0)  + A.geti(1) * B.geti(3)  + A.geti(2) * B.geti(6);
	C[1] = A.geti(0) * B.geti(1)  + A.geti(1) * B.geti(4)  + A.geti(2) * B.geti(7);
	C[2] = A.geti(0) * B.geti(2)  + A.geti(1) * B.geti(5)  + A.geti(2) * B.geti(8);
	C[3] = A.geti(3) * B.geti(0)  + A.geti(4) * B.geti(3)  + A.geti(5) * B.geti(6);
	C[4] = A.geti(3) * B.geti(1)  + A.geti(4) * B.geti(4)  + A.geti(5) * B.geti(7);
	C[5] = A.geti(3) * B.geti(2)  + A.geti(4) * B.geti(5)  + A.geti(5) * B.geti(8);
	C[6] = A.geti(6) * B.geti(0)  + A.geti(7) * B.geti(3)  + A.geti(5) * B.geti(6);
	C[7] = A.geti(6) * B.geti(1)  + A.geti(7) * B.geti(4)  + A.geti(8) * B.geti(7);
	C[8] = A.geti(6) * B.geti(2)  + A.geti(7) * B.geti(5)  + A.geti(8) * B.geti(8);
	
	R = MyMatrix33(C, size);
	
	return R;
}

const MyMatrix33 operator +(const MyMatrix33& A, const MyMatrix33& B) {
	MyMatrix33 R;   
	int *C;
	
	C = new int[size];

	for(int i = 0; i < size; i++)  
		C[i] = A.geti(i) + B.geti(i); 
	
	R = MyMatrix33(C, size);

    return R;
}

const MyMatrix33 operator ++(const MyMatrix33& A) {
	MyMatrix33 R;
	int *C, i, count = 0;

	C = new int[size];
			
	for(i = 0; i < size; i++)
			C[i] = A.geti(i) + 1;
	
	R = MyMatrix33(C, size);

    return R;
}

const MyMatrix33 operator -(const MyMatrix33& A) {
    MyMatrix33 R;   
	int *C, i;

	C = new int[size];

	for(i = 0; i < size; i++)  
		C[i] = -A.geti(i); 
	
	R = MyMatrix33(C, size);

    return R;
}

istream& operator >>(istream& inputstream, MyMatrix33& B) { 
	int i;
	int *arrayC;
	
	arrayC = new int[size];
	
	for(i = 0; i < size; i++) {
		arrayC[i] = (rand ( ) % 9);
	}
	
	B = MyMatrix33(arrayC, size);
	
	return inputstream;
}

ostream& operator <<(ostream& outputstream, const MyMatrix33& B) {
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++) {
			cout << B.geti(i * 3 + j) << " ";
		cout << endl;
	}
	
	return outputstream;
}


void MyMatrix33::seti(int i, int e){
	A[i] = e;
}
