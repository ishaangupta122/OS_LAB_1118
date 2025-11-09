// Q5: Demonstrate use of lseek() System call.

// Function Prototype:
// off_t lseek(int fd, off_t offset, int whence);
// Parameters:
// • fd → File descriptor (from open())
// • offset → How far to move the pointer
// • whence → Reference point for movement:
// o SEEK_SET → Beginning of file
// o SEEK_CUR → Current file position
// o SEEK_END → End of file
//  Create  a  file  ‘seeking’  and  write  some  content  e.g.
// 1234567890abcdefghijklmnopqrstuvwxyz  and  save  it.  Predict  the  output  of  following
// code:

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int f;
  char buff[10];
  f = open("seeking", O_RDWR);  // open the file "seeking" in read+write mode
  if (f < 0) {
    perror("open");
    return 1;
  }
  // read first 10 bytes and print
  read(f, buff, 10);
  write(1, buff, 10);
  // move file pointer 10 bytes ahead from current
  lseek(f, 10, SEEK_CUR);
  // read next 10 bytes and print
  read(f, buff, 10);
  write(1, buff, 10);
  close(f);
  return 0;
}