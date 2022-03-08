#include <iostream>

using namespace std;

int NroAB(int N){
    // Retorna o # de árvores de busca com N valores
    if (N==0){ //Número de árvores: "N=0" ==> "N==0" (comparador de igualdade é sempre com "==".
        return 1;
    } else {
        int t = 0;
        int r;
        for (r = 1; r <= N; r++){
            int ne; int nd;
            ne = NroAB(r-1);
            nd = NroAB(N-r);
            t = t + ne*nd;
        }
        return t;
    }
}

int main(){
    cout << "O numero de arvores de busca com 3 valores eh: ";
    cout << NroAB(3);
}