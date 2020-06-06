#include <iostream>

using namespace std;

int main(){

int a[3],temp,i,max;

	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
for(i=1;i<3;i++){
	if(temp<a[i]){
	temp=max;
	max=a[i];
	a[i]=temp;
	}
	cout<<a[1];
}
}
