#include <stdio.h>
// Napisz program, który oblicza silnię dla podanego n. Algorytm zaimplementuj
// tworząc nową funkcję z pętlą.
static int silnia(int n) {
  int wynik = 1;
  for (int i = 1; i <= n; i++) {
    wynik *= i;
  }
  return wynik;
}

int main(void) {
  int n;
  printf("Podaj liczbe calkowita n do obliczenia silni: ");
  scanf("%d", &n);
  if (n < 0) {
    printf("Silnia nie jest zdefiniowana dla liczb ujemnych.\n");
  } else {
    int wynik = silnia(n);
    printf("Silnia %d wynosi: %d\n", n, wynik);
  }
  return 0;
}
