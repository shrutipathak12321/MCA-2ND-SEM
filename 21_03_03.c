#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *data;
	int tos;
	int size;
}stack;

void push(stack *s,int val){
    if (s->tos==s->size-1){
        printf("\nStack overflow!\n");
        return;
    }
    s->data[++s->tos] = val;
//	printf("\n%d is pushed into stack.\n",val);
}

stack* create(FILE *file){
	stack *st=(stack *)malloc(sizeof(stack));
	st->data=(int *)malloc(sizeof(int)*100);
	st->tos=-1;
	st->size=100;
	int n;
	while(fscanf(file,"%d",&n)!= EOF)
		push(st,n);
	return st;
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
int main()
{
	FILE *file=fopen("data.txt","r");
	stack *s=create(file);
	display(s);
	return 0;
}
