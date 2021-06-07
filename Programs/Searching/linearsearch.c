#include<stdio.h>
void linearsearch(int A[],int n,int item)
{
    int i;
    int flag=1;
    for(i=0;i<n;i++)
    {
        if(A[i]==item)
        {
            printf("Search successful");
            flag=0;
            return;
        }
    }
    if(flag==1)
    {
        printf("Search unsuccessful");
    }

}
int main()
{
    int n,i,item;
    printf("\n Please Enter size of array: ");
    scanf("%d",&n);
    int A[n];
    printf("Please Enter data of Array:");
    for(i=0;i<n;i++)
    {
        scanf(" %d",&A[i]);
    }
    printf("please enter the item to be searched: ");
    scanf("%d",&item);
    linearsearch(A,n,item);
    return 0;
}
