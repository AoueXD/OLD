#include<iostream>

using namespace std;

int main(){
	
	for(int k=1;k<10;k=k+3){
		for(int i=1;i<10;i++){
			for(int j=k;j<k+3;j++)
	cout<<j<<"x"<<i<<"= "<<j*i<<"	";
	cout<<endl<<endl;	
	cout<<endl;
		}
	}
	return 0;
}
