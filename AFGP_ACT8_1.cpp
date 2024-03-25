// Abraham Felipe Gonzalez Paez 00375052
// LLnear vectores manualmente, aleatoriamente y llenar matriz
// 22/03/2024
// AFGP_ACT8_1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 20
// PROTOTIPOS
int msges();
void menu();
void llenarVectorManualmente(int vector[], int longitud);
void llenarVectorAleatoriamente(int vector[], int longitud);
void llenarVectorConVectores(int vector1[], int vector2[], int vector3[]);
void imprimirVectores(int vector1[], int vector2[], int vector3[]);
void llenarMatriz(int matriz[4][4], int vector1[], int vector2[]);
void imprimirMatriz(int matriz[4][4]);
//  MAIN
int main()
{
  menu();

  return 0;
}
//  FUNCIONES
int msges()
{
  int op;
  printf("\nMENÚ\n");
  printf("1.- LLENAR VECTOR 1 (MANUALMENTE)\n");
  printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE\n");
  printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)\n");
  printf("4.- IMPRIMIR VECTORES\n");
  printf("5.- LLENAR MATRIZ 4 X 4\n");
  printf("6.- IMPRIMIR MATRIZ\n");
  printf("0.- SALIR\n");
  scanf("%d", &op);
  return op;
}
//.................
void menu()
{
  int op;
  int vector1[N];
  int vector2[N];
  int vector3[M];
  int matriz[4][4];
  do
  {
    op = msges();
    switch (op)
    {
    case 1:
      llenarVectorManualmente(vector1, N);
      break;
    case 2:
      llenarVectorAleatoriamente(vector2, N);
      break;
    case 3:
      llenarVectorConVectores(vector1, vector2, vector3);
      break;
    case 4:
      imprimirVectores(vector1, vector2, vector3);
      break;
    case 5:
      llenarMatriz(matriz, vector1, vector2);
      break;
    case 6:
      imprimirMatriz(matriz);
      break;
    }

  } while (op != 0);
}

//.......................................................
void llenarVectorManualmente(int vector[], int longitud)
{
  printf("Ingrese %d números para el vector:\n", longitud);
  for (int i = 0; i < longitud; i++)
  {
    printf("Elemento %d: ", i + 1);
    scanf("%d", &vector[i]);
  }
}

//..........................................................
void llenarVectorAleatoriamente(int vector[], int longitud)
{
  srand(time(NULL));
  int numeros_disponibles[20];

  for (int i = 0; i < 20; i++)
  {
    numeros_disponibles[i] = i + 1;
  }

  printf("Vector llenado aleatoriamente:\n");
  for (int i = 0; i < longitud; i++)
  {
    int indice = rand() % (20 - i);
    vector[i] = numeros_disponibles[indice];
    printf("%d ", vector[i]);
    for (int j = indice; j < 19 - i; j++)
    {
      numeros_disponibles[j] = numeros_disponibles[j + 1]; 
    }
  }
  printf("\n");
}
//........................................................................
void llenarVectorConVectores(int vector1[], int vector2[], int vector3[])
{
  printf("Vector 3 llenado con los datos de Vector 1 y Vector 2:\n");
  for (int i = 0; i < N; i++)
  {
    vector3[i] = vector1[i];
  }
  for (int i = N; i < M; i++)
  {
    vector3[i] = vector2[i - N];
  }
}
//................................................................
void imprimirVectores(int vector1[], int vector2[], int vector3[])
{
  printf("Vector 1:\n");
  for (int i = 0; i < N; i++)
  {
    printf("%d ", vector1[i]);
  }
  printf("\n");

  printf("Vector 2:\n");
  for (int i = 0; i < N; i++)
  {
    printf("%d ", vector2[i]);
  }
  printf("\n");

  printf("Vector 3:\n");
  for (int i = 0; i < M; i++)
  {
    printf("%d ", vector3[i]);
  }
  printf("\n");
}
//...................................................................................
void llenarMatriz(int matriz[4][4], int vector1[], int vector2[])
{
  printf("Matriz llenada con los datos de Vector 1 y Vector 2:\n");
  int k = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (k < N)
        matriz[i][j] = vector1[k];
      else
        matriz[i][j] = vector2[k - N];
      k++;
    }
  }
}
//................................................
void imprimirMatriz(int matriz[4][4])
{
  printf("Matriz:\n");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}