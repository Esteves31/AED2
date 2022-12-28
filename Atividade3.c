#include <stdio.h>
#include <stdlib.h>

/*
Matheus Ramos Esteves  
Atividade 3: InsertionSort recursivo com busca binária
*/

//prototipo das funcoes utilizadas
void InsertionSort(int *vet, int chave, int nivel);
int Busca(int num, int *vet, int ini, int fim);

int main(void) {
  int *vet;
  int i, N, j; 

  //scaneia o tamanho do vetor
  scanf("%d", &N);
  
  //aloca espaço dinamicamente para o vetor
  vet = (int *)(malloc(N * sizeof(int)));
  
  //laço para colocar os valores nos vetores
  for(i=0; i<N; i++){
    scanf("%d", &vet[i]);
  }
  
  //chama a funcao insertionSort
  InsertionSort(vet, N, 1);
  
  //printa a nova ordem do vetor
  for(j=0; j<N; j++){
    printf("%d ", vet[j]);
  }
  
  //libera a o vetor alocado
  free(vet);
  return 0;
}

void InsertionSort(int *vet, int tam, int nivel){
  int chave, i, pos;
  //condicao de parada da recursao é se o tamanho for menor ou igual a 1
  if(tam <= 1){
    return;  
  }
  //chama a funcao novamente até encontrar o menor subnivel
  InsertionSort(vet, tam-1, nivel+1);
  
  chave = vet[tam-1];
  i = tam-2;
  //posicao assume o valor encontrado pela funcao de busca binária
  pos = Busca(chave, vet, 0, i);
  //printa a saida desejada
  printf("%d %d %d\n", nivel, chave, pos);
  while(i >= 0 && vet[i] > chave){
    vet[i+1]= vet[i];
    i--;
  }
  //coloca o numero no vetor correto
  vet[pos] = chave;
}

//funcao recursiva de busca binaria
int Busca(int num, int *vet, int ini, int fim){
  int meio;
    //encontra o meio do vetor para ser usado de base
    meio = ((fim-ini)/2)+ini;
    if(ini <= fim){
      if(num == vet[meio]){
        return meio++;
    }
    //chama a recursao caso o numero esteja depois do meio
    else if(vet[meio] < num)
      return Busca(num, vet, meio+1,fim);
    //se nao faz a recursao caso esteja antes
    else
      return Busca(num, vet, ini, meio-1);
    }
  return meio;
}