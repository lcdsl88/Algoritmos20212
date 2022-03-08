/* Algoritmo de impressao de arvores elaborado com base nos ensinamentos da Aula 15 de Algoritmos 2021.2 08/12/2021 */

#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Esq;
	No * Dir;
} No;

// minha solucao proposta para a impressao
void MeuImprime(No *T){
	if (T==NULL){
		cout << "NULL";
	} else {
	cout << MeuImprime(T->Esq);
	cout << MeuImprime(T->Dir);
	cout << "No" << T->Valor;
	cout << "Esq" << T->Esq->Valor;
	cout << "Dir" << T->Dir->Valor;
    }
}

// solucao Fabiano
void Escreve(No *T){
    if (T!=NULL){
        cout << "----------";
        cout << "No: " << T->Valor;
        if (T->Esq == NULL){
            cout << "Esq: NULL";
        } else {
            cout << "Esq: " << T->Esq->Valor;
        }
        if (T->Dir == NULL){
            cout << "Dir: NULL";
        } else {
            cout << "Dir: " << T->Dir->Valor;
        }
        Escreve(T->Esq);
        Escreve(T->Dir);
    }
}
