#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
int tos = -1;
char stack[SIZE];

void push(char val){
    if (tos==SIZE-1){
        printf("\nStack overflow!\n");
        return;
    }
    stack[++tos] = val;
}

char pop(){
    if (tos==-1){
        printf("\nStack underflow! Invalid infix expression\n");
        exit(1);
    }
    return stack[tos--];
}

int is_matching(char c1,char c2)
{
	if(c1=='(' && c2==')')
	return 1;
	else if(c1=='{' && c2=='}')
	return 1;
	else if(c1=='[' && c2==']')
	return 1;
	else
	return 0;
}

int is_balanced(char exp[])
{
	int i;
	for(i=0;exp[i]!=0;i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		push(exp[i]);
		else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			if(tos==-1)
			return 0;
			else if(!is_matching(pop(),exp[i]))
			return 0;
		}
	}
	if(tos==-1)
	return 1;
	else
	return 0;
}

int main()
{
	char exp[SIZE];
	printf("Enter an expression in paranthesis: ");
	gets(exp);
	if(is_balanced(exp))
	printf("The expression is balanced.");
	else
	printf("The expression is not balanced.");
	return 0;
}
