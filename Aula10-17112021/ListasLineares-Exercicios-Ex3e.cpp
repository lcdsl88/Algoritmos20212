#include <iostream>

using namespace std;

typedef struct No {
	int Valor;
	No * Prox;
} No;

typedef struct ListaLinearEnc {
	No * Inicio;	//Inicio: ^No
	int N;
} ListaLinearEnc;

int Busca(ListaLinearEnc L, int x) {
	No * p;
	p = L.Inicio;
	int i = 1; 
	while (p != NULL) {
		if (p->Valor == x) {
			return i;
		} else {
			i = i+1;
			p = p->Prox;
		}
	}
	return -1;
}

void Insere(ListaLinearEnc &L, int x) {
	//Theta(1)
	No * novo;
	novo = (No *) malloc(sizeof(No));  //alocar(novo)
	novo->Valor = x;
	novo->Prox = L.Inicio;
	L.Inicio = novo;
	L.N = L.N+1;
}

void Remove(ListaLinearEnc &L, int x) {
	//O(N)
	No * p = L.Inicio;
	No * antp = NULL;
	while (p != NULL) {
		if (p->Valor == x) {
			if (antp == NULL) {
				L.Inicio = p->Prox;
			} else {
				antp->Prox = p->Prox;
			}
			//desalocar(p)
			free(p);
			L.N = L.N - 1;
			return;
		}
		antp = p;
		p = p->Prox;
	}
}

void Imprime(ListaLinearEnc L) {
	cout << "# elementos: " << L.N << " [";
	No * p;
	p = L.Inicio;
	while (p != NULL) {
		cout << p->Valor << " ";
		p = p->Prox;
	}
	cout << "]\n";
}

int Ex3a(ListaLinearEnc L) {
	int c = 0;
	No * p = L.Inicio;
	while (p != NULL) {
		if (p->Valor > 0) {
			c = c+1;
		}
		p = p->Prox;
	}
	return c;
}

int Ex3b(ListaLinearEnc L) {
	int m = -1000000000;
	No * p = L.Inicio;
	while (p != NULL) {
		if (p->Valor > m) {
			m = p->Valor;
		}
		p = p->Prox;
	}
	return m;
}

int Ex3c(ListaLinearEnc L) {
	No * p = L.Inicio;
	No * antp = NULL;
	while (p != NULL) {
		antp = p;
		p = p->Prox;
	}
	if (antp == NULL) {
		return -1000000000;
	} else {
		return antp->Valor;
	}
}

int Ex3dver1(ListaLinearEnc L, int k) {
	No * p = L.Inicio;
	//para i <-- 1 ate L.N - k faça
	//for (int i = 1; i <= L.N - k; i++) {
	int i = 1;
	while (i <= L.N - k) {
		p = p->Prox;
		i++;
	}
	if (p == NULL) {
		return -1000000000;
	} else {
		return p->Valor;
	}
}

int Ex3dver2(ListaLinearEnc L, int k) {
	No * p = L.Inicio;
	int i = 1;
	while (i <= k) {
		p = p->Prox;
		i++;
	}
	No * antp = L.Inicio;
	while (p != NULL) {
		p = p->Prox;
		antp = antp->Prox;
	}
	return antp->Valor;
}

void Ex3e(ListaLinearEnc &L, int k){
	No * p = L.Inicio;
	while (p != NULL) {
		if(p->Valor>k){
			Remove(L,p->Valor);
			}
		p = p->Prox;
	}
}

bool Ex3f(ListaLinearEnc L) {
	if (L.Inicio == NULL) {
		return true;
	} else {
		int u;
		No * p = L.Inicio;
		u = p->Valor;
		p = p->Prox;
		while (p != NULL) {
			if (p->Valor < u) {
				return false;
			}
			u = p->Valor;
			p = p->Prox;
		}
		return true;
	}
}

double Ex3g(ListaLinearEnc L) {
	No * p = L.Inicio;
	double s = 0.0;
	while (p != NULL) {
		s = s + p->Valor;
		p = p->Prox;
	}
	return s/L.N;
}

ListaLinearEnc Ex3h(ListaLinearEnc L) {
	ListaLinearEnc R;
	R.Inicio = NULL; R.N = 0;
	No * p = L.Inicio;
	while (p != NULL) {
		if (Busca(R, p->Valor) == -1) {
			Insere(R, p->Valor);
		}
		p = p->Prox;
	}
	return R;
}

int main() {
	//lista linear
	
	ListaLinearEnc L; 
	L.N = 0;
	L.Inicio = NULL;

	
	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,0); Imprime(L); 
	Insere(L,5); Imprime(L); 
	Insere(L,4); Imprime(L);
	Insere(L,7); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,0); Imprime(L); 
	Remove(L,5); Imprime(L); 
	Remove(L,4); Imprime(L);
	Remove(L,7); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,6); Imprime(L);
	Remove(L,0); Imprime(L);
	Ex3e(L,3); Imprime(L);
	
	/*Insere(L,50); Imprime(L); 
	Insere(L,42); Imprime(L);
	Insere(L,27); Imprime(L);
	Insere(L,16); Imprime(L);
	Insere(L,6); Imprime(L);
	Insere(L,-10); Imprime(L); */
	

	//cout << Ex3a(L) << "\n"; //3
	//cout << Ex3b(L) << "\n"; //7
	//cout << Ex3c(L) << "\n"; //5
	/*for (int k=1; k<=L.N; k++) {
		cout << k << ".o último elemento = " << Ex3dver2(L, k) << "\n"; 
	}*/
	//cout << Ex3f(L) << "\n"; //0
	//cout << Ex3g(L) << "\n"; //4.66...
	ListaLinearEnc R;
	R = Ex3h(L);
	Imprime(R);
}