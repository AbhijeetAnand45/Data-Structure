//Time Complexity for average case is = n(log n)
//Time Complexity for worst case = n^2 i.e. square of n
#include<stdio.h>
#include<stdlib.h>
int partitionofarray(int A[],int start,int end)
{
    int pivot, p,i,temp;
    pivot=A[end];
    p=start;
    for(i=start;i<end;i++)
    {
        if(A[i]<=pivot)
        {
            temp=A[i];
            A[i]=A[p];
            A[p]=temp;
            p=p+1;
        }
    }
    temp=A[p];
    A[p]=A[end];
    A[end]=temp;
    return p;

}
void quicksort(int A[],int start,int end)
{
    int p;
    if(start>=end)
        return;
    p=partitionofarray(A,start,end);
    quicksort(A,start,p-1);
    quicksort(A,p+1,end);
}
int main()
{
    int i;
    int n;
    printf("\nEnter size of Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nENTER THE ARRAY ELEMENT: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quicksort(arr,0,n);
    printf("\nSORTED NUMBERS ARE: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}




