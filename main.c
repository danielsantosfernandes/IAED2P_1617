// Daniel Fernandes 86400

#include "aux.h"

link head;			//cabeca da arvore
int contador;		//numero de produtos no sistema
Item maior;			//item com maior quant e menor chave

int main() {

	char com=0;
	contador=0;
	maior=NULL;

	STinit();		//inicializa a arvore
	
	while(com!='x') {

		com=getchar();

		switch(com) {

			case 'a': //adiciona ou atualiza produto
				adiciona();	
				break;
			case 'l': //lista os produtos
				lista();
				break;
			case 'm': //escreve o produto com mais unidades
				escreveMaior();
				break;
			case 'r': //remove um produto
				remover();
				break;
			case 'x': //termina
				acaba();
				return EXIT_SUCCESS;
			default:
				break;
		}

	}

	return EXIT_FAILURE;
}
