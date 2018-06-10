#include <stdio.h>

void good_echo() {
  int BUFF_SIZE = 10;
  char buff[BUFF_SIZE];
  while (1) {
    char *p = fgets(buff, BUFF_SIZE, stdin);
    if (!p)
      break;
    printf("%s", buff);
  }
  
}

int main() {
  good_echo();
  return 0;
}
