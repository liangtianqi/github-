#include<iostream>
using namespace std;
int main(){
	int year;
	cin>>year;
	if(year%400==0)
	cout<<"年是闰年"
	else {if(year&4==0&&year%100!=0)
	cout<<"年是闰年"
	else
	cout<<"年是平年"} 
	return 0; 
}
