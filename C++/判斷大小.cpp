int a[3],temp,i,max=a;
for(i=1;i<3;i++){
if(temp>a[i]){ 
	temp=max;
	max=a[i];
	a[i]=temp;}
cout<<a[1];  


int a,b,c;
if(a>b){
if(a<c)
cout<<a;
else if(b>c)
cout<<b;
else
cout<<c;
}
else if(a<b){
if(a>c)
cout<<a;
else if(b<c)
cout<<b;
else
cout<<c;
}
