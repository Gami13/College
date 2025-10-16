#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

//Zad 8. Napisz program, który dla danych rzeczywistych x, y, z i całkowitych k, m policzy wartości
//następujących wyrażeń arytmetycznych 
void mainA() {
	double x = 3.14;
	double y = 12.56;
	double z = 7;
	int k = 2;
	int m = 4;

	double w1 = cbrt(x / (y * z)) * log(pow(x, 2) + pow(y, 2));
	double w2 = sin(k * (x / 2)) * cos(m * y) + y * exp(2 * x - 1);
	double w3 = fabs(x / (2.0 * y * y + 1.0)) + sqrt(y / (z * z + 3.0)) + (5.0 * pow(y + z, 3.0));
	double w4 = (x / (y * z)) * cbrt(z + 1) + pow(x * x + z * z + 1.0, 1.0 / k) - fabs(y);
	double w5 = 1.0 / sqrt(x * x + y * y + k * k) + (1.0 / x) * sin(k * y);
	printf("w1 = %.8lf \n", w1);
	printf("w2 = %.8lf \n", w2);
	printf("w3 = %.8lf \n", w3);
	printf("w4 = %.8lf \n", w4);
	printf("w5 = %.8lf \n", w5);
}

