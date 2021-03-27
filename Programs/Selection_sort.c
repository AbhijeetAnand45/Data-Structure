//overall time complexity--> square of n or (n^2)
#include<stdio.h>
#include<stdlib.h>
void selectionsort(int A[],int n)
{
    int i,j,min=0,temp;
    for(i=0;i<n;i++)      //(n-1)-->time complexity
    {
        min=i;
        for(j=i+1;j<n;j++)  //n(n-1)/2 --->time complexity
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];  //(n-1)---->time complexity
        A[min]=temp;
    }
}
int main()
{
    int arr[]={5,3,7,2,9,11,19,13,6};
    selectionsort(arr,9);
    for(int i=0;i<9;i++)
        printf("%d ",arr[i]);
    return 0;
}
