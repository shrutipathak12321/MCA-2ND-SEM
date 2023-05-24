#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int **data;
	int front;
	int rear;
	int *start;
	int *end;
	int max_size;
	int size;
}queue;

void create(queue *p,int size)
{
	int i;
	p->max_size=size;
	p->front=-1;
	p->rear=-1;
	p->size=0;
	p->data=(int **)malloc(sizeof(int *)*p->max_size);
	for(i=0;i<p->max_size;i++)
	{
		p->data[i]=(int *)malloc(sizeof(int)*(p->max_size+1));
	}
	p->start=(int *)malloc(sizeof(int)*p->max_size);
	p->end=(int *)malloc(sizeof(int)*p->max_size);
	for(i=0;i<p->max_size;i++)
	{
		p->start[i]=-1;
		p->end[i]=-1;
	}
	return;
}

int isempty(queue p)
{
	if(p.front==-1&&p.rear==-1)
		return 1;
	return 0;
}

int isfull(queue p)
{
	if(p.max_size==p.size)
		return 1;
	return 0;
}

void enqueue(queue *q,int d,int p)
{
	int i,j,k;
	if(isfull(*q))
	{
		printf("Queue overflow\n");
		return;
	}
	else if(isempty(*q))
	{
		q->front=0;
		q->rear=0;
		q->start[0]=1;
		q->end[0]=1;
		q->data[0][0]=p;
		q->data[0][1]=d;
		printf("Enqueued successfully\n");
		q->size++;
		return;
	}
	//for 1st row
	if(p<q->data[q->front][0])
	{
		if(q->front==0)
		{
			for(i=q->rear;i>=q->front;i--)
			{
				q->start[i+1]=q->start[i];
				q->end[i+1]=q->end[i];
				for(j=0;j<=q->max_size;j++)
				{
					q->data[i+1][j]=q->data[i][j];
				}
			}
			q->rear++;
		}
		else
			q->front--;
		q->start[q->front]=1;
		q->end[q->front]=1;
		q->data[q->front][0]=p;
		q->data[q->front][1]=d;
		printf("Enqueued successfully\n");
		q->size++;
		return;
	}
	
	//for other rows
	for(k=q->front;k<=q->rear;k++)
	{
		if(p==q->data[k][0])
		{
			q->end[k]++;
			q->data[k][q->end[k]]=d;
			printf("Enqueued successfully\n");
			q->size++;
			return;
		}
		else if(p<q->data[k][0])
		{
			for(i=q->rear;i>=k;i--)
			{
				q->start[i+1]=q->start[i];
				q->end[i+1]=q->end[i];
				for(j=0;j<=q->max_size;j++)
				{
					q->data[i+1][j]=q->data[i][j];
				}
			}
			q->rear++;
			q->start[k]=1;
			q->end[k]=1;
			q->data[k][0]=p;
			q->data[k][1]=d;
			printf("Enqueued successfully\n");
			q->size++;
			return;
		}
	}
	q->rear++;
	q->start[k]=1;
	q->end[k]=1;
	q->data[k][0]=p;
	q->data[k][1]=d;
	printf("Enqueued successfully\n");
	q->size++;
	return;
}

int dequeue(queue *q,int *p)
{
	int t;
	if(isempty(*q))
	{
		printf("\nQueue underflow\n");
		*p=-1;
		return;
	}
	*p=q->data[q->front][0];
	t=q->data[q->front][q->start[q->front]];
	q->start[q->front]++;
	if(q->start[q->front]>q->end[q->front])
	{
		q->start[q->front]=-1;
		q->end[q->front]=-1;
		if(q->front==q->rear)
		{
			q->front=-1;
			q->rear=-1;
			q->size=0;
		}
		else
			q->front++;
	}
	return t;
}

int peek(queue q,int *p)
{
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		*p=-1;
		return;
	}
	*p=q.data[q.front][0];
	return(q.data[q.front][q.start[q.front]]);
}

void display(queue p)
{
	int i,j;
	if(isempty(p))
	{
		printf("\nQueue is empty\n");
		return;	
	}
	for(i=0;i<p.max_size;i++)
	{
		if(i<p.front||i>p.rear)
		{
			printf("");
		}
		else
		{
			printf("Priority = %d\tdata --->   ",p.data[i][0]);
			for(j=p.start[i];j<=p.end[i];j++)
			{
				printf("%d ",p.data[i][j]);
			}
			printf("\n");
		}
	}
	return;
}

int main()
{
	queue q;
	int ch,p,d,size;
	printf("Enter the size of the priority queue = ");
	scanf("%d",&size);
	create(&q,size);
	do
	{
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
				printf("Enter data = ");
				scanf("%d",&d);
				printf("Enter the priority = ");
				scanf("%d",&p);
				enqueue(&q,d,p);
				break;
			case 2:
				d=dequeue(&q,&p);
				if(p!=-1)
					printf("\nDeleted highest priority(%d) element %d from queue.\n",p,d);
				break;
			case 3:
				d=peek(q,&p);
				if(p!=-1)
					printf("\nElement with highest priority(%d) = %d\n\n",p,d);
				break;
			case 4:
				display(q);
				break;
			default:
				printf("\nInvalid Choice!!!\n");
				break;
		}
	}while(1);
	free(q.data);
	return(0);
}

