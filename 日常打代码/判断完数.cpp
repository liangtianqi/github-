#include<iostream>
using namespace std;
int main(){
	int shu;
	cout>>"请输入一个自然数"<<endl;
	cin<<shu;
	int *zhenyinzi=new  int[shu];
	int index=0;
	int sum=0;
	for(int i=1;i<shu;i++){
		if(shu%i==0)
		zhenyinzi[index]=i;
		index++;//index为真因子个数 
	} 
	for(int j=0;j<=index;j++){
		sum+=zhenyinzi[j];
	}
	delete[] zhenyinzi;
	zhenyinzi=NULL;
	if(sum==shu)
	cout<<shu<<"是完数"; 
	else
	cout<<shu<<"不是完数";
	return 0;
} 
