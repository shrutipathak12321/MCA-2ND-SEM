#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *front,*rear;

void enqueue(int val){
	node *ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	printf("\nStack Overflow\n");
	else{
		ptr->data=val;
		ptr->next=NULL;
		if(front == NULL)
		{
			front=ptr;
			rear=ptr;
		}
		else{
			rear->next=ptr;
			rear=ptr;
		}
	}
	printf("\n%d is pushed into queue.\n",val);
}

int dequeue(){
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
	    free(temp);
    	return val;
	}
    
}

void display()
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

int main(){
	int ch,val;
	do{
		printf("\n------------MENU FOR QUEUE----------------\n");
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
				enqueue(val);
				break;
			case 2:
				val=dequeue();
				if(val!=-1)
				printf("\n%d is deleted from queue.\n",val);
				break;
			case 3:
				display();
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid Choice!!!\n");		
		}	
	}while(1);
	
    return 0;   
}
