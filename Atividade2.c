#include <stdio.h>
#include <stdlib.h>

/*
Matheus Ramos Esteves
Ra: 156732
Atividade 2: recursão
*/

int quantidade(int quant, int p, int v );

/* d = dinheiro que possui
   p = preço do livro
   v = quantidade de vales para mais uma compra */

int main(void) {
  //declaraçao de variaveis
  int d,p,v;
  int N, i, quant, vales;
  
  //scaneia o tamanho do vetor
  scanf("%d", &N);
  //condição que o N nao pode ser maior que 10 ou menor que 1
  if((N>10)||(N<1))
    return 0;

  //laço for para pegar os valores para a quantidade, preço e vale compras
  for(i=0; i<N; i++){
    scanf("%d %d %d", &d, &p, &v);
    quant = d/p;
    vales = quant;
    printf("%d\n", quantidade(quant, vales, v));
  }  
  
  return 0;
}

//função recursiva para saber a quantidade de livros que podem ser adquiridos
int quantidade(int quant, int vales, int v){
  int livros;
  //condição para a recursão
  if(vales >= v){
    livros = vales/v;
    quant = livros + quant;
    vales = livros + (vales%v); //atualiza a quantidade dos vales
    return quantidade(quant, vales, v);
  }
  return quant;  
}

/*
OBS: foi dito que não era necessário a alocação dinâmica para o exercício
*/