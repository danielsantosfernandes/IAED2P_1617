#ifndef _ST_
#define _ST_

#include "produto.h"

typedef struct node* link;

struct node {
	Item item; 
	link l, r;
	int N;
};

extern link head;
extern int contador;

void STinit();
link newNode(Item, link, link, int);
link search(link,Key);
link insertR(link,Item);
link max(link);
link deleteNode(link,Key);
int height(link);
void traverse(link);
link rotL(link);
link rotR(link);
link rotLR(link);
link rotRL(link);
int balance(link);
link AVLbalance(link);
link freeR(link);

#endif
