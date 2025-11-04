#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
// 13. Znajdź pozycję wybranego znaku w tekście.

int main(void) {
  char text[] = "Hello, World!";
  char target = 'W';
  int position = -1;

  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == target) {
      position = i;
      break;
    }
  }

  if (position != -1) {
    printf("Znak '%c' znaleziony na pozycji: %d\n", target, position);
  } else {
    printf("Znak '%c' nie znaleziony w tekście.\n", target);
  }

  return 0;
}