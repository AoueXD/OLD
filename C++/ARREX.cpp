#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


void ArrOutput(double A[],int size);

using namespace std;

int main(){
	srand(time(0));
	double A_arr[30],B_arr[30],C_arr[60];
	
	for(int i=0;i<30;i++){
		A_arr[i]=rand()%100;
		B_arr[i]=rand()%100;
	}
	cout<<"**********  A_array   **********"<<endl;
	ArrOutput(A_arr,sizeof(A_arr)/8);
	cout<<endl<<"**********  B_array   **********"<<endl;
	ArrOutput(B_arr,sizeof(B_arr)/8);
	
	system("pause");
	return 0;
}

void ArrOutput(double A[],int size){
	for(int i=0;i<size;i++){
		cout<<setw(5)<<setprecision(4)<<A[i]<<"	";
		if(i%10==9)
			cout<<endl;
	}
}

