#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
	
	int size, i, j, count, pos;
	
	cin >> size;
	
	for(i = 200; i > 2; i--){
		pos = 0;
		for(j = 2; j < i; j++)
			if(i % j != 0)
				pos++;
		if(pos == (i - 2)){
			cout << i << endl;
			count++;
		}			
		
		if(count == size)
			break;
	}
	
	return 0;
	
}