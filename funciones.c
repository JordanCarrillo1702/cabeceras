#include <stdio.h>
void suma(int a, int b){
    printf("La suma de %d + %d es igual a %d\n",a,b,(a+b));
}
 
 
//Funciones que retornan valor
int resta(int a, int b){
    return a - b;
 
}
 
int multiplicacion(int a, int b){
    return a * b;
 
}
 
float division(int a, int b){
    if( b != 0){
        return (float)a / b;
    }
    return 0;
 
 
}