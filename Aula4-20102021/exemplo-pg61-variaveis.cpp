#include <stdio.h>

int CalculaDobro (int &X){
	X=2*X;
	return X;
}

int main(){
	int Y, CopiaY;
	Y=10;
	CopiaY=Y;
	printf("%d\n",CalculaDobro(CopiaY));
	printf("%d",Y);
}