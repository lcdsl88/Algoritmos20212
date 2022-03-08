#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Prox;
} No;

typedef struct ListaLinearEnc {
	No * Inicio;	//Inicio: ^No
	int N;
} ListaLinearEnc;

void Insere(ListaLinearEnc &L, int x) {
	//Theta(1)
	No * novo;
	novo = (No *) malloc(sizeof(No));  //alocar(novo)
	novo->Valor = x;
	novo->Prox = L.Inicio;
	L.Inicio = novo;
	L.N = L.N+1;
}

void ImprimeNos(No * L) {
	cout << "[";
	No * p;
	p = L;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

void Imprime(ListaLinearEnc L) {
	cout << "# elementos: " << L.N << " ";
	ImprimeNos(L.Inicio);
}

void RemoveRepetidos(No *&L, int x){
    // assume L pode possuir elementos repetidos
    if(L!=NULL){
        RemoveRepetidos(L->Prox, x); //Remove Repetidos: A chamada "RemoveRepetidos(L->Prox, x);" deveria estar no pseudocódigo antes da remoção do primeiro nó, e não depois        
        if(L->Valor==x){
            No *p = L;
            L = L->Prox;
            free(p);
        } 
    }
}

int main() {
		
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

    Insere(L,6); Imprime(L); 
	Insere(L,8); Imprime(L); 
	Insere(L,6); Imprime(L);
	Insere(L,1); Imprime(L);
	Insere(L,5); Imprime(L);
    
    RemoveRepetidos(L.Inicio,6); Imprime(L);
}