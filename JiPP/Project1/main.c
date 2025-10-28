
// PROJEKT NR1.Policz wartości funkcji 𝑦 = 𝑓(𝑥) we wszystkich punktach podziału
// na 𝑛 części przedziału[𝑎, 𝑏]. Funkcja 𝑓 dana jest w postaci rozwinięcia w
// szereg potęgowy i w postaci wzoru analitycznego. Obliczanie sumy szeregu
// wykonaj z dokładnością 𝜀. Algorytm obliczania sumy szeregu zapisz w
// oddzielnej funkcji.Uzupełnij funkcję obliczającą sumę szeregu tak, by
// sumowanych było co najwyżej 𝑀 wyrazów szeregu.Oznacza to, że przerwanie
// sumowania może nastąpić również wtedy, gdy nie została osiągnięta żądana
// dokładność.Informacja o tym, czy została osiągnięta dokładność czy też nie
// winna być znana w funkcji main() .Uzupełnij funkcję obliczającą sumę szeregu
// tak, by w funkcji main() znana była dodatkowo liczba sumowanych wyrazów
// szeregu.Wyniki wyświetl na ekranie i zapisz do pliku.Wyniki przedstaw w
// następującym układzie: x | f_szereg(x) | f_ścisłe(x) | liczba wyrazów szeregu
// | warunek stopu

// D/158143, nr6

// f(x) = (1-x)^(-1/4)
// przedzial abs(x)<1
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  double sum;
  int terms_used;
  bool reached_accuracy;
} SeriesResult;

// Computes the binomial series for (1 - x)^(-1/4) up to epsilon or max_terms.
static SeriesResult compute_series(double x, double epsilon, int max_terms) {
  SeriesResult result = {0.0, 0, false};
  if (max_terms <= 0) {
    return result;
  }

  const double alpha = -0.25;
  double term = 1.0;
  double sum = term;
  int terms = 1;
  bool accuracy = fabs(term) <= epsilon;

  while (!accuracy && terms < max_terms) {
    double k = (double)terms;
    term *= (alpha - (k - 1.0)) / k * (-x);
    sum += term;
    terms++;
    if (fabs(term) <= epsilon) {
      accuracy = true;
    }
  }

  result.sum = sum;
  result.terms_used = terms;
  result.reached_accuracy = accuracy;
  return result;
}

int main(void) {
  double a = 0.0;
  double b = 0.0;
  int n = 0;
  double epsilon = 0.0;
  int max_terms = 0;

  printf("Podaj a, b, n, epsilon oraz M (maksymalna liczba wyrazow): ");
  if (scanf("%lf %lf %d %lf %d", &a, &b, &n, &epsilon, &max_terms) != 5) {
    fprintf(stderr, "Niepoprawny format danych.\n");
    return 1;
  }

  if (a >= b) {
    fprintf(stderr, "Wymagane jest, aby a < b.\n");
    return 1;
  }
  if (n <= 0) {
    fprintf(stderr, "Liczba podzialow n musi byc dodatnia.\n");
    return 1;
  }
  if (epsilon <= 0.0) {
    fprintf(stderr, "Dokladnosc epsilon musi byc dodatnia.\n");
    return 1;
  }
  if (max_terms <= 0) {
    fprintf(stderr, "Maksymalna liczba wyrazow musi byc dodatnia.\n");
    return 1;
  }
  if (!(a > -1.0 && a < 1.0 && b > -1.0 && b < 1.0)) {
    fprintf(stderr, "Przedzial musi miescic sie w (-1, 1).\n");
    return 1;
  }

  FILE *out = fopen("wyniki.txt", "w");
  if (!out) {
    perror("Nie mozna utworzyc pliku wyjsciowego");
    return 1;
  }

  const char *header = "        x  |     f_szereg(x)  |      f_scisle(x) | "
                       "liczba wyrazow   | warunek stopu";
  const char *separator = "-----------+------------------+------------------+--"
                          "----------------+---------------";
  printf("%s\n%s\n", header, separator);
  fprintf(out, "%s\n%s\n", header, separator);

  double step = (b - a) / (double)n;
  for (int i = 0; i <= n; ++i) {
    double x = a + step * i;
    if (i == n) {
      x = b;
    }

    SeriesResult approx = compute_series(x, epsilon, max_terms);
    double exact = pow(1.0 - x, -0.25);
    const char *stop_condition = "max_terms";
    if (approx.reached_accuracy && approx.terms_used == max_terms) {
      stop_condition = "epsilon_at_max";
    } else if (approx.reached_accuracy) {
      stop_condition = "epsilon";
    }

    printf("%10.6f | %16.10f | %16.10f | %16d | %s\n", x, approx.sum, exact,
           approx.terms_used, stop_condition);
    fprintf(out, "%10.6f | %16.10f | %16.10f | %16d | %s\n", x, approx.sum,
            exact, approx.terms_used, stop_condition);
  }

  fclose(out);
  printf("Wyniki zapisano w pliku wyniki.txt\n");
  return 0;
}