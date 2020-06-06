#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *link;
};

class Chain {
public:
	Chain() {
		create();
		number = 0;
	};
	Chain(Chain& aChain);
	~Chain();
	int NextNode(int x);
	int GetFirst() {return First -> data;}
	int GetNode(int k);
	Chain& operator=(Chain& aChain);
	Chain& AppendNode(const int& x);	
	Chain& Insertion(const int& x, int k);
	Chain& Deletion(int k, int kk);
	void OutputChain();
	bool IsInChain(int x);
private:
	Node *First;
	Node *Last;
	int number;
	void erase();
	void create();
};

void Chain::erase() {
	while(First != NULL) {
		Node *next = First;
		First = First -> link;
		delete next;
	}
}

void Chain::create(){
	First = new Node;
	First -> data = 0;
	First -> link = NULL;
	Last = First;
}

Chain::~Chain() {
	erase();
}

int Chain::GetNode(int k) {
	int i = 0;
	Node *current = First;

	while(i < k) {
		current = current -> link;
		i++;
	}

	return current -> data;
}

int Chain::NextNode(int x){
	Node *current = First;
	
	while(current != Last && current -> data != x) 
		current = current -> link;
	
	if(current == Last) return Last -> data;
	else {
		current = current -> link; 
		return current -> data;
	}
}

Chain& Chain::AppendNode(const int& x) {
    Node *y = new Node;
	y -> data = x;
	y -> link = NULL;
	number++;
	
	Last -> link = y;
	Last = y;
				
	return *this;
}

//Chain& Chain::AddFrontNode(const int& x) {
//	Node *y = new Node;
//	y -> data = x;
//	y -> link = First;
//	First = y;
//	
//	return *this;
//}

void Chain::OutputChain() {
	Node *current = First -> link;

	cout << endl << "The chain is : ";
	while(current != NULL) {
		cout << current -> data << " ";
		current = current -> link;
	}
	cout << endl << "Current size of the chain = " << number << endl;
}

bool Chain::IsInChain(int x) {
	Node *temp = First;

	while(temp) {
		if(x == temp -> data) return true;
		else temp = temp -> link;
	}
	return true;
}

Chain::Chain(Chain& aChain) {
    int i;
	Node *temp = aChain.First -> link;

	number = aChain.number;
    create();
	
	while(temp != NULL) {    
		Node *y = new Node;
	    y -> link = NULL;
    	y -> data = temp -> data;
    	Last -> link = y;
    	Last = y;
		temp = temp -> link;
    }   
}

Chain& Chain::operator=(Chain& aChain) {
	erase();
	
	Node *temp = aChain.First -> link;
	number = aChain.number;
    create();
    
    while(temp != NULL) {    
		Node *y = new Node;
	    y -> link = NULL;
    	y -> data = temp -> data;
    	Last -> link = y;
    	Last = y;
		temp = temp -> link;
    }   
    
    return *this;
}

Chain& Chain::Insertion(const int& x, int k) {
	int i = 0;
	Node *temp = First;
	Node *InsertedNode = new Node;
	number++;

	while(i < k) {
		i++;
		temp = temp -> link;
	}
	InsertedNode -> data = x;
	InsertedNode -> link = temp -> link;
	temp -> link = InsertedNode;
	
	return *this;
}

Chain& Chain::Deletion(int k, int kk) {
	int i = 1;   //因為下面的FIRST已經指向第一個(也就是 0; 
	Node *temp = First;
	Node *temp2; ///////////////NOT FIRST? 
	
	int j = kk - k + 1;
		
	while(i < k) {
		i++;
		temp = temp -> link;
	}
	
	//if(i == number - 1)
	if(i == kk)
		temp -> link = NULL;
	else
		temp2 = temp;
		while(i <= kk) { //讓temp2 指到KK 而KK的指向LINK就是我們要的 
			i++;
			temp2 = temp2 -> link;
		}
	
	temp -> link = temp2 -> link; //再讓Temp指向我們要的
	 
	number -= (kk - k + 1);
	
	return *this;
}

int main() {
    int number, item, k, kk;
	char which, next;
    Chain ChainA, ChainB;
    
    cout << "Enter an number of items: ";
    cin >> number;
    
    for(int i = 0; i < number; i++) {
       	cout << endl;
       	cout <<"Enter an number: ";
       	cin >> item;
        
     	ChainA.AppendNode(item);        
    }
	
    ChainA.OutputChain();  
	cout << endl;  
	
	do {
		cout << "What operation want?" << endl;
		cout << "Insertion: Press 'i'" << endl;
		cout << "Deletion: Press 'd'" << endl;
		cout << "Press: ";
		cin >> which;
		
		if(which == 'i') {
			cout << "insert an item after ";
			cin >> k;
			if(k > number)
				cout << "OUT OF RANGE!";
			else {
				cout << "data = ";
				cin >> item;
				ChainA.Insertion(item, k);
				ChainA.OutputChain();
				cout << endl;
				number++;
			}
		}
		if(which == 'd') {
			cout << "Delete which item to which";
			cin >> k >> kk;
			if(k > number || kk > number)
				cout << "OUT OF RANGE!";
			else if(k > kk)
				cout << "(ERROR!)";	
			else {
				ChainA.Deletion(k, kk);
				ChainA.OutputChain();
				cout << endl;
				number--;
			}
		}
		
		cout << endl << "continue?" << endl;
		cout << "YES: press 'c'" << endl;
		cout << "NO: press 'q'" << endl;
		
		cin >> next;
				
	} while(next == 'c');
	
    ChainA.OutputChain();
    
    cout << endl;
	cout << "Overloading Assignment B = A";
    ChainB = ChainA;
    ChainB.OutputChain();
	
	cout << endl << "Copy Constructor";
	Chain ChainC(ChainA);
	ChainB.OutputChain();

	return 0;
}
