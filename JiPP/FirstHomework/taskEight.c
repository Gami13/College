#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <tchar.h>

// Zad 8. Napisz program, który dla danych rzeczywistych x, y, z i całkowitych
// k, m policzy wartości następujących wyrażeń arytmetycznych

static void w1(double x, double y, double z) {
  // check for z and y not zero
  if (y == 0.0 || z == 0.0) {
    printf("Blad: dzielenie przez zero w wyrazeniu w1\n");
    exit(1);
  }

  double logInput = x * x + y * y;
  if (logInput <= 0.0) {
    printf("Blad: logarytm z nie-dodatniej wartosci w wyrazeniu w1\n");
    exit(1);
  }

  double result = pow(x / (y * z), 1.0 / 3.0) * log(logInput);
  printf("w1 = %.8lf \n", result);
}

static void w2(double x, double y, int k, int m) {
  double result = sin(k * (x / 2)) * cos(m * y) + y * exp(2 * x - 1);
  printf("w2 = %.8lf \n", result);
}

static void w3(double x, double y, double z) {
  double denom = 2.0 * y * y + 1.0;
  if (denom == 0.0) {
    printf("Blad: dzielenie przez zero w wyrazeniu w3\n");
    exit(1);
  }
  double zDenom = z * z + 3.0;
  if (zDenom == 0.0) {
    printf("Blad: dzielenie przez zero w wyrazeniu w3\n");
    exit(1);
  }

  if (y < 0.0) {
    printf("Blad: pierwiastek z liczby ujemnej w wyrazeniu w3\n");
    exit(1);
  }

  double result = fabs(x / denom) + sqrt(y / zDenom) + (5.0 * pow(y + z, 3.0));
  printf("w3 = %.8lf \n", result);
}

static void w4(double x, double y, double z, int k) {
  double denom = y * z;
  if (denom == 0.0) {
    printf("Blad: dzielenie przez zero w wyrazeniu w4\n");
    exit(1);
  }

  if (k == 0) {
    printf("Blad: dzielenie przez zero w wyrazeniu w4\n");
    exit(1);
  }

  double result = (x / denom) * pow(z + 1, 1.0 / 3.0) +
                  pow(x * x + z * z + 1.0, 1.0 / k) - fabs(y);
  printf("w4 = %.8lf \n", result);
}

static void w5(double x, double y, int k) {
  const double EPS = 1e-12;

  if (fabs(x) < EPS) {
    printf("Blad: dzielenie przez zero w wyrazeniu w5\n");
    exit(1);
  }
  double root = sqrt(x * x + y * y + k * k);
  if (fabs(root) < EPS) {
    printf("Blad: dzielenie przez zero w wyrazeniu w5\n");
    exit(1);
  }

  double result = 1.0 / root + (1.0 / x) * sin(k * y);
  printf("w5 = %.8lf \n", result);
}

int main(int argc, _TCHAR *argv[]) {
  (void)argc;
  (void)argv;

  double x = 3.14;
  double y = 12.56;
  double z = 7;
  int k = 2;
  int m = 4;
  printf("Podaj liczby reczywiste x, y, z, i liczby calkowite k, m\n");
  int ret = scanf("%lf%lf%lf%d%d", &x, &y, &z, &k, &m);
  if (ret != 5) {
    printf("Blad przy wczytaniu\n");
    return 1;
  }

  w1(x, y, z);
  w2(x, y, k, m);
  w3(x, y, z);
  w4(x, y, z, k);
  w5(x, y, k);
  return 0;
}
