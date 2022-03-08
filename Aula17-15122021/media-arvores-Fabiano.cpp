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

double Media(No *T, int &N){
    if(T==NULL){
        N=0;
        return -1;
    } else {
        int Ne; int Nd; double me; double md;
        me = Media(T->Esq,Ne);
        md = Media(T->Dir,Nd);
        N = Ne + Nd + 1;
		/*Média das árvores: o problema estava com a transcrição para C das contas: 
		lembre-se que, em C, a divisão de dois números inteiros é feita como divisão inteira. 
		É necessário fazer uma conversão de algum inteiro para real para que o C faça a divisão fracionária.*/
        return T->Valor/((double)N) + me*Ne/((double)N) + md*Nd/((double)N);
    }
        
}

int main(){
	
	No *T;
	T = NULL;
		
	Insere(T,1);
	Insere(T,2);
	Insere(T,3);
	Insere(T,4);
    Insere(T,5);
    Insere(T,6);
	Escreve(T);
	
    int N=0;
    
	cout << Media(T,N);
	
}