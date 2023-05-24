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
    if (q->rear==q->size-1){
        printf("\nQueue overflow!\n");
        return;
    }
	if(q->front==-1)
	q->front=0;
    q->data[++q->rear] = val;
//	printf("\n%d is inserted into queue.\n",val);
}

int dequeue(queue *q){
    if (q->front==-1 || q->front>q->rear){
       printf("\nQueue underflow!\n");
        return -1;
    }
    q->size--;
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
    	printf("queue is: ");
		for(i=q->front;i<=q->rear;i++)
			printf("%d ",q->data[i]);
		printf("\n");

	}	
}

queue* replace(queue *q,int e,int x)
{
	int i;
	for(i=0;i<=q->rear;i++)
	{
		if(q->data[i]==e){
			q->data[i]=x;
		}	
	}
	return q;	
}

int main()
{
	queue *q;
	int size,i,val,e,x;
	printf("Enter size of the queue: ");
	scanf("%d",&size);
	q=create(size);
	for(i=1;i<=size;i++)
	{
		printf("\nEnter value: ");
		scanf("%d",&val);
		enqueue(q,val);
	}
	printf("\n");
	display(q);
	printf("\nEnter the element(e) you want to replace: ");
	scanf("%d",&e);
	printf("\nEnter the element(x) you want to replace with: ");
	scanf("%d",&x);
	q=replace(q,e,x);
	printf("\nAfter replace %d with %d, ",e,x);
	display(q);
	return 0;
}
