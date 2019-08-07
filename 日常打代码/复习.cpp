#include <stdio.h>                //读入必须包含的头文件 
#include <malloc.h>
#include <stdlib.h>  
#include <windows.h>                 //清屏和颜色设置需要 
#define ENDMARK 9999        //定义输入数据结束标志 
#define ARRAYMAXLENTH 21    //定义数组大小
//技巧：故意不用0单元，第几个逻辑数据就在第几个单元中
#define CUTTINGLINESTART 1      //宏定义切分线开始位置
#define CUTTINGLINELENGTH 25    //宏定义切分线长度 
enum returninfo{success,fail};
//用枚举类型保存各种返回信息的英文单词，以便分类显示某个功能运行后的返回结果
typedef struct node
{ int data;                    //数据域 
  struct node *next;         // 结点指针 
 } Node,*Nodep;              //此处将结点定义成Node，同时设置了一个指针变量Nodep
 
void showmenu(void)
{
	//注意puts（）和printf（）的不同，puts（）会在字符串尾部加上换行符，而printf（）不会 
	puts("=================================================");
	puts("c语言常见知识点复习系统");
	puts("=================================================");
	puts("软件功能说明：             ");
	puts("   用菜单的方式管理数个c语言必须掌握的 ");
	puts("程序构造知识点，为数据结构的程序设计做 ");
	puts("好准备。                               ");
	puts("==================================================");
	puts("          *功能菜单*                ");
	puts("===================================================");
	puts("1.两个整数的加法运算                ");
	puts("2.统计正负数或零的个数              ");
	puts("3.数组数据的累加                    ");
	puts("4.组合数的计算                      ");
	puts("5.求多个数据的最大值和最小值        ");
	puts("6.三个数据的排序                    ");
	puts("7.链表的三个结点的挂链和数据显示    ");
	puts("8.文件链表数组等切换，数据全部加100 "); 
	puts("0.结束程序                          ");
	puts("===================================================");
	printf("请输入您的选择: "); 
 } 
 
 
 
 /********************************************************************
 *函数功能：两个整形数据的交换
 **********************************************************************/
 void exchange2nums(int *num1,int *num2)
 {
 	int temp;
 	temp=*num1;*num1=*num2;*num2=temp;
  } 
 /**********************************************************************
 *两个整数加法运算：除了学习最简单的加法器s=x+y外，主要学习函数中多个数据作为参数
 *传进来，利用函数名吧一个值的计算结果传回去的方法。
 **********************************************************************/
 int addinteger(int num1,int num2) //两个整数相加并返回结果
 {
 	int result;
 	result=num1+num2;   //加法器
	return result; 
  } 
 /************************************************************************
 *函数功能：向给定的数组中输入一定个数的数据，并返回数组数据和数据个数
 ***********************************************************************/
 void getarraynums(int array[],int *arrayposnow)
 {
 	int buffercache;   //设置一个变量存储缓冲区数据信息 
 	int overcount =0;   //记录输入超界数据个数 
 	*arrayposnow=0;    //按照约定数组下标从一开始使用，但是此时初始值依然设置为零 
 	puts("请用空格分开一次输入多个整数");
 	printf("以%d标志结束输入，个数超过%d的一律不承认：\n",ENDMARK,ARRAYMAXLENTH-1);
 	scanf("%d",&buffercache);    //向缓冲区输入一个数据 
 	while(buffercache!=ENDMARK)
	 {
	 	if(*arrayposnow<ARRAYMAXLENTH-1)
	 	                               //判断:如果数组接收到的数据个数小于数组最大接收容量 
	 	{
	 		(*arrayposnow)++;    //切换到下一个地址 ，注意此句与下面语句的次序 
	 		array[*arrayposnow]=buffercache;//标注1 
	 		//上面两句可以简写成：array[++arrayposnow]=buffercache;注意区别标注2 
		 }
		 else   //判断：超越数组最大容纳容量 
		   overcount++;     //越界数据个数加1 
		scanf("%d",&buffercache);
	  } 
	  if(overcount>0)
	     printf("\n【重要提示】输入数据量越界，忽略后面%d个数据，前%d个数据依然有效。\n",overcount,ARRAYMAXLENTH-1);
  } 
 
/****************************************************************************************
* 分别统计出正数负数和零的个数，学习计数器c=c+1的使用，通过把数组中的一批数据传入函数中，
*然后传回去统计结果在调用处显示，学习把数组存储的多个数据作为参数传入，
*处理后把多个数据作为参数传出的函数关系，而文件名处可以用无参数返回类型。
***********************************************************************************/
void countnums(int array[],int arraylenthnow,int *countpos,int *countneg, int *countzero)
{
	int arrayposnow;
	*countpos=0;
	*countneg=0;
	*countzero=0;
	for (arrayposnow=1;arrayposnow<=arraylenthnow;arrayposnow++)
	{if(array[arrayposnow]>0)  *countpos=*countpos+1;      //计数器，可以简写成countpos++； 
	     else if(array[arrayposnow]<0)  *countneg=*countneg+1;
	             else *countzero=*countzero+1;
	}
}
 
/**************************************************************************
*数组数据的累加：学习用循环结构控制数组数据的读取，学习累加器s=s+n,
*学习吧数组名作为参数传进去，通过函数名返回一个计算结果。
****************************************************************************/
int accumulator(int array[],int arraylenthnow)
{
	int addresult=0;
	int arrayposnow;
	for(arrayposnow=1;arrayposnow<=arraylenthnow;arrayposnow++)
	   addresult=addresult+array[arrayposnow];     //累加器 
	return addresult;
 } 
/*******************************************************************************
*本函数学习c语言的阶乘运算，也是累乘器m=m*n
*******************************************************************************/
int factorial(int num)
{
	int result=1;
	int i;
	for(i=1;i<=num;i++)
	result=result*i;//累乘器
	return result; 
 } 
/*************************************************************************
*组合数的计算：从n个不同元素中，任取m（m<=n)个元素并成一组，叫做从n个不同元素中
*取出m个元素的一个组合，其所有组合的个数叫做从n个不同元素中取出m个元素的组合数。
*用符号c（n，m）表示，学习多次调用同一个函数。
***************************************************************************/
int combinationnum(int n,int m)
{
	int cnm;
	if(n<m||m<0||n<0)
	return -1;
	        //此处约定用-1代表失败，因为使用了函数名来返回计算结果，故不能用fail返回
	else
	  cnm=factorial(n)/(factorial(n)*factorial(n-m));
	 return cnm; 
 } 
/********************************************************************************
*求多个数据的最大值和最小值，可以学习线性结构扫描式处理算法和循环结构的使用，
*熟练掌握求最大值和最小值的方法，多个数据返回时，文件名依然可以返回其他信息，如成功。
******************************************************************************/
enum returninfo getmaxmin(int array[],int arraylenthnow,int *max,int *min)
{
	int arrayposnow;
	*max=*min=array[1];   //约定第一个数据为最初的最大值和最小值 
	for(arrayposnow=2;arrayposnow<=arraylenthnow;arrayposnow++)
	                       //技巧：初始值已经是1号单元的，所以从2号单元开始扫描 
	{
		if(*max<array[arrayposnow])   *max=array[arrayposnow];
		if(*min>array[arrayposnow])   *min=array[arrayposnow];
	 }
	return success; 
 } 
/*********************************************************************
*三个数据的排序：学习利用两个两个数据交换，掌握简单的排序思路。同时学习多个数据
*传入和同样的数据量传出的函数程序设计技巧。
**********************************************************************/
enum returninfo sort3nums(int *num1,int *num2,int *num3)
{
	if(*num1>*num2)exchange2nums(num1,num2);
	if(*num1>*num3)exchange2nums(num1,num3);
	if(*num2>*num3)exchange2nums(num2,num3);
	return success; 
 } 
/*****************************************************************************
*函数功能：形象化显示链表指针headp指向的链表全部数据信息
*******************************************************************************/
void displaylinklist(Nodep headp)
{
	Nodep searchp=headp->next;
	printf("链表中的全部数据为：Headp->[|-]->");
	while(searchp!=NULL)
	{
		printf("[%d]",searchp->data);
		if(searchp->next==NULL)
		   printf("|^]");           //根据先处理意外后处理正常的规则显示最后一个结点 
		else
		   printf("|-]->");
		searchp=searchp->next;           //显示中间的结点 
	}
	puts(" ");
 } 
/**********************************************************************
*链表的三个结点的挂链和数据显示：学习结点的定义，用最原始的方式逐个挂上结点
*来构造链表，然后显示所有数据。
************************************************************************/
Nodep processlinklist(int num1,int num2,int num3)
{
	int num;
	Nodep headp=(Nodep)malloc(sizeof(Node));
	Nodep newnodep=(Nodep)malloc(sizeof(Node));
	Nodep lastnodep;
	//使用尾插法
	num=num1;
	newnodep->data=num;
	newnodep->next=NULL;
	headp->next=newnodep;
	printf("\n向链表尾部挂上新数据%d后\n",num1);
	displaylinklist(headp);
	//向链表插入第二个数据 
	num=num2; 
	newnodep=(Nodep)malloc(sizeof(Node));
	newnodep->data=num;
	newnodep->next=NULL;
	lastnodep=headp->next;
	lastnodep->next=newnodep;
	lastnodep=newnodep;
	printf("\n向链表尾部挂上新数据%d后\n",num2);
	displaylinklist(headp);
	//向链表中插入第三个数据
	num=num3;
	newnodep=(Nodep)malloc(sizeof(Node));
	newnodep->data=num;
	newnodep->next=NULL;
	lastnodep->next=newnodep;
	printf("\n向链表尾部挂上新数据%d后\n",num3);
	displaylinklist(headp);
	return headp;
 } 
 
/************************************************************************
*函数功能:释放headp指向的所有链表节点的空间，还给操作系统
***********************************************************************/
void releaselinklist(Nodep headp)
{
	Nodep searchp=headp->next,followp;
	//定义搜索指针并初始化，同时在定义一个尾随指针
	while(searchp!=NULL)
	{
		followp=searchp;
		searchp=searchp->next;
		free(followp); 
	 } 
	headp->next=NULL;
 } 
 
/**************************************************************************
*文件(data.txt)中存入数量不等的整数，读入后用循环写入链表，然后把链表所有数据增加100
再写入数组，然后再把所有数据写入结果文件（result.txt)中
data.txt文件中的数据最后一项数据之后要求没有任何符号（包括空格符、换行符）
否则系统就会默认数据没有读完，导致多读
****************************************************************************/
enum returninfo fileprocess()
{
	Nodep headp=(Nodep)malloc(sizeof(Node));
	FILE *in=fopen("【程序源码1-1】data.txt","rb");
	FILE *out=fopen("【程序源码1-1】result.txt","wb");
	int arrayposnow=0;
	//读入数据个数计数器
	int count=0;
	Nodep searchp=headp;
	Nodep Head=headp;
	//高级技巧，申请一个动态数组有两种写法
	int *temparray=(int *)malloc( sizeof ( (int *) count));
	// int *temparray=(int*)ccalloc(count, sizeof(int*));
	if(feof(in))
	return fail;
	else
	{
		int data;
		Nodep newnodep;
		printf("开始从文件中读入数据并且同时显示...\n");
		printf("文件中数据如下:\n");
		while(!feof(in))
		{
			/*从文件（data.txt)中读入数量不等的整数*/
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
	printf("\n\n文件中的数据已经转入链表...\n");
	searchp=headp->next;
	while(searchp!=NULL)
	{
		searchp->data=searchp->data+100;
		searchp=searchp->next;
	}
	puts("所有数据加上100的运算已经结束...");
	puts("运算结果如下：");
	displaylinklist(headp);
	//这个数组故意用了0单元，以区别上面的0单元空置
	/*数据转入数组*/
	searchp=headp->next;
	while(searchp!=NULL)
	{
		temparray[arrayposnow]=searchp->data;
		arrayposnow++;
		searchp=searchp->next;
	 } 
	puts("\n数据已经传入数组...");
	/*再把所有数据写入结果文件中*/
	if(feof(out))
	  return fail;
	else
	{
		for(arrayposnow=0;arrayposnow<count;arrayposnow++)
		  fprintf(out,"%d",temparray[arrayposnow]);
		puts("\n数据已经重新写入文件...\n");
		printf("打开文件中，请稍后...\n");
		ShellExecute(NULL,"open","result.txt",NULL,NULL,SW_SHOWNORMAL);	
	 } 
	fclose(in);
	fclose(out);
	return success;
 } 
 
 
/**************************************************************************
*函数功能：清除界面内容
***********************************************************************/
void clearscreen()
{
	system("cls");
}
/**********************************************************************
*绘制系统窗口封面显示时的分割线
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
*函数功能：根据用户输入选择调用不同的函数
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
			puts("请输入两个整数（空格隔开）：");
			scanf("%d %d",&num1,&num2);
			//学习调用c中实现多数据进入，单数据返回的函数调用
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
			//下面的调用是向给定的数组中输入数据，并返回数组数据和数据个数
			getarraynums(array, &arraylenthnow);
			//下面的调用学习c中实现多个数据传入和多个数据传出的函数调用
			countnums(array,arraylenthnow,&num1,&num2,&num3);
			showcuttingline();
			printf("正数的个数：%d\n",num1);
			printf("负数的个数：%d\n",num2);
			printf("零  的个数：%d\n",num3);
			showcuttingline();
			break;
		case 3:
			getarraynums(array,&arraylenthnow);
			showcuttingline();
			//下面的调用学习c中实现用数组来管理数据，数组名作为参数传进去，返回一个计算结果
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
			puts("请输入两个正整数n、m（提醒：n个数据中取m个，空格隔开，n>=m）：");
			scanf("%d %d",&num1,&num2);
			//下面的调用学习c中实现组合数的计算
			num3=combinationnum(num1,num2);
			showcuttingline();
			if(num3!=-1)
			    printf("组合计算结果为C(n,m)= %d\n",num3);
			else
			    puts("输入数据不符合要求！\n");
			showcuttingline();
			break;
		case 5:
		     //下面的调用是向给定的数组中输入数据，并返回数组数据和数据个数
			getarraynums(array,&arraylenthnow);
			//下面的调用学习c中实现扫描法程序设计思路和循环结构的使用，熟练掌握求
			//最大值和最小值的方法
			returnvalue=getmaxmin(array,arraylenthnow,&num1,&num2);
			showcuttingline();
			printf("最大数据：%d\n",num1);
			printf("最小数据：%d\n",num2);
			showcuttingline();
			break;
		case 6:
		    puts("请输入三个整数（空格隔开）：");
			scanf("%d %d %d",&num1,&num2,&num3);
			//下面的调用学习c中实现多个数据传入和同样的数据量传出的函数程序设计
			returnvalue=sort3nums(&num1,&num2,&num3);
			showcuttingline();
			printf("处理后数据（从小到大）:%d %d %d\n",num1,num2,num3);
			showcuttingline();
			break;
		case 7:
			puts("请输入三个整数用于创建链表（空格隔开）：");
			scanf("%d %d %d",&num1,&num2,&num3);
			showcuttingline();
			//下面的调用学习c中实现链表的三个结点的挂链和数据显示
			releaselinklist(processlinklist(num1,num2,num3));
			//恢复headp指针初态，调用清除函数
			showcuttingline();
			break;
		case 8:
		    showcuttingline();
			//下面的调用学习c中实现文件读写操作，数据多种常用存储方式的切换
			fileprocess();
			//releaselinklist();
			showcuttingline;
			break;
		case 0:
		    puts("\n您已经成功退出本系统，欢迎再次使用！！！");
			system("pause");
			exit(1);
		default:
		    puts("对不起，您输入的功能编号有错！请重新输入！！！");
			break;   
	}
 } 
 
 
 
//*******************程序主入口
int main()
{
	SetConsoleTitle("C语言常见知识复习系统（C版）");
	system("color f0");//第一个为背景白色(f),第二个为字体颜色黑色(0)
	clearscreen();      //清屏 
	while(1)         //永真循环，出口在循环体中 
	{
		showmenu();     //显示菜单 
		processmenu();  //处理菜单，出口就在其中 
		system("pause");  //暂停一下，等用户给一个回车 
		clearscreen();    //清屏 
	 } 
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
