#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100
int tos = -1;
char stack[SIZE];

void push(int val){
    if (tos==SIZE-1){
        printf("\nStack overflow!\n");
        return;
    }
    stack[++tos] = val;
}

int pop(){
    if (tos==-1){
        printf("\nStack underflow! Invalid postfix expression\n");
        exit(1);
    }
    return stack[tos--];
}

void PostfixEvaluation(char postfix[])
{
	int i,val,a,b;
	char item;
	for(i=0;postfix[i]!='\0';i++)
	{
		item=postfix[i];
		if(isdigit(item))
			push(item-'0');
		else if(item=='+' || item=='-' || item=='*' || item=='/')
		{
			a=pop();
			b=pop();
			switch(item)
			{
				case '+':
					val=b+a;
					break;
				case '-':
					val=b-a;
					break;
				case '*':
					val=b*a;
					break;
				case '/':
					val=b/a;
					break;
			}
			push(val);
		}		
	}
	if(tos>0)
	{		
		printf("\nInvalid postfix expression!!!");
		exit(1);		
	}
	printf("\nThe result of postfix evaluation is: %d",val);
}
int main()
{
	char postfix[SIZE];
	printf("Enter postfix expression(only four operators(+,-,*,/) and operand must be single digit only): ");
	gets(postfix);
	PostfixEvaluation(postfix);
	return 0;
}
