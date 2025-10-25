#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define DOUBLE_EPSILON 1e-12
void kolo(double r, double *w1, double *w2);

int main(void) {
  double r, w1, w2;
  printf("Podaj promien kola: ");
  int ret = scanf("%lf", &r);
  if (ret != 1) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }
  if (isnan(r)) {
    printf("Blad podczas wczytywania danych.\n");
    return 1;
  }
  if (r <= DOUBLE_EPSILON) {
    printf("Promien nie moze byc ujemny lub rowny zero.\n");
    return 1;
  }

  kolo(r, &w1, &w2);
  printf("Pole kola: %.4lf\n", w1);
  printf("Obwod kola: %.4lf\n", w2);

  return 0;
}

void kolo(double r, double *w1, double *w2) {
  *w1 = M_PI * r * r;
  *w2 = 2 * M_PI * r;
}