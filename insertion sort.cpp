#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;

void coutt(int arr[], int size);

int main(){
	srand(time(0));
	
	int size = 5;
	int arr[size];
	
	for(int i = 0; i < size; i++)
		arr[i] = (rand( ) % 9) + 3;
		
	coutt(arr, 5);
	cout << endl;
	
	Is
	return 0;
} 

void InsertionSort(int size, int arr[]) {
	for(int i = 1; i < size; i++){
		int j = i; 
		int temp = arr[i];
		while(j = i - 1 && temp)
	}
}

void coutt(int arr[], int size) {
	for(int i = 0; i < size; i++){
		cout << arr[i] << "---";
	}
}
