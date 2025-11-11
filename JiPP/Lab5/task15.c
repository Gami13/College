#include <stdbool.h>
#include <stdio.h>
// 15. Zamien kazde wystapienie wybranego znaku na inny znak.

int main(void) {
  char text[] = "Hello, World!";
  char target = 'o';
  char replacement = 'a';
  for (int i = 0; text[i] != '\0'; i++) {
    if (text[i] == target) {
      text[i] = replacement;
    }
  }
  printf("Tekst po zamianie: %s\n", text);

  return 0;
}