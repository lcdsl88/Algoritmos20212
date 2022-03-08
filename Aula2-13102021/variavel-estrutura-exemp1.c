# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <time.h>

struct Aluno{
    int Matricula;
    char Nome[50];
    time_t DataNasc;
    char Endereco[500];
    bool Formado;
    double CR;
    }

int main(){
    struct Aluno a; /*Declara a como um tipo de Aluno*/    
    return(0);
}
