#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;
int main()
{
	ifstream file("data.txt", ios::in);
	string str, str2[10];
	int i = 0;
	
	if(file.is_open()){
		while(!file.eof()){
			file >> str;
			cout << str << endl;
			str2[i] = str;
			i++;
		}
	}
	else
		cout << "Error!" << endl;
		
	file.close();
	
	for(i=0; i<10; i++)
		cout << str2[i] <<endl;
	
	return 0;
}

