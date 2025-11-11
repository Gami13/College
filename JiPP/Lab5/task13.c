#include <stdbool.h>
#include <stdio.h>
// 13. Znajdz pozycje wybranego znaku w tekscie.

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
    printf("Znak '%c' nie znaleziony w tekscie.\n", target);
  }

  return 0;
}