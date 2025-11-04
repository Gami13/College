#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
// 19. Napisz funkcje:
// int moje_strcmp(const char*, const char*);
// char* moje_strcat(char*, const char*);
// char* moje_strcpy(char*, const char*);
// realizujące te same operacje co standardowe funkcje strcmp, strcat, strcpy z biblioteki <string.h>.
static int moje_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return (unsigned char)*str1 - (unsigned char)*str2;
}

static char *moje_strcat(char *dest, const char *src) {
  char *ptr = dest;
  while (*ptr) {
    ptr++;
  }
  while ((*ptr++ = *src++))
    ;
  return dest;
}

static char *moje_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  while ((*ptr++ = *src++))
    ;
  return dest;
}
int main(void) {
  char str1[100] = "Hello, ";
  char str2[100] = "Hello, ";
  char str3[] = "world!";
  printf("Porównanie: %d\n", moje_strcmp(str1, str2));
  printf("Klejenie: %s\n", moje_strcat(str1, str3));
  printf("Kopiowanie: %s\n", moje_strcpy(str1, str3));
  return 0;
}
