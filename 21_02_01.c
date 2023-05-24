#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* head=NULL,*first=NULL,*second=NULL,*result=NULL;

node* create(node* list)
{
	int n,d,i;
	node *newnode,*temp;
	if(list==NULL)
	{
		printf("\nEnter number of nodes: ");
		scanf("%d",&n);
		if(n!=0)
		{
			newnode=(node*)malloc(sizeof(node));
			list=newnode;
			temp=list;
			printf("\nEnter data to be inserted: ");
			scanf("%d",&d);
			list->data=d;
			for(i=2;i<=n;i++)
			{
				newnode=(node*)malloc(sizeof(node));
				temp->next=newnode;
				printf("Enter data to be inserted: ");
				scanf("%d",&d);
				newnode->data=d;
				temp=temp->next;
			}
			temp->next=NULL;
			printf("\nThe list is created.\n");
		}
		
	}
	else
	printf("\nThe list is already craeted!\n");	
	return list;
}

void display(node *list)
{
	node* temp;
	if(list==NULL)
	printf("List is empty");
	else{
		temp=list;
		printf("\nThe values of the list: ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	printf("\n");	
	}
}

node* insert_front(node *list)
{
	int d;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted at front: ");
	scanf("%d",&d);
	temp->data=d;
	temp->next=list;
	list=temp;
	printf("\nInserted successfully\n");
	return list;
}
node* insert_end(node *list)
{
	int d;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted at end: ");
	scanf("%d",&d);
	temp->data=d;
	temp->next=NULL;
	ptr=list;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
	printf("\nInserted successfully\n");
	return list;
}
node * insert_after(node *list)
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted after kth node: ");
	scanf("%d",&d);
	printf("Enter value of k: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=list;
	while(i<k){
		ptr=ptr->next;
		i++;
	}
	temp->next=ptr->next;
	ptr->next=temp;	
	printf("\nInserted successfully\n");
	return list;
}
node * insert_before(node *list)
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted before kth node: ");
	scanf("%d",&d);
	printf("Enter value of k: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=list;
	while(i<k-1){
		ptr=ptr->next;
		i++;
	}
	temp->next=ptr->next;
	ptr->next=temp;	
	printf("\nInserted successfully\n");
	return list;
}
node* insert_aftervalue(node *list)
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted: ");
	scanf("%d",&d);
	printf("Enter the value after which you want to insert: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=list;
	while(ptr->data!=k && ptr!=NULL){
		ptr=ptr->next;
	}
		temp->next=ptr->next;
		ptr->next=temp;	
		printf("\nInserted successfully\n");
	return list;

}
node* insert_beforevalue(node *list)
{
	int d,k,i=1;
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	printf("\nEnter data to be inserted: ");
	scanf("%d",&d);
	printf("Enter the value before which you want to insert: ");
	scanf("%d",&k);
	temp->data=d;
	ptr=list;
	while(ptr->next->data!=k && ptr!=NULL){
		ptr=ptr->next;
	}
	
		temp->next=ptr->next;
		ptr->next=temp;	
		printf("\nInserted successfully\n");
	return list;
}
node* delete_front(node *list)
{
	node *temp;
	if(list==NULL)
	printf("List is empty\n");
	else{
		temp=list;
		list=list->next;
		free(temp);
		printf("\nDeleted Successfully\n");

	}
	return list;
}
node* delete_end(node * list)
{
	node *temp,*prev;
	if(list==NULL)
	printf("List is empty\n");
	else{
		temp=list;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		free(temp);
		printf("\nDeleted Successfully\n");
	}
		return list;	
}
node* delete_after(node *list)
{
	int i=1,k;
	node *temp,*prev;
	if(list==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter value of k: ");
		scanf("%d",&k);
		temp=list;
		while(i<=k){
			prev=temp;
			temp=temp->next;
			i++;
		}
		prev->next=temp->next;
		free(temp);
		printf("\nDeleted Successfully\n");		
	}
	return list;	
}
node* delete_before(node *list)
{
	int i=1,k;
	node *temp,*prev;
	if(list==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter value of k: ");
		scanf("%d",&k);
		temp=list;
		while(i<k-1){
			prev=temp;
			temp=temp->next;
			i++;
		}
		prev->next=temp->next;
		free(temp);
		printf("\nDeleted Successfully\n");		
	}
	return list;	
}
node* delete_node(node *list)
{
	int i=1,k;
	node *temp,*prev;
	if(list==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter value of k: ");
		scanf("%d",&k);
		temp=list;
		while(i<k){
			prev=temp;
			temp=temp->next;
			i++;
		}
		prev->next=temp->next;
		free(temp);
		printf("\nDeleted Successfully\n");		
	}
	return list;	
}
node* delete_value(node *list)
{
	int i=1,k;
	node *temp,*prev;
	if(list==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter the value which you want to delete: ");
		scanf("%d",&k);
		temp=list;
		while(temp->data!=k && temp!=NULL){
			prev=temp;
			temp=temp->next;
		}
			prev->next=temp->next;
			free(temp);
			printf("\nDeleted Successfully\n");		
	}
	return list;	
}
node* reverse(node *list)
{
	node *t1,*t2,*temp;
	t1=t2=NULL;
	if(list==NULL)
	printf("List is empty\n");
	else{
		while(list!=NULL)
		{
			t2=list->next;
			list->next=t1;
			t1=list;
			list=t2;
		}
		list=t1;
		printf("\nReversed Successfully\n");				
	}
	return list;
}
node* sort(node* list)
{
	node *curr=list, *index=NULL;
	int temp;
	if(list==NULL)
	printf("List is empty\n");
	else{
		while(curr!=NULL)
		{
			index=curr->next;
			while(index!=NULL)
			{
				if(curr->data>index->data)
				{
					temp=curr->data;
					curr->data=index->data;
					index->data=temp;
				}
				index=index->next;
			}			
			curr=curr->next;
		}
		printf("\nSorted Successfully\n");				

	}
	return list;
}
void search(node* list)
{
	int k,i=0;
	node* temp=list;
	if(list==NULL)
	printf("List is empty\n");
	else{
		printf("\nEnter the element you want to search: ");
		scanf("%d",&k);
		printf("%d is present at index/indices: ",k);
		while(temp!=NULL)
		{
			if(temp->data==k){
			printf("%d ",i);
			}
			i++;
			temp=temp->next;
		}
		printf("\n");
	}		
}
void merge(node* first,node* second)
{
	node *last=NULL;
	if(first->data<second->data)
	{
		result=last=first;
		first=first->next;
		last->next=NULL;
	}
	else
	{
		result=last=second;
		second=second->next;
		last->next=NULL;
	}
	while(first!=NULL && second!=NULL)
	{
		if(first->data<second->data)
		{
			last->next=first;
			last=first;
			first=first->next;
			last->next=NULL;
		}
		else{
			last->next=second;
			last=second;
			second=second->next;
			last->next=NULL;
		}
	}
	if(first!=NULL)
	last->next=first;
	else
	last->next=second;
	printf("\nAfter merge, ");
	display(result);
}
void concatenate(node* first,node* second)
{
	node *temp;
	temp=first;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=second;
	printf("\nAfter concatenation, ");
	display(first);
}
int isequal(node* first,node* second)
{
	while(first!=NULL && second!=NULL)
	{
		if(first->data != second->data)
		return 0;
		first=first->next;
		second=second->next;		
	}
	return (first==NULL && second==NULL);
}

int main()
{
	int n,ch,val,k;
	while(1)
	{
		printf("\n---------------MENU FOR SINGLY LINKED LIST---------------\n");
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
		printf("16.Sort\n");
		printf("17.Search a given element\n");
		printf("18.Merge two list(those are in ascending order)\n");
		printf("19.Concatenate two list\n");
		printf("20.Find if two lists are equal or not\n");
		
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 0:
				exit(0);
			case 1: 
				head=create(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				head=insert_front(head);
				break;
			case 4:
				head=insert_end(head);
				break;
			case 5:				
				head=insert_after(head);
				break;
			case 6:
				head=insert_aftervalue(head);
				break;
			case 7:
				head=insert_before(head);
				break;
			case 8:
				head=insert_beforevalue(head);
				break;
			case 9:
				head=delete_front(head);
				break;
			case 10:
				head=delete_end(head);
				break;
			case 11:
				head=delete_after(head);
				break;
			case 12:
				head=delete_before(head);
				break;
			case 13: 
				head=delete_node(head);
				break;
			case 14:
				head=delete_value(head);
				break;
			case 15:
				head=reverse(head);
				break;
			case 16:
				head=sort(head);
				break;
			case 17:
				search(head);
				break;
			case 18:
				printf("\nFirst list: \n");
				first=create(first);
				printf("Second list: \n");
				second=create(second);			
				merge(first,second);
				first=second=NULL;
				break;
			case 19:
				printf("\nFirst list: \n");
				first=create(first);
				printf("Second list: \n");
				second=create(second);	
				concatenate(first,second);
				first=second=NULL;
				break;
			case 20:
				printf("\nFirst list: \n");
				first=create(first);
				printf("Second list: \n");
				second=create(second);
				if(isequal(first,second))	
				printf("\nThe lists are equal\n");
				else
				printf("\nThe lists are not equal\n");
				first=second=NULL;
				break;
			default:
				printf("\nYou have entered a wrong choice!!!\n");

		}		
	}
	return 0;
}
