// 17. Wstaw jedną linię teksu po linii o numerze n.

#include <stdio.h>

#define BASE_LINE_COUNT 5
#define TOTAL_LINES (BASE_LINE_COUNT + 1)

static void clear_line(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main(void) {
  const char *lines[TOTAL_LINES] = {
      "Ala ma kota", "Kot ma Ale", "Trzecia linia tekstu", "Czwarta linia", "Piaty wiersz",
  };
  int current_lines = BASE_LINE_COUNT;
  const char new_line[] = "Nowa dopisana linia";

  printf("Dostepny tekst:\n");
  for (int i = 0; i < current_lines; ++i) {
    printf("%2d: %s\n", i + 1, lines[i]);
  }
  printf("Linia do wstawienia: %s\n", new_line);

  int insert_after;
  printf("Podaj numer linii, po ktorej wstawic nowa linie (1-%d): ", current_lines);
  if (scanf("%d", &insert_after) != 1 || insert_after < 1 || insert_after > current_lines) {
    fprintf(stderr, "Niepoprawny numer linii.\n");
    return 1;
  }
  clear_line();

  int new_index = insert_after; // 1-based -> po wskazanej linii
  for (int i = current_lines; i > new_index; --i) {
    lines[i] = lines[i - 1];
  }
  lines[new_index] = new_line;
  ++current_lines;

  printf("\nTekst po wstawieniu:\n");
  for (int i = 0; i < current_lines; ++i) {
    printf("%2d: %s\n", i + 1, lines[i]);
  }

  return 0;
}