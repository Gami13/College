#include <stdio.h>
#define _USE_MATH_DEFINES
#include <tchar.h>

// Zad 11. Dane są cztery liczby całkowite a,b,c,d. Znaleźć wśród nich liczbę
// największą i wydrukować jej wartość i pozycję przyjmując, że dla a(pozycja =
// 1), b(pozycja = 2) itd. (nie wprowadzać zmiennej indeksowanej).

int main(int argc, _TCHAR *argv[]) {
  (void)argc;
  (void)argv;
  int a = 0, b = 0, c = 0, d = 0;
  int ret = -1;
  printf("Podaj a,b,c,d\n");
  ret = scanf("%d%d%d%d", &a, &b, &c, &d);
  if (ret != 4) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }

  int max = a;
  int pos = 1;

  if (b > max) {
    max = b;
    pos = 2;
  }
  if (c > max) {
    max = c;
    pos = 3;
  }
  if (d > max) {
    max = d;
    pos = 4;
  }

  printf("Najwieksza liczba to %d, na pozycji %d\n", max, pos);
  return 0;
}
