#include <stdio.h>

int main(int argc, char *argv[]){
    int num1=5;
    //declaro puntero
    int *puntero;
    // asignar direccion de memoria al puntero
    puntero = &num1;
    printf("El valor de la variable num1 es %d\n",num1);
    printf("El contenido de la direccion del puntero es %d\n",*puntero);
    // manipular el contenido a traves 
    // operador de indireccion
    *puntero = 10;
    printf("El valor de la variable num1 es %d\n",num1);
    printf("El contenido de la direccion del puntero es %d\n",*puntero);
    num1 = 8;
    printf("El valor de la variable num1 es %d\n",num1);
    printf("El contenido de la direccion del puntero es %d\n",*puntero);
    printf("La direccion de memoria donde esta almacenado num1 es %p\n",&num1);
    printf("La direccion de memoria donde esta almacenado el puntero es %p\n",&puntero);
    printf("El puntero tiene almacenado  %p\n",puntero);
    return 0;
}