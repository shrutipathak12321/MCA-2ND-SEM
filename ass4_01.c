#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid = fork();
    if(pid == -1){
        printf("Fork failed");
        exit(EXIT_FAILURE);
        0;
     }
     if(pid == 0){
        printf("Child process - PID: %d, parent PID: %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
      }else{
        printf("Parent process - PID %d, Parent PID: %d\n", getpid(), getppid());
        int status;
        waitpid(pid, &status, 0);
        printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        }
        
      
    
    return 0;
    }
