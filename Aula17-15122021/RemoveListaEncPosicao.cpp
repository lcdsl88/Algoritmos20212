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

void RemovePos(No *&L, int k){
    // Remover k-esimo No de L; assume k>=1
    if(L!=NULL){
        if(k==1){
            No *p = L;
            L = L->Prox;
            free(p);
        } else {
            RemovePos(L->Prox, k-1);
        }
    }
}

int main() {
		
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,8); Imprime(L); 
	Insere(L,6); Imprime(L);
	Insere(L,1); Imprime(L);
	Insere(L,5); Imprime(L);
    
    RemovePos(L.Inicio,1); Imprime(L);
    RemovePos(L.Inicio,2); Imprime(L);
}
