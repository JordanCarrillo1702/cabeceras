#include <stdio.h>
#include "inventario.h"

int main(){

    char nombres[Productos][TamanoNombre];//Matriz para almacenar nombres 
    float precios[Productos];// precios
    int opcion;// para el menu
    IngresarDatos(nombres,precios); // nos llama los datos y precios

    do{
        printf("1. Calcular precio total\n");
        printf("2. Producto mas caro y mas barato\n");
        printf("3. Calcular promedio\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if(opcion ==1){
            float total =Calculartotal(precios); // funcion que suma todos los productos
            printf("El precio total del inventario es: %.2f\n",total);
        }

        else if(opcion ==2){// producto mas caro y barato
            int precioMax = CalcularMax(precios);
            printf("El producto mas caro es: %s, con un precio de: %.2f\n",nombres[precioMax],precios[precioMax]);
            int precioMin= CalcularMin(precios);
            printf("El producto mas barato es: %s, con un precio de: %.2f\n",nombres[precioMin],precios[precioMin]);
        }

        else if(opcion ==3){//promedio de precios
            float promedio = CalcularPromedio(precios);
            printf("El promedio de todos los articulos es: %.2f\n",promedio);
        }

        else if(opcion ==4){
            char buscado[TamanoNombre];
            printf("Ingrese el nombre del producto a buscar: ");
            scanf("%s", buscado);

            int pos = BuscarProducto(nombres, buscado);
            if (pos == -1) {
                printf("Producto no encontrado.\n");
            } 
            else {
                printf("Producto encontrado: %s Su Precio: %.2f\n",
                nombres[pos], precios[pos]);
            }
        }

        else if(opcion != 5){
            printf(" Opcion invalida, intente nuevamente\n");
        }

    } while (opcion !=5); // repite hasta que el usuario decida salir

}