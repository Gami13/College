#include <stdio.h>
// Napisz program, który oblicza silnię dla podanego n. Algorytm zaimplementuj
// tworząc nową funkcję z pętlą.
static unsigned long long silnia(int n) {
  unsigned long long wynik = 1;
  for (int i = 1; i <= n; i++) {
    wynik *= (unsigned long long)i;
  }
  return wynik;
}

int main(void) {
  int n;
  printf("Podaj liczbe calkowita n do obliczenia silni: ");
  if (scanf("%d", &n) != 1) {
    printf("Blad: Nieprawidlowe dane wejsciowe.\n");
    return 1;
  }
  if (n < 0) {
    printf("Silnia nie jest zdefiniowana dla liczb ujemnych.\n");
    return 1;
  }
  if (n > 20) {
    printf("Silnia dla n > 20 nie miesci sie w unsigned long long.\n");
    return 1;
  }
  unsigned long long wynik = silnia(n);
  printf("Silnia %d wynosi: %llu\n", n, wynik);

  return 0;
}
