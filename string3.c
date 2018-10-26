#include<stdio.h>
int main()
{
	int i,j,ch,flag=0;
	char s1[30],s2[30];
	printf("\n ENTER YOUR NAME :: ");
	scanf("%s",s1);
	do
	{
		printf("\n ENTER \n 1. LENGTH \n 2. COPY \n 3. REVERSE \n 4. PALLINDROME \n 5. EXIT \n ENTER YOUR CHOICE :: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: //length of string
				 i=0;
				while(s1[i]!='\0')
				{
					i++;
				}
				printf("\n LENGTH OF STRING IS :: %d \n",i);
				break;
			case 2: //copy of string
				 i=0;
				while(s1[i]!='\0')
				{
					s2[i]=s1[i];
					i++;
				}
				printf("\n COPIED STRING IS :: %s \n",s2);
				break;
			case 3: //reverse of string
				 i=0;
				j=0;
				while(s1[i]!='\0')
				{
					i++;
				}
				i--;
				while(i>=0)
				{
					s2[j]=s1[i];
					i--;
					j++;
				}
				printf("\n REVERSE OF STRING IS :: %s",s2);
				break;
			case 4:  i=0;
				j=0;
				while(s1[i]!='\0')
				{
					i++;
				}
				i--;
				while(i>=0)
				{
					s2[j]=s1[i];
					i--;
					j++;
				}
				i=0;
				j=0;
				while(s1[i]!='\0')
				{
					if(s1[i]==s2[j])
					{
						flag=0;
						i++;
						j++;
					}
					else
					{
						flag=1;
						printf("\n THE STRING IS NOT PALLINDROME.. \n");
						break;
					}
				}
				if(flag==0)
				{
					printf("\n THE STRING IS PALLINDROME.. \n");
				}
				break;
		}
	}while(ch!=5);
}