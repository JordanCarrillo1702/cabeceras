#include <stdio.h>
#include "funciones.h"

int main(){
    int num1 = 5;
    int num2 = 0;
 
    //Llamada a la funcion que no retorna valor
    suma(num1, num2);
 
    //ERROR
    //int resultadoSuma = suma(num1, num2); //No se puede asignar el valor de una funcion que no retorna nada
 
    //Llamada a la funcion que retorna valor, se puede hacer 3 cosas
 
    //1, almacenar el valor que retorna la funcion en una variable
    int resultadoResta = resta(num1, num2);
    printf("La resta de %d - %d es igual a %d\n",num1,num2,resultadoResta);
 
    //2, imprimir directamente el valor que retorna la funcion
    printf("La multiplicacion de %d * %d es igual a %d\n",num1,num2,multiplicacion(num1,num2));
 
    //3, usar el valor que retorna la funcion en una expresion, operacion o en un condicional
    if(division(num1,num2)){
        printf("La division se ejecuto correctamente");    
       
    }else{
        printf("Ocurrio un Error, no se puede dividir entre 0");
    }
    return 0;
 
    //CUIDADO
    division(num1,num2);
 
}