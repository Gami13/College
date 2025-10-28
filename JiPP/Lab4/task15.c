#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
// Tablicowanie funkcji w przedziale[a, b] z krokiem dx.Policzyć wartości
// funkcji f(𝑥) = 1 𝑥2 +√1 + 2𝑥 + 3𝑥2 Dla x zmieniającego od a do b z krokiem
// dx. Wartości funkcji 𝑓(𝑥) liczone w funkcji double ff(double x) {} Wyniki(𝑥,
// 𝑓(𝑥)) wyświetl na ekranie i zapisz do pliku.fprintf(fw,
// "\t%10.2lf\t\t%15.4lf\n", x, y); printf("\t%10.2lf\t\t%15.4lf\n", x, y);

double ff(double x);
int main(void) {
  double a = 0, b = 10, dx = 0.1;
  FILE *fw = fopen("results.txt", "w");
  if (fw == NULL) {
    perror("Nie można otworzyć pliku");
    return 1;
  }
  for (double x = a; x <= b; x += dx) {
    double y = ff(x);
    fprintf(fw, "\t%10.2lf\t\t%15.4lf\n", x, y);
    printf("\t%10.2lf\t\t%15.4lf\n", x, y);
  }
  fclose(fw);
  return 0;
}

double ff(double x) { return 1 / (x * x + sqrt(1 + 2 * x + 3 * x * x)); }
