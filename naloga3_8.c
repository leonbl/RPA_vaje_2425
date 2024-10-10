#include <stdio.h>

int main(void) {
  unsigned int stevilo;
  scanf("%u", &stevilo);
  if(stevilo<30 || stevilo>99) 
    printf("Nisi vnesel pravega števila");

  unsigned int stevka1 = stevilo%10;

  switch(stevka1){
    case 1: printf("enain"); break;
    case 2: printf("dveain"); break;
    case 3: printf("triin"); break;
    case 4: printf("štiriin"); break;
    case 5: printf("petain"); break;
    case 6: printf("šestin"); break;
    case 7: printf("sedemin"); break;
    case 8: printf("osemin"); break;
    case 9: printf("devetin"); break;
  }

  unsigned int stevka2 = stevilo/10;
  switch(stevka2){
    case 3: printf("trideset"); break;
    case 4: printf("štirideset"); break;
    case 5: printf("petdeset"); break;
    case 6: printf("šestdeset"); break;
    case 7: printf("sededeset"); break;
    case 8: printf("osedeset"); break;
    case 9: printf("devetdeset"); break;
  }
}