#include <stdbool.h>
#include <stdio.h>
// 14. Usun z tekstu pierwsze wystapienie wybranego znaku.

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
    for (int i = position; text[i] != '\0'; i++) {
      text[i] = text[i + 1];
    }
    printf("Tekst po usunieciu znaku: %s\n", text);
  } else {
    printf("Znak '%c' nie znaleziony w tekscie.\n", target);
  }

  return 0;
}