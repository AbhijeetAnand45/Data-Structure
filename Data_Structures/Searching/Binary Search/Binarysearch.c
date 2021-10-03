#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void binarysearch(int A[],int n,int item)
{
    int l=0,u=n-1,m;
    while(l<=u)
    {
        m=(l+u)/2;
        if(item==A[m])
        {
            printf("\nSEARCH SUCCESSFUL AT INDEX %d\n",m);
            return;
        }
        else if(item>A[m])
        {
            l=m+1;
        }
        else
        {
            u=m-1;
        }
    }
    printf("\nSEARCH UNSUCCESSFUL");
}
int main()
{
    int n,i;
    int data;
    printf("Enter the no of data you want to enter: ");
    scanf("%d",&n);
    int arr[n];
    // ={1,3,4,6,8,9,15,39,42};
    printf("Enter the Data of the array: ");
    for(i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    
    printf("\nENTER THE DATA TO BE SEARCHED: ");
    scanf("%d",&data);
    binarysearch(arr,n,data);

}


