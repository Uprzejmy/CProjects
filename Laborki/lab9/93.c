//gcc -g -Wall 93.c -o 93 -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sinCosRad(double x, double* pSinValue, double* pCosValue, double* pDegreesValue);

int main()
{
  double x, sinValue, cosValue, degreesValue;
  double* pSinValue = &sinValue;
  double* pCosValue = &cosValue;
  double* pDegreesValue = &degreesValue;

  printf("Podaj wartosc do przeliczenia (w radianach)\n");
  scanf("%lf", &x);

  sinCosRad(x, pSinValue, pCosValue, pDegreesValue);

  printf("x = %lf rad\n", x);
  printf("sin(x) = %lf \n", sinValue);
  printf("cos(x) = %lf \n", cosValue);
  printf("x = %lf deg\n", degreesValue);

  return 0;
}


void sinCosRad(double x, double* pSinValue, double* pCosValue, double* pDegreesValue)
{
  *pSinValue = sin(x);
  *pCosValue = cos(x);
  *pDegreesValue = x / M_PI;//M_PI zdefiniowane w math.h
}