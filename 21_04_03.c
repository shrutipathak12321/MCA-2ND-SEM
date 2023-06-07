#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ThreadedBT{
	int data;
	struct ThreadedBT *left;
	struct ThreadedBT *right;
	bool l;
	bool r;
}node;

node * create(node *p,int i)
{
	node *t,*c;
	int ch;
	if(p==NULL)
	{
		p=(node *)malloc(sizeof(node));
		p->data=-999;
		p->l=false;
		p->r=false;
		p->right=p;
		p->left=p;
		p->left=create(p,0);
		return p;
	}
	else
	{
		t=(node *)malloc(sizeof(node));
		printf("Enter data = ");
		scanf("%d",&t->data);
		t->l=true;
		t->r=true;
		if(i==0)
		{
			t->left=p->left;
			t->right=p;
		}
		else
		{
			t->left=p;
			t->right=p->right;
		}
		printf("\nDo you want to add left child of %d (Enter 1 for yes or 0 for no) : ",t->data);
		scanf("%d",&ch);
		if(ch)
		{
			t->left=create(t,0);
			t->l=false;
		}
		printf("\nDo you want to add right child of %d (Enter 1 for yes or 0 for no) : ",t->data);
		scanf("%d",&ch);
		if(ch)
		{
			t->right=create(t,1);
			t->r=false;
		}
	}
	return t;
}

void preorder(node *p)
{
	node *t=p->left;
	while(t!=p)
	{
		while(t->l==false)
		{
			printf("%d  ",t->data);
			t=t->left;
		}
		printf("%d  ",t->data);
		while(t->r==true)
		{
			t=t->right;
			if(t==p)
				break;
		}
		t=t->right;
	}
	return;
}

void inorder(node *p)
{
	node *t=p->left;
	while(t!=p)
	{
		while(t->l==false)
			t=t->left;
		printf("%d  ",t->data);
		while(t->r==true)
		{
			t=t->right;
			if(t==p)
				break;
			printf("%d  ",t->data);
		}
		t=t->right;
	}
	return;
}

int main()
{
	node *root;
	int ch,data;
	do
	{
		printf("\n------------MENU FOR THREADED BINARY TREE----------------\n");
		printf("0.EXIT\n");
		printf("1.CREATE\n");
		printf("2.PREORDER TRAVERSAL\n");
		printf("3.INORDER TRAVERSAL\n");

		printf("------------------------------------------\n");
		printf("\nEnter any choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				printf("Program terminates...\n");
				exit(0);
				break;
			case 1:
				root=NULL;
				root=create(root,0);
				printf("Threaded binary tree created successfully\n");
				break;
			case 2:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				{
					printf("Preorder traversal :    ");
					preorder(root);
					printf("\n");
				}
				break;
			case 3:
				if(root==NULL)
				printf("\nTree is empty!!!\n");
				else
				{
					printf("Inorder traversal :    ");
					inorder(root);
					printf("\n");
				}
				break;
			default:
				printf("\nInvlid choice!!!\n");
				break;
		}
	}while(1);
	return 0;
}
