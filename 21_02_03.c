#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *prev,*next;
}node;
node *head=NULL,*tail=NULL;

void create()
{
	int n,d,i;
	node *newnode;
	if(head==NULL)
	{
		printf("\nEnter number of nodes: ");
		scanf("%d",&n);
		if(n!=0)
		{
			newnode=(node*)malloc(sizeof(node));
			head=newnode;
			tail=head;
			printf("\nEnter data to be inserted: ");
			scanf("%d",&d);
			head->data=d;
			head->prev=NULL;
			head->next=NULL;
			for(i=2;i<=n;i++)
			{
				newnode=(node*)malloc(sizeof(node));
				printf("Enter data to be inserted: ");
				scanf("%d",&d);
				newnode->data=d;
				newnode->prev=tail;
				newnode->next=NULL;
				tail->next=newnode;
				tail=newnode;
			}
			printf("\nThe list is created.\n");
		}
		
	}
	else
	printf("\nThe list is already craeted!\n");
}

void display()
{
	node* temp;
	if(head==NULL)
	printf("List is empty");
	else{
		temp=head;
		printf("\nThe values of the list: ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	printf("\n");	
	}
}

void insert_front()
{
	int d;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted at front: ");
	scanf("%d",&d);
	temp->data=d;
	temp->prev=NULL;
	temp->next=head;
	head=temp;
	printf("\nInserted successfully\n");
}
void insert_end()
{
	int d;
	node *temp,*ptr=head;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted at end: ");
	scanf("%d",&d);
	temp->data=d;
	temp->next=NULL;
	temp->prev=tail;
	tail->next=temp;
	tail=temp;
	
	printf("\nInserted successfully\n");
}

void insert_after()
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted after kth node: ");
	scanf("%d",&d);
	printf("Enter value of k: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=head;
	while(i<k){
		ptr=ptr->next;
		i++;
	}
	temp->prev=ptr;
	temp->next=ptr->next;
	ptr->next=temp;	
	printf("\nInserted successfully\n");
}
void insert_before()
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted before kth node: ");
	scanf("%d",&d);
	printf("Enter value of k: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=head;
	while(i<k-1){
		ptr=ptr->next;
		i++;
	}
	temp->prev=ptr;
	temp->next=ptr->next;
	ptr->next=temp;	
	printf("\nInserted successfully\n");
}
void insert_aftervalue()
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted: ");
	scanf("%d",&d);
	printf("Enter the value after which you want to insert: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=head;
	while(ptr->data!=k && ptr!=NULL){
		ptr=ptr->next;
	}
		temp->prev=ptr;
		temp->next=ptr->next;
		ptr->next=temp;	
		printf("\nInserted successfully\n");

}
void insert_beforevalue()
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted: ");
	scanf("%d",&d);
	printf("Enter the value before which you want to insert: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=head;
	while(ptr->next->data!=k && ptr!=NULL){
		ptr=ptr->next;
	}
		temp->prev=ptr;
		temp->next=ptr->next;
		ptr->next=temp;	
		printf("\nInserted successfully\n");
}
void delete_front()
{
	node *temp;
	if(head==NULL)
	printf("List is empty\n");
	else{
		temp=head;
		head=head->next;
		free(temp);
		printf("\nDeleted Successfully\n");
	}
}
void delete_end()
{
	node *temp;
	if(head==NULL)
	printf("List is empty\n");
	else{
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(temp);
		printf("\nDeleted Successfully\n");
	}
}
void delete_after()
{
	int i=1,k;
	node *temp,*ptr;
	if(head==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter value of k: ");
		scanf("%d",&k);
		temp=head;
		while(i<=k){
			ptr=temp;
			temp=temp->next;
			i++;
		}
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
		printf("\nDeleted Successfully\n");		
	}
}
void delete_before()
{
	int i=1,k;
	node *temp,*ptr;
	if(head==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter value of k: ");
		scanf("%d",&k);
		temp=head;
		while(i<k-1){
			ptr=temp;
			temp=temp->next;
			i++;
		}
		ptr->next=temp->next;
		temp->next->prev=ptr;
		free(temp);
		printf("\nDeleted Successfully\n");		
	}
}
void delete_node()
{
	int i=1,k;
	node *temp,*ptr;
	if(head==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter value of k: ");
		scanf("%d",&k);
		temp=head;
		while(i<k){
			ptr=temp;
			temp=temp->next;
			i++;
		}
		temp->next->prev=ptr;
		ptr->next=temp->next;
		free(temp);
		printf("\nDeleted Successfully\n");		
	}
}
void delete_value()
{
	int i=1,k;
	node *temp,*ptr;
	if(head==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter the value which you want to delete: ");
		scanf("%d",&k);
		temp=head;
		while(temp->data!=k && temp!=NULL){
			ptr=temp;
			temp=temp->next;
		}
			temp->next->prev=ptr;
			ptr->next=temp->next;
			free(temp);
			printf("\nDeleted Successfully\n");		
	}
}
void reverse()
{
	node *curr=head,*temp=NULL;
	if(head==NULL)
	printf("List is empty\n");
	else{
		while(curr!=NULL)
		{
			temp=curr->next;
			curr->next=curr->prev;
			curr->prev=temp;
			curr=temp;
		}
		temp=head;
		head=tail;
		tail=temp;
		printf("\nReversed Successfully\n");				
	}
}

int main()
{
	int n,ch,val,k;
	while(1)
	{
		printf("\n---------------MENU FOR DOUBLY LINKED LIST--------------\n");
		printf("0.Exit\n");
		printf("1.Create\n");
		printf("2.Display\n");
		printf("3.Insert at front\n");
		printf("4.Insert at end\n");
		printf("5.Insert after kth node\n");
		printf("6.Insrt after the node containing a given value\n");
		printf("7.Insert before kth node\n");
		printf("8.Insrt before the node containing a given value\n");
		printf("9.Delete first node\n");
		printf("10.Delete last node\n");
		printf("11.Delete after kth node\n");
		printf("12.Delete before kth node\n");
		printf("13.Delete the kth node\n");
		printf("14.Delete the node containing a specified value\n");
		printf("15.Reverse\n");
		
		
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0:
				exit(0);
			case 1: 
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_front();
				break;
			case 4:
				insert_end();
				break;
			case 5:				
				insert_after();
				break;
			case 6:
				insert_aftervalue();
				break;
			case 7:
				insert_before();
				break;			
			case 8:
				insert_beforevalue();
				break;
			case 9:
				delete_front();
				break;
			case 10:
				delete_end();
				break;
			case 11:
				delete_after();
				break;
			case 12:
				delete_before();
				break;
			case 13: 
				delete_node();
				break;
			case 14:
				delete_value();
				break;
			case 15:
				reverse();
				break;
			default:
				printf("\nYou have entered a wrong choice!!!\n");

		}		
	}
	return 0;
}
