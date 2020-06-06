#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

int arr_show(int arr[][4],char str[],int size);	//�}�C��X 
int Insertion(int arr[][4],int size);			//���J�s�ǥ͸�ƨñƧ� 
void Modification(int arr[][4],int size);		//����¾ǥͦ��Z���Z 
int Deletion(int arr[][4],int size);			//�R���¾ǥ͸�� 


int main(){
	fstream file;
	file.open("Exam1_3Input.txt");		//Ū�� 
	int arr[50][4];
	char str_title[100];
	int i=0;
	
	file.getline(str_title,100);		//Ū���D 
	
	while(!file.eof()){					//�N�ɮפ��eŪ���@�ӤG���x�} 
		int j=0;
		file>>arr[i][j++];
		file>>arr[i][j++];
		file>>arr[i][j++];
		file>>arr[i][j];
		i++;
	}	
	int size=i;							//size�����N�q�������� 
	file.close();						//�����ɮ� 



	char key;							//�ŧichar���A��key�A�@����ƳB�z���P�_�з� 
	while(key!='q'&&key!='Q'){			//while�j��A�bkey��'Q'���e�|�@�����ư��� 
	
	arr_show(arr,str_title,size);
		cout<<"(i).......Insert member\n"
			<<"(d).......Delete member\n"
			<<"(m).......Change score\n"
			<<"(q).......Quit program\n\n";				
		cin>>key;
		
	switch(key){						//�Hswitch��@��檺�P�_ 
		
		case 'i':
		case 'I':
			size=Insertion(arr,size);
			break;
			
		case 'M':
		case 'm':
			Modification(arr,size);
			break;
			
		case 'D':
		case 'd':
			size=Deletion(arr,size);
			break;
			
		case 'Q':
		case 'q':
			cout<<"Quit Program..."<<endl;
			break;		
	}
	cout<<"\n\n\n\n";
}
	
	
	return 0;
}




int Insertion(int arr[][4],int size){		//********************���J���********************// 
	int num,insert;
	bool sw=true;							//do-while�j����� 
	do{
		cout<<"Input \"Student Identification Code\" to insert\n";
		cin>>num;							//��J�Ǹ� 
		for(int i=0;i<size&&sw;i++){
			if(arr[i][0]==num){				//�ˬd�Ǹ��O�_���P�w������ƭ��ơA���ƫh�ݭn���s��J 
				sw=true; 
				cout<<"A Wrong Number"<<endl;
				i=size;						//���F���X�j�� 
			}
			else if((arr[i][0]>num)){		//���Y�ˬd����Ƥj���J��ơA��ܾǸ������ƥB��F���J�I�A�Ni�O���U�� 
				insert=i;
				i=50;
				sw=false;
			}
		}
		
	}while(sw);

	for(int i=size;i>insert;i--){			//�N���J�I�H�᪺��Ƴ��V��첾 
		for(int j=0;j<4;j++)
			arr[i][j]=arr[i-1][j];
	}
	
	
	arr[insert][0]=num;						//��s���J�I��� 
	for(int j=1;j<4;j++){
		cout<<"Input Score ("<<j<<")\n";
		cin>>arr[insert][j];
	}
	
	
	return size+1;
}


void Modification(int arr[][4],int size){	//********************�����********************// 
	int num,Mod;
	bool sw;
	do{	
		sw=true;
		cout<<"Input \"Student Identification Code\" to Change\n";
		cin>>num;
		for(int i=0;i<size&&sw;i++){		//�ˬd�Ǹ��O�_�b�w������Ƥ��A���O�h�ݭn���s��J 
			if(arr[i][0]==num){
				Mod=i;						//�����n��令�Z���I 
				sw=false;
			}
		}
		if(sw)
			cout<<"A Wrong Number"<<endl;
	}while(sw);
	
	for(int j=1;j<4;j++){
		cout<<"Input News Score ("<<j<<")\n";
		cin>>arr[Mod][j];
	}
}



int Deletion(int arr[][4],int size){		//********************�R�����********************// 
	int num,delet;
	bool sw;
	do{
		sw=true;
		cout<<"Input \"Student Identification Code\" to Delete\n";
		cin>>num;
		for(int i=0;i<size&&sw;i++){		//�ˬd�Ǹ��O�_�b�w������Ƥ��A���O�h�ݭn���s��J 
			if(arr[i][0]==num){
				delet=i;					//�����R���I 
				sw=false;					//�Y�b�w����Ƥ��h�N�j��P�_���]��false 
			}
		}
		if(sw)
			cout<<"A Wrong Number"<<endl;
	}while(sw);
	
	for(int i=delet;i<size-1;i++){
		for(int j=0;j<4;j++)
			arr[i][j]=arr[i+1][j];			//�N�R���I�᪺��ƦV�e�ɻ� 
	}
	for(int j=0;j<4;j++)
		arr[size][j]=0;						//�N���Ƴ̫�@���k�s 
		
	return size-1; 
}



int arr_show(int arr[][4],char str[],int size){		//********************��X��Ʀܿù�********************// 
	cout<<" "<<str<<endl;
	for(int k=0;k<size;k++){
		cout<<"<"<<setw(2)<<k+1<<">";
		for(int j=0;j<4;j++){
			cout<<setw(6)<<arr[k][j]<<" ";
		}
		cout<<endl;
	}
}

