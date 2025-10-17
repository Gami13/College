#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <tchar.h>
#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif

// Zad 12. Napisać program, który będzie obliczał pole powierzchni oraz obwód
// takich figur jak: trójkąt, kwadrat, prostokąt, koło. Dla trójkąta sprawdzić
// warunek trójkąta, dla wszystkich figur wprowadzić zabezpieczenia
// uniemożliwiające podanie przez użytkownika wartości
// niepoprawnych (np. ujemnych).
// Obliczenie pola kwadratu, obwodu kwadratu itd. dla wszystkich figur zapisać w
// osobnych funkcjach, które kolejno będą wywoływane w main().

#define DOUBLE_EPSILON 1e-12

static int trojkat_obliczenia(void) {
  double a = 0.0, b = 0.0, c = 0.0;
  int ret = -1;
  printf("Podaj boki trojkata a,b,c\n");
  ret = scanf("%lf%lf%lf", &a, &b, &c);
  if (ret != 3) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }
  if (a <= 0.0 || b <= 0.0 || c <= 0.0) {
    printf("Boki trojkata musza byc dodatnie\n");
    return 1;
  }
  if ((a + b - c) <= -DOUBLE_EPSILON || (a + c - b) <= -DOUBLE_EPSILON ||
      (b + c - a) <= -DOUBLE_EPSILON) {
    printf("Nie istnieje trojkat o podanych bokach\n");
    return 1;
  }
  if (fabs(a + b - c) <= DOUBLE_EPSILON || fabs(a + c - b) <= DOUBLE_EPSILON ||
      fabs(b + c - a) <= DOUBLE_EPSILON) {
    printf("To jest trojkat zdegenerowany, pole wynosi 0\n");
    return 1;
  }

  double obwod = a + b + c;
  double p = obwod / 2.0;
  double pole = sqrt(p * (p - a) * (p - b) * (p - c));
  printf("Trojkat: obwod = %.4lf pole = %.4lf\n", obwod, pole);
  return 0;
}

static int kwadrat_obliczenia(void) {
  double a = 0.0;
  int ret = -1;
  printf("Podaj bok kwadratu a\n");
  ret = scanf("%lf", &a);
  if (ret != 1) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }
  if (a <= 0.0) {
    printf("Bok kwadratu musi byc dodatni\n");
    return 1;
  }

  double obwod = 4.0 * a;
  double pole = a * a;
  printf("Kwadrat: obwod = %.4lf pole = %.4lf\n", obwod, pole);
  return 0;
}

static int prostokat_obliczenia(void) {
  double a = 0.0, b = 0.0;
  int ret = -1;
  printf("Podaj boki prostokata a,b\n");
  ret = scanf("%lf%lf", &a, &b);
  if (ret != 2) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }
  if (a <= 0.0 || b <= 0.0) {
    printf("Boki prostokata musza byc dodatnie\n");
    return 1;
  }

  double obwod = 2.0 * (a + b);
  double pole = a * b;
  printf("Prostokat: obwod = %.4lf pole = %.4lf\n", obwod, pole);
  return 0;
}

static int kolo_obliczenia(void) {
  double r = 0.0;
  int ret = -1;
  printf("Podaj promien kola r\n");
  ret = scanf("%lf", &r);
  if (ret != 1) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }
  if (r <= 0.0) {
    printf("Promien kola musi byc dodatni\n");
    return 1;
  }

  double obwod = 2.0 * M_PI * r;
  double pole = M_PI * r * r;
  printf("Kolo: obwod = %.4lf pole = %.4lf\n", obwod, pole);
  return 0;
}

int main(int argc, _TCHAR *argv[]) {
  (void)argc;
  (void)argv;
  if (trojkat_obliczenia() != 0) {
    return 1;
  }
  if (kwadrat_obliczenia() != 0) {
    return 1;
  }
  if (prostokat_obliczenia() != 0) {
    return 1;
  }
  if (kolo_obliczenia() != 0) {
    return 1;
  }
  return 0;
}
