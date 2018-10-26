#include<stdio.h>

int main()
{
	int a[10][10],b[10][10],c[20][20],m,n,p,q,i,j,k,ch;
	printf("\n ENTER THE VALUES OF M & N FOR MATRIX A :: \n");
	scanf("%d  %d",&m,&n);
	printf("\n ENTER THE VALUES OF MATRIX A :: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n ENTER THE VALUES OF P & Q FOR MATRIX B :: \n");
	scanf("%d  %d",&p,&q);
	printf("\n ENTERTHE VALUES OF MATRIX B :: \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("\n MATRIX A :: \n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",a[i][j]);
		}
	}
	printf("\n MATRIX B :: \n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d  ",b[i][j]);
		}
	}
	do
	{
		printf("\n SELECT :: \n 1. ADDITION \n 2. SUBTRACTION \n 3. TRANSPOSE \n 4. MULTIPLICATION \n 5. EXIT \n ENTER YOUR CHOICE :: \n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						c[i][j]=a[i][j]+b[i][j];
					}
				}
				printf("\n ADDITION IS :: \n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%d  ",c[i][j]);
					}
				}
				printf("\n");
				break;
			case 2: for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						c[i][j]=a[i][j]-b[i][j];
					}
				}
				printf("\n SUBSTRACTION IS :: \n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%d  ",c[i][j]);
					}
				}
				printf("\n");
				break;
			case 3: for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						c[i][j]=a[j][i];
					}
				}
				printf("\n TRANSPOSE IS :: \n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%d  ",c[i][j]);
					}
				}
				printf("\n");
				break;
			case 4: if(n==p)
				{
				 	for(i=0;i<m;i++)
					{
						for(j=0;j<n;j++)
						{
							c[i][j]=0;
							for(k=0;k<n;k++)
							{
								c[i][j]=c[i][j]+a[i][k]*b[k][j];
							}
						}
					}
					printf("\n MULTIPLICATION IS :: \n");
					for(i=0;i<m;i++)
					{
						for(j=0;j<n;j++)
						{
							printf("%d  ",c[i][j]);
						}
					}
				}
				else
				{
					printf("\n MATRIX MULTIPLICATION IS NOT POSSIBLE... \n");
				}
				printf("\n");
				break;
		}
	}while(ch!=5);
	printf("\n");
}