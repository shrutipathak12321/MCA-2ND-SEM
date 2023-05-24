#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int *data;
	int rear;
	int front;
	int size;
}queue;

queue* create(int q_size){
	queue *q=(queue *)malloc(sizeof(queue));
	q->data=(int *)malloc(sizeof(int)*q_size);
	q->front=-1;
	q->rear=-1;
	q->size=q_size;
	return q;
}

void enqueue(queue *q,int val){
    if (q->rear==q->size-1){
        printf("\nQueue overflow!\n");
        return;
    }
	if(q->front==-1)
	q->front=0;
    q->data[++q->rear] = val;
	printf("\n%d is inserted into queue.\n",val);
}

int dequeue(queue *q){
    if (q->front==-1 || q->front>q->rear){
        printf("\nQueue underflow!\n");
        return -1;
    }
    return q->data[q->front++];
}

void display(queue *q)
{
	int i;
	if (q->front==-1 || q->front>q->rear){
        printf("\nQueue is empty!\n");
        return;
    }
    else{
    	printf("\nQueue is: ");
		for(i=q->front;i<=q->rear;i++)
			printf("%d ",q->data[i]);
		printf("\n");

	}	
}

int main(){
	int ch,val,n,i,size,num,c;
	queue *q[MAX];
	printf("Enter no of queue you want to create(MAX = 10): ");
	scanf("%d",&n);
	do{	
		printf("Enter the queue number: ");
		scanf("%d",&i);
		printf("Enter the size of queue %d:",i);
		scanf("%d",&size);
		q[i-1]=create(size);
		printf("Queue - %d created!",i);
		do{
			printf("\n------------MENU FOR QUEUE %d----------------\n",i);
			printf("0.Exit\n");
			printf("1.ENQUEUE\n");
			printf("2.DEQUEUE\n");
			printf("3.DISPLAY\n");
			printf("------------------------------------------\n");
			printf("\nEnter any choice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\nEnter a value: ");
					scanf("%d",&val);
					enqueue(q[i-1],val);
					break;
				case 2:
					val=dequeue(q[i-1]);
					if(val!=-1)
					printf("\n%d is deleted from queue.\n",val);
					break;
				case 3:
					display(q[i-1]);
					break;
				case 0:
					exit(0);
				default:
					printf("\nInvalid Choice!!!\n");		
			}	
			printf("\nDo you want to continue operation on this queue?(1 or 0): ");
			scanf("%d",&c);
		}while(c);	
			
		printf("\nDo you want to swich in another queue (1 or 0): ");
		scanf("%d",&c);
	}while(c);
    return 0;   
}
