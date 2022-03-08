#include <iostream>
using namespace std;

void Insere(int V[], int N, int x, int p); 
// V-> Vetor; N -> Numero de elementos; x-> elemento a ser inserido; p-> posição do elemento

int main(){
	//lista linear
	//não-ordenada
	//sequencial
	int V[11];
	int N = 0;
	Insere(V,N,3,1);
	//Insere(V,N,4,2);
	//Insere(V,N,5,1);
	cout << V[1];
	//cout << V[1] << V[2];
	//cout << V[1] << V[2] << V[3];
	return 0;
}

void Insere(int V[], int N, int x, int p){
	V[N+1]=V[p];
	V[p]=x;
	N=N+1;
}