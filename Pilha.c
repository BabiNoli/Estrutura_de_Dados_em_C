// Created by Bárbara on 06.05.2025.
// Estruturas de dados dinâmicas
// Aula sobre Pilha em C (https://wagnergaspar.com/)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia, mes, ano;
}Data;

typedef struct {
  char nome[50];
  Data data;
}Pessoa;

typedef struct no{
  Pessoa p;
  struct no *prox;
}No;

// funcao para criar uma Pessoa
Pessoa ler_Pessoa(){
  Pessoa p;
  printf("\nDigite o nome do pessoa: \n\n");
  scanf("%49[^\n]", p.nome);
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  printf("\nDigite a data de nascimento de %s (dd mm aaa): \n\n", p.nome);
  scanf("%d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);

  return p;
}

//procedimento para imprimir as iformacoes de uma Pessoa
void imprimir_pessoa(Pessoa p){
  printf("\nNome: %s\nData: %02d/%02d/%04d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

//funcao para a operacao de push (empilhar)
No* empilhar(No *topo){
  No *novo = malloc(sizeof(No));

  if (novo){
    novo->p = ler_Pessoa();
    novo->prox = topo;
    topo = novo;
  }
  else {
    printf("Erro na alocacao de memoria...\n\n");
    return NULL;
  }
}

//funcao para a operacao de pop (desempilhar)
No* desempilhar(No **topo){
  if (*topo == NULL){
    printf("Erro na desempilhar. A Pilha esta vazia\n\n");
    return NULL;
  }
  else{
    No *remover = *topo;
    *topo = remover->prox;
    printf("Um elemento foi desempilhado do topo.\n\n");
    return remover;
  }
}

//procedimento para imprimir toda a pilha
void imprimir_pilha(No *topo){
  printf("\n----------------- PILHA -----------------\n");
  while (topo){
    imprimir_pessoa(topo->p);
    topo = topo->prox;
  }
  printf("\n-------------- FIM PILHA ---------------\n");
}

int main(){
  int count = 0;
  No *topo = NULL;
  No *remover;
  int opcao;

  do{
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n\nOpcao: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao){
      case 0:
        return 0;
        break;
      case 1:
        topo = empilhar(topo);
        count++;
        break;
      case 2:
        remover = desempilhar(&topo);
        if (remover){
          printf("\nElemento removido com Sucesso!.\n");
          imprimir_pessoa(remover->p);
          count--;
        }
        else
          printf("\nSem no a remover.\n");
        break;
      case 3:
        imprimir_pilha(topo);
        printf(" A pilha tem %d elemento(s)\n", count);
        break;
      default:
        printf("Opcao invalida\n\n");
    }
  }while(opcao != 0);
  return 0;
}