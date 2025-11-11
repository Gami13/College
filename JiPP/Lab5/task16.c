#include "stdio.h"
#include <stdbool.h>
#include <string.h>

// 16. Dolacz tekst do innego tekstu.

int main(void) {
  char text1[100] = "Hello, ";
  char text2[] = "World!";
  strcat(text1, text2);
  printf("Polaczony tekst: %s\n", text1);
  return 0;
}