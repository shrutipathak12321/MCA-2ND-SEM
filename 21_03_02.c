#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int *data;
	int tos;
	int size;
}stack;

stack* create(int s){
	stack *st=(stack *)malloc(sizeof(stack));
	st->data=(int *)malloc(sizeof(int)*s);
	st->tos=-1;
	st->size=s;
	return st;
}

void push(stack *s,int val){
    if (s->tos==s->size-1){
        printf("\nStack overflow!\n");
        return;
    }
    s->data[++s->tos] = val;
	printf("\n%d is pushed into stack.\n",val);
}

int pop(stack *s){
    if (s->tos==-1){
        printf("\nStack underflow!\n");
        return -1;
    }
    return s->data[s->tos--];
}

void display(stack *s)
{
	int i;
	if (s->tos==-1){
        printf("\nStack is empty!\n");
        return;
    }
    else{
		for(i=s->tos;i>=0;i--)
			printf("\n\t|\t%d\t|",s->data[i]);
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
		printf("Enter the size of stack %d:",i);
		scanf("%d",&size);
		s[i-1]=create(size);
		printf("Stack - %d created!",i);
		do{
			printf("\n------------MENU FOR STACK %d----------------\n",i);
			printf("0.Exit\n");
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
				case 0:
					exit(0);
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
