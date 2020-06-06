//https://zerojudge.tw/ShowProblem?problemid=d097
#include<iostream>
#include<cmath>

using namespace std;

int main (){
 int n , c , a[3000] ,b,x;
 bool xx=true;
 while(cin>>n){
  if( n > 0 && n <= 3000 ){
   for(int i=0;i<n;i++){
    cin>>c;
    a[i]=c;
  }
    
   for(int i=0;i<n-1;i++){
   b=abs(a[i]-a[i+1]);
   if( b == 0 || b >= n ){
    xx=false;
    break;
   }
  }
  if(xx==true)
   cout<<"Jolly"<<endl;
  else
   cout<<"Not jolly"<<endl;
  }
 }
 return 0;
}
