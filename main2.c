#include <stdio.h>
#include "inventario.h"

int main(){

    char nombres[Productos][TamanoNombre];
    float precios[Productos];
    int opcion;
    IngresarDatos(nombres,precios);

    do{
        printf("1. Calcular precio total\n");
        printf("2. Producto mas caro y mas barato\n");
        printf("3. Calcular promedio\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if(opcion ==1){
            float total =Calculartotal(precios);
            printf("El precio total del inventario es: %2.f\n",total);
        }

        else if(opcion ==2){
            int precioMax = CalcularMax(precios);
            printf("El producto mas caro es: %s, con un precio de: %2.f\n",nombres[precioMax],precios[precioMax]);
            int precioMin= CalcularMin(precios);
            printf("El producto mas barato es: %s, con un precio de: %2.f\n",nombres[precioMin],precios[precioMin]);
        }

        else if(opcion ==3){
            float promedio = CalcularPromedio(precios);
            printf("El promedio de todos los articulos es: %2.f\n",promedio);
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

    } while (opcion !=5);

    return 0;
}