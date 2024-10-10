#include <stdio.h>

int main(void) {
  unsigned int stevilo_dni, prvi_dan, dan = 1;
  printf("Število dni v mesecu: ");
  scanf("%u", &stevilo_dni);
  printf("\nPrvi dan v mesecu (1: pon, 2: tor, ...): ");
  scanf("%u", &prvi_dan);
  printf("\n\nP\tT\tS\tČ\tP\tS\tN\n");
  
  for(int n = 1; n < prvi_dan; n++) {
    printf("\t");
  }
  for(int n = prvi_dan; n<=7; n++){
    printf("%u\t", dan);
    dan++;
  }
  printf("\n");
  for(int n = 1; n < (stevilo_dni - 7 + prvi_dan); n++){
    printf("%u\t", dan);
    if(n%7 == 0){
      printf("\n");
    }
    dan++;
  }
}