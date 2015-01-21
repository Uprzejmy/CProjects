#include <stdio.h>
#include <math.h>

double series(double x, double y);

int main()
{
  double x,y,start,end,interval;
  int pointsToPrint=10;

  printf("Podaj początek przedziału: \n");
  scanf("%lf",&start);
  printf("Podaj koniec przedziału: \n");
  scanf("%lf",&end);
  printf("Podaj wykladnik potegi: \n");
  scanf("%lf",&y);

  if(y<0)
  {
    if(x<=-1 || x>=1);
    {
      printf("Jeżeli podany wykładnik jest mniejszy od 0, przedział x musi pozostać w przedziale (-1,1)\n");
      start = -0.999999;
      end = 0.9999999;
    }
  }

  interval=(end-start)/pointsToPrint;
  printf("    |    x       |pow((1+x),y)|   szereg(x) |\n");
  printf("    ----------------------------------------\n");
  for(x=start;x<=end;x+=interval)
  {
    printf("    | %10.6lf | %10.6lf | %10.6lf  |\n",x,pow((1+x),y),series(x,y));
  }

  return 0;
}

double series(double x, double y)
{
  double element = 1;
  double sum = 1;
  int i;
  int precision = 500;

  for(i=1;i<=precision;i++)
  {
    element *= x * (y-i+1) / i;
    sum += element;
  }

  return sum;
}