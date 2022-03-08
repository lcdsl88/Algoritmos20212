/* Data: 17/10/2021 - Resolucao exercicio variaveis ponteiros  */
/* Ex: Escrever um algoritmo que armazene 3 contatos em um vetor, no qual cada elemento é um ponteiro para um contato. Usar definição existente de estrutura de Contato.  */
# include <stdio.h>
# include <string.h>
# include <conio.h>

struct Contato{
	
	char Nome[50];
	char email[20];
	char EndComerc[100];
	char EndResid[100];
};

int main(){

	int i;
	struct Contato Contato[3];
	
	for (i = 0; i < 3; i++) {
    printf("Entre com o Nome do Contato %d\n:",i);    
	scanf("%s",&Contato[i].Nome);
	printf("Entre com o email do Contato %d\n:",i);    
	scanf("%s",&Contato[i].email);
	printf("Entre com o Endereco Comercial do Contato %d\n:",i);
	scanf("%s",&Contato[i].EndComerc);
	printf("Entre com o Endereco Residencial do Contato %d\n:",i);
	scanf("%s",&Contato[i].EndResid);	
	}
	
	for (i = 0; i < 3; i++) {
	
	printf("Nome do Contato %d: %s,email do Contato %d: %s, Endereco Comercial do Contato %d: %s, Endereco Residencial do Contato %d: %s",i,Contato[i].Nome,i,Contato[i].email,i,Contato[i].EndComerc,i,Contato[i].EndResid);
	
	}

	struct Contato *contato[3];
	
	for (i = 0; i < 3; i++) {
	contato[i]=&Contato[i];
	}	
	
	for (i = 0; i < 3; i++) {
	printf("Endereco da variavel Contato: %x\n", &Contato[i]  );
    /* Endereco gravado na variavel ponteiro */
    printf("Endereco gravado na variavel *contato: %x\n", contato[i] );
    /* acesso aos valores usando ponteiro */
    printf("O valor da varivel *contato: %d\n", *contato[i] );
	}
	
	getch();
	
	return(0);
	
}