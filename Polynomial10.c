#include<stdio.h>
#include<stdlib.h>
typedef struct node
{	
	int co;
	int expo;
	struct node *next;
}poly;
poly *p1=NULL;
poly *p2=NULL;
poly *p3=NULL;
poly *p4=NULL;
poly *create(poly *start,int n);
void display(poly *start);
poly*add(poly *p1,poly *p2,poly *p3);
poly *create1(poly *start,int n);
void display1(poly *start);
poly*mul(poly *p1,poly *p2,poly *p3);
			

void main()
{
	int ch;
	int n,n1,n2;
	do
	{

		printf("\n****************Polynomial Representation**********************");
		printf("\n 1.Addition of polynomial \n 2.Multiplication of polynomial \n 3.Exit");
		printf("\n Enter your choice.....");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:

			printf("Enter the number of terms in 1st polynomial::>");
			scanf("%d",&n1);
			p1=create(p1,n1);
			display(p1);

			printf("\n Enter the number of terms in 2nd polynomial::>");
			scanf("%d",&n2);
			p2=create(p2,n2);
			display(p2);

			p3=add(p1,p2,p3);
			printf("\n The result of addition is\n");
			display(p3);

			break;

		case 2:
			
			printf("Enter the number of terms in 1st polynomial::>");
			scanf("%d",&n1);
			p1=create1(p1,n1);
			display1(p1);

			printf("\n Enter the number of terms in 2nd polynomial::>");
			scanf("%d",&n2);
			p2=create1(p2,n2);
			display1(p2);

			p4=mul(p1,p2,p4);
			printf("\n The result of Multiplication is\n");
			display1(p4);

			break;

		case 3:
			break;

		default:
			printf("\n Enter a valid choice.....");
			break;
		}
	}while(ch!=3);
}



poly *create(poly *start,int n)
{
	poly *temp,*newnode;
	int i;
	temp=start;
	printf("\n Enter the exponential terms in ascending orders");
	for(i=0;i<n;i++)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		printf("\n Enter the co-efficient & exponent terms::>");
		scanf("%d%d",&newnode->co,&newnode->expo);
		if(start==NULL)
			temp=start=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return start;
}

void display(poly *start)
{
	poly *temp;
	temp=start;
	if(temp!=NULL)
	{
		while(temp->next!=NULL)
		{
			printf("%dx^%d+",temp->co,temp->expo);
			temp=temp->next;
		}
		printf("%dx^%d=0",temp->co,temp->expo);
	}
	printf("\n");
}

poly *add(poly *p1,poly *p2,poly *p3)
{
	poly *t1,*t2,*t3,*newnode;
	t1=p1;
	t2=p2;
	t3=p3;
	while(t1&&t2)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		if(t1->expo>t2->expo)
		{
			newnode->expo=t1->expo;
			newnode->co=t1->co;
			t1=t1->next;
		}
		else
		{
			if(t1->expo<t2->expo)
			{
				newnode->expo=t2->expo;
				newnode->co=t2->co;
				t2=t2->next;
			}
			else
			{
				newnode->expo=t1->expo;
				newnode->co=t1->co+t2->co;
				t1=t1->next;
				t2=t2->next;
			}
		}
		if(p3==NULL)
		{
			p3=newnode;
			t3=newnode;
		}
		else 
		{
			t3->next=newnode;
			t3=newnode;
		}
	}
	while(t1)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		newnode->expo=t1->expo;
		newnode->co=t1->co;
		t3->next=newnode;
		t3=newnode;
		t1=t1->next;
	}
	while(t2)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		newnode->expo=t2->expo;
		newnode->co=t2->co;
		t3->next=newnode;
		t3=newnode;
		t2=t2->next;
	}
	return(p3);
}

poly *create1(poly *start,int n)
{
	poly *temp,*newnode;
	int i;
	temp=start;
	printf("\n Enter the exponential terms in ascending orders");
	for(i=0;i<n;i++)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		printf("\n Enter the co-efficient & exponent terms::>");
		scanf("%d%d",&newnode->co,&newnode->expo);
		if(start==NULL)
			temp=start=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
	return start;
}

void display1(poly *start)
{
	poly *temp;
	temp=start;
	if(temp!=NULL)
	{
		while(temp->next!=NULL)
		{
			printf("%dx^%d*",temp->co,temp->expo);
			temp=temp->next;
		}
		printf("%dx^%d=0",temp->co,temp->expo);
	}
	printf("\n");
}

poly *mul(poly *p1,poly *p2,poly *p4)
{
	poly *t1,*t2,*t4,*newnode;
	t1=p1;
	t2=p2;
	t4=p4;
	while(t1&&t2)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		if(t1->expo>t2->expo)
		{
			newnode->expo=t1->expo;
			newnode->co=t1->co;
			t1=t1->next;
		}
		else
		{
			if(t1->expo<t2->expo)
			{
				newnode->expo=t2->expo;
				newnode->co=t2->co;
				t2=t2->next;
			}
			else
			{
				newnode->expo=t1->expo;
				newnode->co=t1->co*t2->co;
				t1=t1->next;
				t2=t2->next;
			}
		}
		if(p4==NULL)
		{
			p4=newnode;
			t4=newnode;
		}
		else 
		{
			t4->next=newnode;
			t4=newnode;
		}
	}
	while(t1)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		newnode->expo=t1->expo;
		newnode->co=t1->co;
		t4->next=newnode;
		t4=newnode;
		t1=t1->next;
	}
	while(t2)
	{
		newnode=(poly*)malloc(sizeof(poly));
		newnode->next=NULL;
		newnode->expo=t2->expo;
		newnode->co=t2->co;
		t4->next=newnode;
		t4=newnode;
		t2=t2->next;
	}
	return(p4);
}