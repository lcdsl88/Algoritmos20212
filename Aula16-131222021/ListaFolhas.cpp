#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Esq;
	No * Dir;
} No;

typedef struct NoLista {
	int Valor;
	NoLista * Prox;
} NoLista;

typedef struct ListaLinearEnc {
	NoLista * Inicio;	//Inicio: ^NoLista
	int N;
} ListaLinearEnc;

void ImprimeNos(NoLista * L) {
	cout << "[";
	NoLista * p;
	p = L;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

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

void InsereNo(NoLista *&L, int x) {
	NoLista * novo;
	novo = (NoLista *) malloc(sizeof(NoLista));  //alocar(novo)
	novo->Valor = x;
	novo->Prox=L;
	L = novo;
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

NoLista* ListaFolhas(No *T){
	if (T==NULL) {
		return NULL;
	} else {
		NoLista *L = NULL;NoLista* Le; NoLista* Ld; // Le: Lista Folhas a Esquerda  Ld: Lista Folhas a Direita
		Le=ListaFolhas(T->Esq);
		Ld=ListaFolhas(T->Dir);
		if((T->Esq==NULL)&&(T->Dir==NULL)){
			InsereNo(L,T->Valor);
		}
		NoLista* p;
		p=Le;
		while(p!=NULL){
			InsereNo(L,p->Valor);
			p=p->Prox;
			}
		p=Ld;
		while(p!=NULL){
			InsereNo(L,p->Valor);
			p=p->Prox;
			}
		return L;
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
	
	ImprimeNos(ListaFolhas(T));
			
}
