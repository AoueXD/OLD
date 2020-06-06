#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    
    int  i, j, n;
    
    fstream fout;
    
    fout.open("TXT.txt");
    if(fout.fail()){
        cout << "outout file opening failed.\n";
        exit(1);
        }
        
        
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            fout << j << "*" << i << "=" << setw(2) << j*i << " ";
            cout << j << "*" << i << "=" << setw(2) << j*i << " ";
		}
    cout << "\n";
    fout << "\n";
            }
    
    fout.close();        
    return 0; 
}
