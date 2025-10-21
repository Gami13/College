#include <stdio.h>
void zamien(int *x, int *y);

int main(void) {
  int x, y;
  printf("Podaj dwie liczby calkowite: ");
  int ret = scanf("%d %d", &x, &y);

  if (ret != 2) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }

  zamien(&x, &y);
  printf("Po zamianie: x = %d, y = %d\n", x, y);

  return 0;
}

void zamien(int *x, int *y) {
  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}
