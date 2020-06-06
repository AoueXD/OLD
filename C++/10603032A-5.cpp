//¶À­³³Ç10603032A
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Max(int A[], int size);

int main(){
	int i = 0, j,a=-1,b=0,c, size,x, A[20],B[20],C[40],D[20];
	
	srand(time(0));
	
	

	for(i = 0; i < 20; i++) {
		A[i] = (rand( ) % 15 + 1;
		B[i] = (rand( ) % 15) + 1;
		D[i] = (rand( ) % 7) + 1;	        
    }

	for(size = 20; size > 1; size--) {
		j = Max(A, size);
		swap(A[j], A[size - 1]);
	}
	
	for(size = 20; size > 1; size--) {
		j = Max(B, size);
		swap(B[j], B[size - 1]);
	}
	
	cout << "The A array is: " << endl;
	cout << " A = [" ;
	for(i = 0; i < 20; i++) {
		cout << A[i]<<" ";
	}
	cout<<"]"<<endl;
	
	cout << "The B array is: " << endl;
	cout << " B = [" ;
	for(i = 0; i < 20; i++) {
	cout << B[i]<<" ";
	}
	cout<<"]"<<endl<<endl;;
	
	cout <<"The First Answer;"<<endl<< "The C array is: " << endl;
	for(i=0;i<40;i++){
	if(i<20)
	C[i]=A[i];
	else
	C[i]=B[i-20];
}

	for(size = 40; size >1;size--){
		j = Max(C, size);
		swap(C[j], C[size - 1]);
}


	cout << " C = [" ;
	for(i = 0; i < 40; i++) {
		cout << C[i]<<" ";
	}
		cout<<"]"<<endl<<endl;;
	

	cout<<"The second answer:"<<endl;
	cout << "The D array is: " << endl;
	cout<<"D = [";
	for(i=0;i<20;i++){
	cout << D[i]<<" ";
	}
	cout<<"]"<<endl;
	
	cin>>c;
	x=D[c];
	cout<<"x="<<x<<endl;;
	for(i=0;i<c;i++){
	if(D[b]>x)
	b++;
	
	else{
		a=a+1;
		swap(D[a],D[b]);
		b++;	
	}
}
	swap(D[a+1],D[c]);
		
	cout << "The D array is: " << endl;
	cout<<"D = [";
	for(i=0;i<20;i++){
	cout << D[i]<<" ";
	}
	cout<<"]"<<endl;
		
	return 0;
	
}

int Max(int A[], int size) {
	int pos = 0;

	for(int i = 0; i < size; i++)
		if(A[i] > A[pos]) 
			pos = i;
	
	return pos;
}


