#define _USE_MATH_DEFINES
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
// 18. Zaproponuj i zaimplementuj algorytm, który przesunie zawartość N-elementowej tablicy
// cyklicznie o jedną pozycję „w górę”. (tzn. pierwszy element na miejsce drugiego, drugi na
// trzeci, ..., ostatni na pierwszy).

int main(void) {
  int array[] = {1, 2, 3, 4, 5};
  int N = sizeof(array) / sizeof(array[0]);
  int temp = array[N - 1]; // Przechowujemy ostatni element
  for (int i = N - 1; i > 0; i--) {
    array[i] = array[i - 1]; // Przesuwamy elementy w górę
  }
  array[0] = temp; // Umieszczamy ostatni element na początku
  printf("Tablica po przesunięciu: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}