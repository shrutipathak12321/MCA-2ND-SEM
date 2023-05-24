#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}node;

node *front,*rear;

void enqueue_front(int val){
	node *ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	printf("\nStack Overflow\n");
	else{
		ptr->data=val;
		ptr->prev=NULL;
		ptr->next=NULL;
		if(front == NULL)
		{
			front=ptr;
			rear=ptr;
		}
		else{
			ptr->next=front;
			front->prev=ptr;
			front=ptr;
		}
	}
}

void enqueue_rear(int val){
	node *ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	printf("\nStack Overflow\n");
	else{
		ptr->data=val;
		ptr->prev=NULL;
		ptr->next=NULL;
		if(front == NULL)
		{
			front=ptr;
			rear=ptr;
		}
		else{
			rear->next=ptr;
			ptr->prev=rear;
			rear=ptr;
		}
	}
}

int dequeue_front(){
    node *temp = front;
 	int val;
    if (temp == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else{
    	val = temp->data;
	   	front = front->next;
	   	front->prev=NULL;
	    free(temp);
    	return val;
	}
    
}

int dequeue_rear(){
    node *temp = rear;
 	int val;
    if (temp == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else{
    	val = temp->data;
	   	rear = rear->prev;
	   	rear->next=NULL;
	    free(temp);
    	return val;
	}
    
}

void display_forward()
{
	node *temp = front;

	if (temp==NULL){
        printf("\nQueue is empty!\n");
        return;
    }
    else{
    	printf("\nQueue is: ");
		while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
		}
		printf("\n");
	}	
}

void display_backward()
{
	node *temp = rear;

	if (temp==NULL){
        printf("\nQueue is empty!\n");
        return;
    }
    else{
    	printf("\nReversed queue is: ");
		while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->prev;
		}
		printf("\n");
	}	
}

int main(){
	int ch,val;
	do{
		printf("\n------------MENU FOR DOUBLE ENDED QUEUE----------------\n");
		printf("0.Exit\n");
		printf("1.ENQUEUE AT FRONT\n");
		printf("2.ENQUEUE AT REAR\n");
		printf("3.DEQUEUE AT FRONT\n");
		printf("4.DEQUEUE AT REAR\n");
		printf("5.FORWARD DISPLAY\n");
		printf("6.BACKWARD DISPLAY\n");
		printf("------------------------------------------\n");
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter a value: ");
				scanf("%d",&val);
				enqueue_front(val);
				printf("\n%d is pushed into the front of the queue.\n",val);
				break;
			case 2:
				printf("\nEnter a value: ");
				scanf("%d",&val);
				enqueue_rear(val);
				printf("\n%d is pushed into the rear of the queue.\n",val);
				break;
			case 3:
				val=dequeue_front();
				if(val!=-1)
				printf("\n%d is deleted from the front of the queue.\n",val);
				break;
			case 4:
				val=dequeue_rear();
				if(val!=-1)
				printf("\n%d is deleted from the rear of the queue.\n",val);
				break;
			case 5:
				display_forward();
				break;
			case 6:
				display_backward();
				break;			
			case 0:
				exit(0);
			default:
				printf("\nInvalid Choice!!!\n");		
		}	
	}while(1);
	
    return 0;   
}
