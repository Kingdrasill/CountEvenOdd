#include "lista.h"

int main()
{
	Lista l;
    int size = 0;

	FLVazia(&l);

    printf("Tamnaho da lista: ");
    scanf("%d", &size);

    Initialize(&l, size);
    
    LImprime(&l);

    printf("\nNão recursivo:\n");
    CountEvenOdd(&l);
    printf("\nRecursivo:\n");
    RecursiveCountEvenOdd(&l);

	return 0;
}