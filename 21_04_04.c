#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	struct bst *left;
	struct bst *right;
}node;

node* create_tree(node *root)
{
	root=NULL;
	printf("Binary Search Tree is created\n");
	return root;
}

node* create(int d)
{
	node *t=(node *)malloc(sizeof(node));
	t->data=d;
	t->left=NULL;
	t->right=NULL;
	return t;
}


node* insert(node *t,int d)
{
	if(t== NULL)
		return create(d);
	if(d< t->data)
		t->left=insert(t->left,d);
	else
		t->right=insert(t->right,d);
	return t;
}

void preorder(node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	return;
}

void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	return;
}

void postorder(node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	return;
}

node* search(node *root,int d)
{
	if(root==NULL || root->data==d)
	return root;
	else if(d < root->data)
	return search(root-> left, d);
	else
	return search(root->right, d);	
}

node* min(node *root)
{
	node *t=root;
	while(t &&t->left!=NULL)
		t=t->left;
	return t;
}

node* deletenode(node *root,int d)
{
	node *t;
	if(root==NULL)
		return root;
	if(d < root->data)
		root->left= deletenode(root->left,d);
	else if(d > root->data)
		root->right=deletenode(root->right,d);
	else
	{
		if(root->left==NULL)
		{
			t=root->right;
			free(root);
			return t;	
		}
		if(root->right==NULL)
		{
			t=root->left;
			free(root);
			return t;
		}
		t=min(root->right);
		root->data=t->data;
		root->right=deletenode(root->right,t->data);	
	}
	return root;
}

int main()
{
	node *root;
	int ch,data;
	do
	{
		printf("\n------------MENU FOR BINARY SEARCH TREE----------------\n");
		printf("0.EXIT\n");
		printf("1.CREATE\n");
		printf("2.INSERT\n");		
		printf("3.PREORDER TRAVERSAL\n");
		printf("4.INORDER TRAVERSAL\n");
		printf("5.POSTORDER TRAVERSAL\n");
		printf("6.SEARCH\n");
		printf("7.DELETE\n");

		printf("------------------------------------------\n");
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
				break;
			case 1:
				root= create_tree(root);
				break;
			case 2:
				printf("Enter the data to be inserted: ");
				scanf("%d",&data);
				root = insert(root,data);
				printf("\n%d is inserted successfully!!!\n",data);
				break;
			case 3:
				printf("\nPreorder traversal : \n");
				preorder(root);
				break;
			case 4:
				printf("\nInorder traversal : \n");
				inorder(root);
				break;
			case 5:
				printf("\nPostorder traversal : \n");
				postorder(root);
				break;
			case 6:
				printf("\nEnter the data to be search: ");
				scanf("%d",&data);
				if(search(root,data))
					printf("\nValue found!!!\n");
				else
					printf("\nValue not found!!!");
				break;
			case 7:
				printf("\nEnter the data to be deleted: ");
				scanf("%d",&data);
				root=deletenode(root,data);
				printf("\n%d is deleted successfully!!!\n",data);
				break;
			default:
				printf("\nInvlid choice!!!\n");
				break;
		}
	}while(1);
	return(0);
}
