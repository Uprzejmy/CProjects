#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMatrix(int*** matrix, int n, int m);
void printMatrix(int** matrix, int n, int m);
void multiplication(int** matrix, int** vector, int*** wynik, int n, int m);

int main (void) 
{
  int i,n,m;
  int** matrix;
  int** vector;
  int** wynik;

  srand(time(NULL));

  printf("Podaj szerokosc macierzy\n");
  scanf("%d",&n);
  
  printf("Podaj wysokosc macierzy\n");
  scanf("%d",&m);
  
  generateMatrix(&matrix, n, m);
  generateMatrix(&vector, 1, n);
  generateMatrix(&wynik, 1, m);

  multiplication(matrix, vector, &wynik, n, m);
  
  printMatrix(matrix,n,m);
  printMatrix(vector,1,n);
  printMatrix(wynik,1,m);

  for(i=0;i<m;i++)
  {
    free(matrix[i]);
  }

  for(i=0;i<n;i++)
  {
    free(vector[i]);
  }

  for(i=0;i<m;i++)
  {
    free(wynik[i]);
  }
  
  free(matrix);
  free(vector);
  free(wynik);

  return 0;
}

void generateMatrix(int*** matrix, int n, int m)//n - szerokosc, m - wysokosc
{
  int i,j;

  *matrix = (int**)malloc(m * sizeof(int*));
   
  for(i=0;i<m;i++)
  {
    (*matrix)[i]=(int*)malloc(n * sizeof(int)); 
  }
  
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      (*matrix)[j][i] = rand()%9;
    }
  }
  
  return;
}

void printMatrix(int** matrix, int n, int m)
{
  int i,j;
  
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d ", matrix[j][i]);
    }
    
    printf("\n");
  }
  
  printf("\n\n");
  
  return;
}

void multiplication(int** matrix, int** vector, int*** wynik, int n, int m)
{
  int i,j;
  
  for(i=0;i<m;i++)
  {
    (*wynik)[0][i] = 0;
    for(j=0;j<n;j++)
    {
      (*wynik)[0][i] += matrix[j][i] * vector[0][j];
    }

  }
}
