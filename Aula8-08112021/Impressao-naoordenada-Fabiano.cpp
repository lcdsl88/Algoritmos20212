#include <iostream>
using namespace std;

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
}