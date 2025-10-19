#include <float.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <tchar.h>

// Zad 10. Dane są a,b,c - długości boków trójkąta. Sprawdzić warunek istnienia
// trójkąta: https://pl.wikipedia.org/wiki/Nierówność_trójkąta Obliczyć pole
// trójkąta i promień koła wpisanego w trójkąt.Wykorzystać wzory Herona : p = (a
// + b + c) / 2 pole : 	promień : 	S = sqrt(p(p - a)(p - b)(p - c))
// R = S / p
#define DOUBLE_EPSILON 1e-12

int main(int argc, _TCHAR *argv[]) {
  (void)argc;
  (void)argv;
  double a = 0.0, b = 0.0, c = 0.0;
  int ret = -1;
  printf("Podaj a,b,c (boki trojkata)\n");
  ret = scanf("%le%le%le", &a, &b, &c);
  if (ret != 3) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }
  if (a <= 0) {
    printf("Bok nie moze byc zerowy lub mniejszy: a <= 0.\n");
    return 1;
  }
  if (b <= 0) {
    printf("Bok nie moze byc zerowy lub mniejszy: b <= 0.\n");
    return 1;
  }
  if (c <= 0) {
    printf("Bok nie moze byc zerowy lub mniejszy: c <= 0.\n");
    return 1;
  }
  if ((a + b - c < -DOUBLE_EPSILON) || (a + c - b < -DOUBLE_EPSILON) ||
      (b + c - a < -DOUBLE_EPSILON)) {
    printf("Nie istnieje trojkat o podanych bokach.\n");
    return 0;
  } else if (fabs(a + b - c) <= DOUBLE_EPSILON ||
             fabs(a + c - b) <= DOUBLE_EPSILON ||
             fabs(b + c - a) <= DOUBLE_EPSILON) {
    printf("To jest trojkat zdegenerowany, pole wynosi 0.\n");
    return 0;
  }

  double p = (a + b + c) / 2.0;
  double S = sqrt(p * (p - a) * (p - b) * (p - c));
  double R = S / p;
  printf("Trojkat o bokach a=%lf b=%lf c=%lf\n", a, b, c);
  printf("Pole trojkata wynosi %.4lf\n", S);
  printf("Promien kola wpisanego w trojkat wynosi %.4lf\n", R);

  return 0;
}
