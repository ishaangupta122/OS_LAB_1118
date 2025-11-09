#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 1;

  if (fork() == 0) {
    x += 5;
  } else {
    x += 10;
  }

  if ((x % 2 == 0) && (fork())) {
    if (x > 6 || fork() == 0) {
      printf("Hello (x = %d)\n", x);
      fork();
    }
  }

  return 0;
}