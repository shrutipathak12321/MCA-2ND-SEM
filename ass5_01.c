#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 100*sizeof(int)

typedef struct {
    int numbers[100];
    int min;
    int max;
    double avg;
} SharedData;

void parentProcess(int shmId) {
    SharedData* sharedData = (SharedData*) shmat(shmId, NULL, 0);

    // Generate random numbers and write them to shared memory
    for (int i = 0; i < 100; i++) {
        int num = rand() % 1000;
        sharedData->numbers[i] = num;
    }

    shmdt(sharedData);

    // Wait for the child process to finish
    wait(NULL);

    // Read the result from shared memory
    sharedData = (SharedData*) shmat(shmId, NULL, 0);

    // Display the result
    printf("Maximum: %d\n", sharedData->max);
    printf("Minimum: %d\n", sharedData->min);
    printf("Average: %.2f\n", sharedData->avg);

    // Detach and remove shared memory
    shmdt(sharedData);
    shmctl(shmId, IPC_RMID, NULL);
}

void childProcess(int shmId) {
    SharedData* sharedData = (SharedData*) shmat(shmId, NULL, 0);

    int min = sharedData->numbers[0];
    int max = sharedData->numbers[0];
    int sum = 0;

    // Compute the minimum, maximum, and average
    for (int i = 0; i < 100; i++) {
        int num = sharedData->numbers[i];
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
        sum += num;
    }

    sharedData->min = min;
    sharedData->max = max;
    sharedData->avg = (double) sum / 100;

    shmdt(sharedData);
}

int main() {
    key_t key = ftok("shared_memory", 1234);
    int shmId = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        childProcess(shmId);
    } else {
        // Parent process
        parentProcess(shmId);
    }

    return 0;
}
