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

//5a. o número de valores
int NumVal(No *L){
	if (L != NULL){
		return 1+NumVal(L->Prox);
	} else {
		return 0;
	}
}

double Media (No *L){
    if(L==NULL) {
        return 0;
    } else if (L->Prox==NULL){
        return L->Valor;
    } else {   
		return ((((double) L->Valor)/(NumVal(L))) + (Media(L->Prox)*(NumVal(L->Prox))/(NumVal(L))));
	}  
}

double Media2 (No *L, int &n){
    if(L==NULL){
        n = 0;
        return 0;
    } else if (L->Prox==NULL){
        n = 1;
        return L->Valor;
    } else {
        double M = Media2(L->Prox,n); 
        n = n+1;
		return ((double) L->Valor)/n + M*(n-1)/n;
	}  
}
int main() {
	//lista linear encadeada
	//exercicios de recursao
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

    Insere(L,6); Imprime(L);
	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,3); Imprime(L);
	Insere(L,2); Imprime(L);
	Insere(L,1); Imprime(L); 
	int n;
	cout << "A Media Lista Encadeada eh= " << Media2(L.Inicio,n) << "\n"; //3.5   
}