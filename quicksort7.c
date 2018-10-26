#include<stdio.h>
void main()
{
	int a[20];
	int i,n;
	printf("\nenter how many numbers you wants to entered:");
	scanf("%d",&n);
       printf("\nenter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	qsort(a,0,n-1);
	printf("sorted elements: \n");
	for(i=0;i<n;i++)
	   printf("%d,",a[i]);
	   printf("\n");
}
qsort(int a[],int l,int n)
{
	int p;
	if(l<n)
	{
		p=part(a,l,n);
		qsort(a,l,p-1);
		qsort(a,p+1,n);
	}
}
part(int a[],int l,int n)
{
	int x=a[n],i,j,z,y;
	i=(l-1);
	for(j=l;j<=n-1;j++)
	{
		if(a[j]<=x)
		{
			i++;
			z=a[i];
			a[i]=a[j];
			a[j]=z;
		}
	}
	
	y=a[i+1];
	a[i+1]=a[n];
	a[n]=y;
	return (i+1);
}

