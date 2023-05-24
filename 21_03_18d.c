#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	struct node *next;
}node;

typedef struct pqueue{
	int p;
	struct pqueue *n;
	node *e;
}pq;

typedef struct{
	pq *front;
	pq *rear;
}queue;

void create_queue(queue *p)
{
	p->front=NULL;
	p->rear=NULL;
}

int isempty(queue p)
{
	if(p.front==NULL && p.rear==NULL)
		return 1;
	return 0;
}

node * create_node(int d)
{
	node *c=(node *)malloc(sizeof(node));
	c->data=d;
	c->next=NULL;
	return c;
}

pq * create_node_priority(int d)
{
	pq *c=(pq *)malloc(sizeof(pq));
	c->p=d;
	c->n=NULL;
	c->e=NULL;
	return c;
}

void enqueue(queue *q)
{
	int n,p,f=0;
	pq *c,*a=q->front;
	node *t,*b;
	printf("Enter data: ");
	scanf("%d",&n);
	printf("Enter the priority = ");
	scanf("%d",&p);
	c=create_node_priority(p);
	t=create_node(n);
	if(isempty(*q))
	{
		q->front=c;
		q->rear=c;
		c->e=t;
		printf("Enqueued successfully\n");
		return;
	}
	
	//For 1st node priority
	if(a->p==p)
	{
		b=a->e;
		while(b->next!=NULL)
			b=b->next;
		b->next=t;
		printf("Enqueued successfully\n");
		return;
	}
	else if(a->p>p)
	{
		c->n=a;
		q->front=c;
		c->e=t;
		printf("Enqueued successfully\n");
		return;
	}
	
	while(a->n!=NULL)
	{
		if(a->n->p==p)
		{
			f=1;
			a=a->n;
			break;
		}
		else if(a->n->p>p)
			break;
		a=a->n;
	}
	//f=1 for equal priority
	if(f==1)
	{
		b=a->e;
		while(b->next!=NULL)
			b=b->next;
		b->next=t;
		printf("Enqueued successfully\n");
		return;
	}
	//f=0 for new priority insert after a
	c->n=a->n;
	a->n=c;
	c->e=t;
	if(c->n==NULL)
		q->rear=c;
	printf("\nEnqueued successfully\n");
	return;
}

node * dequeue(queue *q,int *i)
{
	node *c;
	if(isempty(*q))
	{
		printf("\nQueue Underflow\n");
		return(NULL);
	}
	*i=q->front->p;
	c=q->front->e;
	q->front->e=c->next;
	if(q->front->e==NULL)
		q->front=q->front->n;
	if(q->front==NULL)
		q->rear=NULL;
	return(c);
}

node * get_front(queue q,int *i)
{
	node *c;
	if(isempty(q))
	{
		printf("\nQueue is empty\n");
		return(NULL);
	}
	*i=q.front->p;
	c=q.front->e;
	return(c);
}

void display(queue p)
{
	pq *c=p.front;
	node *t;
	if(isempty(p))
	{
		printf("\nQueue is empty\n");
		return;	
	}
	while(c!=NULL)
	{
		printf("Priority = %d\tdata ---->  ",c->p);
		t=c->e;
		while(t!=NULL)
		{
			printf("%d   ",t->data);
			t=t->next;
		}
		printf("\n");
		c=c->n;
	}
	return;
}

int main()
{
	queue q;
	int ch,i;
	node *p;
	create_queue(&q);
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
				enqueue(&q);
				break;
			case 2:
				if((p=dequeue(&q,&i))!=NULL)
					printf("\nDeleted highest priority(%d) element %d from queue.",i,p->data);
				break;
			case 3:
				if((p=get_front(q,&i))!=NULL)
					printf("\nElement with highest priority(%d) = %d\n",i,p->data);
				break;
			case 4:
				display(q);
				break;
			default:
				printf("\nInvalid Choice!!!\n");
				break;
		}
	}while(1);
	return 0;
}

