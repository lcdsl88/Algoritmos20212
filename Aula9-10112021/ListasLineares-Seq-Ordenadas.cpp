#include <iostream>

using namespace std;

#define MAXN 1000000000

typedef struct ListaLinearSeq {
	int * V;
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

int BuscaBinaria(ListaLinearSeq &L, int x) {
	//O(log(N))
	int i; int f;
	i = 1; f = L.N;
	while (i <= f) { //"a região de busca [i,f] não for vazia"
		int m = (i+f)/2;
		if (L.V[m] == x) {
			return m;
		} else if (L.V[m] > x) {
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
	
	ListaLinearSeq L; 
	L.V = (int *) malloc(sizeof(int) * (MAXN+1));	//alocar(L)
	L.N = 0;

	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);

	cout << BuscaBinaria(L,5) << "\n"; //1	
	cout << BuscaBinaria(L,3) << "\n"; //3	
	cout << BuscaBinaria(L,7) << "\n"; //-1	
	
	Remove(L,4); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,5); Imprime(L);
	Remove(L,7); Imprime(L);

	for (int i = 1; i<=MAXN; i++) {
		L.V[i] = i;
	}
	L.N = MAXN;

	cout << "Buscando último elemento (Busca Linear)...\n";
	cout << Busca(L, MAXN) << "\n";
	cout << "Buscando último elemento (Busca Binária)...\n";
	cout << BuscaBinaria(L, MAXN) << "\n";
		
}