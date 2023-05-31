#include<stdio.h>
#include<stdlib.h>

void create(int *a,int n,int i)
{
	int d,ch;
	if(i<n)
	{
		printf("\nEnter the data of the node: ");
		scanf("%d",&d);
		a[i]=d;
		printf("\nDo you want to add left child of %d (Enter 1 for yes or 0 for no) : ",a[i]);
		scanf("%d",&ch);
		if(ch)
			create(a,n,2*i+1);
		printf("\nDo you want to add right child of %d (Enter 1 for yes or 0 for no) : ",a[i]);
		scanf("%d",&ch);
		if(ch)
			create(a,n,2*i+2);
	}
	else
		printf("Array is full\n");
	return;
}

void preorder(int *a,int n,int i)
{
	if(i>=n)
		return;
	printf("%d  ",a[i]);
	preorder(a,n,2*i+1);
	preorder(a,n,2*i+2);
	return;
}

void inorder(int *a,int n,int i)
{
	if(i>=n)
		return;
	inorder(a,n,2*i+1);
	printf("%d  ",a[i]);
	inorder(a,n,2*i+2);
	return;
}

void postorder(int *a,int n,int i)
{
	if(i>=n)
		return;
	postorder(a,n,2*i+1);
	postorder(a,n,2*i+2);
	printf("%d  ",a[i]);
	return;
}

int main(){
	int ch,val,n,i;
	int *root= NULL;
	do{
		printf("\n------------MENU FOR BINARY TREE----------------\n");
		printf("0.EXIT\n");
		printf("1.CREATE\n");		
		printf("2.INORDER TRAVERSAL\n");
		printf("3.PREORDER TRAVERSAL\n");
		printf("4.POSTORDER TRAVERSAL\n");
		printf("------------------------------------------\n");
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter no of nodes in the binary tree: ");
				scanf("%d",&n);
				root=(int *)malloc(sizeof(int)*n);
				create(root,n,0);
				printf("\nBinary tree created successfully\n");
				break;
			case 2:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				printf("\nInorder Traversal: \n");
				inorder(root,n,0);
				break;
			case 3:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				printf("\nPreorder Traversal: \n");
				preorder(root,n,0);
				break;
			case 4:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				printf("\nPostorder Traversal: \n");
				postorder(root,n,0);
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid Choice!!!\n");		
		}	
	}while(1);
	
    return 0;   
}	
