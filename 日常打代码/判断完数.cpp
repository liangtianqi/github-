#include<iostream>
using namespace std;
int main(){
	int shu;
	cout>>"������һ����Ȼ��"<<endl;
	cin<<shu;
	int *zhenyinzi=new  int[shu];
	int index=0;
	int sum=0;
	for(int i=1;i<shu;i++){
		if(shu%i==0)
		zhenyinzi[index]=i;
		index++;//indexΪ�����Ӹ��� 
	} 
	for(int j=0;j<=index;j++){
		sum+=zhenyinzi[j];
	}
	delete[] zhenyinzi;
	zhenyinzi=NULL;
	if(sum==shu)
	cout<<shu<<"������"; 
	else
	cout<<shu<<"��������";
	return 0;
} 
