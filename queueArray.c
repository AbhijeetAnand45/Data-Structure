#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int capacity;
    int front,rear;
    int *array;
};
struct Queue *createqueue(int capacity)
{
    struct Queue *Q=malloc(sizeof(struct Queue));
    if(!Q) return NULL;
    Q->capacity=capacity;
    Q->front=-1;
    Q->rear=-1;
    Q->array=malloc(Q->capacity*sizeof(int));
    if(!Q->array)
       return NULL;
    return Q;
}
int isEmptyqueue(struct Queue *Q)
{
    return(Q->front==-1);
}
// int isFullqueue(struct Queue *Q)
// {
//     return(Q->rear==Q->capacity);
// }
void enqueue(struct Queue *Q,int data)
{
   
    if(isFullqueue(Q))
         printf("Overflow\n");
    else{
        Q->rear=(Q->rear+1)%Q->capacity;
        Q->array[Q->rear]=data;
        if(Q->front==-1)
        {
            Q->front=Q->rear;
        }
        
    }
}
int dequeue(struct Queue *Q)
{
    int data=-1;
    if(isEmptyqueue(Q))
    {
        printf("Queue is Empty\n");
        return (-1);
    }
    else{
        data=Q->array[Q->front];
        if(Q->front==Q->rear)
        {
            Q->front=Q->rear=-1;
        }
        else{
            Q->front=(Q->front+1)%Q->capacity;
        }
    
    }
    return data;
}
void traversequeue(struct Queue *Q)
{
    int i;
    if(Q->front==Q->rear)
        printf("queue is empty\n");
    else
    {
        printf("elements of queue are: ");
        for(i=0;i < Q->rear+1;i++)
        {
            printf("%d ",Q->array[i]);
        }
    }
}
int main()
{
    int cap;
    struct Queue *Q;
    int ch,item,n;
    printf("Please Enter the capacity of your array: ");
    scanf("%d",&cap);
    Q=createqueue(cap);

    while(1)
    {
        printf("\n1. insert in queue");
        printf("\n2. delete the element of queue");
        printf("\n3. display the element of queue");
        printf("\n4. quit the loop\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the item/data to insert: ");
            scanf("%d",&item);
            enqueue(Q,item);
            break;
        case 2:
            n=dequeue(Q);
            if(n==-1)
             {
               printf("Queue is UnderFlow!!\n");

             }
             else{
               printf("Popped value is %d\n",n);
             }
            break;
        case 3:
            traversequeue(Q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
        }
    }
}
// #include<stdio.h>
// #include<stdlib.h>
// #define CAPACITY 5
// int front=0,rear=0;
// int queue[CAPACITY];
// void insertqueue()
// {
//     int ele;
//     printf("enter the element to insert: ");
//     scanf("%d",&ele);
//     if(rear==CAPACITY)
//     {
//         printf("queue is full\n");
//     }
//     else
//     {
//         queue[rear]=ele;
//         rear++;
//     }
// }
// void deletequeue()
// {
//     int i;
//     if(front==rear)
//         printf("queue is empty\n");
//     else
//     {
//         printf("deleted : %d\n",queue[front]);
//         for(i=0;i<rear-1;i++)
//         {
//             queue[i]=queue[i+1];
//         }
//         rear--;
//     }
// }
// void traversequeue()
// {
//     int i;
//     if(front==rear)
//         printf("queue is empty\n");
//     else
//     {
//         printf("elements of queue are: ");
//         for(i=0;i<rear;i++)
//         {
//             printf("%d ",queue[i]);
//         }
//     }
// }
// int main()
// {
//     int ch;

//     while(1)
//     {
//         printf("\n1. insert in queue");
//         printf("\n2. delete the element of queue");
//         printf("\n3. display the element of queue");
//         printf("\n4. quit the loop\n");
//         printf("Enter your choice: ");
//         scanf("%d",&ch);
//         switch(ch)
//         {
//         case 1:
//             insertqueue();
//             break;
//         case 2:
//             deletequeue();
//             break;
//         case 3:
//             traversequeue();
//             break;
//         case 4:
//             exit(0);
//             break;
//         default:
//             printf("invalid input\n");
//         }
//     }
// }