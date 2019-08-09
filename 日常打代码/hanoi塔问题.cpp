//通过递归实现汉诺塔的求解
#include<stdio.h>
#include<windows.h>
void move(char pillarsource, int num,char pillartarget);
void hanoi(int num,char pillar01,char pillar02,char pillar03);
void startmove(void);
int num;
int main(void)
{
	SetConsoleTitle("递归实现汉诺塔（C版）");
	system("color f0");
	char choose;
	while(1)
	{
		system("cls");
		printf("       通过递归实现汉诺塔\n");
		startmove();
		printf("任务完成！！！\n");
		printf("是否继续（Y/N）?\n");
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
	printf("把%d号盘从第%c号柱 移动到第%c号柱\n",num,pillarsource,pillartarget);
}


void startmove(void)
{
	printf("请输入总盘数:");
	scanf("%d",&num);
	hanoi(num,'1','2','3');
}




