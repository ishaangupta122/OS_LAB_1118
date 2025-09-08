// Write a program to implement execv() system call
// FILE 2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  printf("We are in program 2 \n");
  printf("PID of program 2 is %d\n", getpid());
  printf("Arguments passed from Program 1:\n");
  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  return 0;
}
