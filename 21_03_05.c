#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node{
	int info;
	struct node *next;
}node;

typedef struct {
	node *data;
	node *tos;
	int size;
}stack;

int count=0;
stack* create(){
	stack *st=(stack *)malloc(sizeof(stack));
	st->tos=NULL;
	return st;
}

void push(stack *s,int val){
	node *temp;
 	if (s->tos == NULL)
    {
        s->tos =(node *)malloc(sizeof(node));
        s->tos->next = NULL;
        s->tos->info = val;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->next = s->tos;
        temp->info = val;
        s->tos = temp;
    }
    count++;
	printf("\n%d is pushed into stack.\n",val);
}

int pop(stack *s){
    node *temp = s->tos;
 
    if (temp == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
    temp = temp->next;
    int val = s->tos->info;
    free(s->tos);
    s->tos = temp;
    count--;
    return val;
}

void display(stack *s)
{
	node *temp = s->tos;

	if (temp==NULL){
        printf("\nStack is empty!\n");
        return;
    }
    else{
		while(temp!=NULL){
			printf("\n\t|\t%d\t|",temp->info);
			temp=temp->next;
		}
		printf("\n\t-----------------\n");

	}	
}

int main(){
	int ch,val,n,i,size,num,c;
	stack *s[MAX];
	printf("Enter no of stack you want to create(MAX = 10): ");
	scanf("%d",&n);
	do{
		printf("Enter the stack number: ");
		scanf("%d",&i);
		s[i-1]=create();
		do{
			printf("\n------------MENU FOR STACK %d----------------\n",i);
			printf("1.PUSH\n");
			printf("2.POP\n");
			printf("3.DISPLAY\n");
			printf("------------------------------------------\n");
			printf("\nEnter any choice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\nEnter a value: ");
					scanf("%d",&val);
					push(s[i-1],val);
					break;
				case 2:
					val=pop(s[i-1]);
					if(val!=-1)
					printf("\n%d is popped from stack.\n",val);
					break;
				case 3:
					display(s[i-1]);
					break;

				default:
					printf("\nInvalid Choice!!!\n");		
			}
			printf("\nDo you want to continue operation on this stack?(1 or 0): ");
		scanf("%d",&c);
		}while(c);	
			
	printf("\nDo you want to swich in another stack (1 or 0): ");
	scanf("%d",&c);
	}while(c);
	
    return 0;   
}
