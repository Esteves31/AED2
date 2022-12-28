#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

/*
Matheus Ramos Esteves
Atividade 5: ordenação por QuickSort
*/

void quicksort(int *vet, int inicio, int fim, int k);
int particiona(int *vet, int inicio, int fim);

int main(void) {
  int N, k, i, j;
  int *vet;
  
  scanf("%d", &k);
  scanf("%d", &N);
  vet = (int *)malloc(N*sizeof(int));

  for(i=0; i<N;i++){
    scanf("%d", &vet[i]);
  }
  
  quicksort(vet, 0, N-1, k);

  printf("%do menor elemento eh o %d\n", k, vet[k-1]);
  for(j=0; j<N; j++){
    printf("%d ", vet[j]);
  }
  
  free(vet);
  return 0;
}

void quicksort(int *vet, int inicio, int fim, int k){
  int pivo;
  if(fim > inicio){
    pivo = particiona(vet, inicio, fim);
    if(k-1 < pivo)
      quicksort(vet, inicio, pivo-1, k);
    if(k-1 > pivo)
      quicksort(vet, pivo+1, fim, k);
  }
}

int particiona(int *vet, int inicio, int fim){
  int x = vet[fim];
  int i = inicio - 1;
  int j, aux;
  
  for(j = inicio; j <= fim-1; j++){
    
    if(vet[j] <= x){
      i++;
      aux = vet[i];
      vet[i] = vet[j];
      vet[j] = aux;
    }
    
  }
  
  aux = vet[i+1];
  vet[i+1] = vet[fim];
  vet[fim] = aux;
  
  return (i+1);
}