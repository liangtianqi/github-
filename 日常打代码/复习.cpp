#include <stdio.h>                //������������ͷ�ļ� 
#include <malloc.h>
#include <stdlib.h>  
#include <windows.h>                 //��������ɫ������Ҫ 
#define ENDMARK 9999        //�����������ݽ�����־ 
#define ARRAYMAXLENTH 21    //���������С
//���ɣ����ⲻ��0��Ԫ���ڼ����߼����ݾ��ڵڼ�����Ԫ��
#define CUTTINGLINESTART 1      //�궨���з��߿�ʼλ��
#define CUTTINGLINELENGTH 25    //�궨���з��߳��� 
enum returninfo{success,fail};
//��ö�����ͱ�����ַ�����Ϣ��Ӣ�ĵ��ʣ��Ա������ʾĳ���������к�ķ��ؽ��
typedef struct node
{ int data;                    //������ 
  struct node *next;         // ���ָ�� 
 } Node,*Nodep;              //�˴�����㶨���Node��ͬʱ������һ��ָ�����Nodep
 
void showmenu(void)
{
	//ע��puts������printf�����Ĳ�ͬ��puts���������ַ���β�����ϻ��з�����printf�������� 
	puts("=================================================");
	puts("c���Գ���֪ʶ�㸴ϰϵͳ");
	puts("=================================================");
	puts("�������˵����             ");
	puts("   �ò˵��ķ�ʽ��������c���Ա������յ� ");
	puts("������֪ʶ�㣬Ϊ���ݽṹ�ĳ�������� ");
	puts("��׼����                               ");
	puts("==================================================");
	puts("          *���ܲ˵�*                ");
	puts("===================================================");
	puts("1.���������ļӷ�����                ");
	puts("2.ͳ������������ĸ���              ");
	puts("3.�������ݵ��ۼ�                    ");
	puts("4.������ļ���                      ");
	puts("5.�������ݵ����ֵ����Сֵ        ");
	puts("6.�������ݵ�����                    ");
	puts("7.������������Ĺ�����������ʾ    ");
	puts("8.�ļ�����������л�������ȫ����100 "); 
	puts("0.��������                          ");
	puts("===================================================");
	printf("����������ѡ��: "); 
 } 
 
 
 
 /********************************************************************
 *�������ܣ������������ݵĽ���
 **********************************************************************/
 void exchange2nums(int *num1,int *num2)
 {
 	int temp;
 	temp=*num1;*num1=*num2;*num2=temp;
  } 
 /**********************************************************************
 *���������ӷ����㣺����ѧϰ��򵥵ļӷ���s=x+y�⣬��Ҫѧϰ�����ж��������Ϊ����
 *�����������ú�������һ��ֵ�ļ���������ȥ�ķ�����
 **********************************************************************/
 int addinteger(int num1,int num2) //����������Ӳ����ؽ��
 {
 	int result;
 	result=num1+num2;   //�ӷ���
	return result; 
  } 
 /************************************************************************
 *�������ܣ������������������һ�����������ݣ��������������ݺ����ݸ���
 ***********************************************************************/
 void getarraynums(int array[],int *arrayposnow)
 {
 	int buffercache;   //����һ�������洢������������Ϣ 
 	int overcount =0;   //��¼���볬�����ݸ��� 
 	*arrayposnow=0;    //����Լ�������±��һ��ʼʹ�ã����Ǵ�ʱ��ʼֵ��Ȼ����Ϊ�� 
 	puts("���ÿո�ֿ�һ������������");
 	printf("��%d��־�������룬��������%d��һ�ɲ����ϣ�\n",ENDMARK,ARRAYMAXLENTH-1);
 	scanf("%d",&buffercache);    //�򻺳�������һ������ 
 	while(buffercache!=ENDMARK)
	 {
	 	if(*arrayposnow<ARRAYMAXLENTH-1)
	 	                               //�ж�:���������յ������ݸ���С���������������� 
	 	{
	 		(*arrayposnow)++;    //�л�����һ����ַ ��ע��˾����������Ĵ��� 
	 		array[*arrayposnow]=buffercache;//��ע1 
	 		//����������Լ�д�ɣ�array[++arrayposnow]=buffercache;ע�������ע2 
		 }
		 else   //�жϣ���Խ��������������� 
		   overcount++;     //Խ�����ݸ�����1 
		scanf("%d",&buffercache);
	  } 
	  if(overcount>0)
	     printf("\n����Ҫ��ʾ������������Խ�磬���Ժ���%d�����ݣ�ǰ%d��������Ȼ��Ч��\n",overcount,ARRAYMAXLENTH-1);
  } 
 
/****************************************************************************************
* �ֱ�ͳ�Ƴ�������������ĸ�����ѧϰ������c=c+1��ʹ�ã�ͨ���������е�һ�����ݴ��뺯���У�
*Ȼ�󴫻�ȥͳ�ƽ���ڵ��ô���ʾ��ѧϰ������洢�Ķ��������Ϊ�������룬
*�����Ѷ��������Ϊ���������ĺ�����ϵ�����ļ������������޲����������͡�
***********************************************************************************/
void countnums(int array[],int arraylenthnow,int *countpos,int *countneg, int *countzero)
{
	int arrayposnow;
	*countpos=0;
	*countneg=0;
	*countzero=0;
	for (arrayposnow=1;arrayposnow<=arraylenthnow;arrayposnow++)
	{if(array[arrayposnow]>0)  *countpos=*countpos+1;      //�����������Լ�д��countpos++�� 
	     else if(array[arrayposnow]<0)  *countneg=*countneg+1;
	             else *countzero=*countzero+1;
	}
}
 
/**************************************************************************
*�������ݵ��ۼӣ�ѧϰ��ѭ���ṹ�����������ݵĶ�ȡ��ѧϰ�ۼ���s=s+n,
*ѧϰ����������Ϊ��������ȥ��ͨ������������һ����������
****************************************************************************/
int accumulator(int array[],int arraylenthnow)
{
	int addresult=0;
	int arrayposnow;
	for(arrayposnow=1;arrayposnow<=arraylenthnow;arrayposnow++)
	   addresult=addresult+array[arrayposnow];     //�ۼ��� 
	return addresult;
 } 
/*******************************************************************************
*������ѧϰc���ԵĽ׳����㣬Ҳ���۳���m=m*n
*******************************************************************************/
int factorial(int num)
{
	int result=1;
	int i;
	for(i=1;i<=num;i++)
	result=result*i;//�۳���
	return result; 
 } 
/*************************************************************************
*������ļ��㣺��n����ͬԪ���У���ȡm��m<=n)��Ԫ�ز���һ�飬������n����ͬԪ����
*ȡ��m��Ԫ�ص�һ����ϣ���������ϵĸ���������n����ͬԪ����ȡ��m��Ԫ�ص��������
*�÷���c��n��m����ʾ��ѧϰ��ε���ͬһ��������
***************************************************************************/
int combinationnum(int n,int m)
{
	int cnm;
	if(n<m||m<0||n<0)
	return -1;
	        //�˴�Լ����-1����ʧ�ܣ���Ϊʹ���˺����������ؼ��������ʲ�����fail����
	else
	  cnm=factorial(n)/(factorial(n)*factorial(n-m));
	 return cnm; 
 } 
/********************************************************************************
*�������ݵ����ֵ����Сֵ������ѧϰ���Խṹɨ��ʽ�����㷨��ѭ���ṹ��ʹ�ã�
*�������������ֵ����Сֵ�ķ�����������ݷ���ʱ���ļ�����Ȼ���Է���������Ϣ����ɹ���
******************************************************************************/
enum returninfo getmaxmin(int array[],int arraylenthnow,int *max,int *min)
{
	int arrayposnow;
	*max=*min=array[1];   //Լ����һ������Ϊ��������ֵ����Сֵ 
	for(arrayposnow=2;arrayposnow<=arraylenthnow;arrayposnow++)
	                       //���ɣ���ʼֵ�Ѿ���1�ŵ�Ԫ�ģ����Դ�2�ŵ�Ԫ��ʼɨ�� 
	{
		if(*max<array[arrayposnow])   *max=array[arrayposnow];
		if(*min>array[arrayposnow])   *min=array[arrayposnow];
	 }
	return success; 
 } 
/*********************************************************************
*�������ݵ�����ѧϰ���������������ݽ��������ռ򵥵�����˼·��ͬʱѧϰ�������
*�����ͬ���������������ĺ���������Ƽ��ɡ�
**********************************************************************/
enum returninfo sort3nums(int *num1,int *num2,int *num3)
{
	if(*num1>*num2)exchange2nums(num1,num2);
	if(*num1>*num3)exchange2nums(num1,num3);
	if(*num2>*num3)exchange2nums(num2,num3);
	return success; 
 } 
/*****************************************************************************
*�������ܣ�������ʾ����ָ��headpָ�������ȫ��������Ϣ
*******************************************************************************/
void displaylinklist(Nodep headp)
{
	Nodep searchp=headp->next;
	printf("�����е�ȫ������Ϊ��Headp->[|-]->");
	while(searchp!=NULL)
	{
		printf("[%d]",searchp->data);
		if(searchp->next==NULL)
		   printf("|^]");           //�����ȴ���������������Ĺ�����ʾ���һ����� 
		else
		   printf("|-]->");
		searchp=searchp->next;           //��ʾ�м�Ľ�� 
	}
	puts(" ");
 } 
/**********************************************************************
*������������Ĺ�����������ʾ��ѧϰ���Ķ��壬����ԭʼ�ķ�ʽ������Ͻ��
*����������Ȼ����ʾ�������ݡ�
************************************************************************/
Nodep processlinklist(int num1,int num2,int num3)
{
	int num;
	Nodep headp=(Nodep)malloc(sizeof(Node));
	Nodep newnodep=(Nodep)malloc(sizeof(Node));
	Nodep lastnodep;
	//ʹ��β�巨
	num=num1;
	newnodep->data=num;
	newnodep->next=NULL;
	headp->next=newnodep;
	printf("\n������β������������%d��\n",num1);
	displaylinklist(headp);
	//���������ڶ������� 
	num=num2; 
	newnodep=(Nodep)malloc(sizeof(Node));
	newnodep->data=num;
	newnodep->next=NULL;
	lastnodep=headp->next;
	lastnodep->next=newnodep;
	lastnodep=newnodep;
	printf("\n������β������������%d��\n",num2);
	displaylinklist(headp);
	//�������в������������
	num=num3;
	newnodep=(Nodep)malloc(sizeof(Node));
	newnodep->data=num;
	newnodep->next=NULL;
	lastnodep->next=newnodep;
	printf("\n������β������������%d��\n",num3);
	displaylinklist(headp);
	return headp;
 } 
 
/************************************************************************
*��������:�ͷ�headpָ�����������ڵ�Ŀռ䣬��������ϵͳ
***********************************************************************/
void releaselinklist(Nodep headp)
{
	Nodep searchp=headp->next,followp;
	//��������ָ�벢��ʼ����ͬʱ�ڶ���һ��β��ָ��
	while(searchp!=NULL)
	{
		followp=searchp;
		searchp=searchp->next;
		free(followp); 
	 } 
	headp->next=NULL;
 } 
 
/**************************************************************************
*�ļ�(data.txt)�д����������ȵ��������������ѭ��д������Ȼ�������������������100
��д�����飬Ȼ���ٰ���������д�����ļ���result.txt)��
data.txt�ļ��е��������һ������֮��Ҫ��û���κη��ţ������ո�������з���
����ϵͳ�ͻ�Ĭ������û�ж��꣬���¶��
****************************************************************************/
enum returninfo fileprocess()
{
	Nodep headp=(Nodep)malloc(sizeof(Node));
	FILE *in=fopen("������Դ��1-1��data.txt","rb");
	FILE *out=fopen("������Դ��1-1��result.txt","wb");
	int arrayposnow=0;
	//�������ݸ���������
	int count=0;
	Nodep searchp=headp;
	Nodep Head=headp;
	//�߼����ɣ�����һ����̬����������д��
	int *temparray=(int *)malloc( sizeof ( (int *) count));
	// int *temparray=(int*)ccalloc(count, sizeof(int*));
	if(feof(in))
	return fail;
	else
	{
		int data;
		Nodep newnodep;
		printf("��ʼ���ļ��ж������ݲ���ͬʱ��ʾ...\n");
		printf("�ļ�����������:\n");
		while(!feof(in))
		{
			/*���ļ���data.txt)�ж����������ȵ�����*/
			fscanf(in,"%d",&data);
			printf("%d",data);
			newnodep=(Nodep)malloc(sizeof(Node));
			newnodep->data=data;
			newnodep->next=NULL;
			searchp->next=newnodep;
			searchp=newnodep;
			count=count+1; 
		}
	 } 
	printf("\n\n�ļ��е������Ѿ�ת������...\n");
	searchp=headp->next;
	while(searchp!=NULL)
	{
		searchp->data=searchp->data+100;
		searchp=searchp->next;
	}
	puts("�������ݼ���100�������Ѿ�����...");
	puts("���������£�");
	displaylinklist(headp);
	//��������������0��Ԫ�������������0��Ԫ����
	/*����ת������*/
	searchp=headp->next;
	while(searchp!=NULL)
	{
		temparray[arrayposnow]=searchp->data;
		arrayposnow++;
		searchp=searchp->next;
	 } 
	puts("\n�����Ѿ���������...");
	/*�ٰ���������д�����ļ���*/
	if(feof(out))
	  return fail;
	else
	{
		for(arrayposnow=0;arrayposnow<count;arrayposnow++)
		  fprintf(out,"%d",temparray[arrayposnow]);
		puts("\n�����Ѿ�����д���ļ�...\n");
		printf("���ļ��У����Ժ�...\n");
		ShellExecute(NULL,"open","result.txt",NULL,NULL,SW_SHOWNORMAL);	
	 } 
	fclose(in);
	fclose(out);
	return success;
 } 
 
 
/**************************************************************************
*�������ܣ������������
***********************************************************************/
void clearscreen()
{
	system("cls");
}
/**********************************************************************
*����ϵͳ���ڷ�����ʾʱ�ķָ���
**********************************************************************/
void showcuttingline()
{
	int i;
	for(i=0;i<CUTTINGLINESTART+CUTTINGLINELENGTH;i++)
	{
		if(i<CUTTINGLINESTART)
		  printf(" ");
		else
		  printf("=");
	}
	puts(" ");
 } 
 
/****************************************************************
*�������ܣ������û�����ѡ����ò�ͬ�ĺ���
*******************************************************************/
void processmenu()
{
	int returnvalue;
	int num1,num2,num3;
	int arraylenthnow,arrayposnow,array[ARRAYMAXLENTH];
	int menuchoice;
	scanf("%d",&menuchoice);
	switch(menuchoice)
	{
		case 1:
			puts("�����������������ո��������");
			scanf("%d %d",&num1,&num2);
			//ѧϰ����c��ʵ�ֶ����ݽ��룬�����ݷ��صĺ�������
			num3=addinteger(num1,num2);
			showcuttingline();
			printf("%d + ",num1);
			if(num2>=0)
			  printf("%d",num2);
			else
			  printf("(%d)",num2);
			printf("=%d\n",num3);
			showcuttingline();
			break; 
		case 2:
			//����ĵ�������������������������ݣ��������������ݺ����ݸ���
			getarraynums(array, &arraylenthnow);
			//����ĵ���ѧϰc��ʵ�ֶ�����ݴ���Ͷ�����ݴ����ĺ�������
			countnums(array,arraylenthnow,&num1,&num2,&num3);
			showcuttingline();
			printf("�����ĸ�����%d\n",num1);
			printf("�����ĸ�����%d\n",num2);
			printf("��  �ĸ�����%d\n",num3);
			showcuttingline();
			break;
		case 3:
			getarraynums(array,&arraylenthnow);
			showcuttingline();
			//����ĵ���ѧϰc��ʵ�����������������ݣ���������Ϊ��������ȥ������һ��������
			num3=accumulator(array,arraylenthnow);
			for(arrayposnow=1;arrayposnow<arraylenthnow;arrayposnow++)
			{
				if(array[arrayposnow]>0)
				    printf("%d + ",array[arrayposnow]);
			    else
			        printf("(%d) + ",array[arrayposnow]);
			 } 
			printf("%d=%d\n",array[arrayposnow],num3);
			showcuttingline();
			break;
		case 4:
			puts("����������������n��m�����ѣ�n��������ȡm�����ո������n>=m����");
			scanf("%d %d",&num1,&num2);
			//����ĵ���ѧϰc��ʵ��������ļ���
			num3=combinationnum(num1,num2);
			showcuttingline();
			if(num3!=-1)
			    printf("��ϼ�����ΪC(n,m)= %d\n",num3);
			else
			    puts("�������ݲ�����Ҫ��\n");
			showcuttingline();
			break;
		case 5:
		     //����ĵ�������������������������ݣ��������������ݺ����ݸ���
			getarraynums(array,&arraylenthnow);
			//����ĵ���ѧϰc��ʵ��ɨ�跨�������˼·��ѭ���ṹ��ʹ�ã�����������
			//���ֵ����Сֵ�ķ���
			returnvalue=getmaxmin(array,arraylenthnow,&num1,&num2);
			showcuttingline();
			printf("������ݣ�%d\n",num1);
			printf("��С���ݣ�%d\n",num2);
			showcuttingline();
			break;
		case 6:
		    puts("�����������������ո��������");
			scanf("%d %d %d",&num1,&num2,&num3);
			//����ĵ���ѧϰc��ʵ�ֶ�����ݴ����ͬ���������������ĺ����������
			returnvalue=sort3nums(&num1,&num2,&num3);
			showcuttingline();
			printf("��������ݣ���С����:%d %d %d\n",num1,num2,num3);
			showcuttingline();
			break;
		case 7:
			puts("�����������������ڴ��������ո��������");
			scanf("%d %d %d",&num1,&num2,&num3);
			showcuttingline();
			//����ĵ���ѧϰc��ʵ��������������Ĺ�����������ʾ
			releaselinklist(processlinklist(num1,num2,num3));
			//�ָ�headpָ���̬�������������
			showcuttingline();
			break;
		case 8:
		    showcuttingline();
			//����ĵ���ѧϰc��ʵ���ļ���д���������ݶ��ֳ��ô洢��ʽ���л�
			fileprocess();
			//releaselinklist();
			showcuttingline;
			break;
		case 0:
		    puts("\n���Ѿ��ɹ��˳���ϵͳ����ӭ�ٴ�ʹ�ã�����");
			system("pause");
			exit(1);
		default:
		    puts("�Բ���������Ĺ��ܱ���д����������룡����");
			break;   
	}
 } 
 
 
 
//*******************���������
int main()
{
	SetConsoleTitle("C���Գ���֪ʶ��ϰϵͳ��C�棩");
	system("color f0");//��һ��Ϊ������ɫ(f),�ڶ���Ϊ������ɫ��ɫ(0)
	clearscreen();      //���� 
	while(1)         //����ѭ����������ѭ������ 
	{
		showmenu();     //��ʾ�˵� 
		processmenu();  //����˵������ھ������� 
		system("pause");  //��ͣһ�£����û���һ���س� 
		clearscreen();    //���� 
	 } 
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
