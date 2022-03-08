#include <iostream>

using namespace std;

typedef struct No{
	int Valor;
	No * Prox; // Ponteiro para o prox. Nó - Próximo: ^No
} No;

typedef struct ListaLinearEnc{
	No * Inicio; // Inicio: ponteiro p/ um certo Nó - Inicio: ^No
	int N;
} ListaLinearEnc;

int Busca(ListaLinearEnc, int x){
	
}

// Nao tem busca binaria em listas encadeadas

void Insere(ListaLinearEnc, int x){
	
}

void Remove(ListaLinearEnc, int x){
	
}

void Imprime(ListaLinearEnc L){
	cout << "# elementos: " << L.N << " [";
	No * p;
	p = L.Inicio;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

int main(){
	
	ListaLinearEnc L;
	L.N = 0;
	L.Inicio = NULL;
	
	Insere(L,5); Imprime(L);
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	
	cout << Busca(L,5) << "\n";
	cout << Busca(L,3) << "\n";
	cout << Busca(L,7) << "\n";
	
	Remove(L,4); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,5); Imprime(L);
	Remove(L,7); Imprime(L);
	
}