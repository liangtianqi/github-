#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#define N 2
typedef struct Student	//学生结构体类型定义
{
	int number;
	char name[10];
	int score;
}Student;

char sign;	//是否继续的标识符
char x[10];	//x用于清除多余的输入

void Displaymenu()
{
	printf("****学生信息管理系统*****\n");
	printf("|	1.输入信息	|\n");
	printf("|	2.显示信息	|\n");
	printf("|	3.查询信息	|\n");
	printf("|	4.删除信息	|\n");
	printf("|	5.信息排序	|\n");
	printf("|	6.统计成绩	|\n");
	printf("|	7.读取文件	|\n");
	printf("|	8.保存文件	|\n");
	printf("|	0.退出系统	|\n");
	printf("*************************\n");
}

void Input(Student stu[],int *n)  	//输入学生信息
{
	do
	{
		printf("请输入学生学号：");
		scanf("%d",&stu[*n].number);
		printf("请输入学生名字：");
		scanf("%s",&stu[*n].name);
		printf("请输入学生成绩：");
		scanf("%d",&stu[*n].score);
		(*n)++;
		getchar();
//		gets(x);	//清除多余的输入
		printf("是否继续输入？(Y/N)");
		scanf("%c",&sign);
	}while(sign=='y'||sign=='Y');
}

void Display(Student stu[],int n)		//显示学生信息
{
	int i;
	if(n>0)		//个数判断
	{
		printf("------------------------\n");
		printf("学号      姓名      成绩\n");
		printf("------------------------\n");
		for(i=0;i<n;i++)
			printf("%-10d%-10s%d\n",stu[i].number,stu[i].name,stu[i].score);
	}
	else
	{
		printf("没有学生信息！\n");
	}
	system("pause");
}

void Query(Student stu[],int n)	//查询学生信息
{
	int i;
	int number;
	do
	{
		i=0;
//		printf("请输入要查询的学生学号：");
		scanf("%d",&number);
		gets(x);
		while(stu[i].number!=number&&i<n)
			i++;
		if(i==n)
			printf("未查询到信息！\n");
		else
		{
			printf("查询成功！\n");
			printf("学号为：%d\n",stu[i].number);
			printf("名字为：%s\n",stu[i].name);
			printf("成绩为：%d\n",stu[i].score);
		}
		printf("是否继续查询？(Y/N):");
		scanf("%c",&sign);
	}while(sign=='y'||sign=='Y');
}
void Delect(Student stu[],int *n)	//删除学生信息
{
	int number;
	int i;
	char Delectsign;	//删除确认标识符
	do
	{
		i=0;
//		printf("请输入您要删除的学生学号：");
		scanf("%d",&number);
		gets(x);
		while(stu[i].number!=number&&i<*n)
			i++;
		if(i==*n)
			printf("未查询到信息！\n");
		else
		{
			printf("查询成功！\n");
			printf("学号为：%d\n",stu[i].number);
			printf("名字为：%s\n",stu[i].name);
			printf("成绩为：%d\n",stu[i].score);
		}
		printf("是否删除？Y/N：");
		scanf("%c",&Delectsign);
		getchar();
		if(Delectsign=='Y'||Delectsign=='y')
		{
/*			for(j=i;j<*n-1;j++)
			{
				stu[j].number=stu[j+1].number;
				strcpy(stu[j].name,stu[j+1].name);
				stu[j].score=stu[j+1].score;
			}
*/
			for(;i<*n;i++)
				stu[i]=stu[i+1];
			(*n)--;
			printf("删除成功！\n");
		}
		printf("是否继续删除？Y/N：");
		scanf("%c",&sign);
		gets(x);
	}while(sign=='Y'||sign=='y');
}

void Sort(Student stu[],int n)	//按学号排序
{
	Student temp;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			if(stu[i].number>stu[j].number)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
	}
	Display(stu,n);
//	system("pause");
}

void Write(Student stu[],int n)	//写入文件
{
	FILE *fp;
	int i;
//	char fname[10];
//	strcpy(fname,"stu.txt");
//	gets(fname);
//	if((fp=fopen("fname","w"))==NULL)
	if((fp=fopen("C:\\Users\\86131\\Desktop\\student.txt","w"))==NULL)
	{
		printf("打开失败！\n");
		system("pause");
		exit(0);
	}
	else
	{
		for(i=0;i<n;i++)
		{
			fprintf(fp,"%-10d%-10s%d",stu[i].number,stu[i].name,stu[i].score);		//原样输入
			fputs("\n",fp);
//			if(fwrite(&stu[i],28,1,fp)!=1)		//二进制输入
//				printf("写入错误！\n");
		}
		printf("保存成功！\n");
		fclose(fp);
	}
}
void Read(Student stu[],int *n)	//读取文件
{
	FILE *fp;
	if((fp=fopen("C:\\Users\\86131\\Desktop\\student.txt","r"))==NULL)
	{
		printf("打开失败！\n");
		exit (0);
	}
	else
	{
		while(!feof(fp))
		{
			if(feof(fp)) break;
			fscanf(fp,"%d%s%d",&stu[*n].number,stu[*n].name,&stu[*n].score);
//			if(feof(fp)) break;
			printf("%-10d%-10s%d\n",stu[*n].number,stu[*n].name,stu[*n].score);
//			if(feof(fp)) break;
			(*n)++;
		}
		printf("写入成功！\n");
	}
	fclose(fp);
}

void Calculate(Student stu[],int n)	//求最高分，最低分，平均分
{
	int j;
	int MAXscore=0,M=0;
	int MINscore=0,m=0;
	float sum=0;
	float AVG=0.0;
	for(j=0;j<=n;j++)
	{
		sum=sum+stu[j].score;
		if(stu[j].score>MAXscore)
		{
			MAXscore=stu[j].score;
			M=j;
		}
		if(stu[j].score<MINscore)
		{
			MINscore=stu[j].score;
			m=j;
		}
	}
	AVG=(sum/n);
	printf("最高分为%d，学号为%d\n",stu[M].score,stu[M].number);
	printf("最低分为%d，学号为%d\n",stu[m].score,stu[m].number);
	printf("平均分为%5.2f\n",AVG);
}

int main()	//主函数
{
	Student stu[N]={0};
	int choice;
	int n=0;	//记录学生信息个数
	do
	{
		Displaymenu();	//显示主菜单
		printf("请输入您的选择(0-8):\n");
		scanf("%d",&choice);
		if(choice>8||choice<0)
		{
			printf("输入错误！\n");
		}
		else
		{
			switch(choice)
			{
			case 1:
				printf("1.请输入学生信息：\n");
				Input(stu,&n);		//输入学生信息
				break;
			case 2:
				printf("2.显示学生信息\n");
				Display(stu,n);
				break;
			case 3:
				printf("3.请输入要查询的学生学号:");
				Query(stu,n);		//查询学生信息
				break;
			case 4:
				printf("4.请输入您要删除的学生学号：");
				Delect(stu,&n);
				break;
			case 5:
				printf("5.按学号升序结果如下：\n");
				Sort(stu,n);
				break;
			case 6:
				printf("6.统计成绩如下：\n");
				Calculate(stu,n);
				break;
			case 7:
				printf("7.读取文件内容！\n");
				Read(stu,&n);
				break;
			case 8:
				printf("8.保存文件！\n");
				Write(stu,n);
				break;
			}
		}
	}while(choice!=0);
	return 0;
}
