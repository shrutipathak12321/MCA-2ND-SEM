#include <stdio.h>
#include <stdlib.h>

typedef struct cll {
	struct cll *prev;
    int val;
    struct cll *next;
}node;

node *head=NULL;

void create(int size){
    node *newnode, *temp ;
    int i;

    for (i = 1; i <= size; i++){
        newnode = (node*)malloc(sizeof(node));
        if (newnode==NULL){
            return;
        }
		newnode->prev= NULL;
        newnode->val = i;
        newnode->next = NULL;

        if(head == NULL){
        	newnode->prev= newnode;
            newnode->next = newnode;
            head = newnode;
        }
		else{
            temp = head;
            while (temp->next != head){
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            newnode->prev= temp;
            head->prev=newnode;
        }
    }
}

void display(){
    node *temp = head;
    
    if (temp == NULL){
        printf("\nList is empty\n");
        return;
    }
      
    printf("\nList of persons: \n");
    do {
        printf("%d  ", temp->val);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

void execute(int index){
    if (head == NULL){
        printf("\nList is empty!\n");
        return;
    }
    
    if (head->next == head){
        head = NULL;
		return;
    }

 	if (index <= -1){
        printf("\nInvalid index: \n");
        return;
    }
    node *temp = head;
    node *ptr = NULL;
    node *prev = NULL;
    int count = 0;
    
    while (count < index){
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == head){
        if (temp->next == temp){
        	printf("\nExecuted : %d", temp->val);
            free(temp);
            head == NULL;
            return;
        }
		else{
            head = temp->next;
            head->prev=temp->prev;
            temp->prev->next=head;
            printf("\nExecuted : %d", temp->val);
            free(temp);
            return;
        }
    }

    if (temp->next == head){
        if (temp == head){
   			printf("\nExecuted : %d", temp->val);
            free(temp);
            head = NULL;
            return;
        }
		else{
            prev->next = temp->next;
            head->prev=prev;
            printf("\nExecuted : %d", temp->val);
            free(temp);
            return;
        }

    }    
    prev->next = temp->next;
    temp->next->prev=prev;
    temp->next = NULL;
    temp->prev = NULL;
    printf("\nExecuted : %d", temp->val);
    free(temp);

}

int josephus(int n, int k, int p){
    create(n);

    int i = p, index, round = 1;

    printf("Intially\n");
    display();

    while (n > 1){
        index = (i + k) % n;
        printf("\nRound %d:", round);
        execute(index);       
        display();

        n -= 1;
        i = (index) % n;   
        round += 1; 

    }
  	return head->val;

}

int main(){
	int n,k,p;

    printf("Enter number of persons: ");
    scanf("%d", &n);
    printf("Enter the number of persons to be skipped: ");
    scanf("%d", &k);
    printf("Enter starting position: ");
    scanf("%d", &p);

    printf("\nSurvived person: %d\n", josephus(n, k, p-1));

    return 0;
}

