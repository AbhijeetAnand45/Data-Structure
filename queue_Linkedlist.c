// EXPERIMENT-10 IMPLEMENTATION OF SIMPLE QUEUE USING LINKED LIST
/* NAME: ABHIJEET ANAND
   ROLL : 19103001
   EXP-10 */
#include <stdio.h> 
#include <stdlib.h> 
     /* STRUCTURE OF LINKED LIST */
struct Node { 
	int data; 
	struct Node* next; 
}; 
    // INITIALISATION OF FRONT AND REAR OF QUEUE
struct Node *front=NULL;
struct Node *rear=NULL;
 
       //CREATING NEW NODE
struct Node* createNode(int k) 
{ 
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->data = k; 
	temp->next = NULL; 
	return temp; 
} 

      //INSERTING ELEMENT INTO QUEUE
void enQueue(int k) 
{  
	struct Node* temp = createNode(k); 

	if (front == NULL && rear==NULL) { 
		front = rear = temp; 
		return; 
	} 

	rear->next = temp; 
	rear = temp; 
} 

    // DELETING ELEMENT FROM QUEUE
void deQueue() 
{ 
    struct Node* temp = front;
	
	if (front == NULL)
    {
        printf("QUEUE IS EMPTY!");
        return;

    } 
		
    if(front==rear)
    {
        front=rear=NULL;
    }
	else{
        front = front->next;

    } 
	
	free(temp); 
} 
    /* VIEWING THE QUEUE */
void viewQueue()
{
    struct Node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
    }
    else{
        temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

    /* MAIN FUNCTION */
int main() 
{
    int ch,x;
    while(1)
    {
        printf("\n1. to insert element in queue");
        printf("\n2. to delete element from queue");
        printf("\n3. to view queue");
        printf("\n4. to exit loop");
        printf("\n\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nENTER ELEMENT TO INSERT IN QUEUE: ");
            scanf("%d",&x);
            enQueue(x);
            break;
            case 2:
            deQueue();
            break;
            case 3:
            viewQueue();
            break;
            case 4:
            exit(0);
            default:
            printf("\nPLEASE ENTER A VALID CHOICE\n");

        }
    }
	 
	return 0;
} 
