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
	printf("�������������ݣ��ÿո��������\n");
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
	printf("˳����е�ȫ������Ϊ��");
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
	printf("˳���������ܲ˵�                  \n");
	printf("=========================           \n");
	printf("1.�������ݣ��������룩              \n");
	printf("2.��ʾ���ݣ�����ȫ�����ݣ�          \n");
	printf("3.�޸����ݣ�Ҫ�ṩλ�ú���ֵ��      \n");
	printf("4.�������ݣ�Ҫ�ṩλ�ú���ֵ��      \n");
	printf("5.ɾ�����ݣ�Ҫ�ṩλ�ã�            \n");
	printf("6.��ȡ���ݣ�Ҫ�ṩλ�ã�            \n");
	printf("7.�����                          \n");
	printf("8.���ݷ�ת��ȫ����������洢��      \n");
	printf("9.��������                          \n");
	printf("=========================           \n");
}



int userchoice(void)
{
	int menuchoice;
	printf("����������ѡ��");
	scanf("%d",&menuchoice);
	return menuchoice;
}


returninfo processmenu(int menuchoice)
{
	int position,item,returnvalue;
	switch(menuchoice)
	{
		case 1:
			printf("������Ҫ�������ݵĸ�����ע��Ҫ��%d�����ڣ�",Maxsize);
			scanf("%d",&item);
			if(item>Maxsize)
			printf("�Բ����������ݳ��ޣ�������ȡ����\n");
			else
			{
				returnvalue=create(item);
				if(returnvalue==success)
				printf("����˳�������ɹ�!\n");
			}
			break;
		case 2:
			returnvalue=traverse();
			if(returnvalue==underflow)
			printf("˳���ĿǰΪ�գ�û�����ݿ�����ʾ��\n");
			else
			printf("˳�����������ɹ���\n");
			break;
		case 3:
			printf("������Ҫ�޸����ݵ�λ�ã�");
			scanf("%d",&position);
			printf("������Ҫ�޸ĵ������ݣ�");
			scanf("%d",&item);
			returnvalue=replace(position,item);
			if(returnvalue==underflow)
			printf("�Բ���˳����ѿգ�\n");
			else if(returnvalue==range_error)
			printf("�Բ����޸ĵ�λ�ó����˷�Χ��\n");
			else
			printf("�޸Ĳ����ɹ���\n");
			break;
		case 4:
			printf("������Ҫ�������ݵ�λ�ã�");
			scanf("%d",&position);
			printf("������Ҫ����������ݣ�");
			scanf("%d",&item);
			returnvalue=insert(position,item);
			if(returnvalue==overflow)
			printf("�Բ���˳���������޷����������ݣ�\n");
			else if(returnvalue==range_error)
			printf("�Բ��𣬲����λ�ó����˷�Χ��\n");
			else 
			printf("��������ɹ���\n");
			break;
		case 5:
		    printf("������Ҫɾ�����ݵ�λ�ã�");
			scanf("%d",&position);
			returnvalue=remove(position);
			if(returnvalue==underflow)
			printf("�Բ���˳����ѿգ�\n");
			else if(returnvalue==range_error)
			printf("�Բ���ɾ����λ�ó����˷�Χ��\n");
			else
			printf("ɾ�������ɹ���\n");
			break;
		case 6:
		    printf("������Ҫ��ȡ���ݵ�λ�ã�");
			scanf("%d",&position);
			returnvalue=get(position,item);
			if(returnvalue==underflow)
			printf("�Բ���˳����ѿգ�\n");
			else if(returnvalue==range_error);
			printf("�Բ��𣬶�ȡ��λ�ó����˷�Χ��\n");
			else
			printf("��ȡ������Ϊ��%d\n��ȡ�����ɹ���\n",item);
			break;
		case 7:
			printf("˳���Ŀǰ�ĳ���Ϊ��%d\n",length());
			printf("��˳����Ȳ����ɹ���\n");
			break;
		case 8:
			returnvalue=invertlist();
			if(returnvalue==underflow)
			printf("�Բ���˳����ѿգ�\n");
			else
			printf("˳�������Ԫ�ط�ת�����ɹ���\n");
			break;
		case 9:
			exit(0);
			break;
		default:
			printf("�Բ���������Ĺ��ܱ���д����������룡����\n");
			break;
	}
		return success;	 	
}
	
void main(void)
{
	SetConsoleTitle("˳���ʵ�����Ա�Ļ������ܣ�c�棩");
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
