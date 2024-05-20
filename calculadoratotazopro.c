#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char valor;
    float valorNum;
    char tipo;
} Token;

Token obtenerSigToken(char **expresion) {
    Token token;
    char *exp = *expresion;

    if (*exp != '\n' && *exp != '\0') {
	while (isspace(*exp)) {
            exp++;
	}
	if (isdigit(*exp)) {
	    char *endptr;
	    token.valorNum = strtof(exp, &endptr);
	    if (*endptr == ','){
		*endptr = '.';
		token.valorNum = strtof(exp, &endptr);
	    }
	    exp = endptr;
	    if (*exp == '%'){
		token.valorNum = token.valorNum/100;
		exp++;
	    }
            token.tipo = 'N';
	} else{
            token.valor = *exp++;
            token.tipo = 'O';
	}
	*expresion = exp;
    } else{
	token.tipo = 'X';
    }
    return token;
}

float evaluarExpresion (char *expresion) {
    Token token, operadorT;
    float resultado, operando;
    char operador;
    char colaOp[100];
    float colaNum[100];
    int inicio = -1;

    token = obtenerSigToken(&expresion);

    if (token.tipo != 'N') {
	printf("Error: expresion invalida \n");
	printf("No es un numero\n");
        exit(0);
    }
    resultado = token.valorNum;

    while ((operadorT = obtenerSigToken(&expresion)).tipo == 'O') {
        token = obtenerSigToken(&expresion);

        if (token.tipo != 'N') {
            printf("Error: expresion invalida.\n");
	    if (token.tipo == 'O')
		printf("Dos operadores seguidos. \n");
            exit(0);
        }
        operando = token.valorNum;
        operador = operadorT.valor;

        if(operador == '+' || operador == '-'){
            colaNum[++inicio] = resultado;
            colaOp[++inicio] = operador;
            resultado = operando;
        }
        else{
            switch(operador){
                case '*':
                    resultado *= operando;
                    break;
                case '/':
                    if(operando == 0){
                        printf("Error: expresión invalida.\n");
			printf("Division por 0. \n");
                        exit(0);
                    }
                    resultado /= operando;
                    break;
                default:
                    printf("Error: expresión invalida.\n");
		    printf("No es una operacion valida. \n");
                    exit(0);
            }
        }
    }

    colaNum[++inicio] = resultado;
    int i = 0;
    resultado = colaNum[i++];
    while (inicio > -1 && i <= inicio-1) {
        operador = colaOp[i++];
        operando = colaNum[i++];
        switch(operador){
            case '+':
                resultado += operando;
                break;
            case '-':
                resultado -= operando;
                break;
            default:
                printf("Error: expresión invalida. \n");
                exit(0);
        }
    }
    return resultado;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main (){

    printf("\n----------------------------- \n");
    printf(" BIENVENID@ A LA CALCULADORA \n");
    printf("----------------------------- \n");
    printf("Para salir de ella presiona Ctrl+C \n");


    while(1){
	printf("\nPresiona enter para ingresar la operacion");
	limpiarBuffer();

        char expresion[100];
        fgets(expresion, sizeof(expresion), stdin);
        float resultado = evaluarExpresion(expresion);
        printf("= %g \n", resultado);
    }
    return 0;
}
