#include <stdio.h>

// Edytuj powyższy program tak, aby w przypadku wystąpienia litery 'c' była ona
// zarówno zliczana jako litera 'c' jak i wliczana do sumarycznej liczby
// wystąpień pozostałych znaków.Skorzystaj z instrukcji goto.
int main(void) {
  char znak;
  int a_count = 0, b_count = 0, c_count = 0, other_count = 0;
  while (1) {
    printf("Podaj znak (wpisz 'e' aby zakończyć): ");
    scanf(" %c", &znak);
    if (znak == 'e') {
      break;
    }
    if (znak == 'a') {
      a_count++;
      continue;
    }
    if (znak == 'b') {
      b_count++;
      continue;
    }
    if (znak == 'c') {
      c_count++;
      goto count_other;
    } else {
    count_other:
      other_count++;
    }
  }
  printf("Liczba liter 'a': %d\n", a_count);
  printf("Liczba liter 'b': %d\n", b_count);
  printf("Liczba liter 'c': %d\n", c_count);
  printf("Liczba innych znaków: %d\n", other_count);
  printf("Koniec programu.\n");
  return 0;
}
