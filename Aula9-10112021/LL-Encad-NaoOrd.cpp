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

int main(){
	ListaLinearEnc L;
	L.N = 0;
	L.Inicio = NULL;
}