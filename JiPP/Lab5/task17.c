#define _USE_MATH_DEFINES
#include "string.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// 17. Dołącz tekst od znaku o podanej pozycji na koniec innego teksu.

int main(void) {
  char text1[100] = "Hello, World!";
  char text2[] = " This is a test.";
  unsigned long long position = 7; // Pozycja od której dołączamy tekst1 do tekst2

  // Sprawdzenie czy pozycja jest poprawna
  if (position < 0 || position >= strlen(text1)) {
    printf("Niepoprawna pozycja: %llu\n", position);
    return 1;
  }

  // Dołączenie tekstu od podanej pozycji
  strcat(text2, &text1[position]);

  printf("Połączony tekst: %s\n", text2);

  return 0;
}