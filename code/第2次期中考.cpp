#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const int size = 9; 

class MyMatrix33 {
public:
	MyMatrix33(int a[], int size);
    MyMatrix33();
    int geti(int i) const;
	int& operator[](int index);
private:
    int A[size];
};

const MyMatrix33 operator *(const MyMatrix33& A, const MyMatrix33& B);
const MyMatrix33 operator +(const MyMatrix33& A, const MyMatrix33& B);
const MyMatrix33 operator ++(const MyMatrix33& A);
const MyMatrix33 operator -(const MyMatrix33& A);
istream& operator >>(istream& inputstream, MyMatrix33& B); 
ostream& operator <<(ostream& outputstream, const MyMatrix33& B);
    
int main() {
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

MyMatrix33::MyMatrix33(int a[], int size) {
	for(int i = 0; i < size; i++)
		A[i] = a[i];
}

MyMatrix33::MyMatrix33() {
	for(int i = 0; i < size; i++)
		A[i] = 0;
}

int MyMatrix33::geti(int i) const{ return A[i];};

int& MyMatrix33::operator[](int index) {
	if(index < 0 || index > size)
		cout << "### Error index! ###";
	else
		return A[index];
}

const MyMatrix33 operator +(const MyMatrix33& A, const MyMatrix33& B) {
	MyMatrix33 ArrayC;   
	int c[size], i;

	for(i = 0; i < size; i++)  
		c[i] = A.geti(i) + B.geti(i); 
	
	ArrayC = MyMatrix33(c, size);

    return ArrayC;
}
      
	  
const MyMatrix33 operator ++(const MyMatrix33& A) {
    MyMatrix33 ArrayC;   
	int c[size], i;

	for(i = 0; i < size; i++) 
		c[i] = A.geti(i) + 1;
	
	ArrayC = MyMatrix33(c, size);
    
    return ArrayC;
}

const MyMatrix33 operator -(const MyMatrix33& A) {
    MyMatrix33 ArrayC;   
	int c[size], i;

	for(i = 0; i < size; i++)  
		c[i] = -A.geti(i); 
	
	ArrayC = MyMatrix33(c, size);

    return ArrayC;
}

const MyMatrix33 operator *(const MyMatrix33& A, const MyMatrix33& B) {
	MyMatrix33 ArrayC;
    int c[size], i, j, k, temp;

	for(i = 0; i < 3; i++) 
		for(j = 0; j < 3; j++) {
			temp = 0;
			for(k = 0; k < 3; k++)
				temp = temp + A.geti(i * 3 + k) * B.geti(j + k * 3);
			c[i * 3 + j] = temp;
		}

	ArrayC = MyMatrix33(c, size);
	
	return ArrayC;
}

istream& operator >>(istream& inputstream, MyMatrix33& B) {
	int i;
	int temp[size];
		
	for(i = 0; i < size; i++)
		temp[i] = (rand( ) % 7) - 3;

	B = MyMatrix33(temp, size);
	
	return inputstream;
}

ostream& operator <<(ostream& outputstream, const MyMatrix33& B) {
	int i, j;
	
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++)
	    	cout << setw(4) << B.geti(i * 3 + j);
		cout << endl;
	}

	return outputstream;
}
