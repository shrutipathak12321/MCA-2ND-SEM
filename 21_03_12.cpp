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

bool is_equal(queue *a,queue *b)
{
	int i,j=0;
	if(a->size!=b->size)
		return false;
	for(i=0;i<=a->rear;i++)
	{
		if(a->data[i]!=b->data[j++]){
			return false;
		}	
	}
	return true;	
}

int main()
{
	queue *x,*y;
	int size1,size2,i,val;
	printf("Enter size for first queue: ");
	scanf("%d",&size1);
	x=create(size1);
	for(i=1;i<=size1;i++)
	{
		printf("\nEnter value: ");
		scanf("%d",&val);
		enqueue(x,val);
	}
	printf("\nFirst ");
	display(x);
	
	printf("\nEnter size for second queue: ");
	scanf("%d",&size2);	
	y=create(size2);
	for(i=1;i<=size2;i++)
	{
		printf("\nEnter value: ");
		scanf("%d",&val);
		enqueue(y,val);
	}
	printf("\nSecond ");
	display(y);
	
	if(is_equal(x,y))
	printf("\nThe queues are equal!!!");
	else
	printf("\nThe queues are not equal!!!");		
	return 0;
}
