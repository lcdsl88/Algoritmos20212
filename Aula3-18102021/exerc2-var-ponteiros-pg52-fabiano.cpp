/*  Data: 21/10/2021 - Resolucao exercicio variaveis ponteiros (apos a aula 3 do prof. Fabiano)

Variável Ponteiro Exercício: Elabore um algoritmo cujo estado de memória, ao final, poderia ser representado pela figura abaixo.  */

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <conio.h>

typedef struct T{
	char Nome[5];
	int Idade;
} T;

typedef struct S{
	int Turma;
	T *Aluno;
	S *Prox;
} S;

int main(){

	T V[3];
	
	strcpy(V[1].Nome,"JOÃO");
	V[1].Idade=5;

	strcpy(V[2].Nome,"LÉO");
	V[2].Idade=8;

	strcpy(V[3].Nome,"LIA");
	V[3].Idade=9;
	
	printf("Nome de V1:%s\n",V[1].Nome);
	printf("Idade de V1:%d\n",V[1].Idade);

	printf("Nome de V2:%s\n",V[2].Nome);
	printf("Idade de V2:%d\n",V[2].Idade);

	printf("Nome de V3:%s\n",V[3].Nome);
	printf("Idade de V3:%d\n",V[3].Idade);
	
	S *L;
	L = (S*) malloc (sizeof(S));
	L->Turma=1;
	L->Aluno=&V[1];
	
	S *t;
	t = (S*) malloc (sizeof(S));
	
	L->Prox=t;
	t->Turma=1;
	t->Aluno=&V[2];
	
	S *t2;
	t2 = (S*) malloc (sizeof(S));
	
	t->Prox=t2;
	t2->Turma=2;
	t2->Aluno=&V[2];
	
	t = (S*) malloc (sizeof(S));
	t2->Prox=t;
	t->Turma=2;
	t->Aluno=&V[3];
	t->Prox=NULL;
	
	printf("O endereco de L é: %x\n", &L);
	
	printf("O endereco da estrutura V[1] é: %x\n", &V[1] );
	printf("O endereco de L^.Aluno é: %x\n", L->Aluno);
		
	printf("O endereco de L^.Turma é: %x\n", L->Turma);
	printf("O endereco de L^.Prox é: %x\n", L->Prox);

	printf("O endereco da estrutura V[2] é: %x\n", &V[2] );
	printf("O endereco de t2^.Aluno é: %x\n", t2->Aluno);
	
	printf("O endereco de t^.Turma é: %x\n", t->Turma);
	printf("O endereco de t.Prox é: %x\n", t->Prox);

	printf("O endereco da estrutura V[3] é: %x\n", &V[3] );
	printf("O endereco do t^.Aluno é: %x\n", t->Aluno);
	
	printf("O endereco de t2^.Turma é: %x\n", t2->Turma);
	printf("O endereco de t2^.Prox é: %x\n", t2->Prox);

	getch();
	
	return(0);
}
