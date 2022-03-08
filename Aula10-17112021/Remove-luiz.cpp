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

void Remove(ListaLinearEnc &L, int x){
	No * p;
	p = L.Inicio;
	No * antp;
	antp = NULL; // Fabiano: antp = NULL;
	while ((p != NULL) && (p->Valor != x)) {
		antp = p;
		p = p->Prox;
	}
	if(antp==NULL){
		L.Inicio = p->Prox;
		L.N=L.N-1;
	} else {
		antp->Prox=p->Prox;
		free(p);
		L.N=L.N-1;
	}
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

// 3a. o número de elementos positivos
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

// 3b. o maior elemento
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

// 3c. o último elemento
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

// 3d. o k-ésimo último elemento (k dado como entrada)
int Ex3dver1(ListaLinearEnc L, int k){
	No * p; // para percorrer a LL eh preciso um ponteiro p/ No
	p = L.Inicio;
	int kesimo = 0;
	for (int i=0;i<= L.N-k;i++){
		kesimo = p->Valor;
		p = p->Prox;
	}
	return kesimo;
}

// 3d. o k-ésimo último elemento (k dado como entrada)
int Ex3dver2(ListaLinearEnc L, int k){
	No * p; // para percorrer a LL eh preciso um ponteiro p/ No
	p = L.Inicio;
	int c=0; //variavel c p/ contagem
	int kesimo = 0;
	while ((p != NULL) && (c<=(L.N-k))) {
		c=c+1;
		kesimo = p->Valor;
		p = p->Prox;
	}
	return kesimo;
}

// Verdadeiro ou Falso, indicando se os valores estão ordenados
bool Ex3f(ListaLinearEnc L){
    No * p;
	p = L.Inicio;
    int m = -1000000;
    while (p != NULL) {		
        if(p->Valor>=m){
            m = p->Valor;
			p = p->Prox;
		} else {
            return false;
        }
	}
	return true;
}

// a média dos valores
double Ex3g(ListaLinearEnc L){
	No * p;
	p = L.Inicio;
	int n = 0; // n = numero de elementos da lista
	double m = 0; // m = soma dos numeradores da expressao da media
	while (p != NULL) {
	n = n+1;
	m = m + p->Valor;
	p = p->Prox;
	}
	return (m/n);
}

int main() {
	//lista linear
	//nao ordenada
	//encadeada
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,0); Imprime(L);
	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,0); Imprime(L);
	Remove(L,5); Imprime(L); 
	Remove(L,4); Imprime(L);
	Remove(L,7); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,0); Imprime(L);
	
	//Insere(L,7); Imprime(L);
	//Insere(L,-3); Imprime(L);
	//Insere(L,0); Imprime(L);
	
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
