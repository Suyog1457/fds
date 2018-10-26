#include<stdio.h>

int accept(int array[30])
{
    int i,n;
    printf("\nEnter the no of Element in array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Array[%d]:",i);
        scanf("%d",&array[i]);
    }
    return n;
}

void display(int array[30],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t%d",array[i]);
    }
}
void bubble(int array[30],int n)
{
    int j,i,temp;

    for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {

                    if(array[j]>array[j+1])
                    {
                        temp=array[j];
                        array[j]=array[j+1];
                        array[j+1]=temp;
                    }

            }
        }

}
void inserction_sort(int array[30],int n)
{
    int i,j,min,t;
    for(i=0;i<n;i++)
    {
            min=i;
            for(j=i+1;j<n;j++)
            if(array[j] > array[min])
            {
                min=j;
            }
            t=array[i];
            array[i]=array[min];
            array[min]=t;
    }
}


int bin_search(int array[],int key,int n)
{
    int i,c,j;
    i=0;j=n-1;c=(i+j)/2;
    printf("\nEnter element to search:");
    scanf("%d",&key);
    while(array[c]!=key && i<=j)
    {
        if(key>array[c])
            i=c+1;
        else
            j=c-1;
            c=(i+j)/2;
    }
        if(i<=j)
            return(c);
        else
            return(-1);
}

int main()
{
    int array[30],choice,n=0,result,key;
    do
    {
        printf("\n********MENU********");
        printf("\n1.Bubble\t\n2.ins\t\n3.binary");
        printf("\n4.exit");
        printf("\n*******************");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                n=accept(array);
                printf("\n******BUBBLE_SORT******");
                printf("\nBefore Sorting:");
                display(array,n);

                printf("\n");
                bubble(array,n);
                printf("\n");

                printf("\nAfter Sorted Element:");
                display(array,n);
                break;
            case 2:

                    printf("\n******INSSORTION_SORT*******");
                    printf("\nBefore Sorting");
                    display(array,n);

                    printf("\n");
                    inserction_sort(array,n);
                    printf("\nAfter Sorted");
                    display(array,n);
                break;

            case 3:
                printf("\n*****Binary_Search********");
			int i,n;
 	 		  printf("\nEnter the no of Element in array:");
  	 		 scanf("%d",&n);
  	 		 for(i=0;i<n;i++)
  	 			{
		   		 printf("\nEnter Array[%d]:",i);
	  	     	 scanf("%d",&array[i]);
  	  			}	
                    printf("\nArray:");
					bubble(array,n);
					 for(i=0;i<n;i++)
   					 {
       					 printf("\t%d",array[i]);
  					  }		
   	               //display(array,n);
               	 printf("\n");
                result=bin_search(array,key,n);
                if(result==-1)
                    printf("\nElement Not found");
                else
                    printf("\nElement is found at Location%d",result+1);
                    //getch();

        }
    }while(choice!=4);
}