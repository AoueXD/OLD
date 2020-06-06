#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
//#include "OneDArray.h"

using namespace std;

class OneDArray {
public:
	OneDArray(int arraySize = 0);
	OneDArray(const OneDArray& arrayA);  
	~OneDArray() {cout << "OneDArray Destructor\n"; delete [] V;};
	OneDArray& operator=(const OneDArray& arrayA);
	const OneDArray operator+(const OneDArray& arrayB);
    const OneDArray operator-(); 
    const OneDArray operator-(const OneDArray& arrayB);
	int& operator[](int i) const {return V[i];};
    void Output(int arraySize);
	void FillArray(int arraySize);
	OneDArray& Create(int arraySize);
private:
	int size;
	int *V;
};

class TwoDArray: public OneDArray {
public:
	TwoDArray(int rowNum = 0, int colNum = 0);
	TwoDArray(const TwoDArray& TwoDA);
	~TwoDArray() {cout << "TwoDArray Destructor\n"; delete [] A;};
	TwoDArray& operator=(const TwoDArray& TwoDA);
	const TwoDArray operator+(const TwoDArray& TwoDB);
    const TwoDArray operator-(const TwoDArray& TwoDB);
	OneDArray& operator[](int i) const {return A[i];};
    void Output();
	void FillData();
	int getRowSize()const {return rowSize;};
	int getColSize()const {return colSize;};
private:
	int rowSize, colSize;
	OneDArray *A;
};

TwoDArray Transport(const TwoDArray TW);

int main(){
	int rowNum, colNum, i;

	cout << "*** Input the size of 2-dimensional array A and B ***" << endl;
	cout << "The size of row: ";
	cin >> rowNum;
	cout << "The size of column: ";
	cin >> colNum;

	TwoDArray TwoDA(rowNum, colNum), TwoDB(rowNum, colNum), TwoDC, TwoDD;	
	srand(time(0));

	cout << "The array A is: " << endl;
	TwoDA.FillData();
	TwoDA.Output(); 
	cout << "The array B is: " << endl;
	TwoDB.FillData();
	TwoDB.Output(); 
	
	cout << "A + B = " << endl;
	TwoDC = TwoDA + TwoDB;
	TwoDC.Output();

	cout << "A - B = " << endl;
	TwoDD = TwoDA - TwoDB;
	TwoDD.Output();
	
	cout << "A = B = C: " << endl;
	TwoDA = TwoDB = TwoDC;
	cout << "Output 2D array A after chain of assignment\n";
	TwoDA.Output();
	cout << "Output 2D array B after chain of assignment\n";
	TwoDB.Output();

	cout << "Create a 2D array E by invoking the copy constructor\n";
	TwoDArray TwoDE(TwoDA);
	TwoDE.Output();
	
	cout << "\nTransport the array A\n";
	//i = colNum;
	//j = rowNum;
	
	//TwoDE = TwoDArray(i, j);
	//TwoDE = Transport(TwoDA);
	Transport(TwoDA).Output();
	//TwoDE.Output();

	return 0;
	
}

TwoDArray::TwoDArray(int rowNum, int colNum) {
	rowSize = rowNum;
	colSize = colNum;
	
	A = new OneDArray[rowSize];

	for(int i = 0; i < rowSize; i++)
		A[i].Create(colSize);
}

void TwoDArray::FillData() {
	for(int i = 0; i < rowSize; i++) 
		A[i].FillArray(colSize);
}

TwoDArray::TwoDArray(const TwoDArray& TwoDA) {
	int i;
	
	cout << "TwoDArray: copy constructor\n";
	rowSize = TwoDA.rowSize;
	colSize = TwoDA.colSize;
	A = new OneDArray[rowSize];

	for(i = 0; i < rowSize; i++) 
		A[i] = TwoDA.A[i];
}

void TwoDArray::Output() {
	int i;
	for(i = 0; i < rowSize; i++) 
		A[i].Output(colSize);
		
	cout << endl;
}

const TwoDArray TwoDArray::operator+(const TwoDArray& TwoDB) {
	int i, j;

	rowSize = TwoDB.rowSize;
	colSize = TwoDB.colSize;
	TwoDArray TwoDC(rowSize, colSize);
	
	for(i = 0; i < rowSize; i++)
		TwoDC.A[i] = A[i] + TwoDB.A[i];
						
	return TwoDC;
}

const TwoDArray TwoDArray::operator-(const TwoDArray& TwoDB) {
	int i, j;

	rowSize = TwoDB.rowSize;
	colSize = TwoDB.colSize;
	TwoDArray TwoDD(rowSize, colSize);
	
	for(i = 0; i < rowSize; i++)
		TwoDD.A[i] = A[i] - TwoDB.A[i];
			
	return TwoDD;
}

TwoDArray& TwoDArray::operator=(const TwoDArray& TwoDA) {
	cout << "TwoDArray: overloading assignment\n";
	if(this == &TwoDA)
		return *this;
	else {
		int i, j;

		delete [] A;

		rowSize = TwoDA.rowSize;
		colSize = TwoDA.colSize;
		A = new OneDArray[rowSize];

		for(i = 0; i < rowSize; i++)
			A[i] = TwoDA.A[i];
	}
				
	return *this;
}

void OneDArray::FillArray(int arraySize) {
	for(int i = 0; i < arraySize; i++) 
		V[i] = (rand( ) % 23) - 7;
}

OneDArray::OneDArray(int arraySize) {
	size = arraySize;
	V = new int[size];
}

OneDArray& OneDArray::Create(int arraySize) {
	delete [] V;

	size = arraySize;

	V = new int[size];

	return *this;
}

OneDArray::OneDArray(const OneDArray& arrayA) {
	cout << "OneDArray: copy constructor\n";
	size = arrayA.size;
	V = new int[size];
	
	for(int i = 0; i < size; i++) 
			V[i] = arrayA.V[i];
}  

void OneDArray::Output(int arraySize) {
	for(int i = 0; i < arraySize; i++)
		cout << setw(4) << V[i];

	cout << endl;
}

const OneDArray OneDArray::operator+(const OneDArray& arrayB) {
	OneDArray arrayC(size);
	
	for(int i = 0; i < size; i++) 
		arrayC.V[i] = V[i] + arrayB.V[i];
    
	return arrayC;
}

const OneDArray OneDArray::operator-(const OneDArray& arrayB) {
	OneDArray arrayC(size);
	
	for(int i = 0; i < size; i++)
		arrayC.V[i] = V[i] - arrayB.V[i];

	return arrayC;
}

const OneDArray OneDArray::operator-() {
	OneDArray arrayC(size);
	
	for(int i = 0; i < size; i++)
		arrayC.V[i] = -V[i];

	return arrayC;
}

OneDArray& OneDArray::operator=(const OneDArray& arrayA) {
	cout << "OneDArray: overloading assignment\n";
	if(this == &arrayA)
		return *this;
	else {
		delete [] V;
		size = arrayA.size;
		V = new int[size];
	
		for(int i = 0; i < size; i++) 
			V[i] = arrayA.V[i];
	}
				
	return *this;
}

TwoDArray Transport(const TwoDArray& TW) {
	int row = TW.getColSize();
	int col = TW.getRowSize();
	
	//WT = new OneDArray[row];
	TwoDArray WT(row, col);
		
	for(int i = 0; i < row; i++) 
		for(int j = 0; j < col; j++)
			WT[i][j] = TW[j][i];
	
	return WT;
}
