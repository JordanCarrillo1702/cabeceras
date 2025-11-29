#include <stdio.h>

int intercambioValor(int a, int b); // Paso de parametro por valor
void intercambioReferencia(int *a,int *b); // paso de parametro por referencia

int main(int argc, char *argv[]){
    int num1,num2;
    num1=5;
    num2=10;
    printf("Valor num1 antes de intercambio: %d\n",num1);
    printf("Valor num2 antes de intercambio: %d\n",num2);
    intercambiarValor(num1,num2);
    printf("Valor num1 despues de intercambio: %d\n",num1);
    printf("Valor num2 despues de intercambio: %d\n",num2);
    intercambiarReferencia();
    printf("Valor num1 despues de intercambiar referencia: %d\n",num1);
    printf("Valor num2 despues de intercambiar referencia: %d\n",num2);
    return 0;
}

int intercambiarValor(int a, int b){
    printf("Valor a al ingresar a la funcion : %d\n",a);
    printf("Valor b al ingresar a la funcion : %d\n",b); 
    int aux= a;
    a=b;
    b= aux;
    printf("Valor a despues del intercambio de la funcion: %d\n",a);
    printf("Valor b despues del intercambio de la funcion : %d\n",b);
}
void intercambiarReferencia(int *a, int *b){
    printf("Valor a al ingresar a la funcion : %d\n",*a);
    printf("Valor b al ingresar a la funcion : %d\n",*b); 
    int aux= a;
    *a=*b;
    b= aux;
    printf("Valor a despues del intercambio de la funcion: %d\n",*a);
    printf("Valor b despues del intercambio de la funcion : %d\n",*b);
}
