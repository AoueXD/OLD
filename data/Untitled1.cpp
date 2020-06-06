#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	int i = 0, j = 0, G = 0, temp = 0, k;
	string name, str1, str2; //沒有長度 
	ifstream data("data.txt", ios::in); //從外面拿進來; 
	ofstream ofile("ans.txt", ios::out);//appent == 串流; out == 取代 	//ofile.open("data.txt");
	
	if(ofile.fail()){
		cout << "ERROR";
		exit(1);
	}
	else{
		while(!data.eof()){
			data >> str1;
			cout << str1<<endl;
			
			if( str1[i] == ' '){
				k++;
			}
			for(i = 0; i <str1.length(); i++){
				if((str1[i] >=65 && str1[i] <= 90) || (str1[i] >= 97 && str1[i] <= 122))
					G++;
				if(str1[i] == 'e')
					str2 += "a";
				if(str1[i] == 'm')
					str2 += "OO";
				else
					str2 += str1[i];
					
			}
			str2 += " ";
			i++;
			temp++;
		}
		cout << temp << endl;
		ofile << temp << endl;
		cout << G << endl;
		ofile << G << endl;
		cout << str2 << endl;
		ofile << str2 << endl;
	}
	ofile.close();
	
	return 0;
}
