#define _USE_MATH_DEFINES
#include "stdio.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>

// 16. Dołącz tekst do innego tekstu.

int main(void) {
  char text1[100] = "Hello, ";
  char text2[] = "World!";
  strcat(text1, text2);
  printf("Połączony tekst: %s\n", text1);
  return 0;
}