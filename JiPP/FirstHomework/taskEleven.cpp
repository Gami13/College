#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <tchar.h>
#pragma warning(disable:4996)


//Zad 11. Dane są cztery liczby całkowite a,b,c,d. Znaleźć wśród nich liczbę największą i wydrukować 
//jej wartość i pozycję przyjmując, że dla a(pozycja = 1), b(pozycja = 2) itd. (nie wprowadzać
//zmiennej indeksowanej).

int mainD(int argc, _TCHAR* argv[])
{
	double a = 0.0, b = 0.0, c = 0.0, d=0.0;
	int ret = -1;
	printf("Podaj a,b,c,d\n");
	ret = scanf("%le%le%le%le", &a, &b, &c, &d);
	if (ret != 4) {
		printf("Blad przy wczytaniu\n");
	}

	double max = a;
	int pos = 1;
	
	if (b > max) {
		max = b;
		pos = 2;
	}
	if (c > max) {
		max = c;
		pos = 3;
	}
	if (d > max) {
		max = d;
		pos = 4;
	}

	printf("Najwieksza liczba to %lf, na pozycji %d\n", max, pos);
	return 0;
}

