#include<iostream> 
using namespace std; 
int main(){ 
int F1=1,F2=1,n,i,Fn=0,a=1,b=1; 
cout << "½Ð¿é¤J¤@­È:"; 
cin >> n ; 
{ 
if (n==1||n==2) {
cout << 1; 
}
else if {
cout << F1 + F2 ;
}
else  { 
for (i=3;i<=n;i++) 
{ 
Fn = F1+F2; 
F1 = F2; 
F2 = Fn; 
cout << "," << Fn+F1 ; 
}
}
system("pause"); 
return 0; 
} 

}
