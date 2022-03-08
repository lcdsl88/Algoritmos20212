#include <iostream>
using namespace std;

void Insere(int V[], int N, int x, int p); 
// V-> Vetor; N -> Numero de elementos; x-> elemento a ser inserido; p-> posição do elemento

int Busca(int V[], int N, int x);

void Remove(int V[], int N, int x);

int main(){
	//lista linear
	//não-ordenada
	//sequencial
	int V[11];
	int N = 0;
	Insere(V,0,3,1); // Considerei o numero N = 0 de elementos inicial do vetor 
	Insere(V,1,4,2); // Agora considerei o vetor com N = 1 elemento
	Insere(V,2,5,1); // Por fim com N = 2 elementos
	//cout << Busca(V,3,5) << "\n"; //1
	//cout << Busca(V,3,3) << "\n"; //3
	//cout << Busca(V,3,7) << "\n"; //-1
	cout << V[1] << V[2] << V[3] << "\n"; // SAIDA: 543
	Remove(V,3,4);
	cout << V[1] << V[2];
	
	//cout << V[1]; // SAIDA: 3
	//cout << V[1] << V[2]; // SAIDA: 34
	//cout << V[1] << V[2] << V[3]; // SAIDA: 543
	return 0;
}

// complexidade do Insere = theta(1);
void Insere(int V[], int N, int x, int p){
	V[N+1]=V[p];
	V[p]=x;
	N=N+1;
}

// Solução Fabiano no vídeo da Aula 08
// complexidade da Busca = O(N);
int Busca(int V[], int N, int x){
	int i = 1; //theta(1);
	while ((i <= N) && (V[i] != x)){
		i = i + 1; // O(N)
 	}
	if (i > N){
		return -1; //theta(1)
	} else {
		return i; //theta(1)
	}
}

// Solução minha errada (11/11/2021 - 19:30)
// int Busca(int V[], int N, int x){
//	int i = 1;
//	while(i<=N && V[i]!=x){
//		i=i+1;
//		if(i>N){
//			return -1;
//		}
//		else{
//			return i;
//		}
//	}
//}

// complexidade do Remove = O(N);
void Remove(int V[], int N, int x){
	int i = 1;
	while(V[i]!=x){
		i=i+1; // O(N)
	}
	V[i]=V[N]; //theta(1)
	N=N-1; //theta(1)
}