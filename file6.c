#include<stdio.h>

struct student
{
	int roll_no;
	char name[30];
	float scale;
}a[20];
void main()
{
	FILE *fp;
	int n,roll,i,ch,flag=0;
	fp=fopen("roll_no_107.txt","w+");
	do
	{
		printf("\n 1. ENTER DATA \n 2. DISPLAY DATA \n 3. UPDATE DATA \n 4. EXIT \n ENTER YOUR CHOICE :: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
		
			case 1: printf("\n ENTER HOW MANY STUDENTS DATA YOU WANT TO INSERT :: ");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("\n ENTER THE ROLL NO :: ");
					scanf("%d",&a[i].roll_no);
					printf("\n ENTER THE NAME :: ");
					scanf("%s",a[i].name);
					printf("\n ENTER THE SCALE :: ");
					scanf("%f",&a[i].scale);
				}
				break;
			case 2: fprintf(fp,"\n ROLL NO  NAME  SCALE");
				printf("\n ROLL NO  NAME  SCALE");
				for(i=0;i<n;i++)
				{	
				fprintf(fp,"\n %3d  %10s  %1.2f",a[i].roll_no,a[i].name,a[i].scale);
				printf("\n %3d  %10s  %1.2f",a[i].roll_no,a[i].name,a[i].scale);
				}				
				break;
			case 3: printf("\n ENTER THE ROLL NO TO UPDATE DATA :: ");
				scanf("%d",&roll);
				flag=0;
				for(i=0;i<n;i++)
				{
					if(a[i].roll_no==roll)
					{
						printf("\n ENTER THE UPDATED NAME :: ");
						scanf("%s",a[i].name);
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					printf("\n THE ENTERED ROLL NO DOES NOT EXIST IN DATA...");
				}
		}
		printf("\n");
	}while(ch!=4);
	fclose(fp);
}