#include <stdio.h>
#include "inventario.h"


// Ingresar Datos
void IngresarDatos(char nombres[][TamanoNombre],float precios[]){
      //ingreso de datos
    for(int i= 0; i < Productos;i++){
        printf("Introduzca el nombre del producto %d: ",i+1);
        scanf("%s",nombres[i]);
        printf("Ingrese el precio de %s: ", nombres[i]);
        float precio;
        int cantidad = scanf("%f", &precio);
        while(cantidad != 1 || precio < 0){
            while(getchar() != '\n');
            printf("Precio invalido. Ingrese el precio de %s: ",nombres[i]);
            cantidad = scanf("%f",&precio);
        }
        precios[i] = precio;
    }  
}
// Calcular el precio total del inventario
float Calculartotal(float precios[]){
    float total=0;
    for(int i=0; i<Productos;i++){
        total= total+precios[i];
    }
    return total;
}
// Encontrar el producto mas caro 
int CalcularMax(float precios[]){
    int Max =0;
    for (int i=0;i<Productos;i++){
        if(precios[i]>precios[Max]){
        Max =i;
    }
    }
    return Max;
}
// Encontrar el producto mas barato
int CalcularMin(float precios[]){
    int Min =0;
    for (int i=0;i<Productos;i++){
        if(precios[i]<precios[Min]){
        Min =i;
    }
    }
    return Min;
}
//Calcular el promedio de todos los productos
float CalcularPromedio (float precios[]){
    float total= Calculartotal(precios);
    return total / Productos;
}
// Buscar un producto con su nombre y mostrar su precio

int sonIguales(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

// FUNCION para buscar el nombre dentro de la matriz
int BuscarProducto(char nombres[][TamanoNombre], char buscado[]) {
    for (int i = 0; i < Productos; i++) {
        if (sonIguales(nombres[i], buscado)) {
            return i;  // encontrado
        }
    }
    return -1; // no encontrado
}

