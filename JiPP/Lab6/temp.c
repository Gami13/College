#include "stdio.h"
int main(void) {
  // take input of one char and print it out including the ascii code
  int c = getchar();
  if (c != EOF) {
    printf("Character: %c, ASCII code: %d\n", c, c);
  } else {
    fprintf(stderr, "Nie udalo sie odczytac znaku.\n");
  }
  return 1;
}