#include <stdio.h>

// Edytuj powyższy program tak, aby zliczał wystąpienia liter: a, b, c - każdej
// osobno oraz wszystkich pozostałych znaków razem - do momentu podania znaku
// 'e'.Skorzystaj z instrukcji continue i break.
int main(void) {
  char znak;
  int a_count = 0, b_count = 0, c_count = 0, other_count = 0;
  while (1) {
    printf("Podaj znak (wpisz 'e' aby zakończyć): ");
    if (scanf(" %c", &znak) != 1) {
      break;
    }
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
      continue;
    }
    other_count++;
  }
  printf("Liczba liter 'a': %d\n", a_count);
  printf("Liczba liter 'b': %d\n", b_count);
  printf("Liczba liter 'c': %d\n", c_count);
  printf("Liczba innych znaków: %d\n", other_count);
  printf("Koniec programu.\n");
  return 0;
}
