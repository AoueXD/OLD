#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

int arr_show(int arr[][4],char str[],int size);	//陣列輸出 
int Insertion(int arr[][4],int size);			//插入新學生資料並排序 
void Modification(int arr[][4],int size);		//更改舊學生成績成績 
int Deletion(int arr[][4],int size);			//刪除舊學生資料 


int main(){
	fstream file;
	file.open("Exam1_3Input.txt");		//讀檔 
	int arr[50][4];
	char str_title[100];
	int i=0;
	
	file.getline(str_title,100);		//讀標題 
	
	while(!file.eof()){					//將檔案內容讀為一個二維矩陣 
		int j=0;
		file>>arr[i][j++];
		file>>arr[i][j++];
		file>>arr[i][j++];
		file>>arr[i][j];
		i++;
	}	
	int size=i;							//size為有意義之成員數 
	file.close();						//關閉檔案 



	char key;							//宣告char型態的key，作為資料處理的判斷標準 
	while(key!='q'&&key!='Q'){			//while迴圈，在key為'Q'之前會一直重複執行 
	
	arr_show(arr,str_title,size);
		cout<<"(i).......Insert member\n"
			<<"(d).......Delete member\n"
			<<"(m).......Change score\n"
			<<"(q).......Quit program\n\n";				
		cin>>key;
		
	switch(key){						//以switch實作選單的判斷 
		
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




int Insertion(int arr[][4],int size){		//********************插入資料********************// 
	int num,insert;
	bool sw=true;							//do-while迴圈條件 
	do{
		cout<<"Input \"Student Identification Code\" to insert\n";
		cin>>num;							//輸入學號 
		for(int i=0;i<size&&sw;i++){
			if(arr[i][0]==num){				//檢查學號是否有與已知的資料重複，重複則需要重新輸入 
				sw=true; 
				cout<<"A Wrong Number"<<endl;
				i=size;						//為了跳出迴圈 
			}
			else if((arr[i][0]>num)){		//假若檢查的資料大於輸入資料，表示學號為重複且到達插入點，將i記錄下來 
				insert=i;
				i=50;
				sw=false;
			}
		}
		
	}while(sw);

	for(int i=size;i>insert;i--){			//將插入點以後的資料都向後位移 
		for(int j=0;j<4;j++)
			arr[i][j]=arr[i-1][j];
	}
	
	
	arr[insert][0]=num;						//更新插入點資料 
	for(int j=1;j<4;j++){
		cout<<"Input Score ("<<j<<")\n";
		cin>>arr[insert][j];
	}
	
	
	return size+1;
}


void Modification(int arr[][4],int size){	//********************更改資料********************// 
	int num,Mod;
	bool sw;
	do{	
		sw=true;
		cout<<"Input \"Student Identification Code\" to Change\n";
		cin>>num;
		for(int i=0;i<size&&sw;i++){		//檢查學號是否在已知的資料內，不是則需要重新輸入 
			if(arr[i][0]==num){
				Mod=i;						//紀錄要更改成績的點 
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



int Deletion(int arr[][4],int size){		//********************刪除資料********************// 
	int num,delet;
	bool sw;
	do{
		sw=true;
		cout<<"Input \"Student Identification Code\" to Delete\n";
		cin>>num;
		for(int i=0;i<size&&sw;i++){		//檢查學號是否在已知的資料內，不是則需要重新輸入 
			if(arr[i][0]==num){
				delet=i;					//紀錄刪除點 
				sw=false;					//若在已知資料內則將迴圈判斷式設為false 
			}
		}
		if(sw)
			cout<<"A Wrong Number"<<endl;
	}while(sw);
	
	for(int i=delet;i<size-1;i++){
		for(int j=0;j<4;j++)
			arr[i][j]=arr[i+1][j];			//將刪除點後的資料向前補齊 
	}
	for(int j=0;j<4;j++)
		arr[size][j]=0;						//將原資料最後一位歸零 
		
	return size-1; 
}



int arr_show(int arr[][4],char str[],int size){		//********************輸出資料至螢幕********************// 
	cout<<" "<<str<<endl;
	for(int k=0;k<size;k++){
		cout<<"<"<<setw(2)<<k+1<<">";
		for(int j=0;j<4;j++){
			cout<<setw(6)<<arr[k][j]<<" ";
		}
		cout<<endl;
	}
}

