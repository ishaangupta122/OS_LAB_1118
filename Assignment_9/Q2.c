// Write  a  C  program  using  semaphores  to  simulate  two  threads  (thread1  and  thread2)
// updating a shared variable inside a critical section.
// Ensure  that  only  one  thread  can  access  the  critical  section  at  a  time  to  prevent
// race conditions.

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>  // For sleep

// Shared variable
int shared_variable = 0;

// Semaphore for mutual exclusion
sem_t mutex_semaphore;

// Function for thread 1
void* thread1_function(void* arg) {
  for (int i = 0; i < 5; ++i) {
    // Wait (acquire) the semaphore
    sem_wait(&mutex_semaphore);

    // Critical section
    shared_variable++;
    printf("Thread 1: shared_variable = %d\n", shared_variable);
    sleep(1);  // Simulate some work inside the critical section

    // Signal (release) the semaphore
    sem_post(&mutex_semaphore);
    sleep(1);  // Simulate some work outside the critical section
  }
  return NULL;
}

// Function for thread 2
void* thread2_function(void* arg) {
  for (int i = 0; i < 5; ++i) {
    // Wait (acquire) the semaphore
    sem_wait(&mutex_semaphore);

    // Critical section
    shared_variable++;
    printf("Thread 2: shared_variable = %d\n", shared_variable);
    sleep(1);  // Simulate some work inside the critical section

    // Signal (release) the semaphore
    sem_post(&mutex_semaphore);
    sleep(1);  // Simulate some work outside the critical section
  }
  return NULL;
}

int main() {
  pthread_t thread1, thread2;

  // Initialize the semaphore with an initial value of 1 (binary semaphore)
  // The second argument (0) indicates that the semaphore is shared between threads of the same
  // process.
  sem_init(&mutex_semaphore, 0, 1);

  // Create threads
  pthread_create(&thread1, NULL, thread1_function, NULL);
  pthread_create(&thread2, NULL, thread2_function, NULL);

  // Join threads (wait for them to finish)
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  // Destroy the semaphore
  sem_destroy(&mutex_semaphore);

  printf("Final value of shared_variable: %d\n", shared_variable);

  return 0;
}
