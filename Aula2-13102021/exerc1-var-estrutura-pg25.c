/* Data: 15/10/2021 - Resolucao exercicio 1 variaveis estrutura  */
/* Ex1: Definir uma estrutura Endereco e preencher valores de duas variáveis deste tipo, e preencher valor para uma variável deste tipo */

#include <stdio.h>
#include <string.h>
#include <conio.h>

struct Endereco {
	char Logradouro[50];
	int Numero;
	//char Complemento[10];
	int CEP;
	char Bairro[25];
	char Cidade[25];
	char Estado[2];
};

int main(){
	
	struct Endereco Endereco1; /* Declaracao Endereco1 do tipo Endereco*/
	struct Endereco Endereco2; /* Declaracao Endereco2 do tipo Endereco*/
	
	/* Preenchimento dos valores do Endereco1 */
	strcpy( Endereco1.Logradouro, "Rua Sao Francisco Xavier");
	Endereco1.Numero = 524;
	Endereco1.CEP = 20550013;
	strcpy( Endereco1.Bairro, "Maracana");
	strcpy( Endereco1.Cidade, "Rio de Janeiro");
	strcpy( Endereco1.Estado, "RJ");
	
	/* Preenchimento dos valores do Endereco2 */
	strcpy( Endereco2.Logradouro, "Rua Francisco Portela");
	Endereco2.Numero = 1470;
	Endereco2.CEP = 24435005;
	strcpy( Endereco2.Bairro, "Patronato");
	strcpy( Endereco2.Cidade, "Sao Goncalo");
	strcpy( Endereco2.Estado, "RJ");
	
	/* Impressao das informacoes do Endereco1 */
	
	printf("O Logradouro do Endereco 1 eh: %s\n",Endereco1.Logradouro);
	printf("O Numero do Endereco 1 eh: %d\n",Endereco1.Numero);
	printf("O CEP do Endereco 1 eh: %d\n",Endereco1.CEP);
	printf("O Bairro do Endereco 1 eh: %s\n",Endereco1.Bairro);
	printf("A Cidade do Endereco 1 eh: %s\n",Endereco1.Cidade);
	printf("O Estado do Endereco 1 eh: %s\n",Endereco1.Estado);
	
	/* Impressao das informacoes do Endereco1 */

	printf("O Logradouro do Endereco 2 eh: %s\n",Endereco2.Logradouro);
	printf("O Numero do Endereco 2 eh: %d\n",Endereco2.Numero);
	printf("O CEP do Endereco 2 eh: %d\n",Endereco2.CEP);
	printf("O Bairro do Endereco 2 eh: %s\n",Endereco2.Bairro);
	printf("A Cidade do Endereco 2 eh: %s\n",Endereco2.Cidade);
	printf("O Estado do Endereco 2 eh: %s\n",Endereco2.Estado);
	
	getch();		
	
	return(0);
}

