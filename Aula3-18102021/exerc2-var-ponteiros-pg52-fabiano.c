/*  Data: 18/10/2021 - Resolucao exercicio variaveis ponteiros (apos as dicas do prof. Fabiano)

Variável Ponteiro Exercício: Elabore um algoritmo cujo estado de memória, ao final, poderia ser representado pela figura abaixo.  */

# include <stdio.h>
# include <string.h>

typedef struct V{
	char Nome[4];
	int Idade;
} V;

typedef struct T{
	int Turma;
	int *Aluno;
	int *Prox;
} T;

int main(){

	V v1;
	V v2;
	V v3;

	strcpy(v1.Nome,"JOÃO");
	v1.Idade=5;

	strcpy(v2.Nome,"LÉO");
	v2.Idade=8;

	strcpy(v3.Nome,"LIA");
	v3.Idade=9;

	printf("Nome de v1:%s\n",v1.Nome);
	printf("Idade de v1:%d\n",v1.Idade);

	printf("Nome de v2:%s\n",v2.Nome);
	printf("Idade de v2:%d\n",v2.Idade);

	printf("Nome de v3:%s\n",v3.Nome);
	printf("Idade de v3:%d\n",v3.Idade);
	
	T t[4];
	
	t[1].Turma=1;
	t[1].Aluno=&v1;
	t[1].Prox=&t[2];
	
	t[2].Turma=1;
	t[2].Aluno=&v2;
	t[2].Prox=&t[3];
	
	t[3].Turma=2;
	t[3].Aluno=&v2;
	t[3].Prox=&t[4];
	
	t[4].Turma=2;
	t[4].Aluno=&v3;
	t[4].Prox=NULL;
		
	int *L;
	
	L=&t[1];
	
	printf("O endereco da estrutura v1 é: %x\n", &v1 );
	printf("O endereco de t.Aluno[1] é: %x\n", t[1].Aluno);
	
	printf("O endereco da estrutura t[2] é: %x\n", &t[2] );
	printf("O endereco do t.Prox[1] é: %x\n", t[1].Prox);
	
	printf("O endereco da estrutura v2 é: %x\n", &v2 );
	printf("O endereco de t.Aluno[2] é: %x\n", t[2].Aluno);
	
	printf("O endereco da estrutura t[3] é: %x\n", &t[3] );
	printf("O endereco do t.Prox[2] é: %x\n", t[2].Prox);
	
	printf("O endereco da estrutura v2 é: %x\n", &v2 );
	printf("O endereco de t.Aluno[3] é: %x\n", t[3].Aluno);
	
	printf("O endereco da estrutura t[4] é: %x\n", &t[4] );
	printf("O endereco do t.Prox[3] é: %x\n", t[3].Prox);
	
	printf("O endereco da estrutura v3 é: %x\n", &v3 );
	printf("O endereco de t.Aluno[4] é: %x\n", t[4].Aluno);

	printf("O endereco da estrutura t[1] é: %x\n", &t[1] );
	printf("O endereco de L é: %x\n", L);
		
	return(0);
}
