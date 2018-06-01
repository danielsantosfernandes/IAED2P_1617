#include "tree.h"


void STinit() {
	head = NULL; 
}

link newNode(Item item, link l, link r, int N) {

	link x = (link) malloc(sizeof(struct node));
	x->item = item;
	x->l = l;
	x->r = r;
	x->N = N;

	return x;
}

link search(link h, Key v) {

	if (h == NULL)
		return NULL;
	if (eq(v, key(h->item)))
		return h;
	if (less(v, key(h->item)))
		return search(h->l, v);
	else
		return search(h->r, v);
}

link max(link h) {
	
	while(h!=NULL && h->r!=NULL)
		h=h->r;
	
	return h;
}

link deleteNode(link h, Key k) {

	if (h==NULL) return h;
	else if (less(k, key(h->item))) h->l=deleteNode(h->l,k);
	else if (less(key(h->item), k)) h->r=deleteNode(h->r,k) ;
	else {
		if (h->l !=NULL && h->r !=NULL){
			link aux=max(h->l);
			{ Item x; x=h->item; h->item=aux->item; aux->item=x; }
			h->l= deleteNode(h->l, key(aux->item));
		}
		else {
			link aux=h;
			if ( h->l == NULL && h->r == NULL ) h=NULL;
			else if (h->l==NULL) h=h->r;
			else h=h->l;
			deleteItem(aux->item);
			free(aux);
			contador--;								//decrementa-se o contador se encontrar o Item
		}
	}
	h = AVLbalance(h);
	return h;
}

int height(link h){
  if (h == NULL) return 0;
  return h->N;
}


void traverse(link h) {
	if (h == NULL)
		return;

	traverse(h->l);
	visitItem(h->item);
	traverse(h->r);
}


link rotL(link h) {
	int height_left, height_right;
	link x = h->r;
	h->r = x->l;
	x->l = h;

	height_left = height(h->l);
	height_right = height(h->r);
	h->N = height_left > height_right ? height_left + 1 : height_right + 1;

	height_left = height(h->l);
	height_right = height(x->r);
	x->N = height_left > height_right ? height_left + 1 : height_right + 1;

	return x;
}

link rotR(link h) {
	int height_left, height_right;
	link x = h->l;
	h->l = x->r;
	x->r = h;

	height_left = height(h->l);
	height_right = height(h->r);
	h->N = height_left > height_right ? height_left + 1 : height_right + 1;

	height_left = height(x->l);
	height_right = height(h->r);
	x->N = height_left > height_right ? height_left + 1 : height_right + 1;

	return x; 
}

link rotLR(link h) {

	if (h==NULL) return h;
	h->l=rotL(h->l);
	return rotR(h); 
}

link rotRL(link h) {

	if (h==NULL) return h;
	h->r=rotR(h->r); 
	return rotL(h); 
}

int balance(link h) { 
	if (h == NULL) return 0; 
	return height(h->l)-height(h->r); 
} 

link AVLbalance(link h) {    
	int balanceFactor, height_left, height_right;

	if (h==NULL) return h;

	balanceFactor = balance(h); 

	if (balanceFactor > 1) { 
		if (balance(h->l) > 0) h = rotR(h); 
		else h = rotLR(h);  
	} 
	else if (balanceFactor < -1) { 
		if (balance(h->r) < 0) h = rotL(h); 
		else h = rotRL(h); 
	} 
	else {
		height_left = height(h->l);
		height_right = height(h->r);
		h->N = height_left > height_right ?  height_left + 1 : height_right + 1;
	}

	return h; 
} 

link insertR(link h, Item item) 
{
  if (h == NULL) 
    return newNode(item, NULL, NULL, 1);
  if (less(key(item), key(h->item)))
    h->l = insertR(h->l, item);
  else 
    h->r = insertR(h->r, item);

  h = AVLbalance(h);

  return h;
}


link freeR(link h) {
	if (h==NULL) 
		return h;
	h->l=freeR(h->l);
	h->r=freeR(h->r);
	return deleteNode(h,key(h->item));
}
