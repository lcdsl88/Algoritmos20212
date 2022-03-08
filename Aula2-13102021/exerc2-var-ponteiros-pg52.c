/*  Data: 17/10/2021 - Resolucao exercicio variaveis ponteiros

Variável Ponteiro Exercício: Elabore um algoritmo cujo estado de memória, ao final, poderia ser representado pela figura abaixo.  */

# include <stdio.h>
# include <string.h>

struct V{
	char Nome[5];
	int Idade;
};

struct T{
	int Turma;
	int *Aluno;
	int *Prox;
};

int main(){

	struct V V1;
	struct V V2;
	struct V V3;

	strcpy(V1.Nome,"JOÃO");
	V1.Idade=5;

	strcpy(V2.Nome,"LÉO");
	V2.Idade=8;

	strcpy(V3.Nome,"LIA");
	V3.Idade=9;

	printf("Nome de V1:%s\n",V1.Nome);
	printf("Idade de V1:%d\n",V1.Idade);

	printf("Nome de V2:%s\n",V2.Nome);
	printf("Idade de V2:%d\n",V2.Idade);

	printf("Nome de V3:%s\n",V3.Nome);
	printf("Idade de V3:%d\n",V3.Idade);
	
	struct T T[4];
	
	T[1].Turma = 1;
	T[1].Aluno = &V1;
	T[1].Prox = &T[2];
	
	T[2].Turma = 1;
	T[2].Aluno = &V2;
	T[2].Prox = &T[3];
	
	T[3].Turma = 2;
	T[3].Aluno = &V2;
	T[3].Prox = &T[4];
	
	T[4].Turma = 2;
	T[4].Aluno = &V3;
	T[4].Prox = NULL;
		
	int *L;
	
	L=&T[1];
	
	printf("O endereco da estrutura V1 é: %x\n", &V1 );
	printf("O endereco de T.Aluno[1] é: %x\n", T[1].Aluno);
	
	printf("O endereco da estrutura T[2] é: %x\n", &T[2] );
	printf("O endereco do T.Prox[1] é: %x\n", T[1].Prox);
	
	printf("O endereco da estrutura V2 é: %x\n", &V2 );
	printf("O endereco de T.Aluno[2] é: %x\n", T[2].Aluno);
	
	printf("O endereco da estrutura T[3] é: %x\n", &T[3] );
	printf("O endereco do T.Prox[2] é: %x\n", T[2].Prox);
	
	printf("O endereco da estrutura V2 é: %x\n", &V2 );
	printf("O endereco de T.Aluno[3] é: %x\n", T[3].Aluno);
	
	printf("O endereco da estrutura T[4] é: %x\n", &T[4] );
	printf("O endereco do T.Prox[3] é: %x\n", T[3].Prox);
	
	printf("O endereco da estrutura V3 é: %x\n", &V3 );
	printf("O endereco de T.Aluno[4] é: %x\n", T[4].Aluno);

	printf("O endereco da estrutura T[1] é: %x\n", &T[1] );
	printf("O endereco de L é: %x\n", L);
		
	return(0);
}
