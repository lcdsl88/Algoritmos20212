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

int Busca(ListaLinearEnc L, int x) {
	No * p;
	p = L.Inicio;
	int i = 1; 
	while (p != NULL) {
		if (p->Valor == x) {
			return i;
		} else {
			i = i+1;
			p = p->Prox;
		}
	}
	return -1;
}

void Insere(ListaLinearEnc &L, int x) {
	//Theta(1)
	No * novo;
	novo = (No *) malloc(sizeof(No));  //alocar(novo)
	novo->Valor = x;
	novo->Prox = L.Inicio;
	L.Inicio = novo;
	L.N = L.N+1;
}

void Remove(ListaLinearEnc &L, int x) {
	//O(N)
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

int Ex3a(ListaLinearEnc	L){
	No * p; // para percorrer a LL eh preciso um ponteiro p/ No
	p = L.Inicio;
	int c=0; //variavel c p/ contagem
	while (p != NULL) {
		if(p->Valor>0){
			c=c+1;
		}
		p = p->Prox;
	}
	return c;
}

int Ex3b(ListaLinearEnc	L){
	No * p; // para percorrer a LL eh preciso um ponteiro p/ No
	p = L.Inicio;
	int m = 0;
	int M = -1000000; // suponha que nao ha nenhum valor na lista menor que -1000000
	while (p != NULL) {
		m = p->Valor;
		if(M<m){
			M=m;
		}
		p = p->Prox;
	}
	return M;
}

int Ex3c(ListaLinearEnc L){
	No * p; // para percorrer a LL eh preciso um ponteiro p/ No
	p = L.Inicio;
	int u = 0;
	while (p != NULL) {
		u = p->Valor;
		p = p->Prox;		
	}
	return u;
}

int main() {
	//lista linear
	//nao ordenada
	//encadeada
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,-7); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,10); Imprime(L);
	//Insere(L,6); Imprime(L);
	//Insere(L,7); Imprime(L);
	//Insere(L,-3); Imprime(L);
	//Insere(L,0); Imprime(L);
	
	cout << "O ultimo elemento da lista L eh: " << Ex3c(L) << "\n"; //-7
	
	//cout << Busca(L,5) << "\n"; //4	
	//cout << Busca(L,3) << "\n"; //-1	
	//cout << Busca(L,7) << "\n"; //2	

	/*
	Remove(L,4); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,5); Imprime(L);
	Remove(L,7); Imprime(L);
	*/
}