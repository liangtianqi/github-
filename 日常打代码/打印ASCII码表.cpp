#include<iostream>
using namespace std;
int main(){
	int i;
	for(int row=1;row<=16;row++){//一列一列的打印，一列打印16个 
		i=row;
		while(i<=127){
			switch(i){
				case 7:cout<<i<<"="<<"\\n"<<" | ";break;
				case 8:cout<<i<<"="<<"\\b"<<" | ";break;
				case 9:cout<<i<<"="<<"\\t"<<" | ";break;
				case 10:cout<<i<<"="<<"\\n"<<" | ";break;
				case 11:cout<<i<<"="<<"\\v"<<" | ";break;
				case 12:cout<<i<<"="<<"\\f"<<" | ";break;
				case 13:cout<<i<<"="<<"\\r"<<" | ";break;
				default:cout<<i<<"="<<"char(i)"<<" | ";break;
			}
			i+=16;
		}
		cout<<endl;
	}
	return 0;
} 
