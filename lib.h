//Feito por Andre Goncalves Ohuti

#define LIB_H

int n, number, ba, bd, num, myExp;
char *n2m, *numero;
char c;

//Checa possiveis valores invalidos no input do programa
void checkExceptions(char *n2m, char *numero, int ba, int bd);
//Realiza a operao de elevar um numero x a uma potencia n
int square(int num, int myExp);
//Recebe uma letra do input e devolve o numero equivalente para realizar os calculos de conversao
int buscaNumero(char c);
//Recebe um numero maior ou iguar a 10 (resultante dos calcs. de conversao) e retorna o numero equivalente
char *buscaLetra(int n);
//Recebe uma letra e converte para numero equivalente por meio da funcao buscaNumero 
char *convertLetters(char* numero);
//Recebe um numero e converte para letra equivalente por meio da funcao buscaLetra
char *convertNumber(int number);
//Converte um numero de qualquer base para decimal
int convertToDec(char *numero, int ba);
//Converte um numero de base decimal para qualquer base
char *convertFromDec(char *numero, int bd);
