/* 
Heapsize 

*/ 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void OutPut(int size, string a[]) {
	for(int i = 0; i < size; i++)
		cout << a[i] << endl;
}

void insertion_sort(int size, string a[]); //用插入排序3

/*void max_heapify(string a[], int start, int heapsize) {   //裡面也是要英文字串嗎 如果是的話要怎麼弄(left 
																//heapsize 是INT嗎 
	int left = (start * 2); 
	int right = (start * 2 + 1);
	int largest = 0;
	
	if (left <= heapsize && a[left] > a[start])
		largest = left;
	else 
		largest = start;
		
	if(right <= heapsize && a[right] > a[largest])
		largest = right;
		
	if(largest != start){
		swap(a[start], a[largest]);
		max_heapify(a, largest, heapsize);
	}
}*/
void max_heapify(string arr[], int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
	while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int size, string a[]);

int main(){
	srand(time(0));
	
	int pos, i = 0, size[5] = {10, 15, 20, 25, 30};
	
	double start, end;
	
	char mode;
	
	string *a;
	
	string b = "abcdefghijklmnopqrstuvwxyz", d = "abcdef", cc = "abcdef";
	string key = "abcdef";
	string m = "hi";
	int k = 0;
	
	cout << "Datasize = {10000, 15000, 20000, 25000, 30000}\n";
	cout << endl;
	cout << "-----------------------------\n";
	cout << "h = HeapSort\n";
	cout << "i = InsertionSort\n";
	cout << "-----------------------------\n";
	

	for(int s = 0; s < 5; s++){
		cout << "Current size is : " << size[s] << endl;
	
		a = new string[size[s]];
	
		for(i = 0; i < size[s]; i++) {
			for(int j = 0; j < 6; j++)
				d[j] = b[(rand () % 26)];//在26個英文字元中隨機取一個 
					a[i] = d;
			cout << a[i] << endl;
		} 
		cout << endl;
		
		for(int mm = 0; mm < 2; mm++){
			mode = m[mm];
			
		cout << "Corrent mode is : " << mode << endl;
		
		cout << endl;
		start = clock();
		switch(mode) {
			case 'h':
				heap_sort(size[s], a);
				OutPut(size[s], a);
				break;
			case 'i':
					insertion_sort(size[s], a);

				OutPut(size[s], a);
				break;
		}
		//cout << a[i] << endl;
		end = clock();
		
		cout << endl; 
		cout << mode <<  "	Cost " << (end - start) / CLOCKS_PER_SEC << " sec.";
		cout << endl;
		
		}	
		delete []a;// OP 	
		cout << endl << endl << "------------" << endl << endl;
		
		
	}
	
	
	return 0;
}
void heap_sort(int size, string a[]) {
	//初始化，i從最後一個父節點開始調整
	for(int i = size / 2 - 1; i >= 0; i--)
		max_heapify(a, i, size - 1);
	//先將第一個元素和已排好的元素前一位做交換，
	//再從新調整(剛調整的元素之前的元素)，直到排序完畢。
	for(int i = size - 1; i > 0; i--) {
		swap(a[0], a[i]);
		max_heapify(a, 0, i - 1);
	}
}

void insertion_sort(int size, string a[]) {
	string temp = "abcdef";
	
	for(int i = 1; i < size; i++){
  		temp = a[i];
   		int j;
   		for (j = i - 1; j >= 0 && temp < a[j]; j--)
       		a[j + 1] = a[j];
   		a[j + 1] = temp;
	}
	
	OutPut(size, a);
}
