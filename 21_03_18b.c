#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	int pri;
	struct node *next;
	
}element;

typedef struct{
	element *front;
	element *rear;
}queue;

int isempty(queue *q)
{
	if(q->front==NULL && q->rear==NULL)
		return 1;
	return 0;
}

queue* create()
{
	queue *q=(queue*)malloc(sizeof(queue));
	q->front=NULL;
	q->rear=NULL;
	return q;
}
element* createnode(int d,int p)
{
	element *e=(element *)malloc(sizeof(element));
	e->data=d;
	e->pri=p;
	e->next=NULL;
	return e;
}
void enqueue(queue *q,element *d)
{
	element *c=q->front;
	if(isempty(q))
	{
		q->front=d;
		q->rear=d;
		return;
	}
	if(d->pri<c->pri)
	{
		d->next=c;
		q->front=d;
		return;
	}
	while(c->next!=NULL && d->pri>=c->next->pri)
		c=c->next;
	d->next=c->next;
	c->next=d;
	printf("\n%d inserted into queue with priority %d\n",d->data,d->pri);
	return;
}

element* deletefirst(element **e)
{
	element *c=*e;
	*e=(*e)->next;
	return c;
}

element* dequeue(queue *q)
{
	int f=0;
	element *d;
	if(isempty(q))
	{
		printf("\nQueue underflow\n");
		return NULL;
	}
	else if(q->front==q->rear)
	f=1;
	d=deletefirst(&q->front);
	if(f==1)
		q->rear=NULL;
	return(d);
}

element* peek(queue *q)
{
	element *e;
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		return(NULL);
	}
	e=q->front;
	return e;
}

void display(queue *q)
{
	element *e=q->front;
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		return;	
	}
	printf("\nThe Priority Queue:\n");
	printf("\nPriority\tData\n");
	printf("-------------------------\n");
	while(e!=NULL)
	{
		printf("%d\t\t%d\n",e->pri,e->data);
		e=e->next;
	}
	printf("-------------------------\n");
	return;
}

int main()
{
	queue *q;
	element *e;
	int ch,d,p;
	q=create();
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
				e=createnode(d,p);
				enqueue(q,e);
				break;
			case 2:
				e=dequeue(q);
				if(e!=NULL)
					printf("\nDeleted highest priority(%d) element %d from queue.\n",e->data,e->pri);
				break;
			case 3:
				e=peek(q);
				if(e!=NULL)
					printf("\nElement with highest priority(%d) = %d\n",e->pri,e->data);
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

