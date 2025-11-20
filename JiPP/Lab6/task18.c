// 18. Wybierz z teksu słowo o podanej pozycji. Załóż, że ogranicznikiem słowa jest dwukropek.

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 1024

static void trim_whitespace(char *text) {
  char *start = text;
  while (*start && isspace((unsigned char)*start)) {
    ++start;
  }
  char *end = start + strlen(start);
  while (end > start && isspace((unsigned char)end[-1])) {
    --end;
  }
  size_t len = (size_t)(end - start);
  memmove(text, start, len);
  text[len] = '\0';
}

int main(void) {
  const char text[] = "Ala: kot: programista: C: zadania: dwukropek";
  printf("Tekst z dwukropkami:\n%s\n", text);

  int position;
  printf("Podaj pozycje slowa (>=1): ");
  if (scanf("%d", &position) != 1 || position <= 0) {
    fprintf(stderr, "Niepoprawna pozycja.\n");
    return 1;
  }

  char copy[MAX_TEXT_LEN];
  strncpy(copy, text, sizeof(copy) - 1);
  copy[sizeof(copy) - 1] = '\0';

  char *token = strtok(copy, ":");
  int current = 1;
  while (token) {
    trim_whitespace(token);
    if (current == position) {
      printf("Slowo nr %d: %s\n", position, token[0] ? token : "(puste)");
      return 0;
    }
    token = strtok(NULL, ":");
    ++current;
  }

  printf("Brak slowa na pozycji %d.\n", position);
  return 0;
}