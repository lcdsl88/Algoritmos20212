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

void Imprime(ListaLinearEnc L) {
	cout << "# elementos: " << L.N << " [";
	No * p;
	p = L.Inicio;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

int Produto(No * L) {
	//retorna a1*a2*...*aN, onde ai representa o i-ésimo valor de L
	if (L == NULL) {
		return 1;
	} else {
		return L->Valor * Produto(L->Prox); //a2*...*aN
	}
}

int Maior(No *L){
    if (L == NULL) {
        return -1000000;
    } else {
        int ms;
        ms = Maior(L->Prox);
        if (L->Valor > ms){
            return L->Valor;
        } else {
            return ms;
        }
    }
}

int main() {
	//lista linear
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,1); Imprime(L); 
	cout << "Maior = " << Maior(L.Inicio) << "\n"; //7
}
