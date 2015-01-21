//gcc -g -Wall 91.c -o 91 -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sinus(double x);

int main(int argc, char *argv[])
{
  if(argc != 4)
  {
    printf("Nie podales odpowiedniej liczby argumentow, prawidlowe wywolanie to: ./91 lewy_koniec prawy_koniec ilosc_podzialow\n");
    return 1;
  }

  double left = strtod(argv[1], NULL);
  double right = strtod(argv[2], NULL);
  double partition = strtod(argv[3], NULL);
  double offset = (right-left)/partition;
  double x = left;

  FILE* fop1;
  FILE* fop2;

  fop1=fopen("sinus_dokladny.txt", "w+");
  fop2=fopen("sinus_szereg.txt", "w+");

  fprintf(fop1, "%10s  |  %.10s\n", "x", "sin(x)");
  fprintf(fop2, "%10s  |  %.10s\n", "x", "sin(x)");

  while(x<=right)
  {
    fprintf(fop1, "%.8lf  |  %.8lf\n", x, sin(x));
    fprintf(fop2, "%.8lf  |  %.8lf\n", x, sinus(x));

    x += offset;
  }

  fclose(fop1);
  fclose(fop2);

  return 0;
}

double sinus(double x)
{
  int i;
  int n = 10;//ilosc krokow
  double top = x;
  double bottom = 1;
  int sign = 0;//0 - dodatni, 1 - ujemny jak bit znaku w U2 ^^
  double sum = x;

  for(i=0;i<n;i++)
  {
    sign = 1-sign;
    top *= x*x;
    bottom *= (2*i+2)*(2*i+3);

    if(sign)
    {
      sum -= top/bottom;
    }
    else
    {
      sum += top/bottom;
    }
  }

  return sum;
}