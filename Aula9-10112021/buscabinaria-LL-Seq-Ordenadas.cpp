#include <iostream>
//#include <conio.h>

using namespace std;

#define MAXN 100000000

typedef struct ListaLinearSeq{
    int V[MAXN + 1];
    int N;
} ListaLinearSeq;

int Busca(ListaLinearSeq L, int x) {
	//O(N)
	int i = 1;
	while ((i <= L.N) && (L.V[i] != x)) {
		i = i + 1;
	}
	if (i > L.N) {
		return -1;
	} else {
		return i;
	}
}

int BuscaBinaria(ListaLinearSeq L, int x) {
	//O(N) -- ainda a ser melhorada
	//int i; //i de inicio
	int f; //f de fim
	int i = 1; f = L.N;
	while ( i<=f ) { //"a regiao de busca [i,f] nao for vazia"
		int m = (i+f)/2; //m denota posicao do m
        if (L.V[m] == x){
            return m;
        } else if (L.V[m] > x){
            f = m-1;
        } else {
            i = m+1;
        }
    }
	return -1;
}

void Insere(ListaLinearSeq &L, int x) {
	//Theta(N)
	int ap = 1;
	while ((ap <= L.N) && (L.V[ap] < x)) {
		ap = ap+1;
	}
	for (int p = L.N; p >= ap; p--) {
		L.V[p+1] = L.V[p];
	}
	L.V[ap] = x;
	L.N = L.N+1;
}

void Remove(ListaLinearSeq &L, int x) {
	//O(N)
	int pr = Busca(L,x);
	if (pr != -1) {
		for (int p = pr; p < L.N; p++) {
			L.V[p] = L.V[p+1];
		}
		L.N = L.N-1;
	}
}

void Imprime(ListaLinearSeq L) {
	cout << "# elementos: " << L.N << " [";
	for (int i = 1; i <= L.N; i++) {
		if (i>=2) {
			cout << ",";
		}
		cout << L.V[i];
	}
	cout << "]\n";
}

int main() {
	//lista linear
	//ordenada
	//sequencial
	
    ListaLinearSeq * L; // variavel L eh ponteiro para a estrutura ListaLinearSeq
    L = (ListaLinearSeq *) malloc(sizeof(ListaLinearSeq)); //alocar(L)
	L->N = 0; //L^.N (-> em C++ equivale a ^. do pseudocodigo)
	
	//cout <<"teste\n";
	
	//Insere(*L,5); Imprime(*L);
	//Insere(*L,4); Imprime(*L);
	//Insere(*L,7); Imprime(*L);
	//Insere(*L,6); Imprime(*L);

	//cout << Busca(L,5) << "\n"; //1	
	//cout << Busca(L,3) << "\n"; //3	
	//cout << Busca(L,7) << "\n"; //-1	
	
	//Remove(*L,4); Imprime(*L);
	//Remove(*L,6); Imprime(*L);
	//Remove(*L,5); Imprime(*L);
	//Remove(*L,7); Imprime(*L);
	
	//int Nteste = 100000000;
	
	//int i = 1;
	//while (i<=MAXN) {
	//	L->V[i] = i;
	//	i++;
	//}
	//L->N = MAXN;
	//cout << L->V[MAXN];
		
	for (int i = 1; i<=MAXN; i++) {
		//Insere(L,i);
		L->V[i] = i;
		L->N = MAXN;
	}
	
	cout << L->V[MAXN];

	//int r = Busca(*L, MAXN);
	//cout << r << "\n";
	
	//cout << "Buscando ultimo elemento ..\n";
	//cout << Busca(*L, MAXN) << "\n";
	//cout << BuscaBinaria(*L, MAXN) << "\n";

}
