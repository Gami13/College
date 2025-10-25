#include <math.h>
#include <stdio.h>
#define DOUBLE_EPSILON 1e-12

double policz(double x, double y, int *usedFormula);

int main(void) {
  double x, y;
  int usedFormula;
  printf("Podaj dwie liczby: ");
  int ret = scanf("%lf %lf", &x, &y);
  if (ret != 2) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }
  if (isnan(x) || isnan(y)) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }

  double z = policz(x, y, &usedFormula);
  if (isnan(z)) {
    printf("Blad podczas obliczen.\n");
    return 1;
  }
  printf("Wynik: %.4lf\n", z);
  printf("Uzyty wzor: %d\n", usedFormula);

  return 0;
}

double policz(double x, double y, int *usedFormula) {
  double z;
  if ((x * x + y * y) - 1 <= DOUBLE_EPSILON) {
    *usedFormula = 1;
    z = x * x + y;
    return z;
  }
  if (y - x - 5 >= DOUBLE_EPSILON) {
    *usedFormula = 2;
    z = 2 * x + y * y;
    return z;
  }
  *usedFormula = 3;
  z = (x * x) / 2 + y;
  return z;
}