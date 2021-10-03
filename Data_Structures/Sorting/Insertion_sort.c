//Time Complexity best case O(n) and for worst case O(n^2)
#include<stdio.h>
void insertsort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=A[i];
        for(j=i-1;j>=0 && temp<A[j]; j--)
            A[j+1]=A[j];
        A[j+1]=temp;
    }
}
int main()
{
    int i=0,n;
    printf("\nEnter the number of data you want to enter: ");
    scanf("%d",&n);
    int A[n];
    
    // int A[]={12,8,24,17,33,71,10,48,4,21,6};
    printf("\nPlease enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf(" %d",&A[i]);
    }
    printf("\nArray element are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    insertsort(A,n);
    printf("\nsorted element are: ");
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    return 0;
}
