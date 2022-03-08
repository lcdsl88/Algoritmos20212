#include <iostream>
using namespace std;

int Busca(int V[], int N, int x){
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

void Insere(int V[], int & N, int x, int p){
	V[N+1] = V[p];
	V[p] = x;
	N = N+1;
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
	//não-ordenada
	//sequencial
	
	int V[11];
	int N = 0;
	
	Insere(V,N,3,1);
	Imprime(V,N);
	Insere(V,N,4,2);
	Imprime(V,N);
	Insere(V,N,5,1);
	Imprime(V,N);
	
	cout << Busca(V,N,5) << "\n"; //1
	cout << Busca(V,N,3) << "\n"; //3
	cout << Busca(V,N,7) << "\n"; //-1
}
