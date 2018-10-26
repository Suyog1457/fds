#include<stdio.h>
#include<stdlib.h>

typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
}dnode;

dnode *create();
void print(dnode *head);
void onescomp(dnode *head);
dnode* twoscomp(dnode *head);
dnode *add1(dnode *head1, int );

int main()
{
    dnode *head1,*head2;
    head1=create();
    printf("Binary Number is: ");
    print(head1);
    printf("\n1's Complement of Number: ");
    onescomp(head1);
    print(head1);
    printf("\n2's Complement of Number: ");
    head2=twoscomp(head1);
    print(head2);
    printf("\n");	
    return 0;
}

dnode *create()
{
    dnode *p,*head;
    char x;
    head=NULL;
    printf("Enter a binary number: ");
    while((x=getchar())!='\n')
    {
        if(head==NULL)
        {
            head=p=(dnode *)malloc(sizeof(dnode));
            p->next=p->prev=NULL;
        }
        else
        {
            p->next=(dnode *)malloc(sizeof(dnode));
            p->next->prev=p;
            p=p->next;
            p->next=NULL;
        }
        if(x=='1')
            p->data=1;
        else
            p->data=0;
    }
    return head;
}

void print(dnode *head)
{
    while(head !=NULL)
    {
        printf("%d",head->data);
        head=head->next;
    }
}

void onescomp(dnode *head)
{
    dnode *p;
    p=head;
    while(p !=NULL)
    {
        if(p->data ==0)
            p->data=1;
        else
            p->data=0;
        p=p->next;
    }
}

dnode* twoscomp(dnode *head)
{
    dnode *p,*r;
    p=head;
    r=add1(p,1);
    return(r);
}   

dnode *add1(dnode *head2, int k)
{
    dnode *head,*p;
    int x,y,z,carry;
    y=k;
    carry=0;
    head=NULL;
    if(head2!=NULL)
        while(head2->next!=NULL)
            head2=head2->next;

        x=0;
        if(head2 !=NULL)
        {
            x=head2->data;
            head2=head2->prev;
            z=(x+y+carry)%2;
            carry=(x+y+carry)/2;
        }
        head=(dnode*)malloc(sizeof(dnode));
        head->next=head->prev=NULL;
        head->data=z;
        while (head2 !=NULL)
        {
            x=head2->data;
            head2=head2->prev;
            z=(x+carry)%2;
            carry=(x+carry)/2;
            head->prev=(dnode*)malloc(sizeof(dnode));
            head->prev->next=head;
            head=head->prev;
            head->prev=NULL;
            head->data=z;
    }
    if(carry==1)
    {
        head->prev=(dnode*)malloc(sizeof(dnode));
        head->prev->next=head;
        head=head->prev;
        head->prev=NULL;
        head->data=carry;
    }
    return head;
}