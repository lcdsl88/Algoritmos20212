# include <stdio.h>
# include <time.h>
# include <conio.h>

int N;

int main(){
	printf("Digite quanto deseja que seja o valor de N: ");
	scanf("%d\n",&N);
	clock_t tStart = clock();
	int i = 2;
	while (i < N){
		i*=i;
		printf ("%d\n",i);
		i++;
		}
	getch();	
    printf("O tempo de execucao foi de: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
