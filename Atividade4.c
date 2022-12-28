#include <stdio.h>
#include <stdlib.h>
#define less(A, B) (A < B)

/*
Matheus Ramos Esteves
RA: 156.732
Atividade 4: Merge Sort
*/

//struct da lista simplesmente encadeada
typedef struct lista {
  int num;
  struct lista *prox;
}Tlista;

//protótipo das funcoes utilizadas
Tlista* cria_lista();
Tlista* insere(Tlista* l, int v);
Tlista* mergesort(Tlista* lista);
Tlista* merge(Tlista* aux1, Tlista* aux2);
void libera(Tlista* lista);
void imprimir(Tlista *p);

int main(){
  int N, num, i;
  Tlista* lista = NULL;
    
  //scaneia o tamanho da lista
  scanf("%d", &N);

  //laço para scanear e inserir os valores na lista encadeada
  for(i=0;i<N;i++){
    scanf("%d", &num);
    lista = insere(lista, num);
  }
  int *p = &lista->num;

  /*chama a funca mergesort para a lista encadeada criada
  fazer sua ordenaçao e imprimir seu resultado ordenado*/
  imprimir(mergesort(lista));

  //funcao que libera a memoria da lista
  libera(lista);  
  return 0;
}

//funcao para alocar espaco para uma lista encadeada
Tlista* cria_lista(){
  Tlista* novo = (Tlista*)malloc(sizeof(Tlista));
  return novo;
}

//funcao para inserir elementos na lista encadeada
Tlista* insere(Tlista* l, int dado){
  //cria uma nova lista
  Tlista* novo = cria_lista();
  //coloca o valor pedido na struct
  novo->num = dado;

  //se a lista for = NULL, então o valor pedido sera o primeiro da lista
  if (l == NULL) {
    l = novo;
    novo->prox = NULL;
  }
  //se nao ele entrará no início da lista
  else {
    novo->prox = l;
    l = novo; 
  }
  //retorno a lista
  return l;
}

//funcao para liberar a memoria da lista
void libera(Tlista* lista){
  //uso de uma variavel auxiliar n
  Tlista *n;
  //laço para enquanto a lista não estiver vazia, desalocar a memoria
  while(lista!=NULL){
    /*n vai para a proxima posiçao da lista
    o numero é liberado e depois a lista toma o valor de n*/
    n=lista->prox;
    free(lista);
    lista=n;
  }
}

//funçao de merge para a lista
Tlista* merge(Tlista* aux1, Tlista* aux2){
  struct lista cabeca;
  Tlista* aux3 = &cabeca;

  //laço para se executar enquanto as listas não forem nulas
  while(aux1 != NULL && aux2 != NULL)
    if(less(aux1->num, aux2->num)){
      aux3->prox = aux1;
      aux3 = aux1; 
      aux1 = aux1->prox;
    }
    else{
      aux3->prox = aux2;
      aux3 = aux2;
      aux2 = aux2->prox;
    }
    aux3->prox = (aux1 == NULL) ? aux2 : aux1;
    return cabeca.prox; 
}

//funçao de MergeSort
Tlista* mergesort(Tlista* lista){
  Tlista* aux1;
  Tlista* aux2;
  //se a lista for vazia ou só houver um elemento, entao ja esta ordenado
  if(lista == NULL || lista->prox == NULL)
    return lista;

  //se não os auxiliares recebem o primeiro item da lista e o proximo
  aux1 = lista;
  aux2 = lista->prox;

  //laço para encontrar os ultimos elementos 2 a 2 da lista
  while(aux2 != NULL && aux2->prox != NULL){
    lista = lista->prox;
    aux2 = aux2->prox->prox;
  }
  aux2 = lista->prox;
  lista->prox = NULL;
  //chama a funçao de merge para fazer as trocas
  return merge(mergesort(aux1), mergesort(aux2));
}

//funcao para imprimir a lista encadeada
void imprimir(Tlista *p){
    /*enquanto a lista nao for vazia, imprime o seu numero e 
    passa o ponteiro para o proximo, até nao haver mais*/
    while(p!=NULL)
    {
        printf("%d ",p->num);
        p=p->prox;
    }
}