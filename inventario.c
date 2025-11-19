#include <stdio.h>
#include "inventario.h"


// Ingresar Datos
void IngresarDatos(char nombres[][TamanoNombre],float precios[]){
      //ingreso de datos
    for(int i= 0; i < Productos;i++){ // recorremos todos los productos
        printf("Introduzca el nombre del producto %d: ",i+1);
        scanf("%s",nombres[i]);
        printf("Ingrese el precio de %s: ", nombres[i]);
        float precio;
        int cantidad = scanf("%f", &precio);// se guarda en cantidad 
        while(cantidad != 1 || precio < 0){
            while(getchar() != '\n');
            printf("Precio invalido. Ingrese el precio de %s: ",nombres[i]);
            cantidad = scanf("%f",&precio);
        }
        precios[i] = precio;// se guarda el precio valido
    }  
}
// Calcular el precio total del inventario
float Calculartotal(float precios[]){
    float total=0;
    for(int i=0; i<Productos;i++){
        total= total+precios[i];// acumula los precios
    }
    return total; // retorna el valor total
}
// Encontrar el producto mas caro 
int CalcularMax(float precios[]){  
    int Max =0;//compara desde el primer elemento
    for (int i=0;i<Productos;i++){ // si encontramos un precio mayor, actualizamos la posicion
        if(precios[i]>precios[Max]){
        Max =i;
    }
    }
    return Max; // retorna el producto mas caro
}
// Encontrar el producto mas barato
int CalcularMin(float precios[]){
    int Min =0; // Se toma el primero como el mas barato 
    for (int i=0;i<Productos;i++){
        if(precios[i]<precios[Min]){
        Min =i; // Se actualiza si hay uno mas barato
    }
    }
    return Min; // Retorna el producto mas barato
}
//Calcular el promedio de todos los productos
float CalcularPromedio (float precios[]){
    float total= Calculartotal(precios); //usamos funcion que suma total
    return total / Productos; // dividimos para sacar el promedio
}
// Buscar un producto con su nombre y mostrar su precio

int sonIguales(char a[], char b[]) { //compara dos cadenas 
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) { // si algun caracter es distinto se devuelve
            return 0;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0'); //si ambos terminaron al mismo tiempo son iguales
}

// FUNCION para buscar el nombre dentro de la matriz
int BuscarProducto(char nombres[][TamanoNombre], char buscado[]) { //usamos funcion  para comparar
    for (int i = 0; i < Productos; i++) {
        if (sonIguales(nombres[i], buscado)) {
            return i;  // encontrado
        }
    }
    return -1; // no encontrado
}

