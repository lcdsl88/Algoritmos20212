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

No *MenoresQue(No *L, int k){
	if (L==NULL){
		return NULL;
	} else {
		No *R;
		R = MenoresQue(L->Prox,k);
		if(L->Valor<=k){
			No *n; n = (No *) malloc(sizeof(No));
			n->Valor = L->Valor;
			n->Prox = R;
			R = n;
		} 
		return R;
	}
}

int main() {
	//lista linear
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,5); Imprime(L); 
	Insere(L,2); Imprime(L);
	Insere(L,1); Imprime(L);
	Insere(L,4); Imprime(L);
	Insere(L,3); Imprime(L);  
	//cout << "Produto = " << Produto(L.Inicio) << "\n"; //840
	cout << "A Lista Encadeada com valores menores ou iguais a 3 eh = " << MenoresQue(L.Inicio,3) << "\n";
}
