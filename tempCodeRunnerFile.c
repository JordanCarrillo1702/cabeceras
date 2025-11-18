#include <stdio.h>
#define Productos 5
#define TamanoNombre 30


// Ingresar Datos
void IngresarDatos(char nombres[][TamanoNombre],float precios[]){
      //ingreso de datos
    for(int i= 0; i < Productos;i++){
        printf("Introduzca el nombre del producto %d\n",i+1);
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
    return Mix;
}

int main(){

    char nombres[Productos][TamanoNombre];
    float precios[Productos];
    IngresarDatos(nombres,precios);
    float total =Calculartotal(precios);
    printf("El precio total del inventario es: %2.f\n",total);
    int precioMax = CalcularMax(precios);
    printf("El producto mas caro es: %s, con un precio de: %2.f\n",nombres[precioMax],precios[precioMax]);
    int precioMin= CalcularMin(precios);
    printf("El producto mas caro es: %s, con un precio de: %2.f\n",nombres[precioMin],precios[precioMin]);

    
}