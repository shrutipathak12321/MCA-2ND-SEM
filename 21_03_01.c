#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int tos = -1;
int stack[SIZE];

void push(int val){
    if (tos==SIZE-1){
        printf("\nStack overflow!\n");
        return;
    }
    stack[++tos] = val;
	printf("\n%d is pushed into stack.\n",val);
}

int pop(){
    if (tos==-1){
        printf("\nStack underflow!\n");
        return -1;
    }
    return stack[tos--];
}

void display()
{
	int i;
	if (tos==-1){
        printf("\nStack is empty!\n");
        return;
    }
    else{
		for(i=tos;i>=0;i--)
			printf("\n\t|\t%d\t|",stack[i]);
		printf("\n\t-----------------\n");

	}	
}

int main(){
	int ch,val;
	do{
		printf("\n------------MENU FOR STACK----------------\n");
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
				push(val);
				break;
			case 2:
				val=pop();
				if(val!=-1)
				printf("\n%d is popped from stack.\n",val);
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
