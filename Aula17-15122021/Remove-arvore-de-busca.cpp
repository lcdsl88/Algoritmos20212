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

bool EhArvBusca(No *T, int &Menor, int &Maior){
	if (T==NULL){
		Menor = 1000000; Maior = -1000000;
		return true;
	} else {
		bool ABe, ABd;
		int me; // menor a esquerda
		int md; // menor a direita
		int Me; // maior a esquerda
		int Md; // maior a direita
		ABe = EhArvBusca(T->Esq, me, Me);
		ABd = EhArvBusca(T->Dir, md, Md);
		if (T->Esq == NULL){
			Menor = T->Valor;
		} else {
			Menor = me;
		}
		if (T->Dir == NULL){
			Maior = T->Valor;
		} else {
			Maior = Md;
		}
		return (ABe && ABd && (Me < T->Valor) && (T->Valor < md));
	}
}

No* RemoveEmBusca (No *&T, int x){
	if(T!=NULL){
        if(T->Valor==x){
            //No *d = T->Dir;
            //No *p = T;
            //T=T->Esq;
            //free(p);
            //Insere(T,d);
            RemoveEmBusca(T,x);
        } else {
            RemoveEmBusca(T->Esq,x);
		    RemoveEmBusca(T->Dir,x);
        }
    }
}

int main(){
	
	No *T;
	T = NULL;
		
	Insere(T,50);
	Insere(T,30);
	Insere(T,70);
	Insere(T,10);
	Insere(T,45);
	Insere(T,60);
	Insere(T,35);
	Insere(T,32);
	Insere(T,40);
    
	Escreve(T);
    
    //int menor;
	//int maior;
	
	//cout << EhArvBusca(T,menor,maior) << "\n";
	//cout << menor << "\n";
	//cout << maior << "\n";
    
    RemoveEmBusca(T,50);
    
    Escreve(T);
    
    //cout << EhArvBusca(T,menor,maior) << "\n";
	//cout << menor << "\n";
	//cout << maior << "\n";    
	
}
