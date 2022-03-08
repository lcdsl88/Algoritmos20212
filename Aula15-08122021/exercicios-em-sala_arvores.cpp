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

int Soma(No *T){
	if (T==NULL){
		return 0;
	} else {
		return Soma(T->Esq)+Soma(T->Dir)+T->Valor;
	}
} //complexidade: theta(N)

bool SaoIdenticas(No *T1, No *T2){
	if ((T1==NULL)||(T2==NULL)){
		return ((T1==NULL)&&(T2==NULL));
	} else {
		return ((T1->Valor==T2->Valor) && SaoIdenticas(T1->Esq,T2->Esq) && SaoIdenticas(T1->Dir,T2->Dir));
	}
} // Complexidade: O(min(N1,N2)) onde N1 numero de nos de T1 e N2 numero de nos de T2

bool Busca(No *T, int x){
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

int Produto(No *T){
    if(T==NULL){
        return 1;
    } else {
        return T->Valor * Produto(T->Esq) * Produto(T->Dir);
    }
        
}

int main(){
	
	No *T;
	//T.Valor = 0;
	//T.Esq = NULL;
	//T.Dir = NULL;
	T = NULL;
		
	Insere(T,8);
	Insere(T,5);
	Insere(T,7);
	
	//Escreve(T);
	
	//cout << Soma(T);
	
	No *T2;
	//T.Valor = 0;
	//T.Esq = NULL;
	//T.Dir = NULL;
	T2 = NULL;
		
	Insere(T2,8);
	Insere(T2,5);
	Insere(T2,7);
	
	//cout << SaoIdenticas(T,T2) << "\n";
	
	//cout << Busca(T,9);
	
	int menor;
	int maior;
	
	cout << EhArvBusca(T,menor,maior) << "\n";
	cout << menor << "\n";
	cout << maior << "\n";
}