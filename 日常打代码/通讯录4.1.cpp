/******************************************************************************
*�������ɼƿƶ���������������2019��9��*****************************************
******************************************************************************/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len sizeof(cs) 

int menu_select();
int charLongth(char *p);
int Addpeo();
int watch_over();
int Delete();
int change();
int changeall();
int changetel();
int changeQQ();
int changeEmail();
int display();
int listLongth();
int arrange();
int write();
int read();




typedef struct txlsystem
{
	char name[15];//����
	char tel[20];//�ֻ�
	char tecent_qq[15];//qq����
	char email[20];//����
	struct txlsystem *Next;
}cs;
txlsystem *Head;//ͨѶ¼�ṹ��
 
typedef struct pcs  //����������ָ���ַ�������ָ��,ע�ⲻͬ�ں궨�� 
{
	cs chat;
	pcs* next;
}*ptcs;//ͨѶ¼�ڵ�
ptcs head=(ptcs)malloc(sizeof(pcs));
 
int menu_select()//����ѡ���
{
	char c;
	do
	{
		system("cls");
		printf("\n\t\t**********ͨѶ¼����ϵͳ**********\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��        1.�����ϵ��           ��\n");
		printf("\t\t��        2.��ѯ��ϵ��           ��\n");
		printf("\t\t��        3.ɾ����ϵ��           ��\n");
		printf("\t\t��        4.�޸���ϵ����Ϣ       ��\n");
		printf("\t\t��        5.�����ϵ���б�       ��\n");
		printf("\t\t��        6.����                 ��\n");
		printf("\t\t��        7.д���ļ�             ��\n");
		printf("\t\t��        8.��ȡ�ļ�             ��\n");
		printf("\t\t��        0.�˳�                 ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t����ѡ��(0-8):");    
		c=getchar(); 
	}while(c<'0'||c>'8');//��������Ƿ���Ϲ淶
	return(c-'0');//c��asc��ֵ��ȥ0��asc��ֵ����Ҫѡ����ǰ����ţ����˷���
	 
}
 
int charLongth(char *p)//�����ַ�������
{
	int i,n=0;
	for(i=0;p[i]!='\0';i++)n++;
	return n;
}
 
int Addpeo()//�����ϵ��
{
	int t,n,a;
	char flag='y';
	ptcs p=head,q;
	while(p->next)p=p->next;
	while(flag!='n'&&flag!='N')
	{
		q=(ptcs)malloc(sizeof(pcs));
		p->next=q;
		p=q;
		q->next=NULL;
		printf("\n\t\t������:\n");
		printf("\t\t����:");//��������
		scanf("\t\t%s",q->chat.name);
		printf("\t\t�ֻ�����:");//�����ֻ���
		scanf("\t\t%s",q->chat.tel);
		do
		{
			n=0;
			if(charLongth(q->chat.tel)!=11)
			{					
				n=1;
				printf("\t\t��������ֻ������ʽ������,����������:");
				scanf("\t\t%s",q->chat.tel);
			}
			else 
			{
				for(t=0;t<11;t++)
				{
					if(q->chat.tel[t]<'0'||q->chat.tel[t]>'9')
					{
						n=1;
						printf("\t\t��������ֻ������ʽ������,����������:");
						scanf("\t\t%s",q->chat.tel);
						break;
					}
				}
			}
		}while(n);
		printf("\t\tQQ��:");//����QQ��
		scanf("\t\t%s",q->chat.tecent_qq);
		do
		{
			n=0;
			if(charLongth(q->chat.tecent_qq)>10)
			{					
				n=1;
				printf("\t\t�������QQ�����ʽ������,����������:");
				scanf("\t\t%s",q->chat.tecent_qq);
			}
			else 
			{
				for(t=0;t<10;t++)
				{
					if(q->chat.tecent_qq[t]<'0'||q->chat.tecent_qq[t]>'9')
					{
						n=1;
						printf("\t\t�������QQ�����ʽ������,����������:");
						scanf("\t\t%s",q->chat.tecent_qq);
						break;
					}
				}
			}
		}while(n);
		printf("\t\t��������:");//��������
		scanf("\t\t%s",q->chat.email);
		do
		{
			a=0;
			for(t=0;q->chat.email[t]!='\0';t++)
			{
				if(q->chat.email[t]=='@')
					a++;
			}
			if(a!=1)
			{
				printf("\t\t��������䲻��������������:");
				scanf("\t\t%s",q->chat.email);
			}
		}while(a!=1);
		printf("\n\t\t�Ƿ�������?(Y/N)");      
		scanf("\t\t%c",&flag);  
	}
	return 0;
}
 
int watch_over()//��ѯ��ϵ��
{
	int m,n;
	char flag='y';
	ptcs p=head->next;
	while(flag!='n'&&flag!='N')
	{
		printf("\n\t\t*************��ѯ��ʽ*************\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��          1.��������           ��\n");
		printf("\t\t��          2.�����ֻ���         ��\n");
		printf("\t\t��          3.����QQ����         ��\n");
		printf("\t\t��          4.����               ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��ѡ���ѯ��ʽ:");
		scanf("\t\t%d",&m);//ѡ���ѯ��ʽ
		do
		{
			n=0;
			if(m!=1&&m!=2&&m!=3&&m!=4)
			{	
				n=1;
				printf("\t\t������Ĳ�ѯ��ʽ������,����������:");
				scanf("\t\t%d",&m);//ѡ���ѯ��ʽ
			}
		}while(n);
		if(!p)
		{
			printf("\t\t��ͨѶ¼Ϊ��!\n");
			return 0;
		}
		if(1==m)
		{
			char name_test[15];
			p=head->next;
			printf("\t\t��������Ҫ��ѯ����ϵ��:");
			scanf("\t\t%s",name_test);
			while(p!=NULL&&strcmp(p->chat.name,name_test)!=0)p=p->next;
			if(!p)
			{
				printf("\t\t��Ҫ��ѯ����ϵ�˲�����!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c",&flag);
				return 0;
			}
			printf("\t\t�ֻ�����:%s\n",p->chat.tel);
			printf("\t\tqq��:%s\n",p->chat.tecent_qq);
			printf("\t\t��������:%s\n",p->chat.email);
		}
		if(2==m)
		{
			char tel_test[20];
			p=head->next;
			printf("\t\t��������Ҫ��ѯ���ֻ�����:");
			scanf("\t\t%s",tel_test);
			while(p!=NULL&&strcmp(p->chat.tel,tel_test)!=0)p=p->next;
			if(!p)
			{
				printf("\t\t��Ҫ��ѯ����ϵ�˲�����!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c",&flag);
				return 0;
			}
			printf("\t\t����:%s\n",p->chat.name);
			printf("\t\tqq��:%s\n",p->chat.tecent_qq);
			printf("\t\t��������:%s\n",p->chat.email);
		}
		if(3==m)
		{
			char qq_test[15];
			p=head->next;
			printf("\t\t��������Ҫ��ѯ��qq��:");
			scanf("\t\t%s",qq_test);
			while(p!=NULL&&strcmp(p->chat.tecent_qq,qq_test)!=0)p=p->next;
			if(!p)
			{
				printf("\t\t��Ҫ��ѯ����ϵ�˲�����!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c",&flag);
				return 0;
			}
			printf("\t\t����:%s\n",p->chat.name);
			printf("\t\t�ֻ���:%s\n",p->chat.tecent_qq);
			printf("\t\t��������:%s\n",p->chat.email);
		}
		if(4==m)return 0;
		printf("\t\t�Ƿ������ѯ?(Y/N)");
		scanf("\t\t%c",&flag);
	}
	return 0;
}
 
int Delete()//ɾ��������Ϣ
{
	char nm[20];
	char flag='y';
	ptcs p=head->next,bh,pre;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	while(flag!='n'&&flag!='N')
	{
		p=head->next;
		printf("\t\t��������Ҫɾ������ϵ������:");
		scanf("\t\t%s",nm);
		while(p!=NULL&&strcmp(p->chat.name,nm)!=0)
		{
			pre=p;
			p=p->next;
		}
		if(!p)
		{
			printf("\t\t����ϵ�˲�����!\n");
			printf("\t\t�Ƿ����ɾ��?(Y/N)");
			scanf("\t\t%c",&flag);
			return 0;
		}
		bh=p->next;
		if(p==head->next)head->next=bh;
		else pre->next=bh;
		printf("\t\t����ϵ����ɾ��!\n");
		printf("\t\t�Ƿ����ɾ��?(Y/N)");
		scanf("\t\t%c",&flag);
	}
	return 0;
}
 
int changeall(ptcs p)//�޸�ĳһ��ϵ�˵�������Ϣ
{
	int a,n,t;
	printf("\t\t����:");//��������
	scanf("\t\t%s",p->chat.name);
	printf("\t\t�ֻ�����:");//�����ֻ���
	scanf("\t\t%s",p->chat.tel);
	do
	{
		n=0;
		if(charLongth(p->chat.tel)!=11)
		{					
			n=1;
			printf("\t\t��������ֻ������ʽ������,����������:");
			scanf("\t\t%s",p->chat.tel);
		}
		else 
		{
			for(t=0;t<11;t++)
			{
				if(p->chat.tel[t]<'0'||p->chat.tel[t]>'9')
				{
					n=1;
					printf("\t\t��������ֻ������ʽ������,����������:");
					scanf("\t\t%s",p->chat.tel);
					break;
				}
			}
		}
	}while(n);
	printf("\t\tQQ��:");//����QQ��
	scanf("\t\t%s",p->chat.tecent_qq);
	do
	{
		n=0;
		if(charLongth(p->chat.tecent_qq)!=10)
		{					
			n=1;
			printf("\t\t�������QQ�����ʽ������,����������:");
			scanf("\t\t%s",p->chat.tecent_qq);
		}
		else 
		{
			for(t=0;t<10;t++)
			{
				if(p->chat.tecent_qq[t]<'0'||p->chat.tecent_qq[t]>'9')
				{
					n=1;
					printf("\t\t�������QQ�����ʽ������,����������:");
					scanf("\t\t%s",p->chat.tecent_qq);
					break;
				}
			}
		}
	}while(n);
	printf("\t\t��������:");//��������
	scanf("\t\t%s",p->chat.email);
	do
	{
		a=0;
		for(t=0;p->chat.email[t]!='\0';t++)
		{
			if(p->chat.email[t]=='@')
				a++;
		}
		if(a!=1)
		{
			printf("\t\t��������䲻��������������:");
			scanf("\t\t%s",p->chat.email);
		}
	}while(a!=1);
	return 0;
}
 
int changetel(ptcs p)//�޸��ֻ�������
{
	int n,t;
	scanf("\t\t%s",p->chat.tel);
	do
	{
		n=0;
		if(charLongth(p->chat.tel)!=11)
		{					
			n=1;
			printf("\t\t��������ֻ������ʽ������,����������:");
			scanf("\t\t%s",p->chat.tel);
		}
		else 
		{
			for(t=0;t<11;t++)
			{
				if(p->chat.tel[t]<'0'||p->chat.tel[t]>'9')
				{
					n=1;
					printf("\t\t��������ֻ������ʽ������,����������:");
					scanf("\t\t%s",p->chat.tel);
					break;
				}
			}
		}
	}while(n);
	return 0;
}
 
int changeQQ(ptcs p)//�޸�QQ����
{
	int n,t;
	scanf("%s",p->chat.tecent_qq);
	do
	{
		n=0;
		if(charLongth(p->chat.tecent_qq)!=10)
		{					
			n=1;
			printf("\t\t�������QQ�����ʽ������,����������:");
			scanf("\t\t%s",p->chat.tecent_qq);
		}
		else 
		{
			for(t=0;t<10;t++)
			{
				if(p->chat.tecent_qq[t]<'0'||p->chat.tecent_qq[t]>'9')
				{
					n=1;
					printf("\t\t�������QQ�����ʽ���Ϸ�,����������:");
					scanf("\t\t%s",p->chat.tecent_qq);
					break;
				}
			}
		}
	}while(n);
	return 0;
}
 
int changeEmail(ptcs p)//�޸ĵ�������
{
	int t,a;
	scanf("\t\t%s",p->chat.email);
	while(a==0)
	{
		a=0;
		for(t=0;p->chat.email[t]!='\0';t++)
		{
			if(p->chat.email[t]=='@')
				a++;
		}
		if(a!=1)
		{
			printf("\t\t��������䲻�Ϸ�������������:");
			scanf("\t\t%s",p->chat.email);
		}
	}
	return 0;
}
 
int change()//�޸���ϵ����Ϣ
{
	char nm[20],flag='y';
	int m,n;
	ptcs p=head->next;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	while(flag!='n'&&flag!='N')
	{
		p=head->next;
		printf("\n\t\t*******��������Ҫ�޸ĵ�����*******\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��       1.��ϵ��                ��\n");
		printf("\t\t��       2.�ֻ�����              ��\n");
		printf("\t\t��       3.QQ��                  ��\n");
		printf("\t\t��       4.��������              ��\n");
		printf("\t\t��       5.����                  ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��������Ҫ�޸ĵ�����:");
		scanf("\t\t%d",&m);
		do
		{
			n=0;
			if(m!=1&&m!=2&&m!=3&&m!=4&&m!=5)
			{	
				n=1;
				printf("\t\t������ı�Ų����Ϲ涨,����������:");
				scanf("\t\t%d",&m);//ѡ���޸�����
			}
		}while(n);
		if(5==m)return 0;
		printf("\t\t�����������޸���Ϣ����ϵ�˵�����:");
		scanf("\t\t%s",nm);
		while(p!=NULL&&strcmp(p->chat.name,nm)!=0)p=p->next;
		if(!p)
		{
			printf("\t\t����ϵ�˲�����!\n");
			return 0;
		}
		if(1==m)
		{
			printf("\t\t�����������޸�:\n");
			changeall(p);
		}
		if(2==m)
		{
			printf("\t\t������%s���ֻ�����:",p->chat.name);
			changetel(p);
		}
		if(3==m)
		{
			printf("\t\t������%s��QQ��:",p->chat.name);
			changeQQ(p);
		}
		if(4==m)
		{
			printf("\t\t������%s�ĵ�������:",p->chat.name);
			changeEmail(p);
		}
		printf("\t\t�Ƿ�����޸�?(Y/N)");
		scanf("\t\t%c",&flag);
	}
	return 0;
}
 
int display()//���ͨѶ¼�б�
{
	ptcs p=head->next;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	printf("\n\t\t******************************ͨѶ¼�б�******************************\n");
	printf("\t\t����\t\t�ֻ�����\tQQ����\t\t��������\n");
	printf("\t\t----------------------------------------------------------------------\n");
	while(p)
	{
		printf("\t\t%-16s%-16s%-16s%-20s\n",p->chat.name,p->chat.tel,p->chat.tecent_qq,p->chat.email);
		p=p->next;
		printf("\t\t----------------------------------------------------------------------\n");
	}
	return 0;
}
 
int listLongth(ptcs p)//��������ĳ���
{
	int n=0;
	while(p)
	{
		p=p->next;
		n++;
	}
	return n;
}
 
int arrange()//��ͨѶ¼��������,ð������ 
{
	int i,n;
	ptcs pre=head,p=head->next,k,q;
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	n=listLongth(p);
	for(i=0;i<n-1;i++)
	{
		for(p=head->next,pre=head;p->next->next!=NULL;pre=p,p=p->next);
		{
			k=p->next;
			q=k->next;
			if(strcmp(p->chat.name,k->chat.name)>0)
			//strcmp������string compare(�ַ����Ƚ�)����д��
			//���ڱȽ������ַ��������ݱȽϽ������������
			//������ʽΪstrcmp(str1,str2)����str1=str2���򷵻��㣻
			//��str1<str2���򷵻ظ�������str1>str2���򷵻�����
			{
				pre->next=k;
				k->next=p;
				p->next=q;
				p=k;
			}
		}
	}
	display();
	return 0;
}
 
int write()//������д���ļ�
{
	ptcs p=head->next;
	FILE* fp;
	char filename[30];
	if(!p)
	{
		printf("\t\t��ͨѶ¼Ϊ��!");
		return 0;
	}
	printf("\t\tд�뵽�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s",filename);
	if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\t\t�޷����ļ�!\n");
		system("pause");
		return 0;
	}
	fprintf(fp,"******************************ͨѶ¼�б�******************************\n");
	fprintf(fp,"����\t\t�ֻ�����\tQQ����\t\t��������\n");
	fprintf(fp,"----------------------------------------------------------------------\n");
	while(p)
	{
		fprintf(fp,"%-16s%-16s%-16s%-20s\n",p->chat.name,p->chat.tel,p->chat.tecent_qq,p->chat.email);
		p=p->next;
		fprintf(fp,"----------------------------------------------------------------------\n");
	}
	fprintf(fp,"\n******************************��%d����ϵ��******************************\n",listLongth(head->next));
	fclose(fp);                                         //�ر��ļ�   
	printf("\t\tд��ɹ�!\n"); 
	return 0;
}
 
int read()//��ȡ�ļ�
{
	char str[100];
	char filename[30];
	FILE* fp;
	printf("\t\t��ȡ�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s",filename);
	if((fp=fopen(filename,"a+"))==NULL)
	{
		printf("\t\t�޷����ļ�!\n");
		system("pause");
		return 0;
	}
	while((fgets(str,100,fp))!=NULL)  
    {  
    
    
    
		printf("\t\t%s",str);  
    }
	return 0;
}
 
 
/*void read() {
	char filename[30];
	printf("\t\t��ȡ�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s",filename);
    FILE *fp;
    cs *p1, *p2, *p3;
    p1 = p2 = (cs *)malloc(len);
    Head = NULL;
    printf("b");
    if((fp = fopen(filename, "r+")) == NULL) {
        printf("\t\t\t\t\t   (δ����ͨѶ¼��)\n");}
    else {
        if(p1 != NULL)
		{
		Head = p1;
        while(1) {
            if(!feof(fp)) {
                fscanf(fp, "%s%s%s%s", p1->name, &p1->tel, p1->tecent_qq, p1->email);
                p2->Next = p1;
                p3 = p2;
                p2 = p1;
                p1 = (cs *)malloc(len);
            }
            else {
                p3->Next = NULL;
            }
                 }
        
        } 
    }
    fclose(fp);
    getchar();
}
 
*/
 

 
int main()
{
	/*head->next=NULL;
	system("cls");
	printf("\n\t\t**********ͨѶ¼����ϵͳ**********\n");
	printf("\t\t��-------------------------------��\n");
	printf("\t\t��        1.�����ϵ��           ��\n");
	printf("\t\t��        2.��ѯ��ϵ��           ��\n");
	printf("\t\t��        3.ɾ����ϵ��           ��\n");
	printf("\t\t��        4.�޸���ϵ����Ϣ       ��\n");
	printf("\t\t��        5.�����ϵ���б�       ��\n");
	printf("\t\t��        6.����                 ��\n");
	printf("\t\t��        7.д���ļ�             ��\n");
	printf("\t\t��        8.��ȡ�ļ�             ��\n");
	printf("\t\t��        0.�˳�                 ��\n");
	printf("\t\t��-------------------------------��\n");
	printf("\t\t����ѡ��(0-8):"); 
	printf("\n\t\t******************************ͨѶ¼�б�******************************\n");
	printf("\t\t����\t\t�ֻ�����\tQQ����\t\t��������\n");*/
	head->next=NULL;
	//while(1)
	for(;;)
	{	switch(menu_select())
		{
		case 1:
			printf("\n\t\t��Ӽ�¼��ͨѶ¼\n"); 
			Addpeo();
			system("pause");
			break;
		case 2:
			printf("\n\t\t��ͨѶ¼�в�����ϵ��\n"); 
			watch_over();
			system("pause");
			break;
		case 3:
			printf("\n\t\t��ͨѶ¼��ɾ����ϵ��\n");
			Delete();
			system("pause");
			break;
		case 4:
			printf("\n\t\t�޸�ͨѶ¼�е���Ϣ\n");
			change();
			system("pause");
			break;
		case 5:
			printf("\n\t\t���ͨѶ¼�б�\n");
			display();
			system("pause");
			break;
		case 6:
			printf("\n\t\t����\n");
			arrange();
			system("pause");
			break;
		case 7:
			printf("\n\t\tд���ļ�\n");
			write();
			system("pause");
			break;
		case 8:
			printf("\n\t\t��ȡ�ļ�\n");
			read();
			system("pause");
		    break;
			
		case 0:    
			printf("\n\t\tлл����ʹ�ã��ڴ���һ��ʹ��!\n");  //��������    
			printf("\n\t\t");    
			system("pause");    
			exit(0);    
		}
	}
	return 0;
}

