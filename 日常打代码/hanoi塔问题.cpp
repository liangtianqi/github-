//ͨ���ݹ�ʵ�ֺ�ŵ�������
#include<stdio.h>
#include<windows.h>
void move(char pillarsource, int num,char pillartarget);
void hanoi(int num,char pillar01,char pillar02,char pillar03);
void startmove(void);
int num;
int main(void)
{
	SetConsoleTitle("�ݹ�ʵ�ֺ�ŵ����C�棩");
	system("color f0");
	char choose;
	while(1)
	{
		system("cls");
		printf("       ͨ���ݹ�ʵ�ֺ�ŵ��\n");
		startmove();
		printf("������ɣ�����\n");
		printf("�Ƿ������Y/N��?\n");
		fflush(stdin);
		scanf("%c",&choose);
		if(choose!='Y'&&choose!='y')  break; 
	 } 
	system("pause");
}

void hanoi(int num,char pillar01,char pillar02,char pillar03)
{
	if(num==1)
	  move(pillar01,1,pillar03);
	else
	{
		hanoi(num-1,pillar01,pillar03,pillar02);
		move(pillar01,num,pillar03);
		hanoi(num-1,pillar02,pillar01,pillar03);
	}
}

void move(char pillarsource,int num,char pillartarget)
{
	printf("��%d���̴ӵ�%c���� �ƶ�����%c����\n",num,pillarsource,pillartarget);
}


void startmove(void)
{
	printf("������������:");
	scanf("%d",&num);
	hanoi(num,'1','2','3');
}




