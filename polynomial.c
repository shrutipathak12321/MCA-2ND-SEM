#include<stdio.h>
#include<stdlib.h>
typedef struct polynomial
{
	int coef;
	int exp;
	struct polynomial *link;
}poly;

void insert_term(poly **start,int c,int e)
{  
	poly *temp,*temp1,*prev;
	if (*start==NULL)
	{
		temp=(poly*)malloc(sizeof(poly));
		if (temp==NULL)
		printf("Node is not created, Term cannot be inserted\n");
	
		else
		{ 
			temp->coef=c;	
		   	temp->exp=e;	
		   	temp->link=NULL;	
		   	*start=temp;
	  	}
	}
	else
	{ 
		temp1=*start;
	  	while (temp1!=NULL && temp1->exp>e)		
		{		
		   prev=temp1;		
		   temp1=temp1->link;		
		}
		if(temp1==NULL)
	  	{		
		   	temp=(poly *)malloc(sizeof(poly));		
		   	if (temp==NULL)		
			printf("Node is not created\n");
		
	  		else
			{ 
				temp->coef=c;
			    temp->exp=e;				
			    temp->link=NULL;				
			    prev->link=temp;		
	   		}
		}

  		else
  		{ 
		  	if(temp1->exp==e)
    		temp1->coef=temp1->coef+c;

  			else
			{ 
				if(temp1==*start)
    			{  
					temp=(poly *)malloc (sizeof (poly));
				    if(temp==NULL)
					printf("Node is not created\n");
					else				
				    { 
						temp->coef=c;				
				      	temp->exp=e;				
				      	temp->link=*start;				
				      	*start=temp;
				
				    } 
				}

    			else
   				{ 
				   	temp=(poly *)malloc(sizeof(poly));
				    if (temp==NULL)				
				    printf("Node is not created\n");				
				    else				
					{ 
						temp->coef=c;					
					    temp->exp=e;					
					    temp->link=temp1;					
					    prev->link=temp;
				
				    }
				}
			}
  		}
  	}
}
void traverse(poly *start)
{
	poly *temp;
	temp=start;
	if(temp==NULL)
	printf("Empty polynomial\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%dx^%d",temp->coef,temp->exp);
			temp=temp->link;
			if(temp!=NULL)
			{
				if(temp->coef>=0)
				printf("+");
			}
			
			else
			printf("\n");
		}
	}
}
void poly_add(poly **first,poly **second,poly **result)
{
	int c,e;
	poly *fptr,*sptr;
	*result=NULL;
	fptr=*first;
	sptr=*second;
	while(fptr!=NULL && sptr!=NULL)
	{
		if(fptr->exp==sptr->exp)
		{
			c=fptr->coef+sptr->coef;
			e=fptr->exp;
			insert_term(result,c,e);
			fptr=fptr->link;
			sptr=sptr->link;
		}
		else
		{
			if(fptr->exp>sptr->exp)
			{
				c=fptr->coef;
				e=fptr->exp;
				insert_term(result,c,e);
				fptr=fptr->link;
			}
			else
			{
				c=sptr->coef;
				e=sptr->exp;
				insert_term(result,c,e);
				sptr=sptr->link;
			}
		}
	}
	while(fptr!=NULL)
	{
		c=fptr->coef;
		e=fptr->exp;
		insert_term(result,c,e);
		fptr=fptr->link;
	}
	while(sptr!=NULL)
	{
		c=sptr->coef;
		e=sptr->exp;
		insert_term(result,c,e);
		sptr=sptr->link;
	}
	
}

void poly_sub(poly **first,poly **second,poly **result)
{
	int c,e;
	poly *fptr,*sptr;
	*result=NULL;
	fptr=*first;
	sptr=*second;
	while(fptr!=NULL && sptr!=NULL)
	{
		if(fptr->exp==sptr->exp)
		{
			c=fptr->coef-sptr->coef;
			e=fptr->exp;
			insert_term(result,c,e);
			fptr=fptr->link;
			sptr=sptr->link;
		}
		else
		{
			if(fptr->exp>sptr->exp)
			{
				c=fptr->coef;
				e=fptr->exp;
				insert_term(result,c,e);
				fptr=fptr->link;
			}
			else
			{
				c=-sptr->coef;
				e=sptr->exp;
				insert_term(result,c,e);
				sptr=sptr->link;
			}
		}
	}
	while(fptr!=NULL)
	{
		c=fptr->coef;
		e=fptr->exp;
		insert_term(result,c,e);
		fptr=fptr->link;
	}
	while(sptr!=NULL)
	{
		c=-sptr->coef;
		e=sptr->exp;
		insert_term(result,c,e);
		sptr=sptr->link;
	}
}
void poly_pdt(poly **first,poly **second,poly **result)
{
	int c,e;
	poly *fptr,*sptr;
	*result=NULL;
	fptr=*first;
	sptr=*second;
	if(*first==NULL &&  *second==NULL)
	printf("\nMultiplication of polynomial is not possible!\n");
	else{
		while(fptr!=NULL)
		{
			sptr=*second;
			while(sptr!=NULL)
			{
				c=fptr->coef*sptr->coef;
				e=fptr->exp+sptr->exp;
				insert_term(result,c,e);
				sptr=sptr->link;
			}
			fptr=fptr->link;
		}			
	}
}


int main()
{
	poly *first=NULL,*second=NULL,*result=NULL;
	int ch,i,n,c,e;
	printf("Enter first polynomial! \n");
	printf("Enter no of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter coefficient: ");
		scanf("%d",&c);
		printf("Enter exponent: ");
		scanf("%d",&e);
		insert_term(&first,c,e);
	}
	printf("Enter second polynomial! \n");
	printf("Enter no of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter coefficient: ");
		scanf("%d",&c);
		printf("Enter exponent: ");
		scanf("%d",&e);
		insert_term(&second,c,e);
	}
	printf("First Polynomial: ");
	traverse(first);
	printf("Second Polynomial: ");
	traverse(second);
	while(1)
	{
		printf("\n------------------ Menu for polynomial ----------------\n");
		printf("0.Exit\n");
		printf("1.Add\n");
		printf("2.Subtract\n");
		printf("3.Multiply\n");
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				poly_add(&first,&second,&result);
				printf("Sum of the two polynomial: ");
				traverse(result);
				result=NULL;
				break;
			
			case 2:
				poly_sub(&first,&second,&result);
				printf("Subtraction of the two polynomial: ");
				traverse(result);
				result=NULL;
				break;
			
			case 3:
				poly_pdt(&first,&second,&result);
				printf("Multiplication of the two polynomial: ");
				traverse(result);
				result=NULL;
				break;
				
		}
	}
}	
