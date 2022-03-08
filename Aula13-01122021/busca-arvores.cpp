/* Algoritmo de busca em arvores elaborado com base nos ensinamentos da Aula 13 de Algoritmos 2021.2 01/12/2021 */

#include <iostream>

using namespace std;

bool Busca(No *T, int x){
	if (T==NULL){
		return false;
	} else {
		bool be;
		be=Busca(T->Esq, x);
		if be {
			return true;
		} else {
			bool bd;
			bd=Busca(T->Dir, x);
			if bd {
				return true;
			} else {
				return (T->Valor == x);
			}
		}
	}
} // complexidade: theta(N)

// algoritmo mais curto que faz a msm coisa que o anterior

bool Busca(No *T, int x){
	if (T==NULL){
		return false;
	} else {
		return (T->Valor == x || Busca(T->Esq, x) || Busca(T->Dir, x));
	}
} // complexidade: theta(N)

