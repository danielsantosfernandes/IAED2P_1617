#include "produto.h"

Item newItem(Key chave, int quant) {

	Item item = (Item) malloc(sizeof(struct Produto));
	item->chave = chave;
	item->quant = quant;

	return item;
}

void deleteItem(Item item) {
	
	free(item);
}

void visitItem(Item item) {

	printf("%08lx %d\n", key(item), quant(item));
	
}
