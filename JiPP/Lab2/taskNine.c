#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <tchar.h>
static void my_exit(void);
static void my_return(void);
// Zad 9. W przykładzie WW4.pdf rozszerzyć program o wyznaczanie pierwiastków
// równia dla delta < 0 (liczby zespolone).Przyjmijmy oznaczenia
int main(int argc, _TCHAR *argv[]) {
  (void)argc;
  (void)argv;
  double a = 0.0, b = 0.0, c = 0.0;
  int ret = -1;
  // input data
  printf(
      "Program obliczenia rzeczywistych pierwiastkow rownania kwadratowego\n");
  printf("-------------------- a*x^2+b*x+c = 0 "
         "------------------------------\n\n");
  printf("Podaj a,b,c\n");
  ret = scanf("%le%le%le", &a, &b, &c);
  if (ret != 3) {
    printf("Blad przy wczytaniu\n");
    printf("Wczytane: a = %e  b = %e  c = %e\n", a, b, c);
    // To jest blad oprogramowania
    my_exit();
  }
  if (a == 0.0) // To nie jest dobry kod: a jest typu double!!!
  {
    // a == 0
    printf("To nie jest rownanie kwadratowe: a = 0.\n");
    // To jest blad uzytkownika przy wprowadzeniu danych
    my_exit();
  }
  double D = -1.0;
  D = b * b - 4.0 * a * c;
  if (D < 0.0) {
    // brak pierwiastkow rzeczywistych

    // Tutaj dodalem zmiany
    // printf("Brak pierwiastkow rzeczywistych: D = %e  < 0.\n", D);
    double r1 = 0.0, u1 = 0.0, r2 = 0.0, u2 = 0.0;
    r1 = -(b / (2 * a));
    u1 = sqrt(fabs(pow(b / (2 * a), 2.0) - (c / a)));
    r2 = -(b / (2 * a));
    u2 = sqrt(fabs(pow(b / (2 * a), 2.0) - (c / a))) * -1;
    printf("Rownanie kwadratowe: %lf *X*X + %lf *X + %lf = 0\n\n", a, b, c);
    printf("Pierwiastki:  x1 = %e %+e i    x2 = %e %+e i\n", r1, u1, r2, u2);
    printf("---------------------------------------------------------");

  } else {

    // Obliczenie pierwiastkow
    double p1, p2, x1, x2;
    p1 = -b / (2.0 * a);
    p2 = sqrt(D) / (2.0 * a);
    x1 = p1 + p2;
    x2 = p1 - p2;
    printf("Rownanie kwadratowe: %lf *X*X + %lf *X + %lf = 0\n\n", a, b, c);
    printf("Pierwiastki:  x1 = %e    x2 = %e\n", x1, x2);
    printf("---------------------------------------------------------");
  }
  my_return();
  return 0;
}
// Przymusowe zakonczenie wykonania
// Zawiesza monitor dok№d nie bкdzie wprowadzony ^Z
// exit(1)
void my_exit(void) {
  int ch;
  printf("Zakoncz - ctrl+Z Enter\n");
  while ((ch = getchar()) != EOF)
    ;
  exit(1);
}
// Normalne zakonczenie
// Zawiesza monitor dok№d nie bкdzie wprowadzony ^Z
// exit(0)
void my_return(void) {
  int ch;
  printf("Zakoncz - ctrl+Z Enter\n");
  while ((ch = getchar()) != EOF)
    ;
  exit(0);
}