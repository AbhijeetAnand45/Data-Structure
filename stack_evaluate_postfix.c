/* NAME : ABHIJEET ANAND
   ROLL : 19103001
   PROGRAM : 11 EVALUATE POSTFIX EXPRESSION */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


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


int eval(char expr[])
{
    struct ArrayStack *stack=createstack(strlen(expr));
    int i;

    int op1,op2;
    for(i=0;(expr[i])!='\0';i++)
    {
        if(isdigit(expr[i]))
            push(stack,expr[i]-'0');
        else
        {
            op2=pop(stack);
            op1=pop(stack);

            switch(expr[i])
            {
             case '+':
                 push(stack,op1+op2);
                 break;
             case '-':
                push(stack, op1-op2);
                break;
             case '*':
                 push(stack,op1*op2);
                 break;
             case '/':
                 push(stack,op1/op2);
                 break;
             case '^':
                 push(stack,pow(op1,op2));
                 break;
            }

        }
    }
    return(pop(stack));
}
int main()
{
    printf("\nPLEASE ENTER POSTFIX EXPRESSION WITHOUT SPACES: ");
    char str[50]; 
    gets(str); 
    
    // char expr[] = "623+-382/+*2^3+";
    printf ("\nPOSTFIX EVALUATION IS: %d\n", eval(str));
    return 0;
}


