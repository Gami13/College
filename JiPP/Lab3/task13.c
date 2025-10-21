#include <stdio.h>

void hanoi(int N, char A, char B, char C);

int main(void) {

  int N;
  printf("Podaj liczbe krazkow: ");
  int ret = scanf("%d", &N);
  if (ret != 1) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }
  if (N <= 0) {
    printf("Liczba krazkow musi byc dodatnia.\n");
    return 1;
  }
  hanoi(N, 'A', 'B', 'C');

  return 0;
}

void hanoi(int N, char A, char B, char C) {
  if (N == 1) {
    printf("Przenies krazek %d z %c na %c\n", N, A, B);
    return;
  }
  hanoi(N - 1, A, C, B);
  printf("Przenies krazek %d z %c na %c\n", N, A, B);
  hanoi(N - 1, C, B, A);
}
