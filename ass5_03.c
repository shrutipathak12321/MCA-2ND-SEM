#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 5

int buffer[MAX_BUFFER_SIZE];
int buffer_index = 0;

sem_t buffer_lock;
sem_t items_available;
sem_t spaces_available;

void* producer(void* arg) {
    int item = 0;
    while (1) {
        // Simulate producing an item
        sleep(1);
        item = rand() % 100;  // Generate a random item

        sem_wait(&spaces_available);  // Wait for an available space in the buffer
        sem_wait(&buffer_lock);  // Acquire the buffer lock to modify the buffer

        buffer[buffer_index] = item;  // Add the item to the buffer
        buffer_index++;

        sem_post(&buffer_lock);  // Release the buffer lock
        sem_post(&items_available);  // Signal that there's an item available for consumption

        printf("Produced item: %d\n", item);
    }
}

void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&items_available);  // Wait for an available item in the buffer
        sem_wait(&buffer_lock);  // Acquire the buffer lock to modify the buffer

        item = buffer[buffer_index - 1];  // Consume the last item from the buffer
        buffer_index--;

        sem_post(&buffer_lock);  // Release the buffer lock
        sem_post(&spaces_available);  // Signal that there's an available space in the buffer

        printf("Consumed item: %d\n", item);
    }
}

int main() {
    srand(time(NULL));

    sem_init(&buffer_lock, 0, 1);
    sem_init(&items_available, 0, 0);
    sem_init(&spaces_available, 0, MAX_BUFFER_SIZE);

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&buffer_lock);
    sem_destroy(&items_available);
    sem_destroy(&spaces_available);

    return 0;
}
