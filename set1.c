#include<stdio.h>
int main()
{
	int a[30],b[30],c[30],m,n,i,j,k=0,ch,flag=0;

	printf("ENTER THE SIZE OF SET A :: \n");
	scanf("%d",&m); 
	printf("ENTER THE VALUES OF SET A :: \n");

	for(i=0;i<m;i++) 
	scanf("%d",&a[i]);

	printf("ENTER THE SIZE OF SET B :: \n");
	scanf("%d",&n); 
	printf("ENTER THE VALUES OF SET B :: \n");

	for(i=0;i<n;i++) 
	scanf("%d",&b[i]);

	do 
	{
		printf("\n SELECT :: \n 1. UNION \n 2. INTERSECTION \n 3. DIFFERENCE \n 4. EXIT \n ENTER YOUR CHOICE :: \n ");
		scanf("%d",&ch);
		switch(ch) 
		{
			case 1: /* union */
         for(i=0;i<m;i++) 
				{
					c[i]=a[i]; 
				}
					k=i; 

				for(i=0;i<n;i++) 
				{
					for(j=0;j<m;j++)
					{
						flag=0;
						if(b[i]==c[j]) 
						{
             flag=1;
							break;
						}
					}
					if(flag==0) 
					{
						c[k]=b[i]; 
						k=k+1; 
					}
				}

				printf("\n THE ELEMENTS OF (A U B) ARE :: \n");

				for(i=0;i<k;i++)
				printf("%d ",c[i]);
       k=0;
				break;

			case 2: k=0;
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						if(a[i]==b[j])
						{
							c[k]=a[i];
							k=k+1;
						}
					}
				}

				printf("THE SET OF A INTERSECTION B IS :: \n");

				for(i=0;i<k;i++)
					printf("%d ",c[i]);
        k=0;
				break;

			case 3: 
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						flag=0;
						if(a[i]==b[j])
						{
							flag=1;
						}
						
					}
					if(flag==0)
					{
						c[k]=a[i];
						k++;
					}
					
				}
				
				printf("THE SET OF (A-B) IS :: \n");

				for(i=0;i<k;i++)
				{
					printf("%d ",c[i]);
				}
       k=0;
				break;
		}
	}while(ch!=4);
}