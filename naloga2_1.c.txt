#include <stdio.h>

int main(void) {
  int x = 0;
  printf("%d\n", x > 2 && x < 5);
  x = 3;
  printf("%d\n", x > 2 && x < 5);
  x = 5;
  printf("%d\n", x > 2 && x < 5);
  return 0; 
}