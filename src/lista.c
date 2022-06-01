#include "lista.h"

void Swap(Block *a, Block *b){
	Item aux;
	aux = a->data;
	a->data = b->data;
	b->data = aux;
	
}

void FLVazia(Lista *l){
	l->first = (Block*) malloc (sizeof(Block));
	l->last  = l->first;
	l->first->prox = NULL;
}

void LInsert(Lista *l, Item d){
	l->last->prox = (Block*) malloc (sizeof(Block));
	l->last = l->last->prox;
	l->last->data = d;
	l->last->prox = NULL;
}

void LRemove(Lista *l, Item d){
	Block *aux, *tmp;

	if(l->first == l->last || l == NULL || l->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = l->first;
	while(aux->prox != NULL){
		if (aux->prox->data.val == d.val){
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			if (aux == l->last) {
				l->last = tmp;
            }
			free(aux);
		}
		else
			aux = aux->prox;
	}
}


void LImprime(Lista *l){
	Block *aux;

	aux = l->first->prox;
	while(aux != NULL){
		printf("%d\n", aux->data.val);
		aux = aux->prox;
	}

}

void Initialize(Lista *l, int size) {
    srand(42);
    Item aux;

    for(int i=0; i<size; i++) {
        aux.val = rand()%100;
        LInsert(l, aux);
    }
}

void CountEvenOdd(Lista *l) {
	Block *aux;
    int even=0, odd=0;

	aux = l->first->prox;
	while(aux != NULL){
        if(aux->data.val % 2 == 0)
            even++;
        else
            odd++;
		aux = aux->prox;
	}

    printf("\nNumero de pares: %d\nNumero de Impares: %d\n", even, odd);
}

void RecursiveCountEvenOdd(Lista *l) {
    Block *aux;
    int count[] = {0,0};

    aux = l->first->prox;
    if(aux != NULL) {
        Recursion(aux, count);
    }

    printf("\nNumero de pares: %d\nNumero de Impares: %d\n", count[0], count[1]);
}

void Recursion(Block *aux, int* count) {
    if(aux == NULL)
        return;
    else {
        if(aux->data.val % 2 == 0)
            count[0]++;
        else
            count[1]++;
        Recursion(aux->prox, count);
    }
}