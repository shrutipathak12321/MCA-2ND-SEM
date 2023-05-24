#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

int is_operator(char c)
{
	if(c=='^' || c=='*' || c=='/' || c=='+' || c=='-' )
	return 1;
	else
	return 0;
}

int precedence(char c)
{
	if(c=='^')
	return 3;
	else if(c=='*' || c=='/')
	return 2;
	else if(c=='+' || c=='-' )
	return 1;
	else 
	return 0;
}

void InfixToPostfix(char infix[],char postfix[])
{
	int i=0,j=0;
	char item;
	char c;
	push('(');
	strcat(infix,")");
	item=infix[i];
	while(item != '\0')
	{
		if(item=='(')
		push(item);
		else if(isdigit(item) || isalpha(item))
		postfix[j++]=item;
		else if(is_operator(item))
		{
			c=pop();
			while(is_operator(c)==1 && precedence(c) >= precedence(item)){
				postfix[j++]=c;
				c=pop();
			}
			push(c);
			push(item);			
		}
		else if(item==')')
		{
			c=pop();
			while(c!='(')
			{
				postfix[j++]=c;
				c=pop();
			}
		}
		else{
			printf("Invalid infix expression!!!");
			exit(1);
		}
		i++;
		item=infix[i];
	}
	
	if(tos>0)
	{		
		printf("Invalid infix expression!!!");
		exit(1);		
	}
	postfix[j]='\0';
}

int main()
{
	char infix[SIZE],postfix[SIZE];
	printf("Enter Infix expression(only five operators(+,-,*,/,^) and operand must be single digit or single character only): ");
	gets(infix);
	InfixToPostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);
	return 0;
}
