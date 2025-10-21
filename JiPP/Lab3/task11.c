#include <stdio.h>

void policz(double x, double y, double *z, int *usedFormula);

int main(void) {
  double x, y, z;
  int usedFormula;
  printf("Podaj dwie liczby: ");
  int ret = scanf("%lf %lf", &x, &y);
  if (ret != 2) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }

  policz(x, y, &z, &usedFormula);
  printf("Wynik: %.4lf\n", z);
  printf("Uzyty wzor: %d\n", usedFormula);

  return 0;
}

void policz(double x, double y, double *z, int *usedFormula) {
  if (x * x + y * y <= 1) {
    *usedFormula = 1;
    *z = x * x + y;
    return;
  }
  if (y > (x + 5)) {
    *usedFormula = 2;
    *z = 2 * x + y * y;
    return;
  }
  *usedFormula = 3;
  *z = (x * x) / 2 + y;
  return;
}