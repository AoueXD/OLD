#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib> 

using namespace std;

int main(){
	int i = 0, j, P[20], RightNumber = 0, LeftNumber = 0;
	char A[20];
	
	return 0;
}
void Generate(int A[], int size) {
	int i = 0, j, P[20], RightNumber = 0, LeftNumber = 0;
	char A[20];
	
	srand(time(0));

	do {
		if(LeftNumber >= RightNumber && LeftNumber <= 10) {
			if((rand( ) % 2) == 0) {
				A[i] = '(';
				LeftNumber++;
			}
			else {
				A[i] = ')';
				RightNumber++;
			}
			i++;
		}
	 	if(LeftNumber > 10) {
			for(j = i - 1; j < 20; j++)
				A[j] = ')';
			i = 20;
		}
		if(LeftNumber < RightNumber) {
			RightNumber--;
			i--;
		}
	} while(i < 20);
}
