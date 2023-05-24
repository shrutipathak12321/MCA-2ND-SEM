#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void display(int arr[][2], int n){
	int i;
    printf("\nList of persons: \n");
    for (i = 0; i < n; i++){
        printf("%d  ", arr[i][0]);
    }
    printf("\n");
}

int josephus(int n, int k, int p){
	int i;

    int arr[MAX][2];
    for (i = 0; i < n; i++) {
        arr[i][0] = i + 1;
        arr[i][1]=1;
    }
    
    printf("\nIntially: ");
    display(arr, n);

    int pos = p;
    int round = 1;
    while (n > 1) 
	{
		printf("\nRound %d:", round);
        pos = (pos + k) % n;
        arr[pos][1]=0;
	    printf("\nExecuted : %d", arr[pos][0]);

        for (i = pos; i < n - 1; i++) {
            arr[i][0] = arr[i + 1][0];
        }
        n--;
        
        display(arr, n);
        round += 1;
    }

    return arr[0][0];
}


int main(){
    int n = 1, k = 1, p = 1;
    
    printf("Enter number of persons: ");
    scanf("%d", &n);
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &k);
    printf("Enter starting position: ");
    scanf("%d", &p);

    printf("\nSurvived person: %d\n", josephus(n, k, p-1));
    
    return 0;
}
