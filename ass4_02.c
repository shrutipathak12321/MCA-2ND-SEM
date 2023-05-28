#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
//function to check whether a number is prime or not
int isPrime(int num){
	int i;
	if(num==1||num==0)
		return 0;
	if(num==2||num==3)
		return 1;
	if(num%2==0)
		return 0;
	//loop to check whether any odd integer divides num
	for(i=3;i*i<=num;i+=2){
		if(num%i==0)
			return 0;
	}
	return 1;
}
//function to print primes in a range
void print_prime(int start,int end){
	int i;
	printf("\nPrimes in the range %d to %d are:\n\n",start,end);
	printf("-------------------------------------------------\n\n");
	for(i=start;i<=end;i++){
		if(isPrime(i)){
			printf("%d\t",i);
		}
	}
	printf("\n");
}
int main()
{
	int i,start,end,status;
	//loop to create 10 child process and distribute tasks
	for(i=0;i<10;i++)
	{
		//allocate tasks to every child
		if(fork()==0)
		{
			start=100000*i+1;
			end=start+99999;
			print_prime(start,end);
			exit(0);   //this exit suspend the child process,so that this cannot furthur iterate in loop
		}
		sleep(1);   
	}
	return 0;
}
