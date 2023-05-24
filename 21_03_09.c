#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int rear = -1;
int front = -1;

int queue[SIZE];

void enqueue(int val){
    if (rear==SIZE-1){
        printf("\nQueue overflow!\n");
        return;
    }
	if(front==-1)
	front=0;
	queue[++rear]=val;
	printf("\n%d is inserted into queue.\n",val);
}

int dequeue(){
    if (front==-1 || front>rear){
        printf("\nQueue underflow!\n");
        return -1;
    }
    return queue[front++];
}

void display()
{
	int i;
	if (front==-1 || front>rear){
        printf("\nQueue is empty!\n");
        return;
    }
    else{
    	printf("\nQueue is: ");
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
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
