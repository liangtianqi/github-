#include<stdio.h>    
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<windows.h>
#define len sizeof(message)          
						
typedef struct Message
{
    char name[10];
    char home[20];
    char phone[20];
    char student[20];
    char email[20];
    int sign;
    struct Message *next;
}message;
message *head;

//函数声明  
message * Newcontact();//新建通讯录    
void Exhibition(message *p1);// 展示全部信息 
void Search (message *p2); //查找联系人 
void readfile(); //从文件中读取相关数据 
void Keep (message *p2);//保存数据到文件中 
void Change(message *p);//改变联系人信息 
void Delete();//删除联系人信息 
void Input(message *p1);//增加联系人 
void Insert();
void end();
void menu1();//菜单1 
void menu2();//菜单2 


void menu1()
{
    int number; 
    char menu[] = {
        "欢迎使用本通讯录系统！！！\n\n\n\n"
    };

    int i;
    for(i = 0; menu[i] != '\0'; i++) {
        Sleep(30);
        printf("%c", menu[i]);
    }
    printf("\t\t\t★                          [通讯录管理系统]                          ☆\n");
    printf("\t\t\t★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
    printf("\t\t\t☆********************************************************************★\n");
    printf("\t\t\t★                                                                    ☆\n");
    printf("\t\t\t☆                                                                    ★\n");
    printf("\t\t\t★          1.新建联系人信息               5.保存联系人信息           ☆\n");
    printf("\t\t\t☆                                                                    ★\n");
    printf("\t\t\t★          2.浏览所有联系人               6.添加联系人信息           ☆\n");
    printf("\t\t\t☆                                                                    ★\n");
    printf("\t\t\t★          3.修改联系人信息               7.删除联系人信息           ☆\n");
    printf("\t\t\t☆                                                                    ★\n");
    printf("\t\t\t★          4.查找联系人信息               0.退出                     ☆\n");
    printf("\t\t\t☆********************************************************************★\n");
    printf("\t\t\t★                   制作人：胡辰昕 201824100320                      ☆\n");
    printf("\t\t\t☆          -------------------------------------------               ★\n");
    readfile();
    while(1) {

        printf("\t\t\t\t\t\t◆■请进行你的操作■◆\t\t\t\t\n");
        scanf("%d", &number);

        if(number >= 0 && number <= 8) 
		{

            switch(number) 
			{
                case 1:
                Newcontact(); 
                break;
                
                case 2:
                Exhibition(head);
                break;
                
                case 3:
                Change(head);               
                break;
                
                case 4:
                Search(head);
                break;
                
                case 5:
                Keep(head);
                break;
                
                case 6:
                Insert();
                break;
                
                case 7:
                Delete();
                break;
                
                case 8:
                menu2();
                break;
                
                case 0:
                end();
                break;
            }
        }

        else 
		{
            printf("\t\t\t\t-----------选择的操作不正确！请重新输入：-------------\n");
        }

    }
}


void Exhibition(message *p1) {
    system("color 0a"); 
	system("cls");
	message *p2;
    p2 = head;
    printf("\n\t\t\t\t\t\t☆☆☆通讯列表展示☆☆☆\n");
    printf("\t\t\t----------------------------------------------------------------------------\n");
    while(p2 != NULL) {
        printf("\t\t\t姓名:%s\t\t", p2->name);
        printf("序号:%d\n\n", p2->sign);
        printf("\t\t\t住址:%s\t", p2->home);
        printf("电话号码:%s\t", p2->phone);
        printf("学号:%s\t", p2->student);
        printf("电子邮箱:%s\n\n", p2->email);
        printf("\t\t\t----------------------------------------------------------------------------\n");
        p2 = p2->next;
    }
    printf("\t\t\t\t\t\t    (按8返回菜单)\n");
    return ;
}


message * Newcontact() {
    system("cls");
	message*p1, *p2, *p3;
    int flag = 1;
    int k = 1, i = 1, max;

    p1 = p2 = (message*)malloc(len);
    head = NULL;

    printf("\n\t\t\t\t\t\t☆☆☆新建联系人信息☆☆☆\n");
    if(p1 != NULL) 
	{
        head = p1;
        while(flag) {
            printf("\t\t--------------------------------------------------------------\n");
            printf("\t\t◇请输入要录入联系人的姓名（姓名一栏中输入end结束）:   ");
            p3 = head;
            scanf("%s", p1->name);
            if(strcmp(p1->name, "end") != 0)
			{   
                max = 0;
                p3 = head;
                while(i < k) {
                    i++;
                    if(strcmp(p1->name, p3->name) == 0) {
                        if(p3->sign > max)max = p3->sign;
                    }
                    p3 = p3->next;
                }
                p1->sign=++max;                
                printf("\n\t\t◇请输入要录入联系人的住址：   ");
                scanf("%s", p1->home);
                printf("\n\t\t◇请输入要录入联系人的电话:   ");
                scanf("%s", p1->phone);
                printf("\n\t\t◇请输入要录入联系人的学号:   ");
                scanf("%s", p1->student);
                printf("\n\t\t◇请输入要录入联系人的电子邮箱:   ");
                scanf("%s", p1->email);
                p2->next = p1;
                p2 = p1;
                p1 = (message*)malloc(len);

                k++;
                printf("\t\t------------------------------------------------------------\n");


            }

            else {
                flag = 0;

                printf("\n\n\t\t\t\t\t   □输入成功！(退出时勿忘输入5保存信息！)■\n");
                printf("\t\t\t\t   -----------------------------------------------------\n");
            }
        }
        p2->next =NULL;

    }
    return (head);
}


void readfile() {
    FILE *fp;
    message *p1, *p2, *p3;
    p1 = p2 = (message *)malloc(len);
    int flag = 1;
    head = NULL;
    if((fp = fopen("我的通讯录", "r")) == NULL) {
        printf("\t\t\t\t\t   (未建立通讯录，请输入1新建联系人！)\n");
    }
    else {
        if(p1 != NULL)
		{
		head = p1;
        while(1) {
            if(!feof(fp)) {
                fscanf(fp, "%s%d%s%s%s%s", p1->name, &p1->sign, p1->home, p1->phone, p1->student, p1->email);
                p2->next = p1;
                p3 = p2;
                p2 = p1;
                p1 = (message *)malloc(len);
            }
            else {
                p3->next = NULL;
            }

        }
        } 
    }
    fclose(fp);
}


 void Search(message *p2) {
	system("cls");
	char phone[20];
    char ch1[5], ch2[5];
    int b;
    int n;
    printf("\n\t\t\t\t\t\t【联系人查找】\n\n");
    printf("\t\t\t\t★             ☆              ☆           ★\n\n");
    printf("\t\t\t\t|                                            |\n");
    printf("\t\t\t\t|        1------按电话查找请输入（1）        |\n");
    printf("\t\t\t\t|                                            |\n");
    printf("\t\t\t\t|        2------按姓氏请输入（2）            |\n");
    printf("\t\t\t\t|                                            |\n");
    printf("\t\t\t\t★             ☆              ☆           ★\n");
    printf("\n\n\t\t\t\t\t△请输入您的选择： "); 
	scanf("%d", &n);
    getchar();
    system("cls");
    switch(n) {
        case 1:
        printf("\n\n\t\t\t △请输入需要查找的号码：");	
        b = 0;
        scanf("%s", phone);
        printf("\n\n\t\t搜索到的信息如下：\n\n"); 
        while(p2 != NULL) {
            if(strcmp(phone, p2->phone) == 0) 
			{
                
                printf("\t\t\t姓名:%s\t\t", p2->name);
                printf("序号:%d\n\n", p2->sign);
                printf("\t\t\t住址:%s\t", p2->home);
                printf("电话号码:%s\t", p2->phone);
                printf("学号:%s\t", p2->student);
                printf("电子邮箱:%s\n\n", p2->email);
                printf("\t\t\t-------------------------------------------------------------\n");
                printf("\t\t\t\t\t\t    (按8返回菜单)\n");
                b = 1;
            }
            p2 = p2->next;
        }
        if(b == 0) {
            printf("\n\t\t\t     --------------您要查找的人不存在!（按8返回菜单）---------------\n\n");
        }
        break;
        case 2:
        b = 0;
        printf("\n\n\t\t\t△请输入您要查找的姓：");
        scanf("%s", ch1);
        printf("\n\n\t\t搜索到的信息如下：\n\n");
        while(p2 != NULL) {
            strncpy(ch2, p2->name, 2);
            if(strcmp(ch1, ch2) == 0) {
                
                printf("\t\t\t姓名:%s\t\t", p2->name);
                printf("序号:%d\n\n", p2->sign);
                printf("\t\t\t住址:%s\t", p2->home);
                printf("电话号码:%s\t", p2->phone);
                printf("学号:%s\t", p2->student);
                printf("电子邮箱:%s\n\n", p2->email);
                printf("\t\t\t----------------------------------------------------\n");
                
                b = 1;
            }
            p2 = p2->next;
        }
        if(b == 0) {
            printf("\n\t\t\t--------------您要查找的人不存在!（按8返回菜单）---------------\n\n");
        }
        printf("\t\t\t\t\t\t    (按8返回菜单)\n");

    }

}


 void Keep(message *p2) 
 {
    FILE *fp;

    printf("\n\t\t\t\t\t   ☆☆☆正在保存数据☆☆☆\n");
    printf("\t\t\t------------------------------------------------------------------\n");
    if((fp = fopen("我的通讯录", "w")) == NULL) 
	{
        printf("cannot open this file\n");
        exit(0);
    }
    while(p2 != NULL)
	 {
        fprintf(fp,"%s\t", p2->name);
        fprintf(fp,"%d\t", p2->sign);
        fprintf(fp,"%s\t", p2->home);
        fprintf(fp,"%s\t", p2->phone);
        fprintf(fp,"%s\t", p2->student);
        fprintf(fp,"%s\t", p2->email);
        p2 = p2->next;
        fputc('\n', fp);
    }
    Sleep(300);
	system("cls"); 
    printf("\n\n\n\n\t\t\t------------------------------保存成功!-----------------------------\n");
    printf("\t\t\t---------------------------------------------------------------------\n\n\n");
    printf("\t\t\t\t\t\t    (按8返回菜单)\n");
    fclose(fp);
}


 void Change(message *p) 
 {
 	int a;
    loop:system("cls");
	message *p1;
	p1=p; 
	char name[20];
    int n,k, flag = 1;
    printf("\n\t\t\t\t\t\t☆☆☆修改数据☆☆☆\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t       ○请输入需要修改的联系人姓名： ");
    scanf("%s", name);
    while(p != NULL) 
	{
        if(strcmp(p->name, name) == 0) 
		{
			printf("\t\t\n\n\t\t搜索到的信息如下：\n\n"); 
            printf("\t\t\t姓名:%s\t\t", p->name);
            printf("序号:%d\n\n", p->sign);
            printf("\t\t\t住址:%s\t", p->home);
            printf("电话号码:%s\t", p->phone);
            printf("学号:%s\t", p->student);
            printf("电子邮箱:%s\n\n", p->email);
            flag = 0;
            p=p->next;
        }
        else p = p->next;

    }
    if(flag)printf("\n\n\t\t\t--------------------查无此人！(按8返回菜单)---------------------------\n\t\t\t");
    else{
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t       ○请输入需要修改的联系人的序号: ");
    scanf("%d", &n);
    while(p1 != NULL && (p1->sign != n || strcmp(p1->name, name) != 0)) 
	{
        p1 = p1->next;
    }
            printf("\n\n\t\t\t\t╭──────────────────────────────────────────────╮\n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t          1.姓名              4.学号           \n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t          2.住址              5.电子邮箱        \n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t          3.电话号码                               \n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t╰━━━━━━━━━━━━━━━━━━━━━━━───────────────────────╯\n");
            printf("\n\t\t\t ○请选择要修改的信息: ");
            scanf("%d", &k);
            system("cls");
            switch(k) 
			{
                case 1: printf("\n\t\t\t\t          ●○输入修改后的姓名○●\n\t\t\t");
                scanf("%s", p1->name);
                break;

                case 2: printf("\t\t\t\t            ●○输入修改后的住址○●\n\t\t\t");
                scanf("%s", p1->home);
                break;

                case 3: printf("\t\t\t\t            ●○输入修改后的电话号码○●\n\t\t\t");
                scanf("%s", p1->phone);
                break;

                case 4: printf("\t\t\t\t            ●○输入修改后的学号○●\n\t\t\t");
                scanf("%s", p1->student);
                break;

                case 5: printf("\t\t\t\t            ●○输入修改后的邮箱○●\n\t\t\t");
                scanf("%s", p1->email);
                break;

            }
            printf("                        正在修改                               ");
            Sleep(300);
            system("cls");
            printf("\n\n\n\n\t\t\t\t◆修改成功！（退出时，记得保存信息)◆\n");
            printf("\t\t\t----------------------------------------------------------------------\n");  
            printf("\t\t                       是否继续修改                  \n\n");
			printf("\t\t                    1--------继续              \n\n");
			printf("\t\t                    2--------回到菜单   ");
			scanf("%d",&a);
			if(a==1)
			{
				goto loop;
			 }
			else menu2();  
    }
}


void Delete() {
    system("cls");
	message *p1, *p2;
    message *p3;
    char name[20];
    int n, k = 1;
    printf("\n\t\t\t\t\t\t☆☆☆删除数据☆☆☆\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t\t◇输入您想删除的联系人姓名： ");
    scanf("%s", name);
    p1 = head;
    if(head == NULL) {
        printf("未建立联系人信息，通讯录为空\n");
        return;
    }
   else{ 
    printf("\n\t\t\t----------------------------------------------------------------------\n");
    p3 = head;
    printf("\n\n\t\t搜索到的信息如下：\n\n");
    while(p3 != NULL) {
        if(strcmp(name, p3->name) == 0) {
             
            printf("\t\t\t姓名:%s\t\t", p3->name);
            printf("序号:%d\n\n", p3->sign);
            printf("\t\t\t住址:%s\t", p3->home);
            printf("电话号码:%s\t", p3->phone);
            printf("学号:%s\t", p3->student);
            printf("电子邮箱:%s", p3->email);
            printf("\n\n");
            k = 0;
            printf("\t\t\t--------------------------------------------------------------\n");
        }
        p3 = p3->next;
    }
    if(k) 
	{
        printf("\t\t\t◇◆抱歉查无此人◆◇\n");
        return;
    }
    else
	{
	printf("\n\t\t◇请输入您要删除的人序号： ");
    scanf("%d", &n);
    int a=1;
    while(p1 != NULL && (p1->sign != n || strcmp(p1->name, name) != 0)) 
	{
        p2 = p1;
        p1 = p1->next;
        a++;
    }
    if(a==1){
        printf("\n\n\t\t\t------------------------------正在删除--------------------------------\n\n\n\n");
        Sleep(300);
		system("cls"); 
    	head=p1->next;
		printf("\n\n\t\t\t   --------------------------删除成功！---------------------------\n\n");
        printf("\t\t\t\t\t        (按5保存，按8返回菜单)\n");
        return ;
	}
	else{
    printf("\n\n\t\t\t------------------------------正在删除--------------------------------\n\n\n\n");
    Sleep(300);
	system("cls"); 
    p2->next = p1->next; 
    printf("\n\n\t\t\t   --------------------------删除成功！---------------------------\n\n");
    printf("\t\t\t\t\t        (按5保存，按8返回菜单)\n");
    return;}
    }
} 

}


void Insert() {
    system("cls");
	char name2[20];
    int flag, max;
    message *p1, *p2, *p3;
    message *p4;
    p1 = head;
    p3 = (message *)malloc(len);
    printf("\n\t\t\t\t\t\t☆☆☆添加联系人☆☆☆\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t\t                      ●○请输入相关的数据○●\n");
    printf("\t\t\t姓名:");
    scanf("%s", &p3->name);
    printf("\n\t\t\t住址:");
    scanf("%s", &p3->home);
    printf("\n\t\t\t手机号:");
    scanf("%s", &p3->phone);
    printf("\n\t\t\t学号:");
    scanf("%s", &p3->student);
    printf("\n\t\t\t邮箱:");
    scanf("%s", &p3->email);
    p3->sign = 1;
    p4 = head;


    max = 0;
    while(p4 != NULL) {
        if(strcmp(p3->name, p4->name) == 0) {
            if(p4->sign > max)max = p4->sign;
        }
        p4 = p4->next;
    }
    p3->sign=++max;


    printf("\n\n\t\t\t                      ●○请输入插入的位置○●\n");
    printf("\t\t\t+---------------------------------------------------------+\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t|                    1.首位置插入                         |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t|                    2.尾位置插入                         |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t|                    3.指定姓名前插入                     |\n");
    printf("\t\t\t+---------------------------------------------------------+\n");

    scanf("%d", &flag);
    switch(flag) {
        case 1:
        p3->next = p1;
        head = p3;
        break;
        case 2:
        p2 = head;
        while(p2->next != NULL) {
            p2 = p2->next;
        }
        p2->next = p3;
        p3->next = NULL;
        break;
        case 3:
        printf("▽请输入您想插入的姓名前面： ");
        scanf("%s", name2);
        while(p1->next != NULL && strcmp(p1->name, name2) != 0) {
            p2 = p1;
            p1 = p1->next;
        }
        if(p1 == head) {
            p3->next =p1;
            head=p3;
        }
        if(p1->next == NULL) {
            printf("\t\t\t---------------------查无此人！----------------------\n");
        }
        else {
            p3->next = p1;
            p2->next = p3;

        }
        break;
    }
    printf("\t\t\t-----------------插入成功！(按8返回菜单)----------------\n");
    printf("\t\t\t--------------------------------------------------------\n");
    return;
}


void menu2() //对菜单进行拓展 
{

	int number;
	system("cls");
	system("color 0e");
	printf("\n\n\n");
	printf("\t\t\t\t△▼△▼△▼△▼△▼△ △▼△ ▼△▼△▼△▼△▼△▼△\n\n");
	printf("\t\t\t\t* * *                    MENU                    * * * \n\n");
	printf("\t\t\t\t□■□■□■□■□★☆ ●▲▽ ■☆○▼■■○▼◆▽▼◆\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  1.新建联系人信息               5.保存联系人信息  ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  2.浏览所有联系人               6.添加联系人信息  ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  3.修改联系人信息               7.删除联系人信息  ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  4.查找联系人信息               8.返回菜单        ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t 	 ＊＊＊＊＊＊＊＊                 ＊＊＊＊＊＊＊＊ \n"); 
	printf("\t\t\t\t                  _(按0退出程序)_                  \n");
    while(1) {

        printf("\t\t\t\t\t\t★☆请进行你的操作☆★\t\t\t\t\n");
        scanf("%d", &number);

        if(number >= 0 && number <= 8) 
		{

            switch(number) 
			{
                case 1:
                Newcontact(); 
                break;
                
                case 2:
                Exhibition(head);
                break;
                
                case 3:
                Change(head);
                break;
                
                case 4:
                Search(head);
                break;
                
                case 5:
                Keep(head);
                break;
                
                case 6:
                Insert();
                break;
                
                case 7:
                Delete();
                break;
                
                case 8:
                menu2();
                break;
                
                case 0:
                end();
                break;
                
            }
            
        }
          else 
		{
            printf("\t\t\t\t-------------选择的操作不正确！请重新输入：--------------\n");
        }

    }

}


void end()
{
	int t; 
	system("color 04");
	system("cls");
	printf("\n\n\n\t\t\t\t- - - - - - - - - - - - - - \n");
	printf("\t\t\t\t|     您真的要退出吗？    | \n");
	printf("\t\t\t\t                             \n");
	printf("\t\t\t\t|   1.是的，我想要退出    |  \n");
	printf("\t\t\t\t                             \n");
	printf("\t\t\t\t|   2.不，我还想再看看    | \n\n");
	printf("\t\t\t\t    (退出前记得保存信息)\n\n\t\t\t\t"); 
	while(1){
		scanf("%d",&t);
		switch(t){
		case 1:
		
			system("cls");
			printf("\t\t\t已安全退出，欢迎下次使用！");
			exit(0);
			break;
			
		case 2:
		
			system("cls");
			menu2();
			break;
		}		
	} 
 } 


int main() {
    system("color e");
    menu1();
    } 




