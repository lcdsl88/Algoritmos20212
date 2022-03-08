#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Esq;
	No * Dir;
} No;

void Insere(No *&T, int x){
	// assume que T eh uma árvore de busca e que x nao pertence a T
	// insere o valor de x em T
	if (T==NULL){
		//No *Novo;
		//novo = (No *) malloc(sizeof(No)); //alocar(novo)
		T = (No *) malloc(sizeof(No)); //alocar(T)
		T->Valor = x;
		T->Esq = NULL; T->Dir = NULL;
	} else {
		if (T->Valor > x){
			Insere(T->Esq, x);
		} else {
			Insere(T->Dir, x);
		}
	}
}

void Escreve(No *T){
    if (T!=NULL){
        cout << "---------" << "\n";
        cout << "No: " << T->Valor << "\n";
        if (T->Esq == NULL){
            cout << "Esq: NULL" << "\n";
        } else {
            cout << "Esq: " << T->Esq->Valor << "\n";
        }
        if (T->Dir == NULL){
            cout << "Dir: NULL" << "\n";
        } else {
            cout << "Dir: " << T->Dir->Valor << "\n";
        }
        Escreve(T->Esq);
        Escreve(T->Dir);
    }
}

void InsereMaisaEsq(No *&T,No *d){
    if (T==NULL){
        T=d;
    } else {
        InsereMaisaEsq(T->Esq,d);
    }    
}

void Remover (No *T, int x){
    if(T!=NULL){
        if(T->Valor==x){
            No *d = T->Dir;
            No *p = T;
            T=T->Esq;
            free(p);
            InsereMaisaEsq(T,d);
        }
        Remover(T->Esq,x);
        Remover(T->Dir,x);
    }
}

int main(){
	
	No *T;
	T = NULL;
		
	Insere(T,5);
	Insere(T,2);
	Insere(T,7);
    Insere(T,3);
    Insere(T,1);
    Insere(T,9);
    Insere(T,10);
	
	Remover(T,1);
	
    Escreve(T);
}
