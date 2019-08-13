#include<stdio.h>
#include<windows.h>
//#include<iomanip.h>
const Maxsize=20;
enum returninfo{success,fail,overflow,underflow,range_error
}; 
int dataarray[Maxsize];
int count;
returninfo create(int number);
bool empty(void);
int length(void);
returninfo traverse(void);
returninfo get(int position,int &item);
returninfo replace(int position,const int &item);
returninfo insert(int position,const int &item);
returninfo remove(int position);
returninfo invertlist(void);
void clearscreen(void);
void showmenu(void);
int userchoice(void);
returninfo processmenu(int menuchoice);



returninfo crete(int number)
{
	count=number;
	printf("请依次输入数据（用空格隔开）：\n");
	for(int i=0;i<count;i++)
	scanf("%d",&dataarray[i]);
	return success; 
 } 
 
 
 
bool empty(void)
{
	if(count==0)
	return true;
	else
	return false;
}


int length(void)
{
	return count;
}

returninfo traverse(void)
{
	if(empty())
	return underflow;
	printf("顺序表中的全部数据为：");
	for(int i=0;i<count;i++)
	printf("%d",dataarray[i]);
	printf("\n");
	return success;	 
}



returninfo get(int position,int &item)
{
	if(empty())
	return underflow;
	if(position<=0||position>count)
	return range_error;
	item=dataarray[position-1];
	return success;
}



returninfo replace(int position,const int &item)
{
	if(empty())
	return underflow;
	if(position<=0||position>count)
	return range_error;
	dataarray[position-1]=item;
	return success;
}


returninfo insert(int position,const int &item)
{
	if(count+1>=Maxsize)
	return overflow;
	if(position<=0||position>count+1)
	return range_error;
	count++;
	for(int i=count;i>=position;i--);
	{
		dataarray[i]=dataarray[i-1];
	 } 
	dataarray[position-1]=item;
	return success;
}


returninfo remove(int position)
{
	if(empty())
	return underflow;
	if(position<=0||position>count)
	return range_error;
	for(int i=position-1;i<count;i++);
	dataarray[i]=dataarray[i+1];
	count--;
	return success;
}


returninfo invertlist(void)
{
	int halfpos,tempddata;
	if(empty())
	return overflow;
	halfpos=count/2;
	for(int i=0;i<halfpos;i++)
	{
		tempdata=dataarray[i];
		dataarray[i]=daraarray[count-1-i];
		dataarray[count-1-i]=tempdata;
	}
	return success;
}

void clearscreen(void)
{
	system("cls");
}

void showmenu(void)
{
	printf("顺序表基本功能菜单                  \n");
	printf("=========================           \n");
	printf("1.输入数据（键盘输入）              \n");
	printf("2.显示数据（遍历全部数据）          \n");
	printf("3.修改数据（要提供位置和新值）      \n");
	printf("4.插入数据（要提供位置和新值）      \n");
	printf("5.删除数据（要提供位置）            \n");
	printf("6.读取数据（要提供位置）            \n");
	printf("7.求表长度                          \n");
	printf("8.数据反转（全部数据逆序存储）      \n");
	printf("9.结束程序                          \n");
	printf("=========================           \n");
}



int userchoice(void)
{
	int menuchoice;
	printf("请输入您的选择：");
	scanf("%d",&menuchoice);
	return menuchoice;
}


returninfo processmenu(int menuchoice)
{
	int position,item,returnvalue;
	switch(menuchoice)
	{
		case 1:
			printf("请问您要输入数据的个数，注意要在%d个以内：",Maxsize);
			scanf("%d",&item);
			if(item>Maxsize)
			printf("对不起，输入数据超限，操作已取消！\n");
			else
			{
				returnvalue=create(item);
				if(returnvalue==success)
				printf("建立顺序表操作成功!\n");
			}
			break;
		case 2:
			returnvalue=traverse();
			if(returnvalue==underflow)
			printf("顺序表目前为空，没有数据可以显示！\n");
			else
			printf("顺序表遍历操作成功！\n");
			break;
		case 3:
			printf("请输入要修改数据的位置：");
			scanf("%d",&position);
			printf("请输入要修改的新数据：");
			scanf("%d",&item);
			returnvalue=replace(position,item);
			if(returnvalue==underflow)
			printf("对不起，顺序表已空！\n");
			else if(returnvalue==range_error)
			printf("对不起，修改的位置超出了范围！\n");
			else
			printf("修改操作成功！\n");
			break;
		case 4:
			printf("请输入要插入数据的位置：");
			scanf("%d",&position);
			printf("请输入要插入的新数据：");
			scanf("%d",&item);
			returnvalue=insert(position,item);
			if(returnvalue==overflow)
			printf("对不起，顺序表溢出，无法插入新数据！\n");
			else if(returnvalue==range_error)
			printf("对不起，插入的位置超出了范围！\n");
			else 
			printf("插入操作成功！\n");
			break;
		case 5:
		    printf("请输入要删除数据的位置：");
			scanf("%d",&position);
			returnvalue=remove(position);
			if(returnvalue==underflow)
			printf("对不起，顺序表已空！\n");
			else if(returnvalue==range_error)
			printf("对不起，删除的位置超出了范围！\n");
			else
			printf("删除操作成功！\n");
			break;
		case 6:
		    printf("请输入要读取数据的位置：");
			scanf("%d",&position);
			returnvalue=get(position,item);
			if(returnvalue==underflow)
			printf("对不起，顺序表已空！\n");
			else if(returnvalue==range_error);
			printf("对不起，读取的位置超出了范围！\n");
			else
			printf("读取的数据为：%d\n读取操作成功！\n",item);
			break;
		case 7:
			printf("顺序表目前的长度为：%d\n",length());
			printf("求顺序表长度操作成功！\n");
			break;
		case 8:
			returnvalue=invertlist();
			if(returnvalue==underflow)
			printf("对不起，顺序表已空！\n");
			else
			printf("顺序表所有元素反转操作成功！\n");
			break;
		case 9:
			exit(0);
			break;
		default:
			printf("对不起，您输入的功能编号有错！请重新输入！！！\n");
			break;
	}
		return success;	 	
}
	
void main(void)
{
	SetConsoleTitle("顺序表实现线性表的基本功能（c版）");
	int menuchoice;
	system("color f0");
	clearscreen();
	while(1)
	{
		showmenu();
		menuchoice=userchoice();
		processmenu(menuchoice);
		system("pause");
		clearscreen();
	}
}
