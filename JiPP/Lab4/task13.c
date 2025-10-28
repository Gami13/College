#include <stdio.h>
// Utwórz plik tekstowy z wiadomością : "I <3 programming".Napisz program, który
// będzie odczytywał wiadomość z pliku po jednym znaku i wyświetlał ją na
// ekranie.Skorzystaj z pętli while.Podpowiedź : sprawdź jakie wartości zwraca
// funkcja fscanf w przypadku, gdy dojdzie do końca pliku.
int main(void) {
  FILE *file = fopen("message.txt", "r");
  if (file == NULL) {
    perror("Nie można otworzyć pliku");
    return 1;
  }
  char c;
  while (fscanf(file, "%c", &c) == 1) {
    printf("%c", c);
  }
  fclose(file);
  return 0;
}
