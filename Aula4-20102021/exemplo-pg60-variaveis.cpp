#include <stdio.h>

int CalculaDobro (int *X){
	*X=2**X;
	return *X;
}

int main(){
	int Y;
	Y=10;
	printf("%d\n",CalculaDobro(&Y));
	printf("%d",Y);
}