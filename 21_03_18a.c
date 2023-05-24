#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	int pri;
}element;

typedef struct{
	element *ele;
	int front;
	int rear;
	int size;
}queue;

int isempty(queue *q)
{
	if(q->front==-1 || q->front>q->rear)
		return 1;
	return 0;
}

int isfull(queue *q)
{
	if(q->rear==q->size-1)
		return 1;
	return 0;
}

queue* create(int size)
{
	queue *q=(queue *)malloc(sizeof(queue));
	q->ele=(element *)malloc(sizeof(element)*size);
	q->front=-1;
	q->rear=-1;
	q->size=size;
	return q;
}

void enqueue(queue *q,element d)
{
	int i,j;
	if(isfull(q))
	{
		printf("\nQueue overflow\n");
		return;
	}
	else if(isempty(q))
	{
		q->front=0;
		q->rear=0;
		q->ele[q->rear]=d;
		return;
	}
	for(i=q->rear;i>=q->front;i--)
	{
		if(d.pri>=q->ele[i].pri)
			break;
	}
	for(j=q->rear;j>i;j--)
	{
		q->ele[j+1]=q->ele[j];
	}
	q->ele[i+1]=d;
	printf("\n%d inserted into queue with priority %d\n",d.data,d.pri);
	q->rear++;
	return;
}

element dequeue(queue *q)
{
	element d;
	d.pri=-1;
	if(isempty(q))
	{
		printf("\nQueue underflow\n");
		return(d);
	}
	d=q->ele[q->front];
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
		q->front++;
	return(d);
}

element peek(queue *q)
{
	element d;
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		return(d);
	}
	d=q->ele[q->front];
	return d;
}

void display(queue *q)
{
	int i,j;
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		return;	
	}
	printf("\nThe Priority Queue:\n");
	printf("\nPriority\tData\n");
	printf("-------------------------\n");
	for(i=0;i<q->size;i++)
	{
		if(i<q->front||i>q->rear)
		printf("");
		else
		printf("%d\t\t%d\n",q->ele[i].pri,q->ele[i].data);
	}
	printf("-------------------------\n");
	return;
}

int main()
{
	queue *q;
	element e;
	int ch,data,size;
	printf("Enter size of the priority queue: ");
	scanf("%d",&size);
	q=create(size);
	do{
		printf("\n------------MENU FOR PRIORITY QUEUE-------------\n");
		printf("0.Exit\n");
		printf("1.ENQUEUE\n");
		printf("2.DEQUEUE\n");
		printf("3.PEEK\n");
		printf("4.DISPLAY\n");
		printf("------------------------------------------------\n");
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				printf("Enter data: ");
				scanf("%d",&e.data);
				printf("Enter the priority: ");
				scanf("%d",&e.pri);
				enqueue(q,e);
				break;
			case 2:
				e=dequeue(q);
				if(e.pri!=-1)
					printf("\nDeleted highest priority(%d) element %d from queue.\n",e.data,e.pri);
				break;
			case 3:
				e=peek(q);
				if(e.pri!=-1)
					printf("\nElement with highest priority(%d) = %d\n",e.pri,e.data);
				break;
			case 4:
				display(q);
				break;
			default:
				printf("\nInvalid Choice!!!\n");
				break;
		}
	}while(1);
	free(q->ele);
	return(0);
}

