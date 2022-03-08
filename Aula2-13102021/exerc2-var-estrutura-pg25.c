/* Data: 16/10/2021 - Resolucao exercicio 2 variaveis estrutura  */
/* Ex2: Definir uma estrutura Contato, com os campos Nome, E-mail, Endereço Comercial e Endereço Residencial, e preencher valor para uma variável deste tipo */


# include <stdio.h>
# include <string.h>
# include <conio.h>

struct Contato{
	
	char Nome[50];
	char email[20];
	char EnderecoComercial[100];
	char EnderecoResidencial[100];
};

int main(){
	
	struct Contato Contato1;
	
	/* Preenchimento dos valores do Contato1 */
	strcpy( Contato1.Nome, "ABC");
	strcpy( Contato1.email, "abc@abc.com");
	strcpy( Contato1.EnderecoComercial, "Rua abc, 123");
	strcpy( Contato1.EnderecoResidencial, "Rua cba, 321");
	
	/* Impressao das informacoes do Endereco1 */
	
	printf("O Nome do Contato1 eh: %s\n",Contato1.Nome);
	printf("O email do Contato1 eh: %s\n",Contato1.email);
	printf("O Endereco Comercial do Contato1 eh: %s\n",Contato1.EnderecoComercial);
	printf("O Endereco Residencial do Contato1 eh: %s\n",Contato1.EnderecoResidencial);
	
	getch();
	
	return(0);
	
}