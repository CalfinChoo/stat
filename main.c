#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

int main() {
  struct stat sb;
  stat("main.c", &sb);
  int fs = sb.st_size, fp = sb.st_mode;
  char * p = ctime(&sb.st_atime);
  printf("File size: %d\n\n", fs);
  printf("File permissions: %o\n\n", fp);
  printf("Last Access: %s\n\n", p);
}
