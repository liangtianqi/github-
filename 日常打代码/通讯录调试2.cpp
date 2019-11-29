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

//��������  
message * Newcontact();//�½�ͨѶ¼    
void Exhibition(message *p1);// չʾȫ����Ϣ 
void Search (message *p2); //������ϵ�� 
void readfile(); //���ļ��ж�ȡ������� 
void Keep (message *p2);//�������ݵ��ļ��� 
void Change(message *p);//�ı���ϵ����Ϣ 
void Delete();//ɾ����ϵ����Ϣ 
void Input(message *p1);//������ϵ�� 
void Insert();
void end();
void menu1();//�˵�1 
void menu2();//�˵�2 


void menu1()
{
    int number; 
    char menu[] = {
        "��ӭʹ�ñ�ͨѶ¼ϵͳ������\n\n\n\n"
    };

    int i;
    for(i = 0; menu[i] != '\0'; i++) {
        Sleep(30);
        printf("%c", menu[i]);
    }
    printf("\t\t\t��                          [ͨѶ¼����ϵͳ]                          ��\n");
    printf("\t\t\t�������������������������������������\n");
    printf("\t\t\t��********************************************************************��\n");
    printf("\t\t\t��                                                                    ��\n");
    printf("\t\t\t��                                                                    ��\n");
    printf("\t\t\t��          1.�½���ϵ����Ϣ               5.������ϵ����Ϣ           ��\n");
    printf("\t\t\t��                                                                    ��\n");
    printf("\t\t\t��          2.���������ϵ��               6.�����ϵ����Ϣ           ��\n");
    printf("\t\t\t��                                                                    ��\n");
    printf("\t\t\t��          3.�޸���ϵ����Ϣ               7.ɾ����ϵ����Ϣ           ��\n");
    printf("\t\t\t��                                                                    ��\n");
    printf("\t\t\t��          4.������ϵ����Ϣ               0.�˳�                     ��\n");
    printf("\t\t\t��********************************************************************��\n");
    printf("\t\t\t��                   �����ˣ������ 201824100320                      ��\n");
    printf("\t\t\t��          -------------------------------------------               ��\n");
    readfile();
    while(1) {

        printf("\t\t\t\t\t\t�����������Ĳ�������\t\t\t\t\n");
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
            printf("\t\t\t\t-----------ѡ��Ĳ�������ȷ�����������룺-------------\n");
        }

    }
}


void Exhibition(message *p1) {
    system("color 0a"); 
	system("cls");
	message *p2;
    p2 = head;
    printf("\n\t\t\t\t\t\t����ͨѶ�б�չʾ����\n");
    printf("\t\t\t----------------------------------------------------------------------------\n");
    while(p2 != NULL) {
        printf("\t\t\t����:%s\t\t", p2->name);
        printf("���:%d\n\n", p2->sign);
        printf("\t\t\tסַ:%s\t", p2->home);
        printf("�绰����:%s\t", p2->phone);
        printf("ѧ��:%s\t", p2->student);
        printf("��������:%s\n\n", p2->email);
        printf("\t\t\t----------------------------------------------------------------------------\n");
        p2 = p2->next;
    }
    printf("\t\t\t\t\t\t    (��8���ز˵�)\n");
    return ;
}


message * Newcontact() {
    system("cls");
	message*p1, *p2, *p3;
    int flag = 1;
    int k = 1, i = 1, max;

    p1 = p2 = (message*)malloc(len);
    head = NULL;

    printf("\n\t\t\t\t\t\t�����½���ϵ����Ϣ����\n");
    if(p1 != NULL) 
	{
        head = p1;
        while(flag) {
            printf("\t\t--------------------------------------------------------------\n");
            printf("\t\t��������Ҫ¼����ϵ�˵�����������һ��������end������:   ");
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
                printf("\n\t\t��������Ҫ¼����ϵ�˵�סַ��   ");
                scanf("%s", p1->home);
                printf("\n\t\t��������Ҫ¼����ϵ�˵ĵ绰:   ");
                scanf("%s", p1->phone);
                printf("\n\t\t��������Ҫ¼����ϵ�˵�ѧ��:   ");
                scanf("%s", p1->student);
                printf("\n\t\t��������Ҫ¼����ϵ�˵ĵ�������:   ");
                scanf("%s", p1->email);
                p2->next = p1;
                p2 = p1;
                p1 = (message*)malloc(len);

                k++;
                printf("\t\t------------------------------------------------------------\n");


            }

            else {
                flag = 0;

                printf("\n\n\t\t\t\t\t   ������ɹ���(�˳�ʱ��������5������Ϣ��)��\n");
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
    if((fp = fopen("�ҵ�ͨѶ¼", "r")) == NULL) {
        printf("\t\t\t\t\t   (δ����ͨѶ¼��������1�½���ϵ�ˣ�)\n");
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
    printf("\n\t\t\t\t\t\t����ϵ�˲��ҡ�\n\n");
    printf("\t\t\t\t��             ��              ��           ��\n\n");
    printf("\t\t\t\t|                                            |\n");
    printf("\t\t\t\t|        1------���绰���������루1��        |\n");
    printf("\t\t\t\t|                                            |\n");
    printf("\t\t\t\t|        2------�����������루2��            |\n");
    printf("\t\t\t\t|                                            |\n");
    printf("\t\t\t\t��             ��              ��           ��\n");
    printf("\n\n\t\t\t\t\t������������ѡ�� "); 
	scanf("%d", &n);
    getchar();
    system("cls");
    switch(n) {
        case 1:
        printf("\n\n\t\t\t ����������Ҫ���ҵĺ��룺");	
        b = 0;
        scanf("%s", phone);
        printf("\n\n\t\t����������Ϣ���£�\n\n"); 
        while(p2 != NULL) {
            if(strcmp(phone, p2->phone) == 0) 
			{
                
                printf("\t\t\t����:%s\t\t", p2->name);
                printf("���:%d\n\n", p2->sign);
                printf("\t\t\tסַ:%s\t", p2->home);
                printf("�绰����:%s\t", p2->phone);
                printf("ѧ��:%s\t", p2->student);
                printf("��������:%s\n\n", p2->email);
                printf("\t\t\t-------------------------------------------------------------\n");
                printf("\t\t\t\t\t\t    (��8���ز˵�)\n");
                b = 1;
            }
            p2 = p2->next;
        }
        if(b == 0) {
            printf("\n\t\t\t     --------------��Ҫ���ҵ��˲�����!����8���ز˵���---------------\n\n");
        }
        break;
        case 2:
        b = 0;
        printf("\n\n\t\t\t����������Ҫ���ҵ��գ�");
        scanf("%s", ch1);
        printf("\n\n\t\t����������Ϣ���£�\n\n");
        while(p2 != NULL) {
            strncpy(ch2, p2->name, 2);
            if(strcmp(ch1, ch2) == 0) {
                
                printf("\t\t\t����:%s\t\t", p2->name);
                printf("���:%d\n\n", p2->sign);
                printf("\t\t\tסַ:%s\t", p2->home);
                printf("�绰����:%s\t", p2->phone);
                printf("ѧ��:%s\t", p2->student);
                printf("��������:%s\n\n", p2->email);
                printf("\t\t\t----------------------------------------------------\n");
                
                b = 1;
            }
            p2 = p2->next;
        }
        if(b == 0) {
            printf("\n\t\t\t--------------��Ҫ���ҵ��˲�����!����8���ز˵���---------------\n\n");
        }
        printf("\t\t\t\t\t\t    (��8���ز˵�)\n");

    }

}


 void Keep(message *p2) 
 {
    FILE *fp;

    printf("\n\t\t\t\t\t   �������ڱ������ݡ���\n");
    printf("\t\t\t------------------------------------------------------------------\n");
    if((fp = fopen("�ҵ�ͨѶ¼", "w")) == NULL) 
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
    printf("\n\n\n\n\t\t\t------------------------------����ɹ�!-----------------------------\n");
    printf("\t\t\t---------------------------------------------------------------------\n\n\n");
    printf("\t\t\t\t\t\t    (��8���ز˵�)\n");
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
    printf("\n\t\t\t\t\t\t�����޸����ݡ���\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t       ����������Ҫ�޸ĵ���ϵ�������� ");
    scanf("%s", name);
    while(p != NULL) 
	{
        if(strcmp(p->name, name) == 0) 
		{
			printf("\t\t\n\n\t\t����������Ϣ���£�\n\n"); 
            printf("\t\t\t����:%s\t\t", p->name);
            printf("���:%d\n\n", p->sign);
            printf("\t\t\tסַ:%s\t", p->home);
            printf("�绰����:%s\t", p->phone);
            printf("ѧ��:%s\t", p->student);
            printf("��������:%s\n\n", p->email);
            flag = 0;
            p=p->next;
        }
        else p = p->next;

    }
    if(flag)printf("\n\n\t\t\t--------------------���޴��ˣ�(��8���ز˵�)---------------------------\n\t\t\t");
    else{
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t       ����������Ҫ�޸ĵ���ϵ�˵����: ");
    scanf("%d", &n);
    while(p1 != NULL && (p1->sign != n || strcmp(p1->name, name) != 0)) 
	{
        p1 = p1->next;
    }
            printf("\n\n\t\t\t\t�q���������������������������������������������������������������������������������������������r\n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t          1.����              4.ѧ��           \n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t          2.סַ              5.��������        \n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t          3.�绰����                               \n");
            printf("\t\t\t\t                                                \n");
            printf("\t\t\t\t�t���������������������������������������������������������������������������������������������s\n");
            printf("\n\t\t\t ����ѡ��Ҫ�޸ĵ���Ϣ: ");
            scanf("%d", &k);
            system("cls");
            switch(k) 
			{
                case 1: printf("\n\t\t\t\t          ��������޸ĺ���������\n\t\t\t");
                scanf("%s", p1->name);
                break;

                case 2: printf("\t\t\t\t            ��������޸ĺ��סַ���\n\t\t\t");
                scanf("%s", p1->home);
                break;

                case 3: printf("\t\t\t\t            ��������޸ĺ�ĵ绰������\n\t\t\t");
                scanf("%s", p1->phone);
                break;

                case 4: printf("\t\t\t\t            ��������޸ĺ��ѧ�š��\n\t\t\t");
                scanf("%s", p1->student);
                break;

                case 5: printf("\t\t\t\t            ��������޸ĺ��������\n\t\t\t");
                scanf("%s", p1->email);
                break;

            }
            printf("                        �����޸�                               ");
            Sleep(300);
            system("cls");
            printf("\n\n\n\n\t\t\t\t���޸ĳɹ������˳�ʱ���ǵñ�����Ϣ)��\n");
            printf("\t\t\t----------------------------------------------------------------------\n");  
            printf("\t\t                       �Ƿ�����޸�                  \n\n");
			printf("\t\t                    1--------����              \n\n");
			printf("\t\t                    2--------�ص��˵�   ");
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
    printf("\n\t\t\t\t\t\t����ɾ�����ݡ���\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t\t����������ɾ������ϵ�������� ");
    scanf("%s", name);
    p1 = head;
    if(head == NULL) {
        printf("δ������ϵ����Ϣ��ͨѶ¼Ϊ��\n");
        return;
    }
   else{ 
    printf("\n\t\t\t----------------------------------------------------------------------\n");
    p3 = head;
    printf("\n\n\t\t����������Ϣ���£�\n\n");
    while(p3 != NULL) {
        if(strcmp(name, p3->name) == 0) {
             
            printf("\t\t\t����:%s\t\t", p3->name);
            printf("���:%d\n\n", p3->sign);
            printf("\t\t\tסַ:%s\t", p3->home);
            printf("�绰����:%s\t", p3->phone);
            printf("ѧ��:%s\t", p3->student);
            printf("��������:%s", p3->email);
            printf("\n\n");
            k = 0;
            printf("\t\t\t--------------------------------------------------------------\n");
        }
        p3 = p3->next;
    }
    if(k) 
	{
        printf("\t\t\t�����Ǹ���޴��ˡ���\n");
        return;
    }
    else
	{
	printf("\n\t\t����������Ҫɾ��������ţ� ");
    scanf("%d", &n);
    int a=1;
    while(p1 != NULL && (p1->sign != n || strcmp(p1->name, name) != 0)) 
	{
        p2 = p1;
        p1 = p1->next;
        a++;
    }
    if(a==1){
        printf("\n\n\t\t\t------------------------------����ɾ��--------------------------------\n\n\n\n");
        Sleep(300);
		system("cls"); 
    	head=p1->next;
		printf("\n\n\t\t\t   --------------------------ɾ���ɹ���---------------------------\n\n");
        printf("\t\t\t\t\t        (��5���棬��8���ز˵�)\n");
        return ;
	}
	else{
    printf("\n\n\t\t\t------------------------------����ɾ��--------------------------------\n\n\n\n");
    Sleep(300);
	system("cls"); 
    p2->next = p1->next; 
    printf("\n\n\t\t\t   --------------------------ɾ���ɹ���---------------------------\n\n");
    printf("\t\t\t\t\t        (��5���棬��8���ز˵�)\n");
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
    printf("\n\t\t\t\t\t\t���������ϵ�ˡ���\n");
    printf("\t\t\t----------------------------------------------------------------------\n");
    printf("\t\t\t                      �����������ص����ݡ��\n");
    printf("\t\t\t����:");
    scanf("%s", &p3->name);
    printf("\n\t\t\tסַ:");
    scanf("%s", &p3->home);
    printf("\n\t\t\t�ֻ���:");
    scanf("%s", &p3->phone);
    printf("\n\t\t\tѧ��:");
    scanf("%s", &p3->student);
    printf("\n\t\t\t����:");
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


    printf("\n\n\t\t\t                      �������������λ�á��\n");
    printf("\t\t\t+---------------------------------------------------------+\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t|                    1.��λ�ò���                         |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t|                    2.βλ�ò���                         |\n");
    printf("\t\t\t|                                                         |\n");
    printf("\t\t\t|                    3.ָ������ǰ����                     |\n");
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
        printf("��������������������ǰ�棺 ");
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
            printf("\t\t\t---------------------���޴��ˣ�----------------------\n");
        }
        else {
            p3->next = p1;
            p2->next = p3;

        }
        break;
    }
    printf("\t\t\t-----------------����ɹ���(��8���ز˵�)----------------\n");
    printf("\t\t\t--------------------------------------------------------\n");
    return;
}


void menu2() //�Բ˵�������չ 
{

	int number;
	system("cls");
	system("color 0e");
	printf("\n\n\n");
	printf("\t\t\t\t���������������������� ������ ������������������������\n\n");
	printf("\t\t\t\t* * *                    MENU                    * * * \n\n");
	printf("\t\t\t\t��������������������� ����� ����𨋡����𨋡�������\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  1.�½���ϵ����Ϣ               5.������ϵ����Ϣ  ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  2.���������ϵ��               6.�����ϵ����Ϣ  ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  3.�޸���ϵ����Ϣ               7.ɾ����ϵ����Ϣ  ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t\t||  4.������ϵ����Ϣ               8.���ز˵�        ||\n");
	printf("\t\t\t\t                                                   \n");
	printf("\t\t\t 	 ����������������                 ���������������� \n"); 
	printf("\t\t\t\t                  _(��0�˳�����)_                  \n");
    while(1) {

        printf("\t\t\t\t\t\t����������Ĳ������\t\t\t\t\n");
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
            printf("\t\t\t\t-------------ѡ��Ĳ�������ȷ�����������룺--------------\n");
        }

    }

}


void end()
{
	int t; 
	system("color 04");
	system("cls");
	printf("\n\n\n\t\t\t\t- - - - - - - - - - - - - - \n");
	printf("\t\t\t\t|     �����Ҫ�˳���    | \n");
	printf("\t\t\t\t                             \n");
	printf("\t\t\t\t|   1.�ǵģ�����Ҫ�˳�    |  \n");
	printf("\t\t\t\t                             \n");
	printf("\t\t\t\t|   2.�����һ����ٿ���    | \n\n");
	printf("\t\t\t\t    (�˳�ǰ�ǵñ�����Ϣ)\n\n\t\t\t\t"); 
	while(1){
		scanf("%d",&t);
		switch(t){
		case 1:
		
			system("cls");
			printf("\t\t\t�Ѱ�ȫ�˳�����ӭ�´�ʹ�ã�");
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




