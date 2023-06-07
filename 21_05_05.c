#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int l, int m, int r)
{
    int n1,n2,i,j,k;
    n1 = m-l+1;
    n2=r-m;
    int L[n1], R[n2];
    for(i=0;i<n1;i++)
        L[i]=a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];
    i=0;j=0;k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=p+(r-p)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);    
        merge(a,p,q,r);
    }
}
void display(int a[],int n)
{
	int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void swap(int *l, int *r)
{
    int t=*l;
    *l=*r;
    *r=t;
}
int partition(int a[],int low, int high)
{
    int pivot = a[high];
    int i = low-1,j;
    for(j=low;j<=high-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return(i+1);
}
void qSort(int a[],int low, int high)
{
    int pivotloc;
    if(low<high) 
    {
    int pi=partition(a,low,high);
    qSort(a,low,pi-1);
    qSort(a,pi+1,high);
    }

}
int main()
{
    int *a,n,ch,i;
    printf("\nEnter no of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter %d elements:\n",n);
    for( i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nOriginal List:");
    display(a,n);
	do{
    	printf("\n------------MENU FOR SORTING-------------\n");
    	printf("0.EXIT\n");
		printf("1.QUICK SORT\n");
		printf("2.MERGE SORT\n");
		printf("------------------------------------------\n");
	
	    printf("Enter any choice: "); 
	    scanf("%d",&ch);
	    switch (ch)
	    {
	    	case 0:
			    exit(0);
		    case 1:
		        qSort(a,0,n-1);
		        printf("\nSorted List:");
		        display(a,n);
		        break;
		    case 2:
		        mergeSort(a,0,n-1);
		        printf("\nSorted List:");
		        display(a,n);
				break;	
		    default:
		        printf("\nInvalid input");
		        break;
	    }
	}while(1);
    return 0;   
}
