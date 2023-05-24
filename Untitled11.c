#include<stdio.h>
#include<stdlib.h>


typedef struct{
	int *data[2];
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
	q->data[0]=(int *)malloc(sizeof(int)*size);
	q->data[1]=(int *)malloc(sizeof(int)*size);
	q->front=-1;
	q->rear=-1;
	q->size=size;
	return q;
}

void enqueue(queue *q,int d,int p)
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
		q->data[q->rear][0]=p;
		q->data[q->rear][1]=p;
		return;
	}
	for(i=q->rear;i>=q->front;i--)
	{
		if(q->data[q->front][0]>=q->data[i][0])
			break;
	}
	for(j=q->rear;j>i;j--)
	{
		q->data[j+1]=q->data[j];
	}
	q->data[i+1][0]=p;
	q->data[i+1][1]=d;
	printf("\n%d inserted into queue with priority %d\n",q->data[1],q->data[0]);
	q->rear++;
	return;
}

int dequeue(queue *q,int *p)
{
	int t;
	if(isempty(q))
	{
		printf("\nQueue underflow\n");
		*p=-1;
		return *p;
	}
	*p=q->data[q->front][0];
	if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
		q->front++;
	return *p;
}

int peek(queue *q,int *p)
{
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		*p=-1;
		return *p;
	}
	*p=q->data[q->front][0];
	return *p;
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
		printf("%d\t\t%d\n",q->data[i][0],q->data[i][1]);
	}
	printf("-------------------------\n");
	return;
}

int main()
{
	queue *q;
	int ch,d,p,size;
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
				scanf("%d",&d);
				printf("Enter the priority: ");
				scanf("%d",&p);
				enqueue(q,d,p);
				break;
			case 2:
				d=dequeue(q,&p);
				if(p!=-1)
					printf("\nDeleted highest priority(%d) element %d from queue.\n",d,p);
				break;
			case 3:
				d=peek(q,&p);
				if(p!=-1)
					printf("\nElement with highest priority = %d\n",d);
				break;
			case 4:
				display(q);
				break;
			default:
				printf("\nInvalid Choice!!!\n");
				break;
		}
	}while(1);
	return(0);
}

