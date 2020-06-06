#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <iomanip>

//有pinter: 
//B丟給A. 植根長度
//if(this == &rtSide) {
//return *this;
//else
//A先清掉在NEW. 原本的SIZE可能不一樣 
//A = new 
//A[i] = rtsid.A[i] 
//+ 
//~PFArrayD();解構子 

using namespace std;

//class MyArray {
//public:
//	   MyArray(int a[], int size);
//     MyArray();
//     int geti(int i) const;
//     void output();
//private:
//     int A[size];
//};

class MyArray {
public:
	MyArray(int *array, int size);
    MyArray();
    int geti(int i) const;
	int getSize() const {return arraySize;};
    void output();
private:
    int *A, arraySize;
};

const int operator *(const MyArray& A, const MyArray& B);
const MyArray operator +(const MyArray& A, const MyArray& B);
const MyArray operator ++(const MyArray& A);
const MyArray operator -(const MyArray& A);
bool operator ==(const MyArray& A, const MyArray& B);

void FillArray(int *A, int size);

istream& operator >>(istream& inputstream, MyArray& B);
ostream& operator <<(ostream& outputstream, MyArray& B);

int main() {
	int result, size, size2, i, *array;
    MyArray arrayA, arrayB, temp;
    
    srand(time(0));
	
	cout << "Input the size A: ";
	cin >> arrayA;
	/*array = new int[size];
	FillArray(array, size);
	arrayA = MyArray(array, size);*/
	
	cout << "Input the size B: ";
	cin >> arrayB;
/*	FillArray(array, size2);
	arrayB = MyArray(array, size2);*/
	
	if(arrayA.getSize() < arrayB.getSize()) {
		cout << "ERROR! ";
		goto start;
	}
	
	cout << "Array A is " << endl;
    arrayA.output();
    cout << endl <<"Array B is " << endl;
    arrayB.output();
    cout << endl;
    
    temp = arrayA + arrayB;
    cout << "A + B = " << endl;
    temp.output();
    cout << endl;
    
    temp = ++arrayA;
    cout << "++A = " << endl;
    temp.output();
    cout << endl;
    
    temp = -arrayA;
    cout << "-A = " << endl;
    temp.output();
    cout << endl;
    
    if(arrayA == arrayB) 
		cout << "A is equal to B" << endl;
    else 
		cout << "A is not equal to B" << endl;

	result = arrayA * arrayB;
	cout << "A * B = " << result << endl;
    
    
    start:
    	
    return 0;
}

void FillArray(int *A, int size) {
	for(int i = 0; i < size; i++) 
		A[i] = (rand( ) % 29) - 7;
}

MyArray::MyArray(int *array, int size) {
	arraySize = size;
	A = new int[size];
	for(int i = 0; i < size; i++)
		*(A + i) = array[i]; //A[i] = array[i];
}

MyArray::MyArray() {
	arraySize = 10;
	A = new int[arraySize];
	for(int i = 0; i < arraySize; i++)
		A[i] = 0;
}

int MyArray::geti(int i) const { return A[i];};

void MyArray::output() {
	int i;
	
	for(i = 0; i < arraySize; i++)
	    cout << setw(4) << A[i];

	cout << endl;
}

const MyArray operator +(const MyArray& A, const MyArray& B) {
	MyArray ArrayC;   
	int *C, i, size;

	size = A.getSize();
	
	C = new int[size];

	for(i = 0; i < size; i++)  
		C[i] = A.geti(i) + B.geti(i); 
	
	ArrayC = MyArray(C, size);

    return ArrayC;
}
      
bool operator ==(const MyArray& A, const MyArray& B) {
	int i, size;

	size = A.getSize();

	for(i = 0; i < size; i++)
		if(A.geti(i)!= B.geti(i)) return false;

	return true;
}

const MyArray operator ++(const MyArray& A) {
    MyArray ArrayC;   
	int *C, i, count = 0, size;

	size = A.getSize();

	C = new int[size];
	for(i = 0; i < size; i++) 
		if(A.geti(i) < 10) 
			count++;
			
	if(count > 5)
		for(i = 0; i < size; i++)
			C[i] = A.geti(i) + 1;
	else
		for(i = 0; i < size; i++)
			if(A.geti(i) < 10) 
				C[i] = A.geti(i) + 1;
			else
				C[i] = A.geti(i);
	
	ArrayC = MyArray(C, size);

    return ArrayC;
}

const MyArray operator -(const MyArray& A) {
    MyArray ArrayC;   
	int *c, i, size;

	size = A.getSize();

	c = new int[size];

	for(i = 0; i < size; i++)  
		c[i] = -A.geti(i); 
	
	ArrayC = MyArray(c, size);

    return ArrayC;
}

const int operator *(const MyArray& A, const MyArray& B) {
    int *C, i, result = 0, size;

	size = A.getSize();

	C = new int[size];
	for(i = 0; i < size; i++)  
		result= result + A.geti(i) * B.geti(i); 
	
	return result;
}

istream& operator >>(istream& inputstream, MyArray& B) {
	int i, size, *array; //給一個ARRAY填值,再回傳給/\  
	//                                        這個B|
	//要先 NEW                                     |                                          
	
	cout << "input size:";
	cin >> size;
	array = new int[size];
	
	for(i = 0; i < size; i++)
		array[i] = (rand( ) % 13) - 7;
	
	B = MyArray(array, size);
	
	return inputstream;
}
ostream& operator <<(ostream& outputstream, MyArray& B) {
	int i;
	
	for(i = 0; i <B.getSize(); i++)
		cout <<setw(4) << B.geti(i);
		
	cout << endl;
		
	return outputstream;
}
