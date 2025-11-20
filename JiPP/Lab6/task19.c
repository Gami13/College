//! uzyj cmd i najpierw chcp 852
// 19. Napisz program kodujący i dekodujący dowolne teksty posługując się alfabetem Morse’a. W rozwiązaniu możesz
// wykorzystać poniższe tablice.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char litery[] = {'a', 165, 'b', 'c', 134, 'd', 'e', 169, 'f', 'g', 'h', 'i', 'j', 'k', 'l', 136, 'm', 'n',
                 228, 'o', 162, 'p', 'q', 'r', 's', 152, 't', 'u', 'v', 'w', 'x', 'y', 'z', 190, 171, 'A',
                 164, 'B', 'C', 143, 'D', 'E', 168, 'F', 'G', 'H', 'I', 'J', 'K', 'L', 157, 'M', 'N', 227,
                 'O', 224, 'P', 'Q', 'R', 'S', 151, 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 189, 141, ' ', '.',
                 ',', '?', ':', '-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '!', '\0'};
const char *mors[] = {".-",      ".-.-",   "-...",   "-.-.",   "-.-..", "-..",     ".",     "..-..", "..-.",  "-.",
                      "....",    "..",     ".---",   "-.-",    ".-..",  ".-..-",   "--",    "-.",    "--.--", "---",
                      "--.",     ".--.",   "--.-",   ".-.",    "...",   "...-...", "-",     "..-",   "...-",  ".--",
                      "-..-",    "-.--",   "--..",   "--..-",  "--",    ".-",      ".-.-",  "-...",  "-.-.",  "-.-..",
                      "-..",     ".",      "....",   "..-.",   "--.",   "....",    "..",    ".---",  "-.-",   ".-..",
                      ".-..-",   "--",     "-.",     "--.-",   "---",   "---.",    ".--.",  "--.-",  ".-.",   "...",
                      "...-...", "-",      "..-",    "...-",   ".-",    "-..-",    "-.--",  "--..",  "--..-", "--",
                      " ",       ".-.-.-", "--..--", "..--..", "--...", "-....-",  "-----", ".----", "..---", "...--",
                      "....-",   ".....",  "-....",  "-...",   "---..", "----.",   "!",     0};

static int read_line(char *buffer, size_t size) {
  if (!fgets(buffer, (int)size, stdin)) {
    return 0;
  }
  buffer[strcspn(buffer, "\r\n")] = '\0';
  return 1;
}

static const char *code_for(unsigned char ch) {
  for (size_t i = 0; litery[i] != '\0'; ++i) {
    if ((unsigned char)litery[i] == ch) {
      return mors[i];
    }
  }
  return NULL;
}

static unsigned char letter_for(const char *token) {
  for (size_t i = 0; mors[i] != NULL; ++i) {
    if (strcmp(mors[i], token) == 0) {
      return (unsigned char)litery[i];
    }
  }
  return 0;
}

static void encode_text(void) {
  char text[256];
  printf("Podaj tekst do zakodowania: ");
  if (!read_line(text, sizeof(text))) {
    return;
  }

  for (size_t i = 0; text[i] != '\0'; ++i) {
    unsigned char symbol = (unsigned char)text[i];
    if (symbol == ' ') {
      printf("/ ");
      continue;
    }

    const char *code = code_for(symbol);
    printf("%s ", code ? code : "?");
  }
  putchar('\n');
}

static void decode_text(void) {
  char coded[512];
  printf("Podaj kod Morse'a (symbole oddziel spacjami): ");
  if (!read_line(coded, sizeof(coded))) {
    return;
  }

  char *token = strtok(coded, " ");
  while (token) {
    if (strcmp(token, "/") == 0) {
      putchar(' ');
    } else {
      unsigned char letter = letter_for(token);
      putchar(letter ? letter : '?');
    }
    token = strtok(NULL, " ");
  }
  putchar('\n');
}

int main(void) {
  char line[8];
  printf("Wybierz tryb (1-kodowanie, 2-dekodowanie): ");
  if (!read_line(line, sizeof(line))) {
    return 0;
  }

  int choice = (int)strtol(line, NULL, 10);

  if (choice == 1) {
    encode_text();
  } else if (choice == 2) {
    decode_text();
  } else {
    printf("Nieznana opcja.\n");
  }

  return 0;
}