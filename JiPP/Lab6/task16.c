// 16. Wybierz z tekstu składającego się z wielu linii te linie, w których na początku znajduje się wybrany tekst.

#include <stdio.h>
#include <string.h>

#define LINE_COUNT 5

static void clear_line(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main(void) {
  const char *lines[LINE_COUNT] = {
      "Ala ma kota", "Kot ma Ale", "Ananas to owoc", "Pies biega szybko", "Programowanie w C",
  };

  const char *prefixes[] = {
      "A",
      "Kot",
      "Pro",
      "",
  };
  const int prefixes_count = (int)(sizeof(prefixes) / sizeof(prefixes[0]));

  printf("Dostepny tekst:\n");
  for (int i = 0; i < LINE_COUNT; ++i) {
    printf("%2d: %s\n", i + 1, lines[i]);
  }

  printf("\nDostepne prefiksy:\n");
  for (int i = 0; i < prefixes_count; ++i) {
    printf("%2d: '%s'\n", i + 1, prefixes[i][0] ? prefixes[i] : "(pusty)");
  }

  int choice;
  printf("Wybierz prefiks (1-%d): ", prefixes_count);
  if (scanf("%d", &choice) != 1 || choice < 1 || choice > prefixes_count) {
    fprintf(stderr, "Niepoprawny wybor prefiksu.\n");
    return 1;
  }
  clear_line();

  const char *prefix = prefixes[choice - 1];
  size_t prefix_len = strlen(prefix);

  int found = 0;
  printf("\nPasujace linie:\n");
  for (int i = 0; i < LINE_COUNT; ++i) {
    if (prefix_len == 0 || strncmp(lines[i], prefix, prefix_len) == 0) {
      printf("%s\n", lines[i]);
      found = 1;
    }
  }

  if (!found) {
    printf("Brak linii spelniajacych warunek.\n");
  }

  return 0;
}