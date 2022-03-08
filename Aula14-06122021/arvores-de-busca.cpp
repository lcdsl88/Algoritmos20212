/* Algoritmos em árvores binárias de busca elaborado com base nos ensinamentos da Aula 14 de Algoritmos 2021.2 06/12/2021 */

#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Esq;
	No * Dir;
} No;

// minha solucao proposta p/ a Busca
bool MinhaBusca(No *T, int x){
	if (T==NULL){
		return false;
	} else {
		if (T->Valor > x){
			return Busca(T->Esq,x);
		} else if (T->valor==x){
			return true;
		} else {
			return Busca(T->Dir,x);
		}		
	}
}

// Solucao Fabiano
bool Busca(No *T, int x){
	// T eh uma arvore de busca
	if (T==NULL){
		return false;
	} else {
		if (T->Valor == x){
			return true;
		} else if(T->Valor > x) {
			return Busca(T->Esq,x);
		} else {
			return Busca(T->Dir,x);
		}
	}
}

// minha solucao proposta p/ a Insercao
void MeuInsere(No *T, int x){
	if (T!=NULL){
		if (T->Valor == x){
			Insere(T,x);
		} else if (T->Valor > x){
			Insere(T->Esq, x);
		} else {
			Insere(T->Dir, x);
		}
	}
}

// Solucao Fabiano
void Insere(&No *T, int x){
	// assume que T eh uma árvore de busca e que x nao pertence a T
	// insere o valor de x em T
	if (T==NULL){
		//No *Novo;
		//novo = (No *) malloc(sizeof(No)); //alocar(novo)
		T = (No *) malloc(sizeof(No)); //alocar(T)
		T->Valor = x;
		T->Esq = NULL; T->Dir = NULL;
	} else {
		if (T->Valor > x){
			Insere(T->Esq, x);
		} else {
			Insere(T->Dir, x);
		}
	}
}

