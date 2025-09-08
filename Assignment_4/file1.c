// Creating CHILD PROCESS USING FORK()

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int pid = fork();
  if (pid < 0) {
    printf("Fork failed.\n");
  } else if (pid == 0) {
    printf("In Child process\n");
  } else {
    printf("In Parent process\n");
  }

  return 0;
}