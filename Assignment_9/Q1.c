// Write a C program to implement multithreading where:
// • The first thread calculates the sum of all elements in a shared integer array int data [10].
// • The second thread finds the maximum value in the array.
// • The  main  thread  should  wait  for  all  three  threads  to  complete  using  appropriate
// thread synchronization (e.g., pthread_join()) and then print their results.

#include <pthread.h>
#include <stdio.h>


// Shared data
int data[10] = {1, 5, 2, 8, 3, 9, 4, 7, 6, 0};
int array_sum = 0;
int max_value = -1;  // Initialize with a value smaller than any possible element

// Mutex for protecting shared data (though not strictly necessary for this read-only scenario)
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to calculate the sum
void* calculate_sum(void* arg) {
  int local_sum = 0;
  for (int i = 0; i < 10; i++) {
    local_sum += data[i];
  }
  // pthread_mutex_lock(&mutex); // Lock if writing to shared variable directly
  array_sum = local_sum;
  // pthread_mutex_unlock(&mutex); // Unlock
  pthread_exit(NULL);
}

// Thread function to find the maximum value
void* find_maximum(void* arg) {
  int local_max = data[0];  // Assume first element is max initially
  for (int i = 1; i < 10; i++) {
    if (data[i] > local_max) {
      local_max = data[i];
    }
  }
  // pthread_mutex_lock(&mutex); // Lock if writing to shared variable directly
  max_value = local_max;
  // pthread_mutex_unlock(&mutex); // Unlock
  pthread_exit(NULL);
}

int main() {
  pthread_t sum_thread_id, max_thread_id;

  // Create the sum thread
  if (pthread_create(&sum_thread_id, NULL, calculate_sum, NULL) != 0) {
    perror("Failed to create sum thread");
    return 1;
  }

  // Create the maximum value thread
  if (pthread_create(&max_thread_id, NULL, find_maximum, NULL) != 0) {
    perror("Failed to create max thread");
    return 1;
  }

  // Wait for the sum thread to complete
  if (pthread_join(sum_thread_id, NULL) != 0) {
    perror("Failed to join sum thread");
    return 1;
  }

  // Wait for the maximum value thread to complete
  if (pthread_join(max_thread_id, NULL) != 0) {
    perror("Failed to join max thread");
    return 1;
  }

  // Print the results
  printf("Sum of array elements: %d\n", array_sum);
  printf("Maximum value in the array: %d\n", max_value);

  return 0;
}
