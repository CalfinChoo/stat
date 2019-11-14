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
  char buffer[50];
  char metric[8];
  int m = 1;
  if (fs / 1000000000 > 0) {
    sprintf(metric, "%s", "GB");
    m = 1000000000;
  }
  else if (fs / 1000000 > 0) {
    sprintf(metric, "%s", "MB");
    m = 1000000;
  }
  else if (fs / 1000 > 0) {
    sprintf(metric, "%s", "KB");
    m = 1000;
  }
  else sprintf(metric, "%s", "B");
  
  sprintf(buffer, "%0.1lf %s", (double)fs/m, metric);
  printf("File size: %s\n", buffer);
  char pbuffer[7];
  sprintf(pbuffer, "%o", sb.st_mode);
  int i = 3;
  printf("Permissions: -");
  for (; i < 7; i++) {
    switch (pbuffer[i] - 48){
      case 0:
        printf("---");
        break;
      case 1:
        printf("--x");
        break;
      case 2:
        printf("-w-");
        break;
      case 3:
        printf("-wx");
        break;
      case 4:
        printf("r--");
        break;
      case 5:
        printf("r-x");
        break;
      case 6:
        printf("rw-");
        break;
      case 7:
        printf("rwx");
        break;
    }
  }
  printf("\n\n");
 }
