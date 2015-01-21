#include <stdio.h>
int main()
{
  int sum = 0;
  int countOfNumbers = 0;
  double average = 0;
  int x;
  printf( "\nProszę podać ciąg liczb rozdzielonych enterem, program policzy średnią liczb podzielnych przez 3.\nŻeby zakończyć wprowadzanie danych, wpisz literę k i potwierdź enterem.\n" );
  while (scanf("%d", &x) == 1)
  {
    if(x % 3 == 0)
    {
      countOfNumbers++;
      sum += x;
    }
  }
  if(countOfNumbers == 0)
  {
    printf( "\nNie podano żadnej liczby podzielnej przez 3\n" );
  }
  else
  {
    printf( "\nSzukana średnia to: %.2lf\n", average = sum/countOfNumbers );
  }
  getchar();
  return 0;
}