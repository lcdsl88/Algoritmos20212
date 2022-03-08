#include <iostream>
using namespace std;

int Busca(int V[], int N, int x){
    // O(N) -- ainda a ser melhorada
    int i = 1;
	while ((i <= N) && (V[i] != x)){
		i = i + 1;
 	}
	if (i > N){
		return -1;
	} else {
		return i;
	}
}

void Insere(int V[], int & N, int x){
    //Theta(N)
    int ap = 1; //ap = antes da posicao
    while ((ap <= N)&&(V[ap] < x)){
        ap = ap+1;
    }
    for (int p = N; p>=ap; p--){
        V[p+1] = V[p];
    }
    V[ap] = x;
    N = N+1;
}

void Remove(int V[], int & N, int x){
	// O(N)
    int pr = Busca(V,N,x); //pr = posicao de remocao
	if (pr != -1){
        for (int p = pr; p < N; p++){
        V[p] = V[p+1];
        }
	N = N-1;    
    }
}

void Imprime(int V[], int N){
	cout << "# elementos: " << N << " [";
	for (int i = 1; i<=N; i++){
		if (i>=2){
			cout <<",";
		}
		cout << V[i];
	}
	cout << "]\n";
}

int main(){
    //lista linear
    //ordenada
    //sequencial

    int V[11];
    int N = 0;
    
    Insere(V,N,5); Imprime(V,N);
    Insere(V,N,4); Imprime(V,N);
    Insere(V,N,7); Imprime(V,N);
    Insere(V,N,6); Imprime(V,N);
    
    Remove(V,N,4); Imprime(V,N);
    Remove(V,N,6); Imprime(V,N);
    Remove(V,N,5); Imprime(V,N);
    Remove(V,N,7); Imprime(V,N);

}
