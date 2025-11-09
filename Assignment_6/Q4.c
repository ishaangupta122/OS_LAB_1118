// Predict the output of the following program.

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int x = 10;
  pid_t pid;
  pid = fork();  // create child process

  if (pid < 0) {  // error in fork
    perror("fork failed");
    return 1;
  }
  if (pid == 0) {  // Child process
    printf("Child: Initially x = %d\n", x);
    x = x + 5;  // modify x in child
    printf("Child: Modified x = %d\n", x);
  } else {
    // Parent process
    wait(NULL);  // wait for child to finish
    printf("Parent: x = %d\n", x);
  }

  return 0;
}

// Expected Output:
// Child: Initially x = 10
// Child: Modified x = 15
// Parent: x = 10