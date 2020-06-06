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

void insertion_sort(int size, string a[]); //�δ��J�Ƨ�3

/*void max_heapify(string a[], int start, int heapsize) {   //�̭��]�O�n�^��r��� �p�G�O���ܭn����(left 
																//heapsize �OINT�� 
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
    // �إߤ��`�I���ЩM�l�`�I����
    int dad = start;
    int son = dad * 2 + 1;
	while (son <= end) { // �Y�l�`�I���Цb�d�򤺤~�����
        if (son + 1 <= end && arr[son] < arr[son + 1]) // �������Ӥl�`�I�j�p�A��̤ܳj��
            son++;
        if (arr[dad] > arr[son]) // �p�G���`�I�j��l�`�I�N��վ㧹���A�������X���
            return;
        else { // �_�h�洫���l���e�A�~��l�`�I�M�]�`�I���
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
				d[j] = b[(rand () % 26)];//�b26�ӭ^��r�����H�����@�� 
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
	//��l�ơAi�q�̫�@�Ӥ��`�I�}�l�վ�
	for(int i = size / 2 - 1; i >= 0; i--)
		max_heapify(a, i, size - 1);
	//���N�Ĥ@�Ӥ����M�w�Ʀn�������e�@�찵�洫�A
	//�A�q�s�վ�(��վ㪺�������e������)�A����Ƨǧ����C
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
