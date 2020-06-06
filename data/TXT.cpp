#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	int n, i, j;
	fstream fin;
	string str;
	
	fin.open("txt.txt");
	
	fin >> str;
	cout << str;
	
	return 0;
}
