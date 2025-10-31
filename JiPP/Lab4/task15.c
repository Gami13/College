#define _USE_MATH_DEFINES
#include <float.h>
#include <math.h>
#include <stdio.h>
// Tablicowanie funkcji w przedziale[a, b] z krokiem dx.Policzyć wartości
// funkcji f(𝑥) = 1 𝑥2 +√1 + 2𝑥 + 3𝑥2 Dla x zmieniającego od a do b z krokiem
// dx. Wartości funkcji 𝑓(𝑥) liczone w funkcji double ff(double x) {} Wyniki(𝑥,
// 𝑓(𝑥)) wyświetl na ekranie i zapisz do pliku.fprintf(fw,
// "\t%10.2lf\t\t%15.4lf\n", x, y); printf("\t%10.2lf\t\t%15.4lf\n", x, y);

double ff(double x);

int main(void) {
  double a = 0.0;
  double b = 0.0;
  double dx = 0.0;

  printf("Podaj a, b i dx (oddzielone spacjami): ");
  if (scanf("%lf %lf %lf", &a, &b, &dx) != 3) {
    printf("Bledne dane wejsciowe. Oczekiwano trzech liczb.\n");
    return 1;
  }

  if (!isfinite(a) || !isfinite(b) || !isfinite(dx)) {
    printf("Wprowadzone wartosci musza byc skonczone.\n");
    return 1;
  }

  if (dx <= 0.0) {
    printf("dx musi byc dodatnie.\n");
    return 1;
  }

  if (a > b) {
    printf("Wymagane jest a <= b.\n");
    return 1;
  }

  FILE *fw = fopen("results.txt", "w");
  if (fw == NULL) {
    perror("Nie mozna otworzyc pliku");
    return 1;
  }

  for (double x = a; x <= b + dx * 0.5; x += dx) {
    const double y = ff(x);

    if (!isfinite(y)) {
      printf("Nie mozna obliczyc wartosci funkcji dla x = %.6f\n", x);
      if (fprintf(fw, "\t%10.2lf\t\t%15s\n", x, "NaN") < 0) {
        printf("Blad zapisu do pliku");
        fclose(fw);
        return 1;
      }
      printf("\t%10.2lf\t\t%15s\n", x, "NaN");

      continue;
    }

    if (fprintf(fw, "\t%10.2lf\t\t%15.4lf\n", x, y) < 0) {
      printf("Blad zapisu do pliku");
      fclose(fw);
      return 1;
    }

    printf("\t%10.2lf\t\t%15.4lf\n", x, y);
  }

  if (fclose(fw) != 0) {
    perror("Blad zamykania pliku");
    return 1;
  }

  return 0;
}

double ff(double x) {
  // sprawdza czy wartosc x nie spowoduje przepełnienia przy obliczeniach
  // sprawdzamy czy 3*x^2 <= DBL_MAX, wiec x^2 <= DBL_MAX/3 czyli x <=
  // sqrt(DBL_MAX/3)
  if (fabs(x) > sqrt(DBL_MAX / 3.0)) {
    return NAN;
  }
  const double radicand = 1.0 + 2.0 * x + 3.0 * (x * x);
  if (radicand < 0.0) {
    return NAN;
  }

  const double root = sqrt(radicand);
  const double denominator = x * x + root;
  if (fabs(denominator) < DBL_EPSILON) {
    return NAN;
  }

  return 1.0 / denominator;
}
