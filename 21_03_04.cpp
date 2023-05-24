#include <stdio.h>
#include <stdlib.h>

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

bool is_equal(stack *a,stack *b)
{
	int i,j=0;
	if(a->size!=b->size)
		return false;
	for(i=0;i<=a->tos;i++)
	{
		if(a->data[i]!=b->data[j++]){
			return false;
		}	
	}
	return true;	
}

int main()
{
	stack *a,*b;
	int size1,size2,i,val;
	printf("Enter size for first stack: ");
	scanf("%d",&size1);
	a=create(size1);
	for(i=1;i<=size1;i++)
	{
		printf("\nEnter value: ");
		scanf("%d",&val);
		push(a,val);
	}
	display(a);
	
	printf("\nEnter size for second stack: ");
	scanf("%d",&size2);	
	b=create(size2);
	for(i=1;i<=size2;i++)
	{
		printf("\nEnter value: ");
		scanf("%d",&val);
		push(b,val);
	}
	display(b);

	if(is_equal(a,b))
	printf("\nThe stacks are equal!!!");
	else
	printf("\nThe stacks are not equal!!!");	
}
