//Time Complexity --> n^2
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bubblesort(int A[],int n)
{
    int i,j,temp,k=0;
    for(i=0;i<n-1;i++)
      {
        for(j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
//        printf("After %d pass: ",i);
//        for(k=0;k<n;k++)
//           {
//               printf("%d ",A[k]);
//           }
//        printf("\n");
      }

}
int main()
{
	clock_t start,end;
	start = clock();
    int i=0,n;
    printf("\nEnter the number of data you want to enter: ");
    scanf("%d",&n);
    int A[n];

    printf("\nPlease enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf(" %d",&A[i]);
    }

//    printf("\nArray element are: ");
//    for(i=0;i<n;i++)
//    {
//        printf("%d ",A[i]);
//    }
//    printf("\n");
    bubblesort(A,n);
    
    printf("\nAfter sorting Elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    end = clock();
    double duration = (double)( end - start);
    printf("Time Taken %f",duration);
    return 0;
}
