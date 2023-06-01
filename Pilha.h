#ifndef PILHA_h
#define PILHA_h
#include <stdio.h>
#define MAX_PILHA 100


typedef char tp_item; 
//vari�vel de tamanho do vetor. foi feita outra structure para essa vari�vel pra n especificar o tipo da vari�vel

typedef struct{
	int topo; //variavel para mostrar o topo
	tp_item item[MAX_PILHA];
}tp_pilha;


// inicializa pilha
int inicializa_pilha(tp_pilha *p){ //passagem de par�metro por ponteiro
p->topo = -1; //p apontando para topo e declarando seu valor como -1

}

int pilha_vazia(tp_pilha *p){
	if(p->topo == -1)return 1;  //valor do topo definido como -1 = pilha vazia.
	else return 0; //caso n esteja vazia, retorna 0.
}

// verificando se a pilha ta cheia

int pilha_cheia(tp_pilha *p) {
	if(p->topo == MAX_PILHA - 1){
		return 1; //pilha de 100 elementos, de 0 a 99, ou seja, se o topo for 100-1(99) a pilha est� cheia, retorna 1
	}else{
		return 0; //pilha n�o est� cheia, retorna 0
	}
}

int push(tp_pilha *p, tp_item e){
	if(pilha_cheia(p)) return 0; 		//pilha possui espa�o
	p->topo++; 							//�ndice do topo aumenta 1 para novo conte�do
	p->item[p->topo] = e; 				//valor de e guardado dentro de item na posi��o que o topo indica
	return 1;
	
}

int pop(tp_pilha *p, tp_item *e){ //primeiro par�metro = pilha, segundo par�metro endere�o de e
	if(pilha_vazia(p) == 1) return 0;
	*e=p->item[p->topo]; //e recebe o valor da vari�vel do topo da lista
	p->topo--;	//diminui um �ndice do topo
	return 1;
}  


int top(tp_pilha *p, tp_item *e){
	if(pilha_vazia(p)) return 0;
	
	*e=p->item[p->topo];
	return 1;
}

	
altura_pilha(tp_pilha *p){
		return p->topo+1;
	}
	
void imprime_pilha(tp_pilha p){
		tp_item e;
		printf("Pilha\n");
		while(pilha_vazia(&p) == 0){
			pop(&p, &e);
			printf("%d\n", e);
		}
	}
	
	
void retira_impares(tp_pilha *p){
	tp_pilha paux;
	inicializa_pilha(&paux);
	tp_item e;
	//desempilha a pilha original e armazena apenas os pares na pilha auxiliar
	while (pilha_vazia(p)==0){
		pop(p,&e);
		if (e%2==0) // conferindo se e par
			push(&paux,e);
	} // fim do while
	
	while (!pilha_vazia(&paux)){
			pop(&paux,&e);
			push(p,e);
			
	}
	

	}
	
int pilhas_iguais(tp_pilha p1, tp_pilha p2){
tp_item e1,e2;			
if(altura_pilha(&p1)    != altura_pilha(&p2))
	return 0;		
	while(!pilha_vazia(&p1)){			
	pop(&p1,&e1);
	pop(&p2,&e2);
	if(e1 != e2) return 0;	
}
 	return 1;
 	
}

int empilha_pilhas(tp_pilha *p1, tp_pilha *p2){
		tp_item e;
		tp_pilha paux;
		inicializa_pilha(&paux);
		if (altura_pilha(p1)+altura_pilha(p2) > MAX_PILHA) return 0;
		while (!pilha_vazia(p2)) {
				pop(p2,&e);
				push(&paux,e);
			}
		while (!pilha_vazia(&paux)){
			pop(&paux, &e);
			push(p1,e);
		}
		
		return 1;
		
}




void iguala_pilhas(tp_pilha *p1, tp_pilha *p2){
	tp_item topo;
	int tamanho1 = altura_pilha(p1);
	int tamanho2 = altura_pilha(p2);
	int i = 0;
	int j =0;
	pop(p1, &topo);
	inicializa_pilha(p1);
	inicializa_pilha(p2);
	while(i != tamanho1){
		push(p1, topo);
		i++;
	}
	while(j != tamanho2){
		push(p2, topo);
		j++;
	}
		
}

 

#endif




