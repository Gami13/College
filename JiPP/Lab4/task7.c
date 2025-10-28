#include <stdio.h>

// Napisz nieskończoną pętlę wczytującą wprowadzane z klawiatury przez
// użytkownika znaki do momentu podania znaku 'e'.Do przerwania wykorzystaj
// instrukcję break.
int main(void) {
  char znak;
  while (1) {
    printf("Podaj znak (wpisz 'e' aby zakończyć): ");
    if (scanf(" %c", &znak) != 1) {
      break;
    }
    if (znak == 'e') {
      break;
    }
    printf("Wprowadzono znak: %c\n", znak);
  }
  printf("Koniec programu.\n");
  return 0;
}
