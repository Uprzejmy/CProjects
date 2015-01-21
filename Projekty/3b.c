// Napisz program w C, który wczytuje wierszami tablicę typu int A o K kolumnach i W
// wierszach. Utwórz wektor wynik, w którym zapamiętasz indeksy tych elementów, które są
// liczbami trzycyfrowymi. Tablicę należy przeglądać kolumnami. 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createMatrix(int*** matrix, int k, int w);
void printMatrix(int** matrix, int k, int w);
void destroyMatrix(int*** matrix, int k, int w);
int checkMatrixForThreeDigitsNumbers(int** matrix, int*** threeDigitsIndexes, int k, int w);

int main()
{
  int i,j,l,m;

  int** matrix;
  int** threeDigitsIndexes;//tablica dwuwymiarowa o k*w - kolumnach i 2 wierszach
  int k=3;
  int w=8;

  srand(time(NULL));

  createMatrix(&matrix,k,w);

  // for(i=0;i<w;i++)
  // {
  //   for(j=0;j<k;j++)
  //   {
  //     matrix[i][j] = rand()%9999;
  //   }
  // }

  createMatrix(&threeDigitsIndexes,k*w,2);

  // printMatrix(matrix,k,w);

  for(m=0;m<100;m++)
  {
    for(i=0;i<w;i++)
    {
      for(j=0;j<k;j++)
      {
        matrix[i][j] = rand()%9999;
      }
    }

    l = checkMatrixForThreeDigitsNumbers(matrix, &threeDigitsIndexes, k, w);

    printMatrix(threeDigitsIndexes,l,2);
  }

  destroyMatrix(&threeDigitsIndexes,k*w,2);
  destroyMatrix(&matrix,k,w);

  return 0;
}


void createMatrix(int*** matrix, int k, int w)
{
  int i,j;

  *matrix = (int**)malloc(w * sizeof(int*));
   
  for(i=0;i<w;i++)
  {
    (*matrix)[i]=(int*)malloc(k * sizeof(int)); 
  }
  
  for(i=0;i<w;i++)
  {
    for(j=0;j<k;j++)
    {
      (*matrix)[i][j] = -1;
    }
  }
  
  return;
}

void printMatrix(int** matrix, int k, int w)
{
  int i,j;
  
  for(i=0;i<w;i++)
  {
    for(j=0;j<k;j++)
    {
      printf("%4d ", matrix[i][j]);
    }
    
    printf("\n");
  }
  
  printf("\n\n");
  
  return;
}

void destroyMatrix(int*** matrix, int k, int w)
{
  int i;

  for(i=0;i<w;i++)
  {
    free((*matrix)[i]);
  }

  free(*matrix);

  return;
}

int checkMatrixForThreeDigitsNumbers(int** matrix, int*** threeDigitsIndexes, int k, int w)
{
  int i,j;
  int l=0;//iterator po wierszach macierzy threeDigitsIndexes

  for(j=0;j<k;j++)
  {
    for(i=0;i<w;i++)
    {
      if(matrix[i][j]>=100 && matrix[i][j]<1000)
      {
        // printf("i: %d,j: %d, wartosc: %d\n", i,j,matrix[i][j]);
        (*threeDigitsIndexes)[0][l] = i;
        (*threeDigitsIndexes)[1][l++] = j;
      }
    }
  }

  return l;
}