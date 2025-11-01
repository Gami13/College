
// PROJEKT NR1.Policz wartości funkcji 𝑦 = 𝑓(𝑥) we wszystkich punktach podziału na 𝑛 części przedziału[𝑎, 𝑏]. Funkcja 𝑓
// dana jest w postaci rozwinięcia w szereg potęgowy i w postaci wzoru analitycznego. Obliczanie sumy szeregu wykonaj z
// dokładnością 𝜀. Algorytm obliczania sumy szeregu zapisz w oddzielnej funkcji.Uzupełnij funkcję obliczającą sumę
// szeregu tak, by sumowanych było co najwyżej 𝑀 wyrazów szeregu.Oznacza to, że przerwanie sumowania może nastąpić
// również wtedy, gdy nie została osiągnięta żądana dokładność.Informacja o tym, czy została osiągnięta dokładność czy
// też nie winna być znana w funkcji main() .Uzupełnij funkcję obliczającą sumę szeregu tak, by w funkcji main() znana
// była dodatkowo liczba sumowanych wyrazów szeregu.Wyniki wyświetl na ekranie i zapisz do pliku.Wyniki przedstaw w
// następującym układzie: x | f_szereg(x) | f_ścisłe(x) | liczba wyrazów szeregu | warunek stopu

// D/158143, nr6

// f(x) = (1-x)^(-1/4)
// Szereg: 1 - (1/4)x + (1*5/4*8)x^2 - (1*5*9/4*8*12)x^3 + ...
// przedzial abs(x)<1
// previous = 1/4, current = previous * 5/8 * x, next = current * 9/12 * x

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
typedef struct {
  double sum;
  bool hitAccuracy;
  bool hitMaxTerms;
  int termsUsed;
} SeriesResult;
///
/// @warning x musi byc mniejsze od 1 poniewaz w przeciwnym wypadku w rownaniu f(x) = (1-x)^(-1/4) bedzie pierwiastek
/// czwartego stopnia z liczby ujemnej
///
static double f_scisle(double x) { return pow(1.0 - x, -0.25); }

///
/// @warning x musi byc mniejsze od 1 poniewaz w przeciwnym wypadku w rownaniu f(x) = (1-x)^(-1/4) bedzie pierwiastek
/// czwartego stopnia z liczby ujemnej
///
static SeriesResult f_szereg(double x, double epsilon, int maxTerms) {
  double numeratorLastNumber = 1.0;
  double denominatorLastNumber = 4.0;
  double fraction = 1.0;
  double sum = 1.0;
  bool hitAccuracy = false;

  int terms = 1;
  for (; terms < maxTerms && !hitAccuracy; terms++) {
    fraction *= numeratorLastNumber / denominatorLastNumber;
    double term = fraction * pow(x, terms);
    sum += term;

    if (fabs(term) <= epsilon)
      hitAccuracy = true;

    numeratorLastNumber += 4.0;
    denominatorLastNumber += 4.0;
  }
  return (SeriesResult){sum, hitAccuracy, terms == maxTerms, terms};
}

int main(void) {
  double a = 0.0;
  double b = 0.0;
  int n = 0;
  double epsilon = 0.0;
  int max_terms = 0;

  printf("Podaj a, b, n (ilosc punktow podzialu), epsilon (precyzja) oraz M (maksymalna liczba wyrazow): ");
  if (scanf("%lf %lf %d %lf %d", &a, &b, &n, &epsilon, &max_terms) != 5) {
    printf("Niepoprawny format danych.\n");
    return 1;
  }

  if (!isfinite(a) || !isfinite(b) || !isfinite(epsilon) || !isfinite((double)n) || !isfinite((double)max_terms)) {
    printf("Wartosci a, b, n, epsilon oraz M musza byc liczbami skonczonymi.\n");
    return 1;
  }

  if (a >= b) {
    printf("Wymagane jest, aby a < b.\n");
    return 1;
  }
  if (n <= 0) {
    printf("Liczba podzialow n musi byc dodatnia.\n");
    return 1;
  }
  if (epsilon <= 0.0) {
    printf("Dokladnosc epsilon musi byc dodatnia.\n");
    return 1;
  }
  if (max_terms <= 0) {
    printf("Maksymalna liczba wyrazow musi byc dodatnia.\n");
    return 1;
  }
  if (a < -1.0) {
    printf("Wprowadzana wartosc a nie moze byc mniejsza niz -1, poniewaz w tym punkcie szereg Taylora jest "
           "rozbiezny.");
    return 1;
  }
  if (b >= 1.0) {
    printf("b musi byc mniejsze od 1 (wynosi %lf) poniewaz w przeciwnym wypadku w rownaniu f(x) = (1-x)^(-1/4) "
           "bedzie pierwiastek "
           "czwartego stopnia z liczby ujemnej",
           b);
    return 1;
  }

  FILE *out = fopen("wyniki.txt", "w");
  if (!out) {
    printf("Nie mozna utworzyc pliku wyjsciowego");
    return 1;
  }

  const char *header = "         x |      f_szereg(x) |      f_scisle(x) |   liczba wyrazow |     warunek stopu";
  const char *separator = "-----------+------------------+------------------+------------------+-------------------";
  printf("%s\n%s\n", header, separator);
  fprintf(out, "%s\n%s\n", header, separator);

  double step = (b - a) / (double)n;
  for (int i = 0; i <= n; ++i) {
    double x = a + step * i;
    if (i == n) {
      x = b;
    }

    SeriesResult approx = f_szereg(x, epsilon, max_terms);
    const char *stop_condition = "maksymalna ilosc wyrazowe";
    if (approx.hitAccuracy && approx.hitMaxTerms) {
      stop_condition = "osiagnieto dokladnosc i maksymalna ilosc wyrazow";
    } else if (approx.hitAccuracy) {
      stop_condition = "osiagnieto dokladnosc";
    }

    double exact = f_scisle(x);
    printf("%10.6f | %16.10f | %16.10f | %16d | %s\n", x, approx.sum, exact, approx.termsUsed, stop_condition);
    fprintf(out, "%10.6f | %16.10f | %16.10f | %16d | %s\n", x, approx.sum, exact, approx.termsUsed, stop_condition);
  }

  fclose(out);
  printf("Wyniki zapisano w pliku wyniki.txt\n");
  return 0;
}