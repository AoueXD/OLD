#include <iostream>
#include <string> 
#include <cstdlib>

using namespace std;

const int defaultsize = 100;

class SymbolTable;

class ListNode {
	friend SymbolTable;
private:

	string ident;
	int  address;
	int blockn;
	ListNode *link;
	ListNode(string);
};

ListNode::ListNode(string s)
{
	ident = s;
	address = 0;
	blockn = 0;
	link = 0;
}

typedef ListNode* ListPtr;

class SymbolTable

{

public:
 	SymbolTable(int size = defaultsize) 
	{
		buckets = size;
		ht = new ListPtr[buckets];
		for (int i = 0; i < size; i++) 
			ht[i] = 0; // 指標一定要初始化為０，否則在執行時容易當機
	};
	ListNode *ChainSearch(const string, int(*) (string));
	void InsertHST(string,int, int, int(*) (string));
	void show_result(const ListPtr);
	void CreatHT(int );
private:
	int buckets;
	ListPtr *ht;
};

int h(string x)
{
	int nbuck = 0;
	for (size_t i = 0; i < x.size(); ++i)
		nbuck += (x[i] - 'a');
		
	return nbuck % 10;
}

void SymbolTable::CreatHT(int Nosyms)
{	
	string alphasA("abcdefghijklmnopqrstuvwxyz");
	string sym("abcdef");
	
	int symlen=6, i, j, address, blockno;
	
	for (i = 0; i < Nosyms; i++) {
		for (j = 0; j < symlen; j++) {
			sym[j] = alphasA[rand() % 26];
			cout << sym[j] << " "; 
		}
		cout << sym << endl;
		address = rand() % 10000;
		blockno = rand() % 5;
		SymbolTable::InsertHST(sym, address, blockno, h);
	}
}
