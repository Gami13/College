// 15. Zamień miejscami tekst z dwóch wybranych linii.

#include <stdio.h>

#define LINE_COUNT 5

static void clear_line(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main(void) {
  const char *lines[LINE_COUNT] = {
      "Ala ma kota", "Kot ma Ale", "Trzecia przykladowa linia", "Czwarta linia testowa", "Piaty wiersz tekstu",
  };

  printf("Dostepny tekst:\n");
  for (int i = 0; i < LINE_COUNT; ++i) {
    printf("%2d: %s\n", i + 1, lines[i]);
  }

  int first_line;
  int second_line;
  printf("Podaj dwie linie do zamiany (1-%d): ", LINE_COUNT);
  if (scanf("%d %d", &first_line, &second_line) != 2 || first_line < 1 || first_line > LINE_COUNT || second_line < 1 ||
      second_line > LINE_COUNT) {
    fprintf(stderr, "Niepoprawne numery linii.\n");
    return 1;
  }
  clear_line();

  const char *tmp = lines[first_line - 1];
  lines[first_line - 1] = lines[second_line - 1];
  lines[second_line - 1] = tmp;

  printf("\nPo zamianie:\n");
  for (int i = 0; i < LINE_COUNT; ++i) {
    printf("%2d: %s\n", i + 1, lines[i]);
  }

  return 0;
}