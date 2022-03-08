/* Algoritmo do exercicio 1a do pdf de árvores elaborado com base nos ensinamentos da Aula 15 de Algoritmos 2021.2 08/12/2021 */

#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	int SCD; // SCD = Soma Chave D - soma de todos os valores que descendem de D (Um nó descende de si próprio)
	No * Esq;
	No * Dir;
} No;

// minha solucao proposta para a funcao SCD
void MeuAtualizaSCD(No *T){
	if (T!=NULL){
		MeuAtualizaSCD(T->Esq);
		MeuAtualizaSCD(T->Dir);
		if (T->Esq != NULL){
			scdesq=T->Esq->SCD;
		}
		if (T->Dir != NULL){
			scdesq=T->Dir->SCD;
		}
		T->SCD = T->Valor + scdesq + scddir;
	}
}

// Primeira Solucao Fabiano com uma funcao auxiliar (Soma)
void AtualizaSCD1(No *T){
	if (T!=NULL){
	AtualizaSCD1(T->Esq);
	AtualizaSCD1(T->Dir);
	T->SCD = Soma(T); //theta(N)
	}
} //theta(N^2)

int Soma(No *T){
	if (T==NULL){
		return 0;
	} else {
		return Soma(T->Esq)+Soma(T->Dir)+T->Valor;
	}
} //complexidade: theta(N)

// segunda solucao proposta pelo Fabiano
void AtualizaSCD2(No *T){
	if (T!=NULL){
		AtualizaSCD2(T->Esq);
		AtualizaSCD2(T->Dir);
		int SCDe = 0;
		int SCDd = 0;
		if(T->Esq!=NULL){
			SCDe=T->Esq->SCD;
		}
		if(T->Dir!=NULL){
			SCDd=T->Dir->SCD;
		}
		T->SCD=SDCe+SCDd+T->Valor;
	}
}