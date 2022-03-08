/* 08/10/2021 - Estudo Algoritmos Aula 01 - Variáveis - C
Referência: https://www.tutorialspoint.com/cprogramming/c_variables.htm */

#include <stdio.h>

//Declaracao de variaveis

extern int a,b;
extern int c;
extern float f;
//extern double d;

int main () {
	
	/* definicao das variaveis */
	int a,b;
	int c;
	float f;
	//double d;
	
	/* inicializacao real */
	a = 10;
	b = 20;
	
	c = a+b;
	printf("o valor de c é: %d \n",c);
	
	f = 70.0/3.0;
	printf("o valor de f é: %f \n",f);
	
	return 0;
}
	
