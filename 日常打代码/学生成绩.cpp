#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#define N 2
typedef struct Student	//ѧ���ṹ�����Ͷ���
{
	int number;
	char name[10];
	int score;
}Student;

char sign;	//�Ƿ�����ı�ʶ��
char x[10];	//x����������������

void Displaymenu()
{
	printf("****ѧ����Ϣ����ϵͳ*****\n");
	printf("|	1.������Ϣ	|\n");
	printf("|	2.��ʾ��Ϣ	|\n");
	printf("|	3.��ѯ��Ϣ	|\n");
	printf("|	4.ɾ����Ϣ	|\n");
	printf("|	5.��Ϣ����	|\n");
	printf("|	6.ͳ�Ƴɼ�	|\n");
	printf("|	7.��ȡ�ļ�	|\n");
	printf("|	8.�����ļ�	|\n");
	printf("|	0.�˳�ϵͳ	|\n");
	printf("*************************\n");
}

void Input(Student stu[],int *n)  	//����ѧ����Ϣ
{
	do
	{
		printf("������ѧ��ѧ�ţ�");
		scanf("%d",&stu[*n].number);
		printf("������ѧ�����֣�");
		scanf("%s",&stu[*n].name);
		printf("������ѧ���ɼ���");
		scanf("%d",&stu[*n].score);
		(*n)++;
		getchar();
//		gets(x);	//������������
		printf("�Ƿ�������룿(Y/N)");
		scanf("%c",&sign);
	}while(sign=='y'||sign=='Y');
}

void Display(Student stu[],int n)		//��ʾѧ����Ϣ
{
	int i;
	if(n>0)		//�����ж�
	{
		printf("------------------------\n");
		printf("ѧ��      ����      �ɼ�\n");
		printf("------------------------\n");
		for(i=0;i<n;i++)
			printf("%-10d%-10s%d\n",stu[i].number,stu[i].name,stu[i].score);
	}
	else
	{
		printf("û��ѧ����Ϣ��\n");
	}
	system("pause");
}

void Query(Student stu[],int n)	//��ѯѧ����Ϣ
{
	int i;
	int number;
	do
	{
		i=0;
//		printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
		scanf("%d",&number);
		gets(x);
		while(stu[i].number!=number&&i<n)
			i++;
		if(i==n)
			printf("δ��ѯ����Ϣ��\n");
		else
		{
			printf("��ѯ�ɹ���\n");
			printf("ѧ��Ϊ��%d\n",stu[i].number);
			printf("����Ϊ��%s\n",stu[i].name);
			printf("�ɼ�Ϊ��%d\n",stu[i].score);
		}
		printf("�Ƿ������ѯ��(Y/N):");
		scanf("%c",&sign);
	}while(sign=='y'||sign=='Y');
}
void Delect(Student stu[],int *n)	//ɾ��ѧ����Ϣ
{
	int number;
	int i;
	char Delectsign;	//ɾ��ȷ�ϱ�ʶ��
	do
	{
		i=0;
//		printf("��������Ҫɾ����ѧ��ѧ�ţ�");
		scanf("%d",&number);
		gets(x);
		while(stu[i].number!=number&&i<*n)
			i++;
		if(i==*n)
			printf("δ��ѯ����Ϣ��\n");
		else
		{
			printf("��ѯ�ɹ���\n");
			printf("ѧ��Ϊ��%d\n",stu[i].number);
			printf("����Ϊ��%s\n",stu[i].name);
			printf("�ɼ�Ϊ��%d\n",stu[i].score);
		}
		printf("�Ƿ�ɾ����Y/N��");
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
			printf("ɾ���ɹ���\n");
		}
		printf("�Ƿ����ɾ����Y/N��");
		scanf("%c",&sign);
		gets(x);
	}while(sign=='Y'||sign=='y');
}

void Sort(Student stu[],int n)	//��ѧ������
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

void Write(Student stu[],int n)	//д���ļ�
{
	FILE *fp;
	int i;
//	char fname[10];
//	strcpy(fname,"stu.txt");
//	gets(fname);
//	if((fp=fopen("fname","w"))==NULL)
	if((fp=fopen("C:\\Users\\86131\\Desktop\\student.txt","w"))==NULL)
	{
		printf("��ʧ�ܣ�\n");
		system("pause");
		exit(0);
	}
	else
	{
		for(i=0;i<n;i++)
		{
			fprintf(fp,"%-10d%-10s%d",stu[i].number,stu[i].name,stu[i].score);		//ԭ������
			fputs("\n",fp);
//			if(fwrite(&stu[i],28,1,fp)!=1)		//����������
//				printf("д�����\n");
		}
		printf("����ɹ���\n");
		fclose(fp);
	}
}
void Read(Student stu[],int *n)	//��ȡ�ļ�
{
	FILE *fp;
	if((fp=fopen("C:\\Users\\86131\\Desktop\\student.txt","r"))==NULL)
	{
		printf("��ʧ�ܣ�\n");
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
		printf("д��ɹ���\n");
	}
	fclose(fp);
}

void Calculate(Student stu[],int n)	//����߷֣���ͷ֣�ƽ����
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
	printf("��߷�Ϊ%d��ѧ��Ϊ%d\n",stu[M].score,stu[M].number);
	printf("��ͷ�Ϊ%d��ѧ��Ϊ%d\n",stu[m].score,stu[m].number);
	printf("ƽ����Ϊ%5.2f\n",AVG);
}

int main()	//������
{
	Student stu[N]={0};
	int choice;
	int n=0;	//��¼ѧ����Ϣ����
	do
	{
		Displaymenu();	//��ʾ���˵�
		printf("����������ѡ��(0-8):\n");
		scanf("%d",&choice);
		if(choice>8||choice<0)
		{
			printf("�������\n");
		}
		else
		{
			switch(choice)
			{
			case 1:
				printf("1.������ѧ����Ϣ��\n");
				Input(stu,&n);		//����ѧ����Ϣ
				break;
			case 2:
				printf("2.��ʾѧ����Ϣ\n");
				Display(stu,n);
				break;
			case 3:
				printf("3.������Ҫ��ѯ��ѧ��ѧ��:");
				Query(stu,n);		//��ѯѧ����Ϣ
				break;
			case 4:
				printf("4.��������Ҫɾ����ѧ��ѧ�ţ�");
				Delect(stu,&n);
				break;
			case 5:
				printf("5.��ѧ�����������£�\n");
				Sort(stu,n);
				break;
			case 6:
				printf("6.ͳ�Ƴɼ����£�\n");
				Calculate(stu,n);
				break;
			case 7:
				printf("7.��ȡ�ļ����ݣ�\n");
				Read(stu,&n);
				break;
			case 8:
				printf("8.�����ļ���\n");
				Write(stu,n);
				break;
			}
		}
	}while(choice!=0);
	return 0;
}
