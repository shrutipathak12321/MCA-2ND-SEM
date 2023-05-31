#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	}node;

void inorder(node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}	

void preorder(node *root)
{
	if(root==NULL)
	return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
	
void postorder(node *root)
{
	if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}


node* create()
{
	node *t;
	int ch;
	t=(node *)malloc(sizeof(node));
	printf("\nEnter the data of the node: ");
	scanf("%d",&t->data);
	printf("\nDo you want to add left child of %d (Enter 1 for yes or 0 for no) : " ,t->data);
	scanf("%d",&ch);
	if(ch)
		t->left=create();
	else
		t->left=NULL;
	printf("\nDo you want to add right child of %d (Enter 1 for yes or 0 for no) : ",t->data);
	scanf("%d",&ch);
	if(ch)
		t->right=create();
	else
		t->right=NULL;
	return t;
}

int main(){
	int ch,val;
	node* root;
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
				root=create(root);
				break;
			case 2:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				printf("\nInorder Traversal: \n");
				inorder(root);
				break;
			case 3:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				printf("\nPreorder Traversal: \n");
				preorder(root);
				break;
			case 4:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				printf("\nPostorder Traversal: \n");
				postorder(root);
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid Choice!!!\n");		
		}	
	}while(1);
	
    return 0;   
}	
