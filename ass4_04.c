#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
	int status,ch;
	do{
	        printf("\n1.ls\n2.pwd\n3.uname\n4.Exit\nEnter your choice:");
	        scanf("%d",&ch);
                switch(ch){
                        case 1:
                                if(fork()==0){
                                        printf("\n-:ls command:-\n");
                                        char *str1[]={"/bin/ls","-l",NULL};
	                                execv("/bin/ls", str1);     //execv executes a command with arguments file path for that command 
	                                                            //and command description with attribute in array of strings
	                        }
	                        else
	                                wait(&status);
                                break;
                        case 2:
                                if(fork()==0){
                                        printf("\npwd command:=>\n");
                                        char *str2[]={"/bin/pwd",NULL};
	                                execv("/bin/pwd", str2);
	                        }
	                        else
	                                wait(&status);
                                break;
                        case 3:
                                if(fork()==0){
                                        printf("\n-:uname command:-\n");
                                        char *str3[]={"/bin/uname",NULL};
	                                execv("/bin/uname", str3);
	                        }
	                        else
	                                wait(&status);
                                break;
                        case 4:
                                printf("Exiting program...\n");
                                break;
                        default:
                                printf("Wrong Choice!!!\n");
                }
        }while(ch!=4);
        return 0;
}
