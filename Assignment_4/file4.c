#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  int fd;
  char buffer[80];
  static char message[] = "Hello";

  fd = open("test.txt", O_RDWR);

  if (fd == 1) {
    perror("Error opening file !! ");
    return 1;
  }

  if (fd != -1) {
    printf("test.txt opened with read / write access\n");
    write(fd, message, sizeof(message));
    lseek(fd, 0, 0);
    read(fd, buffer, sizeof(message));
    printf("%s — was written to test.txt \n", buffer);
    close(fd);
  }

  return 0;
}