// Write a program that accepts two small numbers (< 50) as arguments and then sums the
// two in a child process. The sum should be returned by the child to the parent as its exit status
// and the parent should print the sum.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <num1> <num2>\n", argv[0]);
    exit(1);
  }

  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);

  if (num1 < 0 || num1 >= 50 || num2 < 0 || num2 >= 50) {
    fprintf(stderr, "Error: Both numbers must be between 0 and 49.\n");
    exit(1);
  }

  pid_t pid = fork();

  if (pid < 0) {
    perror("Fork failed");
    exit(1);
  } else if (pid == 0) {
    // Child process
    int sum = num1 + num2;
    exit(sum);
  } else {
    // Parent process
    int status;
    wait(&status);
    if (WIFEXITED(status)) {
      int sum = WEXITSTATUS(status);
      printf("Sum: %d\n", sum);
    }
  }

  return 0;
}