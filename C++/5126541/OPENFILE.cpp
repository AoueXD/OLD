#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	int i;
	char str[60], name[16], cha[100];
	ifstream EmailBook;//fin
	ofstream fout;
	
	cout << "輸入檔案名稱(不可超過16個字)";
	cin >> name;
	
	//EmailBook.open("EmailBook.txt");//直接打開 要 " "; 
	EmailBook.open(name);//直接打 不用 " "; 
	if(EmailBook.fail()){
		cout  << "FILE ERROR !";
		exit(1);
	}
	
	while(!EmailBook.eof()){
		EmailBook >> cha;
		cout << cha;
	}
	
	EmailBook.close();
	
	return 0;

}

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	int n, i=2;
	bool state = true;
	cin >> n;
	
	while(i<n&&state){
		if(n%i == 0)
		state = false;
		
		i++;
	}
	
	if(state)
		cout << "植樹";
	else
		cout << "NO植樹" ;
			
}
