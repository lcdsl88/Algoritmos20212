# include <stdio.h>
# include <stdbool.h> 

int main(){
    int x,y;
    bool xbemmaior;
    x=2;
    y=3;
    x+=y;
    y+=x;
    x=2*x+y;
    xbemmaior=x>3*y;
    printf("O valor de x é %d\n",x);
    printf("O valor de y é %d\n",y);
    printf("O valor lógico de xbemmaior é %d\n",xbemmaior);
 return (0);   
}
