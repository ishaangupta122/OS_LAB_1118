//  Write a program to:
// • Create a child process using fork().
// • Print the process IDs (PID, PPID) in both parent and child.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("Fork failed");
    exit(1);
  } else if (pid == 0) {
    // Child process
    printf("Child Process: PID = %d, PPID = %d\n", getpid(), getppid());
  } else {
    // Parent process
    printf("Parent Process: PID = %d, PPID = %d\n", getpid(), getppid());
  }
  return 0;
}