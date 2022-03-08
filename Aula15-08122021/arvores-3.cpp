/* Algoritmo do exercicio 3 do pdf de árvores elaborado com base nos ensinamentos da Aula 15 de Algoritmos 2021.2 08/12/2021 */
/* 3. Decidir se duas árvores binárias dadas de entrada são idênticas, isto é,
contém os mesmos elementos exatamente nas mesmas posições */

#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Esq;
	No * Dir;
} No;

// minha solucao proposta para a funcao SaoIdenticas
bool MinhaSaoIdenticas(No *T1, No *T2){
	//if ((T1==NULL)&&(T2==NULL)){
	//	return true; 1 solucao proposta ERRADA!
	if ((T1=NULL)||(T2=NULL)){
		return ((T1==NULL)&&(T2==NULL));
	} else {
		MSIesq=MinhaSaoIdenticas(T1->Esq,T2->Esq);
		MSIdir=MinhaSaoIdenticas(T1->Dir,T2->Dir);
		if (MSIesq)&&(MSIdir)&&(T1->Valor==T2->Valor)){
			return true;
		} else {
			return false;
		}
	}
}

// solucao SaoIdenticas Fabiano
bool SaoIdenticas(No *T1, No *T2){
	if ((T1=NULL)||(T2=NULL)){
		return ((T1==NULL)&&(T2==NULL));
	} else {
		return ((T1->Valor==T2->Valor) && SaoIdenticas(T1->Esq,T2->Esq) && SaoIdenticas(T1->Dir,T2->Dir));
	}
} // Complexidade: O(min(N1,N2)) onde N1 numero de nos de T1 e N2 numero de nos de T2