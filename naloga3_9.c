#include <stdio.h>

int main(void) {
  unsigned int stevilo;
  scanf("%u", &stevilo);
  if(stevilo<1 || stevilo>99) 
    printf("Nisi vnesel pravega števila");

  unsigned int stevka1 = stevilo%10;
  unsigned int stevka2 = stevilo/10;

  if(stevka1 != 0){
    switch(stevka1){
      case 1: printf("ena"); break;
      case 2: printf("dva"); break;
      case 3: printf("tri"); break;
      case 4: printf("štiri"); break;
      case 5: printf("pet"); break;
      case 6: printf("šest"); break;
      case 7: printf("sedem"); break;
      case 8: printf("osem"); break;
      case 9: printf("devet"); break;
    }
  } 
  
  if(stevilo > 10 && stevilo < 20){
     printf("najst"); 
  } 
  else if(stevka1 != 0 && stevka2 != 0){
    printf("in");
  }

  switch(stevka2){
    case 2: printf("dvajset"); break;
    case 3: printf("trideset"); break;
    case 4: printf("štirideset"); break;
    case 5: printf("petdeset"); break;
    case 6: printf("šestdeset"); break;
    case 7: printf("sededeset"); break;
    case 8: printf("osedeset"); break;
    case 9: printf("devetdeset"); break;
  }
}