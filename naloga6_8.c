#include <stdio.h>

int stVecjihOdSred(float t[], int stEl) {
  float vsota = 0;
  int stevec = 0;
  for (int n = 0; n < stEl; n++) {
    vsota += t[n];
  }
  float povprecje = vsota / stEl;
  for (int n = 0; n < stEl; n++) {
    if (t[n] > povprecje) {
      stevec++;
    }
  }
  return stevec;
}

int main(void) {
  float tabela[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 70.7};
  printf("stevilo elementov vecjih od sredine je :%d\n",
         stVecjihOdSred(tabela, 7));
}