#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Esq;
	No * Dir;
} No;

// minha solucao proposta para a função EhArvBusca
bool MeuEhArvBusca(No *T){
	if (T==NULL){
		return true;
	} else {
		EABesq=EhArvBusca(T->Esq);
		EABdir=EhArvBusca(T->Dir);
		if((T->Valor > T->Esq->Valor)&&(T->Valor < T->Dir->Valor)){
			return (EABesq&&EABdir);
		} else {
			return false;
		}
	}
}

// solucao Fabiano
bool EhArvBusca(No *T, int &Menor, int &Maior){
	if (T==NULL){
		Menor = 1000000; Maior = -1000000;
		return true;
	} else {
		bool ABe, ABd;
		int me; // menor a esquerda
		int md; // menor a direita
		int Me; // maior a esquerda
		int Md; // maior a direita
		ABe = EhArvBusca(T->Esq, me, Me);
		ABd = EhArvBusca(T->Dir, md, Md);
		if (T->Esq == NULL){
			Menor = T->Valor;
		} else {
			Menor = me;
		}
		if (T->Dir == NULL){
			Maior = T->Valor;
		} else {
			Maior = Md;
		}
		return (ABe && ABd && (Me < T->Valor) && (T->Valor < md));
	}
}

int main(){
	
}