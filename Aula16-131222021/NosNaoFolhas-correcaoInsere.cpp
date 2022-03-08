#include <iostream>

using namespace std;

typedef struct NoA {
	int Valor;
	NoA * Esq;
	NoA * Dir;
} NoA;

typedef struct NoL {
	int Valor;
	NoL * Prox;
} NoL;

typedef struct ListaLinearEnc {
	NoL * Inicio;	//Inicio: ^No
	int N;
} ListaLinearEnc;

void ImprimeNos(NoL * L) {
	cout << "[";
	NoL * p;
	p = L;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

void Insere(NoA *&T, int x){
	// assume que T eh uma árvore de busca e que x nao pertence a T
	// insere o valor de x em T
	if (T==NULL){
		//No *Novo;
		//novo = (No *) malloc(sizeof(No)); //alocar(novo)
		T = (NoA *) malloc(sizeof(NoA)); //alocar(T)
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

void InsereNo(NoL *&L, int x) {
	NoL * novo;
	novo = (NoL *) malloc(sizeof(NoL));  //alocar(novo)
	novo->Valor = x;
	novo->Prox=L;
	L = novo;
}

void Escreve(NoA *T){
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

int Soma(NoA *T){
	if (T==NULL){
		return 0;
	} else {
		return Soma(T->Esq)+Soma(T->Dir)+T->Valor;
	}
} //complexidade: theta(N)

bool SaoIdenticas(NoA *T1, NoA *T2){
	if ((T1==NULL)||(T2==NULL)){
		return ((T1==NULL)&&(T2==NULL));
	} else {
		return ((T1->Valor==T2->Valor) && SaoIdenticas(T1->Esq,T2->Esq) && SaoIdenticas(T1->Dir,T2->Dir));
	}
} // Complexidade: O(min(N1,N2)) onde N1 numero de nos de T1 e N2 numero de nos de T2

bool Busca(NoA *T, int x){
	// T eh uma arvore de busca
	if (T==NULL){
		return false;
	} else {
		if (T->Valor == x){
			return true;
		} else if(T->Valor > x) {
			return Busca(T->Esq,x);
		} else {
			return Busca(T->Dir,x);
		}
	}
}

bool EhArvBusca(NoA *T, int &Menor, int &Maior){
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

int SomaFolhas(NoA *T){
	if (T==NULL){
		return 0;
	} else {
		if((T->Esq==NULL)&&(T->Dir==NULL)){
			return T->Valor;
		} else {
			return SomaFolhas(T->Esq)+SomaFolhas(T->Dir);
		}
		
	}	
}

NoL* NosNaoFolhas(NoA *T){
	if (T==NULL) {
		return NULL;
	} else {
		NoL *L = NULL;NoL* Le; NoL* Ld;
		Le=NosNaoFolhas(T->Esq);
		Ld=NosNaoFolhas(T->Dir);
		if((T->Esq!=NULL)||(T->Dir!=NULL)){
			InsereNo(L,T->Valor);
		}
		NoL* p;
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
	
	NoA *T;
	T = NULL;
		
	Insere(T,5);
	Insere(T,3);
	Insere(T,7);
	Insere(T,6);
	Insere(T,8);
		
	Escreve(T);
	
	ImprimeNos(NosNaoFolhas(T));
			
}
