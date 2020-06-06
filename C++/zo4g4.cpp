#include <iostream>

using namespace std;

int main(){
	int F0=1,F1=1,Fn,n,i,count=0;
	
	cout << "please1 input a FIB value:";
	
	cin >> n;
	
	if (n==0||n==1)
	cout << "1";
	
	else if (n<0)
		cout << "ERROR";
		
		else {
			for(i=3;i<=n;i+2)
			{
				Fn=F0+F1;
				F0=F1;
				F1=Fn;
			
				count++;
			}
			cout << F0+F1 << "\n";
			cout << "°j°é°õ¦æ¦¸¼Æ:" << count; 
		} 
	return 0;
}
