#include <stdio.h>
#include <stdlib.h>

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
    if (q->front==(q->rear+1)%q->size){
        printf("\nQueue overflow!\n");
        return;
    }
	if(q->front==-1)
	q->front=0;
	q->rear=(q->rear+1)%q->size;
    q->data[q->rear] = val;
	printf("\n%d is inserted into queue.\n",val);
}

int dequeue(queue *q){
	int val;
    if (q->front==-1){
       printf("\nQueue underflow!\n");
        return -1;
    }
    else{
    	val=q->data[q->front];
    	if(q->front==q->rear){
    		q->front=q->rear=-1;
		}
    	else{
    		q->front=(q->front+1)%q->size;
		}    	
	}
    return val;
}

void display(queue *q)
{
	int i;
	if (q->front==-1){
        printf("\nQueue is empty!\n");
        return;
    }
    else{
    	printf("\nQueue is: ");
		for(i=q->front;i!=q->rear;i=(i+1)%q->size)
			printf("%d ",q->data[i]);
		printf("%d\n",q->data[q->rear]);

	}	
}

int main()
{
	queue *q;
	int size,i,val;
	printf("Enter size of the circular queue: ");
	scanf("%d",&size);
	q=create(size);
	int ch;
	do{
		printf("\n------------MENU FOR CIRCULAR QUEUE----------------\n");
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
				enqueue(q,val);
				break;
			case 2:
				val=dequeue(q);
				if(val!=-1)
				printf("\n%d is deleted from queue.\n",val);
				break;
			case 3:
				display(q);
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid Choice!!!\n");		
		}	
	}while(1);
}
