#include <stdio.h>
#include <stdlib.h>
int linearSearch(int *a, int s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == s)
        {            
            return i;
        }
    }
    return -1;
}
int binarySearch(int *a, int s, int n)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(a[m]<s)
            l=m+1;
        else if(a[m]>s)
            r=m-1;
        else
        {
            return m;
        }
    }    
    return -1;
}
int main()
{
    int *a,n,t,ch,p,i;
    printf("\nEnter no of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("\nEnter the %d elements in sorted order:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    do
    {
		printf("\n------------MENU FOR SEARCHING-------------\n");
    	printf("0.EXIT\n");
		printf("1.LINEAR SEARCH\n");
		printf("2.BINARY SEARCH\n");
		printf("------------------------------------------\n");

        printf("Enter any choice: ");        
		scanf("%d",&ch);
        switch (ch)
        {
	        case 1:
	        	printf("\nEnter target: ");
        		scanf("%d",&t);
	            p=linearSearch(a,t,n);
	            if(p>=0)
	                printf("\nElement found at index -> %d",p);
	            else
	                printf("\nElement not found");
	            break;
	        case 2:
	        	printf("\nEnter target: ");
       		 	scanf("%d",&t);
	            p=binarySearch(a,t,n);
	            if(p>=0)
	                printf("\nElement found at index -> %d",p);
	            else
	                printf("\nElement not found");
	            break;
	        case 0:
	            exit(0);
        	default:
        	printf("\nInvalid input!");
            break;
        }
    } while (1);
    
    return 0;
}
