#include<stdio.h>
#define max 20

void printsparse(int [][3]);
void readsparse(int [][3]);
void transpose(int [][3],int [][3]);
int main()
{
	int b1[max][3],b2[max][3],m,n;
	printf("Enter the Size of Matrx(row,colums):");
	scanf("%d%d",&m,&n);
	b1[0][0]=m;
	b1[0][1]=n;
	
	readsparse(b1);
	transpose(b1,b2);
	printsparse(b2);
}

void readsparse(int b[max][3])
{
	int i,t;
	printf("Enter no.of non_Zero element:");
	scanf("%d",&t);
	b[0][2]=t;
	printf("\n");
	
	for(i=1;i<=t;i++)
	{
		printf("Enter the next triple(row,colume,value):");
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	}
}

void printsparse(int b[max][3])
{
	int i,n;
	n=b[0][2];// no of 3-triples
	printf("\n After Transpose:\n");
	printf("\nRow\tColumn\tValue\n");
	for(i=0;i<1;i++)
		{
			printf("(%d)\t  (%d)\t (%d)\n",b[i][0],b[i][1],b[i][2]);
			printf("------------------------------------\n");
		}
	for(i=1;i<=n;i++)
		printf("%d\t %d\t  %d\n",b[i][0],b[i][1],b[i][2]);
	printf("------------------------------\n");
}

void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;
	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	k=1;
	n=b1[0][2];
	for(i=0;i<b1[0][1];i++)
	  for(j=1;j<=n;j++)
		
	if(i==b1[j][1])
	{
		b2[k][0]=i;
		b2[k][1]=b1[j][0];
		b2[k][2]=b1[j][2];
		k++;
	}

}