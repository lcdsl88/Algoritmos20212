#include <iostream>

using namespace std;

typedef struct ListaLinearSeq{
    int V[1000001];
    int N;
} ListaLinearSeq;

int Busca(ListaLinearSeq L, int x) {
	//O(N) -- ainda a ser melhorada
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
    L.N = 0;
	int N = 0;

	Insere(L,5); Imprime(L);
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);

	//cout << Busca(L,5) << "\n"; //1	
	//cout << Busca(L,3) << "\n"; //3	
	//cout << Busca(L,7) << "\n"; //-1	
	
	Remove(L,4); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,5); Imprime(L);
	Remove(L,7); Imprime(L);

	/*atenção! ao descomentar o código abaixo, o tempo para 
	sua execução será da ordem de dias!
	for (int i = 1000000; i>=1; i--) {
		Insere(L,i);
	}
	*/
}
