//Feito por Andre Goncalves Ohuti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

#define N 100

int main(){

    char *numero, *n2m;
    n2m = (char*)malloc(N*sizeof(char));
    numero = (char*)malloc(N*sizeof(char));
    int ba, bd, result;

    scanf("%s",n2m);//Constante de inicializacao do programa
    scanf("%s", numero);//valor a ser convertido
    scanf("%d", &ba);//base em que o valor acima se encontra
    scanf("%d", &bd);//base para qual esse valor sera convertido

    checkExceptions(n2m,numero,ba,bd);//verifica inputs invalidos e retorna as respectivas mensagens de erro

    if(ba==bd){//se a base atual e a base para conversao forem as mesmas, o numero inicial e retornado
        printf(numero);
    }else if(bd==10){//caso a base para qual o num sera convertido e igual a 10, executa a funcao convertToDec
        printf("%d\n",convertToDec(numero,ba));
    }else if(ba==10){//caso a base atual do num  e igual a 10, executa a funcao convertFromDec
        printf("%s\n",convertFromDec(numero,bd));
    }else{////caso a base atual e a para qual o num sera convertido for diferente de 10, executa a funcao convertToDec e depois a convertFromDec
        result = convertToDec(numero,ba);
        sprintf(numero,"%d",result);
        printf("%s\n",convertFromDec(numero,bd));
    }
    free(n2m);
    free(numero);
    return 0;
}
