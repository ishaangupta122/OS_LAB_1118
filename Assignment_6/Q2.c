//  Write a program to:
// • Demonstrate creation of an orphan process using fork() and sleep().
// • Demonstrate creation of a zombie process (child exits before parent calls wait ()).

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Orphan Process (whose parent has terminated and child is still running)
int orphan() {
  pid_t pid = fork();
  if (pid < 0) {
    perror("Fork failed");
    exit(1);
  } else if (pid > 0) {
    printf("Parent Process (Orphan): PID = %d, PPID = %d\n", getpid(), getppid());
    exit(0);
  } else {
    sleep(10);
    printf("Child Process (Orphan): PID = %d, PPID = %d\n", getpid(), getppid());
  }
}

// Zombie Process (whose child has terminated and parent is waiting for the child)
int zombie() {
  pid_t pid = fork();

  if (pid < 0) {
    perror("Fork failed");
    exit(1);
  } else if (pid == 0) {
    printf("Child Process (Zombie): PID = %d, PPID = %d\n", getpid(), getppid());
    exit(0);
  } else {
    printf("Parent Process (Zombie): PID = %d, PPID = %d\n", getpid(), getppid());
    sleep(10);
  }
}

int main() {
  printf("Demonstrating Orphan Process:\n");
  orphan();

  printf("\nDemonstrating Zombie Process:\n");
  zombie();

  return 0;
}