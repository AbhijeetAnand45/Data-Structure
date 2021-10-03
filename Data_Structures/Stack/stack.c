//stack using DMA
#include<stdio.h>
#include<stdlib.h>
struct ArrayStack
{
    int top;
    unsigned capacity;
    int *array;
};
struct ArrayStack * createstack(int cap)
{
    struct ArrayStack *stack;
    stack=malloc(sizeof(struct ArrayStack));

    stack->capacity=cap;
    stack->top=-1;
    stack->array=malloc(sizeof(int)*stack->capacity);

    return stack;
};
int isFull(struct ArrayStack *stack)
{
    if(stack->top==stack->capacity-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct ArrayStack *stack)
{
    if(stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct ArrayStack *stack,int item)
{
    if(!isFull(stack))
    {
        stack->top++;
        stack->array[stack->top]=item;
    }
}
int pop(struct ArrayStack *stack)
{
    int item;
    if(!isEmpty(stack))
    {
        item=stack->array[stack->top];
        stack->top--;
        return(item);
    }
    return -1;
}
void traverse(struct ArrayStack *stack)
{
    int i;
    if(isEmpty(stack))
    {
        printf("No element\n");
    }
    else
    {
        printf("stack elements are:\n");
        for(i=0;i<=stack->top;i++)
            printf("%d ",stack->array[i]);
    }

}
int main()
{
    int choice,item;
    struct ArrayStack *stack;
    stack=createstack(4);
    while(1)
    {
        printf("\n1,push");
        printf("\n2,pop");
        printf("\n3,view stack");
        printf("\n4,exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d",&item);
            push(stack,item);
            break;
        case 2:
            item=pop(stack);
            if(item==-1)
                 printf("stack is empty");
            else
                printf("popped value is %d",item);
            break;
        case 3:
            traverse(stack);
            break;
        case 4:
            exit(0);
        }
    }
}
