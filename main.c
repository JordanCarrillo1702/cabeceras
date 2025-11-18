#include <stdio.h>
#include "operaciones.h"

int main() {
    int opcion;

    do {
        printf("\n MENU PRINCIPAL \n");
        printf("1. Calcular Hipotenusa\n");
        printf("2. Calculo de Estacionamiento\n");
        printf("3. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                hipotenusa();
                break;
            case 2:
                estacionamiento();
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }

    } while (opcion != 3);

    return 0;
}
