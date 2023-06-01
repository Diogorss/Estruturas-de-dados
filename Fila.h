#ifndef FILA_H
#define FILA.H
#include <stdio.h>
#define MAX 100
#include "pilha.h"

typedef char tp_item;
typedef struct {
  tp_item item[MAX];
  int ini, fim;

}tp_fila;


void inicializa_fila(tp_fila *f){
  f->ini = f->fim = MAX-1;

}


int fila_vazia(tp_fila *f){
  if(f->ini == f->fim) return 1;
  return 0;
}

int proximo(int pos){
  if(pos== MAX-1)return 0;
  return ++pos;
}

int fila_cheia(tp_fila *f){
  if(proximo(f->fim)==f->ini)
    return 1;
  return 0;
}




int insere_fila(tp_fila *f, tp_item e){
  if(fila_cheia(f))
    return 0;
  f->fim = proximo(f->fim);
  f->item [f->fim]=e;
    return 1;
}

int remove_fila(tp_fila *f, tp_item *e){
  if(fila_vazia(f))
    return 0;
  f->ini = proximo(f->ini);
  *e = f->item[f->ini];

  return 1;
}

void imprime_fila(tp_fila f){
  tp_item e;
  printf("FIla:\n");
  while(!fila_vazia(&f)){
    remove_fila(&f, &e);
    printf("\n%c", e);
  }
}

int tamanho_fila(tp_fila *f){
  if(fila_vazia(f)) return 0;
  if(f->ini < f->fim) return f->fim - f->ini;
  return MAX -1 - f->ini + f->fim + 1;
}

void inverte_fila(tp_fila *f){
  tp_pilha paux;
  tp_item e;
  while(!fila_vazia(f)){
    remove_fila(f, &e);
    push(&paux, e);
  }
  while(!pilha_vazia(&paux)){
    pop(&paux,&e);
    insere_fila(f,  e);
  }
}

  void organiza_comboio(tp_fila *trem){
    tp_pilha desvio;
    tp_item e;
    int tam;
    inicializa_pilha(&desvio);
    tam = tamanho_fila(trem);
    for(int i=0; i <tam; i++){
      remove_fila(trem, &e);
      if(e== 'C') push(&desvio,e);
      else insere_fila(trem, e);
      tam = tamanho_fila(trem);
     for(int i = 0; i<tam; i++){
        remove_fila(trem, &e);
        if(e=='B') push (&desvio, e);
       else insere_fila(trem, e);
     while(!pilha_vazia(&desvio)){
       pop(&desvio, &e);
       insere_fila(trem, e);
     }    
      }
    }
  }

  



#endif
