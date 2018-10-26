#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct sll
{
	int data;	
	struct sll *next;	
}node;
node *temp,*temp1,*temp2,*temp3,*start,*q,*newnode;	


node* create();
node* getnode();
void addatbegin(int info);	
void reversesll();
void search(int info);		
void delet(int info);		
void display();
void addafter(int info);	

int main()
{
	int n,i,info,op;
	char m;
start=NULL;
clrscr();
	do
	{
		printf("\n************************* SLL *************************");
		printf("\n1.CREATE SLL \t\t2.DELETE \t3.ADD AT BEGINING");
		printf("\n4.ADD AFTER NODE \t5.SEARCH");
		printf("\t6.SLL REVERSE \n7.EXIT\n 8.Display");
		printf("\n*******************************************************");
		printf("\nENTER OPTION: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:start=create();		
					break;
			case 2:printf("\nENTER ELEMENT TO BE DELETED: ");
					scanf("%d",&info);
					delet(info) ;		
					break;
			case 3:printf("\nENTER DATA TO BE ADDED AT BEGINING: ");
					scanf("%d",&info);
					addatbegin(info);	
					break;
			case 4:printf("\nENTER DATA: ");
					scanf("%d",&info);
					addafter(info);		
					break;
			case 5:printf("\nENTER ELEMENT TO BE SEARCHED: ") ;
					scanf("%d",&info);
					search(info);		
					break;
			case 6:reversesll();		
					break;
			case 7:exit(0);			
					break;
			case 8:display();		
					break;
		}
		printf("\n\nCONTINUE WITH MAIN MENU(y/n): ");
	     m=getch();

	}while(m=='y'||m=='Y');
       getch();
}
node* create()
{
	int val,flag=1;		
	char choice;
	do
	{

		printf("Enter data: ");
		scanf("%d",&val);
		newnode=getnode();		
		newnode->data=val;		
		if(flag==1)			
		{
			start=newnode;		
			temp=start;		
			flag=0;			
		}
		else
		{
			temp->next=newnode;	
			temp=newnode;
		}
		printf("Continue(y/n): ");
scanf("%c",&choice);
	}while(choice=='y'||choice=='Y');
	return start;
}

node* getnode()  
{
	node *temp;		
							
	temp=(node*)malloc(sizeof(node));		
	temp->next=NULL;				
	return temp;
}

void display()
{
	temp=start;
	while(temp!=NULL)
	{
		printf(" %d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}

void addatbegin(int info)
{
	temp=(node*)malloc(sizeof(node));
	temp->data=info;
	temp->next=start;
	start=temp;
}

void addafter(int info)
{
	int i,pos;
	temp=(node*)malloc(sizeof(node));
	temp->data=info;
	temp->next=NULL;
	q=start;
	printf("\nENTER POSITION AFTER WHICH,DATA TO BE ADDED: ");
	scanf("%d",&pos);
	for(i=1;i<=pos;i++)
	{
		q=q->next;
	}
	temp->next=q->next;
	q->next=temp;
}
void search(int info)
{
	int i=0,flag=0;
	temp=start;
	while(temp!=NULL)
	{
		if(temp->data==info)
		{
			flag=1;
			break;
		}
		temp=temp->next;
		i++;
	}
	if(flag==1)
		printf("\nELEMENT %d IS FOUND AT POSITION %d.\n",info,i);
	else
		printf("\nELEMENT NOT PRESENT.\n");
}

void delet(int info)
{
	int flag=0;
	if(start->data==info)
	{
		flag=1;
		temp=start;
		start=start->next;
		temp->next=NULL;
		free(temp);
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			if(q->next->data==info)
			{
				flag=1;
				temp=q->next;
				q->next=q->next->next;
				temp->next=NULL;
				free(temp);
			}
			q=q->next;
		}
	}
	if(flag==1)
		printf("\nDATA IS DELETED.\n");
	else
		printf("\nDATA NOT FOUND.\n");
}

void reversesll()  
{
	temp1=start;
	temp2=NULL;
	while(temp1!=NULL)
	{
		temp3=temp2;
		temp2=temp1;
		temp1=temp1->next;
		temp2->next=temp3;
	}
	start=temp2;
}