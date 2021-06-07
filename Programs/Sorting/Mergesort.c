#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int a[],int l[],int r[],int leftcount, int rightcount)
{
    int i=0,j=0,k=0;
    while(i<leftcount && j<rightcount)
    {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<leftcount)
    {
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<rightcount)
    {
        a[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int n)
{
    int mid,i,*l,*r;
    if(n<2)
        return;
    mid=n/2;
    l=(int *)malloc((mid) * sizeof(int));
    r=(int *)malloc((n-mid) * sizeof(int));
    for(i=0;i<mid;i++)
        l[i]=a[i];
    for(i=mid;i<n;i++)
        r[i-mid]=a[i];
    mergesort(l,mid);
    mergesort(r,n-mid);
    merge(a,l,r,mid,n-mid);
    free(l);
    free(r);
}
int main()
{
    int i=0,n;
    clock_t start,end;
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
    start = clock();
    mergesort(A,n);
    end = clock();
    printf("\nAfter sorting Elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    double duration = (double)(start - end);
    printf("Time Taken : %f", duration);
    return 0;
}


