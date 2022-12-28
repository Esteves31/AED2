#include <stdio.h>
#include <stdlib.h>

/*
Matheus Ramos Esteves;
AED II;
Atividade 1: Busca binária.
*/

//prototipo da funcao de busca
int Busca(int num, int *vet, int ini, int fim, int cont);

int main(void) {
  //declaracao das variaveis
  int N, *vet, num;
  int i=0, cont=0;
  
  scanf("%d", &N);
  //alocando espaço dinamicamente no vetor
  vet = (int *)(malloc(N * sizeof(int)));
  
  //laço para colocar os valores nos vetores
  for(i=0; i<N; i++){
    scanf("%d ", &vet[i]);
  }
  
  //pede o numero que o usuario deseja pesquisar
  scanf("%d", &num);
  
  //chama e verifica o retorno da funcao para saber se o numero foi achado
  if(Busca(num, vet, 0, N-1, cont) == 0){
    printf("%d nao foi encontrado", num);
  }
  else{
    printf("%d" ,Busca(num, vet, 0, N-1, cont));
  }
  
  //libera o vetor
  free(vet);
  return 0;
}

int Busca(int num, int *vet, int ini, int fim, int cont){
  int meio;
  if(ini <= fim){
    meio = (ini+fim)/2;
    if(num== vet[meio]){
      return cont;
    }
    if(num > vet[meio]){
      cont++;
      return Busca(num, vet, meio+1, fim, cont);
    }
    else{
      cont++;
      return Busca(num, vet, ini, meio-1, cont);
    }   
  }
  return meio;
}