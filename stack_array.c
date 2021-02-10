 
 /* DYNAMIC IMPLEMENTATION OF STACK USING ARRAY */

 /* EXPERIMENT - 7 IMPLEMENT OF STACK USING ARRAY
   NAME : ABHIJEET ANAND
   ROLL : 19103001   */

#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
  /*CREATING STACK*/
struct Stack *createstack(int cap)
{
    struct Stack *stack;
    stack=malloc(sizeof(struct Stack));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=malloc(sizeof(int)*stack->capacity);
    return stack;
}
int isfull(struct Stack *stack)
{
    if(stack->top==stack->capacity-1)
       return 1;
    else
       return 0;
}
int isEmpty(struct Stack *stack)
{
    if(stack->top==-1)
      return 1;
    else return 0;
}
   /* INSERTING ELEMENT INTO STACK */
void push(struct Stack *stack,int item)
{
    if(!isfull(stack))
    {
        stack->top++;
        stack->array[stack->top]=item;
    }
    else{
        printf("\nStack is overflow");
        return;
    }
}
  /*DELETING ELEMENT FROM STACK*/
int pop(struct Stack *stack)
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
   /* VIEWING ELEMENTS OF STACK */
void traverse(struct Stack *stack)
{
    
    int i;
    if(isEmpty(stack))
    {
        printf("NO ELEMENT\n");
    }
    else{
        printf("\nSTACK ELEMENTS ARE: ");
        for(i=0;i<=stack->top;i++)
        {
            printf("%d ",stack->array[i]);
        }
    }
}

    /* MAIN FUNCTION */
int main()
{
    struct Stack *stack;
    int n,ch,item;
    
    printf("\nPlease enter the size of stack you want to create: ");
    scanf("%d",&n);
    stack=createstack(n);
    while (1)
    {
       printf("\n\n1. To push");
       printf("\n2. To pop ");
       printf("\n3. To traverse");
       printf("\n4. To exit");
       printf("\n5. IsEmpty");
       printf("\n6. Isfull");
       printf("\nPlease Enter your choice: ");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1:
             printf("\nEnter the item/data to push: ");
             scanf("%d",&item);
             push(stack,item);
             break;
           case 2:
             item=pop(stack);
             if(item==-1)
             {
               printf("stack is UnderFlow!!\n");

             }
             else{
               printf("Popped value is %d\n",item);
             }
             break;
            case 3:
              traverse(stack);
              break;
            case 4:
              exit(0);
            case 5:
              if(isEmpty(stack))
              {
                  printf("Stack is empty!!\n");
              }
              else{
                  printf("Stack is partially filled!!\n");
              }
              break;
            case 6:
              if(isfull(stack))
              {
                  printf("Stack is full!");
              }
              else{
                  printf("stack is not full,you can insert element!");
              }
              break;
            default:
              printf("\nInvalid Choice");

       }
    }
    

}