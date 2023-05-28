#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int fd1[2], fd2[2];
	pipe(fd1);  //for parent write child read
	pipe(fd2);  //for child write parent read
	if(fork()!=0){
		while(1){
		        char buffer[100]={0};
		        printf("\nEnter string in parent process : ");
		        scanf("\n");
		        scanf("%[^\n]",buffer);
		        if((strcmp("quit",buffer)==0) || (strcmp("Quit",buffer)==0)){
		                exit(1);
		        }
		        //write and pass to child through pipe1
		        write(fd1[1], buffer, strlen(buffer));

		        //read child's string via pipe2
		        read(fd2[0], buffer, 100);
		        int len=strlen(buffer);
		        buffer[len]='\0';
		        printf("\nParent has string returned from child : %s\n", buffer);
		}
	}
	else{
		while(1){
		        char buffer[100]={0};
		        sleep(2);
		        //read parent's string via pipe1
		        read(fd1[0], buffer, 100);
		        int len=strlen(buffer);
		        buffer[len]='\0';
		        int j=0,k=len-1;
		        printf("\nChild has read from parent : %s\n", buffer);
		        //loop to reverse string from parent
		        while(j<k){
		                char ch=buffer[j];
		                buffer[j]=buffer[k];
		                buffer[k]=ch;
		                j++;
		                k--;
	                }
	                printf("\nString reversed in child : %s\n",buffer);
	                fflush(stdout);
		        write(fd2[1], buffer, len);
		}
	}
	return 0;	
}
