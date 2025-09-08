// Write a program to implement the system calls open (), read (), write () &
// close ()

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid < 0) {
    printf("Fork failed.\n");
  } else if (pid == 0) {
    printf("Child process, PID: %d\n", getpid());
    printf("Child is exiting.\n");
    exit(0); // exit() system call
  } else {
    printf("Parent process, Child PID: %d\n", pid);
    printf("Parent is waiting for the child to exit...\n");
    wait(NULL); // wait() system call
    printf("Parent's wait is done.\n");
  }

  return 0;
}