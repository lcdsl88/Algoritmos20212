/* Algoritmo do exercicio 1a do pdf de árvores elaborado com base nos ensinamentos da Aula 15 de Algoritmos 2021.2 08/12/2021 */

#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	int Altura;
	No * Esq;
	No * Dir;
} No;

// minha solucao proposta para o procedimento Atualiza Altura
int MeuAtualizaH (No *T){
	if (T==NULL){
		T->Altura = 0;
	} else {
		hesq=MeuAtualizaH(T->Esq);
		hdir=MeuAtualizaH(T->Dir);
		if (hesq >= hdir){
			T->Altura = 1+hesq;
		} else {
			T->Altura = 1+hdir;
		}
	}
}

// solucao proposta pelo Fabiano para o procedimento Atualiza Altura
void AtualizaH (No *T){
	if (T!=NULL){
		AtualizaH(T->Esq);
		AtualizaH(T->Dir);
		int he=0;
		int hd=0;
		if (T->Esq != NULL){
			he = T->Esq->Altura;
		}
		if (T->Dir != NULL){
			hd = T->Dir->Altura;
		}
		T->Altura = max(he,hd)+1;
	}
}

int max(a,b){
	int x;
	if (a<=b){
		x=b;
	} else {
		x=a;
	}
	return x;
}
