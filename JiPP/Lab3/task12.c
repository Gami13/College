#include <stdio.h>
void sumaRekurencyjna(int *sum, int n);

int main(void) {
  int sum = 0;
  int n;
  printf("Podaj liczbe n: ");
  int ret = scanf("%d", &n);
  if (ret != 1) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }
  if (n < 0) {
    printf("Liczba n nie moze byc ujemna.\n");
    return 1;
  }

  sumaRekurencyjna(&sum, n);
  printf("Suma %d kolejnych liczb naturalnych wynosi: %d\n", n, sum);

  return 0;
}

void sumaRekurencyjna(int *sum, int n) {
  if (n == 0) {
    return;
  }
  *sum += n;
  sumaRekurencyjna(sum, n - 1);
}