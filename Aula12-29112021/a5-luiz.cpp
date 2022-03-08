#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Prox;
} No;

void Insere(No &L,int x){
	L.Valor = x;
	}

void Imprime(No L){
	cout << L.Valor;
}

/*int NroNos(No *L){
	
}*/

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

int main(){
	No L;
	L.Valor=5;
	L.Prox=NULL;
	Insere(L,3);
	Imprime(L);
	cout << Maior(&L);
}
