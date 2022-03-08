#include <iostream>
using namespace std;

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

}
