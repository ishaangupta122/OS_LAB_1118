// Write a program to implement execv() system call
// FILE 1

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  char *args[] = {"a", "Hello", NULL};

  printf("PID of ex1.c = % d\n", getpid());
  execv("./a", args);
  printf("Back to program 1");

  return 0;
}