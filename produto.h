#ifndef _PRODUTO_
#define _PRODUTO_

#include <stdio.h>
#include <stdlib.h>

#define key(a) (a != NULL ? a->chave : -1)
#define quant(a) (a != NULL ? a->quant : 0)
#define less(a,b) (a<b)
#define eq(a,b) (a==b)

typedef unsigned long Key;

typedef struct Produto {

	Key chave;
	int quant;

} *Item;

Item newItem(Key, int);
void deleteItem(Item);
void visitItem(Item);



#endif
