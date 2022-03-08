#include <iostream>

using namespace std;

typedef struct ListaLinearSeq{
    
    int V[1000001];    
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

void Insere(ListaLinearSeq & L, int x, int p) {
	//Theta(1)
	L.V[L.N+1] = L.V[p];
	L.V[p] = x;
	L.N = L.N+1;
}

void Remove(ListaLinearSeq & L, int x) {
	//O(N)
	int p = Busca(L,x);
	if (p != -1) {
		L.V[p] = L.V[L.N];
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
	//não-ordenada
	//sequencial
	
    ListaLinearSeq L;
	L.N = 0;

	Insere(L,3,1); Imprime(L);
	Insere(L,4,2); Imprime(L);
	Insere(L,5,1); Imprime(L);

	cout << Busca(L,5) << "\n"; //1	
	cout << Busca(L,3) << "\n"; //3	
	cout << Busca(L,7) << "\n"; //-1	
	
	Remove(L,4); Imprime(L);
	Remove(L,3); Imprime(L);
	Remove(L,5); Imprime(L);
	
	for (int i = 1; i<=1000000; i++) {
		Insere(L,i,1);
	}

}
