//Feito por Andre Goncalves Ohuti

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

#define N 100
#define alphabet 26

//Checa possiveis valores invalidos no input do programa
void checkExceptions(char *n2m, char *numero, int ba, int bd){
    char *pch = strstr(n2m,"n2m");
    int tempNum = atoi(numero);

    if(!pch){
        printf("ERROR! INVALID INITIATION KEY.\n");
        exit(0);
    }
    if(tempNum<0){
        printf("ERROR! INVALID NUMBER.\n");
        exit(0);
    }
    if(ba<2||ba>36){
        printf("ERROR! INVALID BASE.\n");
        exit(0);
    }
    if(bd<2||bd>36){
        printf("ERROR! INVALID BASE.\n");
        exit(0);
    }
    if(ba==2){
        int i, limit;
        char temp[1];
        tempNum = strlen(numero);
        for(i=0;i<tempNum;i++){
            temp[0] = numero[i];
            limit = atoi(temp);
            if(limit<0||limit>1){
                printf("ERROR! INVALID INPUT.\n");
                exit(0);
            }
        }
    }
    if(ba>10){
        int i, length, limit;
        char l;
        
        limit = ba-11+65;
        length = strlen(numero);
        for(i=0;i<length;i++){
            l = numero[i];
            if(isalpha(l)){
                tempNum = l;
                if(tempNum>=97&&tempNum<=122){
                    tempNum -= 32;
                }
                if(tempNum<65||tempNum>limit){
                    printf("ERROR! INVALID INPUT.\n");
                    exit(0);
                }
            }
        }
    }
    if(ba<=10){
        int i, length;
        char l;

        length = strlen(numero);
        for(i=0;i<length;i++){
            l = numero[i];
            if(isalpha(l)){
                printf("ERROR! INVALID INPUT.\n");
                exit(0);
            }
        }
    }
}

//Realiza a operao de elevar um numero x a uma potencia n
int square(int num, int myExp){
    int i, result=1;
    for(i=0;i<myExp;i++){
        result *= num;
    }
    return result;
}

//Recebe uma letra do input e devolve o numero equivalente para realizar os calculos de conversao
int buscaNumero(char c){
    int i, result;
    char V[alphabet] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char v[alphabet] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    for(i=0;i<alphabet;i++){
        if(c == V[i] || c == v[i]){
            result = i+10;
            return result;
        }
    }
    return -1;
}

//Recebe um numero maior ou iguar a 10 (resultante dos calcs. de conversao) e retorna o numero equivalente
char *buscaLetra(int n){
    int i;
    char V[alphabet] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char *temp;
    temp = (char *)malloc(alphabet*sizeof(char));
    n -= 10;

    for(i=0;i<alphabet;i++){
        if(i == n){
            *temp = V[n];
            return temp;
        }
    }
    return "-1";
}

//Recebe uma letra e converte para numero equivalente por meio da funcao buscaNumero 
char *convertLetters(char* numero){
    int temp;
    char c = numero[0];
    temp = buscaNumero(c);
    if(temp != -1){
        sprintf(numero, "%d", temp);
        return numero;
    }else{
        numero[0] = -1;
        return numero;
    }
}

//Recebe um numero e converte para letra equivalente por meio da funcao buscaLetra
char *convertNumber(int number){
    char *temp = buscaLetra(number);
    if(strcmp(temp,"-1")){
        return temp;
    }else{
        temp[0] = -1;
        return temp;
    }
    free(temp);
}

//Converte um numero de qualquer base para decimal
int convertToDec(char *numero, int ba){

    int length = strlen(numero);
    int i, result=0, temp1=0, temp2=length;

    for(i=0;i<length;i++){
        char *num = (char*)malloc(length*sizeof(char));
        
        strncpy(num,numero+i,1);
        if(isdigit(*num)==0){ 
            num = convertLetters(num);
        }
        
        temp1 = atoi(num);
        result = result + (temp1*square(ba,temp2-1));
        temp2--;
        free(num);
    }
    return result;
}

//Converte um numero de base decimal para qualquer base
char *convertFromDec(char *numero, int bd){

    int i, result=0, resto, length, temp;
    char *tempVal, *PosConv;
    char *rest;
    tempVal = (char *)malloc(N*sizeof(char));
    PosConv = (char *)malloc(N*sizeof(char));
    rest = (char *)malloc(1*sizeof(char));
    

    result = atoi(numero);
    if(result>=bd){
        while(result>=bd){
            resto = result%bd;
            result = result/bd;
            if(resto>9){
                strcat(tempVal,convertNumber(resto));
            }else{
                sprintf(rest,"%d",resto);
                strcat(tempVal,rest);
            }
        }
        if(result>9){
            strcat(tempVal,convertNumber(result));
        }else{
            sprintf(rest,"%d",result);
            strcat(tempVal,rest);
        }
        length = strlen(tempVal);
        temp = length;
        for(i=0;i<=length;i++){
            PosConv[i] = tempVal[temp-1];
            temp--;
        }
    }else{
        if(result>9){
            PosConv = convertNumber(result);
        }else{
            sprintf(PosConv,"%d",result);
        }
    }
    return PosConv;
}
