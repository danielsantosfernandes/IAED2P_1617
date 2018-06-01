#include "aux.h"

void adiciona() {

	Key c;
	int q;
	Item i;
	link a;

	scanf("%lx", &c);
	scanf("%d", &q);

	a=search(head, c);					//verifica se o item ja existe

	if(a==NULL) {						//se nao, cria um novo, insere-o na arvore
										//e verifica se a quant e maior do que a do atual maior
		i=newItem(c, q);
		head=insertR(head, i);
		contador++;
		if (maior==NULL || quant(maior) < quant(i) || (quant(i) == quant(maior) && less(key(i), key(maior))))
			maior = i;
	}

	else {								//se sim, atualiza-o

		a->item->quant += q;
		if (quant(a->item)<0) a->item->quant=0;

		if (eq(key(maior), key(a->item)) && q<0) {		//se o item atualizado for o atual maior e caso se tenha diminuido
			link l=encontraMaior(head);					//a quantidade, procura um novo maior
			if(l==NULL) maior=NULL;
			else maior=l->item;
		}
														//se nao, verifica se a quant maior ou se e igual mas tem uma chave menor
		else if (quant(maior) < quant(a->item) || (quant(a->item) == quant(maior) && less(key(a->item), key(maior))))
			maior = a->item;
	}

}

void lista() {

	traverse(head);
}

void escreveMaior() {

	if(maior==NULL) return;

	visitItem(maior);

}

link encontraMaior(link h) {			//funcao recursiva que encontra o link com o item de maior quant
										//de cada sub-arvore e compara-os com a cabeca
	if(h==NULL) return NULL;

	link m = h;

	link a = encontraMaior(h->l);		//maior da esquerda
	link b = encontraMaior(h->r);		//maior da direita

	if (a!=NULL && quant(m->item) <= quant(a->item)) m=a;
	if (b!=NULL && quant(m->item)  < quant(b->item)) m=b;

	return m;

}

void remover() {

	Key c;

	scanf("%lx", &c);

	if(eq(key(maior),c)) {				//se for o atual maior, remove-se e procura-se o novo maior
		head=deleteNode(head, c);			
		link l=encontraMaior(head);
		if(l==NULL) maior=NULL;
		else maior=l->item;
	}

	else								//se nao, apenas se remove
		head=deleteNode(head, c);		//(a funcao deleteNode decrementa o contador se encontrar o Item)

}


void acaba() {

	printf("%d\n", contador);			//escreve o numero de produtos

	head=freeR(head);					//liberta a memoria ocupada pela arvore
}
