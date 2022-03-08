/* Algoritmos elaborados com base nos ensinamentos da Aula 13 de Algoritmos 2021.2 01/12/2021 */

#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Prox1;
	No * Prox2;
} No;

// minha solucao proposta p/ o Produto

int MeuProduto(No * L) {
	if (L == NULL) {
		return 1;
	} else {
		return L->Valor * Produto(L->Prox1) * Produto(L->Prox2);
	}
}

// solucao proposta p/ o Produto pelo Fabiano

int Produto(No * L) {
	if (L == NULL) {
		return 1;
	} else {
		return Produto(L->Prox1) * Produto(L->Prox2) * L->Valor;
	}
}

// minha solucao proposta p/ o Maior

int MeuMaior(No * L){
	if (L==NULL){
		return -1000000;
	}
	M1 = Maior(L->Prox1);
	M2 = Maior(L->Prox2);
	if (M1>M2){
		if(L->Valor<M1){
			return M1;
		} else{
			return L->Valor;
		}
	} else {
		if(L->Valor<M2){
			return M2;
		} else{
			return L->Valor;
		}
	}
}

// solucao proposta p/ o Produto pelo Fabiano

int Maior(No * L){
	// assume que L é a a lista alterada
	// retornar o maior valor de L
	m1 = Maior(L->Prox1);
	m2 = Maior(L->Prox2);
	if ((L->Valor>=m1)&&(L->Valor>=m2)){
		return L->Valor;
	} else if (m1>=m2) {
		return m1;
	} else {
		return m2;
	}
	// o bloco do if acima poderia ser substituido por max(L->Valor, m1, m2)
}