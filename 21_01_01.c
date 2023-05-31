#include<stdio.h>
#include<stdlib.h>

int* create(int *ptr,int n)
{
	int i;
	ptr=(int*)malloc(n*sizeof(int));
	printf("Enter %d values for the array: ",n);
	for(i=0;i<n;i++)
	scanf("%d",&ptr[i]);
	printf("Elements entered successfully\n");
	return ptr;
}

void display(int *ptr,int n)
{
	int i;
	if(n==0)
	printf("The array is empty!");
	else{
		printf("The values of the array: \n");
		for(i=0;i<n;i++)
		printf("%d ",ptr[i]);
		printf("\n");
	}
}

void reverse(int *ptr,int n)
{
	int i,temp;if(n==0)
	printf("The array is empty!");
	else{
	
		for(i=0;i<n/2;i++)
		{
			temp=ptr[i];
			ptr[i]=ptr[n-1-i];
			ptr[n-1-i]=temp;
		}
		printf("\nAfter Reverse,\n");
		display(ptr,n);
	}
	
}

void index_of(int *ptr,int n,int m)
{
	int i;
	if(n==0)
	printf("The array is empty!");
	else{
		printf("%d is present in the array at index/indices: ",m);
		for(i=0;i<n;i++)
		{
			if(ptr[i]==m)
			printf("%d ",i);
		}
		printf("\n");
	}
}

int insert(int *ptr,int n,int m,int k)
{
	int i;
	if(k>n)
		printf("Insertion not possible!");
		
	else{
		ptr=(int*)realloc(ptr,sizeof(int));
		n++;
		for(i=n-1;i>=k;i--)
		{
			ptr[i]=ptr[i-1];
		}
		ptr[k]=m;
		printf("Element inserted successfully\n");
		display(ptr,n);
	}
	return n;
	
}

int delete_at(int *ptr,int n,int k)
{
	int i;
	if(k>=n)
	printf("Deletion not possible!");
	else{
		
		for(i=k;i<n;i++)
		{
			ptr[i]=ptr[i+1];
		}
		n--;
		printf("Element deleted successfully\n");
		display(ptr,n);
	}
	return n;

}

void merge()
{
	int i,j=0,*first,*second,l1,l2,result[100];
	printf("Enter length of first array: ");
	scanf("%d",&l1);
	first=create(first,l1);
	printf("Enter length of second array: ");
	scanf("%d",&l2);
	second=create(second,l2);

	for(i=0;i<l1;i++){
	result[i]=first[i];	
	}
	for(i=0,j=l1;i<l2 && j<l1+l2;i++,j++)
	result[j]=second[i];
	
	printf("\nAfter merge, ");
	display(result,l1+l2);	
}

void split()
{
	int l,*a,first[10],second[10],pos,i,k1=0,k2=0;
	printf("Enter length of the array: ");
	scanf("%d",&l);
	a=create(a,l);
	printf("Enter the position to split the array in to two arrays: ");
	scanf("%d",&pos);
	if(pos>=l){
		printf("Split cannot be possible!!!");
		return;
	}
	for(i=0;i<l;i++)
	{
		if(i<pos)
		first[k1++]=a[i];
		else
		second[k2++]=a[i];
	}
	printf("\nFirst array: \n");
	display(first,k1);
	printf("Second array: \n");
	display(second,k2);
	
}

void sort(int *ptr,int n)
{
	int i,j,temp;
	if(n==0)
	printf("The array is empty!");
	else{
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(ptr[j]>ptr[j+1])
				{
					temp=ptr[j];
					ptr[j]=ptr[j+1];
					ptr[j+1]=temp;
				}
			}
		}
		printf("After sorting,\n");
		display(ptr,n);
	}

}

void search(int *ptr,int n,int m)
{
	int i;
	if(n==0)
	printf("The array is empty!");
	else{
		printf("%d is present at index: ",m);
		for(i=0;i<n;i++)
		{
			if(ptr[i]==m)
			{
				printf("%d ",i);
				break;
			}
		}
		printf("\n");
	}
}

int main()
{
	int c,m,i,j,k,n;
	int *array;
	do{
		printf("\n-----------MENU-------------\n");
		printf("0.Exit\n");
		printf("1.Create\n");
		printf("2.Display the entire list\n");
		printf("3.Count\n");
		printf("4.Reverse\n");
		printf("5.Index of a given element\n");
		printf("6.Indexed element\n");
		printf("7.Insert\n");
		printf("8.Delete\n");
		printf("9.Merge\n");
		printf("10.Split\n");
		printf("11.Sort\n");
		printf("12.Search\n");
		
		printf("\nEnter any choice: ");
		scanf("%d",&c);
		switch(c)
		{
			case 0:
				exit(0);
			case 1:
				printf("Enter number of elements: ");
				scanf("%d",&n);
				array=create(array,n);		
				break;
			case 2:
				display(array,n);
				break;
			case 3:
				printf("The no of elements in the array is %d\n",n);
				break;
			case 4:
				reverse(array,n);
				break;
			case 5:
				printf("Enter the element whose index/indices you want to know: ");
				scanf("%d",&m);
				index_of(array,n,m);
				break;
			case 6:
				printf("Enter the index: ");
				scanf("%d",&i);
				if(i>=n)
				printf("Enter valid index! ");
				else
				printf("Element present at index %d is %d\n",i,array[i]);
				break;
			case 7:
				printf("Enter a element you want to insert: ");
				scanf("%d",&m);
				printf("Enter the position where you want to insert the element: ");
				scanf("%d",&k);
				n=insert(array,n,m,k);
				break;
			case 8:
				printf("Enter the position which you want to delete: ");
				scanf("%d",&k);
				n=delete_at(array,n,k);
				break;
			case 9:				
				merge();
				break;
			case 10:
				split();
				break;
			case 11:
				sort(array,n);
				break;
			case 12:
				printf("Enter a element you want to search: ");
				scanf("%d",&m);
				search(array,n,m);
				break;
			default:
				printf("You have entered a wrong choice!!!\n");
		}


	}while(1);
	return 0;
}
