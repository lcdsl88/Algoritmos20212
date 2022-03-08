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

int Busca(ListaLinearEnc L, int x){
	No * p;
	p = L.Inicio;
	int i = 1; // posicao inicial
	while (p != NULL){
		if (p->Valor == x){
			return i;
		} else {
			i = i+1;
			p = p->Prox;
		}
	}
	return -1;
}

void Insere(ListaLinearEnc &L, int x){
	//Theta(1)
	No * novo;
	novo = (No *) malloc(sizeof(No)); //alocar(novo)
	novo->Valor = x;
	novo->Prox = L.Inicio;
	L.Inicio = novo;
	L.N = L.N + 1;
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
	
	cout << Busca(L,5) << "\n"; //4
	cout << Busca(L,3) << "\n"; //-1
	cout << Busca(L,7) << "\n"; //2
	
}