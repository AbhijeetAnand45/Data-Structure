/*stack implementation using SMA*/
#include<stdio.h>
#define CAPACITY 5
int stack[CAPACITY];
int top=-1;
void push(int );
int pop();
int isFull();
int isEmpty();
void peek();
void traverse();
void main()
{
    while(1)
    {
        int ele,item;
        int ch;
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. traverse\n");
        printf("4. peek\n");
        printf("5. quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            item=pop();
            if(item==-1)
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("popped value is %d\n",item);
            }
            break;
        case 3:
            traverse();
            break;
        case 4:
            peek(); /*to find top element*/
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input\n");


        }
    }
}
void push(int item)
{
    if(isFull())
    {
        printf("stack is full\n");
    }
    else
    {
        top++;
        stack[top]=item;
        printf("%d is inserted\n",item);
    }
}
int isFull()
{
    if(stack[top]==CAPACITY-1)
    {
        return 1;
    }
    else
        return 0;
}
int pop()
{
   int item;
   if(isEmpty())
   {
       return -1;
   }
   else
   {
       item=stack[top];
       top--;
       return(item);
   }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek()
{
    if(isEmpty())
        printf("stack is empty");
    else
    {
        printf("peak element is %d\n",stack[top]);
    }
}
void traverse()
{
    if(isEmpty())
        printf("stack is empty");
    else{
        int i;
        printf("stack elements are: \n");
        for(i=0;i<=top;i++)
            printf("%d \n",stack[i]);
    }
}
