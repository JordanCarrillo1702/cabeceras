#include "produccion.h"
#include "lecturas.h"
#include <string.h>
#include <stdio.h>

void ingresarDatos(char nombres[][MAX_NOMBRE], float tiempos[], float recursos[], float cobre[], int demandas[], int* cantidad_productos) {
    if (*cantidad_productos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar mas productos.\n");
        return;
    }

    printf("\n--- Ingreso de Productos ---\n");

    // Leer nombre (con fgets, porque es texto)
    printf("Nombre del producto: ");
    fgets(nombres[*cantidad_productos], MAX_NOMBRE, stdin);
    nombres[*cantidad_productos][strcspn(nombres[*cantidad_productos], "\n")] = 0;

    //validaciones:
    tiempos[*cantidad_productos]  = ingresaFloat("Tiempo de produccion");
    recursos[*cantidad_productos] = ingresaFloat("Cantidad de aluminio necesario");
    cobre[*cantidad_productos]    = ingresaFloat("Cantidad de cobre necesario");
    demandas[*cantidad_productos] = ingresaEntero("Demanda del producto");

    (*cantidad_productos)++;

    printf("Producto agregado correctamente.\n");
}

void mostrarProductos(const char nombres[][MAX_NOMBRE], const float* tiempos, const float* recursos, const float* cobre, const int* demandas, int cantidad_productos) {
    if (cantidad_productos == 0) {
        printf("No hay productos para mostrar.\n");
        return;
    }
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < cantidad_productos; ++i) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Tiempo de Fabricacion: %.2fh\n", tiempos[i]);
        printf("  Cantidad de Aluminio: %.2f mg\n", recursos[i]);
        printf("  Cantidad de Cobre: %.2f mg\n", cobre[i]);
        printf("  Demanda: %d unidades\n", demandas[i]);
    }
}

int buscarProducto(const char nombres[][MAX_NOMBRE], int cantidad_productos, const char* nombre_buscar) {
    for (int i = 0; i < cantidad_productos; ++i) {
        if (strcmp(nombres[i], nombre_buscar) == 0) {
            return i; 
        }
    }
    return -1; 
}

void editarProducto(char nombres[][MAX_NOMBRE], float tiempos[], float recursos[],
                    float cobre[], int demandas[], int cantidad_productos) 
{
    if (cantidad_productos == 0) {
        printf("No hay productos para editar.\n");
        return;
    }

    char nombre_buscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    fgets(nombre_buscar, MAX_NOMBRE, stdin);
    nombre_buscar[strcspn(nombre_buscar, "\n")] = 0;

    int index = buscarProducto(nombres, cantidad_productos, nombre_buscar);
    if (index == -1) {
        printf("El producto no existe.\n");
        return;
    }

    printf("\n--- Editando producto: %s ---\n", nombres[index]);

    tiempos[index]  = ingresaFloat("Nuevo tiempo de produccion");
    recursos[index] = ingresaFloat("Nueva cantidad de recurso");
    cobre[index]    = ingresaFloat("Nuevo costo en cobre");
    demandas[index] = ingresaEntero("Nueva demanda");

    printf("Producto actualizado correctamente.\n");
}

void eliminarProducto(char nombres[][MAX_NOMBRE], float* tiempos, float* recursos, float* cobre, int* demandas, int* cantidad_productos) {
    if (*cantidad_productos == 0) {
        printf("No hay productos para eliminar.\n");
        return;
    }
    char nombre_buscar[MAX_NOMBRE];
    printf("Ingrese el nombre del producto que desea eliminar: ");
    scanf("%49s", nombre_buscar);
    while (getchar() != '\n');

    int indice = buscarProducto(nombres, *cantidad_productos, nombre_buscar);

    if (indice != -1) {
        for (int i = indice; i < *cantidad_productos - 1; ++i) {
            strcpy(nombres[i], nombres[i + 1]);
            tiempos[i] = tiempos[i + 1];
            recursos[i] = recursos[i + 1];
            cobre[i] = cobre[i + 1];
            demandas[i] = demandas[i + 1];
        }
        (*cantidad_productos)--;
        printf("Producto eliminado.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void calcularTotales(const char nombres[][MAX_NOMBRE], const float* tiempos, const float* recursos, const float* cobre, const int* demandas, int cantidad_productos) {
    if (cantidad_productos == 0) {
        printf("No hay productos para calcular.\n");
        return;
    }

    double tiempo_total = 0;
    double recursos_totales = 0;
    double cobre_total = 0;

    for (int i = 0; i < cantidad_productos; i++) {
        tiempo_total += (double)tiempos[i] * demandas[i];
        recursos_totales += (double)recursos[i] * demandas[i];
        cobre_total += (double)cobre[i] * demandas[i];
    }

    printf("\n--- Totales de Produccion ---\n");
    printf("Tiempo total de fabricacion requerido: %.2f horas.\n", tiempo_total);
    printf("Cantidad total de aluminio necesaria: %.2f mg.\n", recursos_totales);
    printf("Cantidad total de cobre necesaria: %.2f mg.\n", cobre_total);
}

void verificarViabilidad(const char nombres[][MAX_NOMBRE], const float* tiempos, const float* recursos, const float* cobre, const int* demandas, int cantidad_productos) {
    if (cantidad_productos == 0) {
        printf("No hay productos para verificar.\n");
        return;
    }

    double tiempo_total_req = 0;
    double recursos_totales_req = 0;
    double cobre_total_req = 0;

    for (int i = 0; i < cantidad_productos; i++) {
        tiempo_total_req += (double)tiempos[i] * demandas[i];
        recursos_totales_req += (double)recursos[i] * demandas[i];
        cobre_total_req += (double)cobre[i] * demandas[i];
    }

    float tiempo_disponible;
    float recursos_disponibles;
    float cobre_disponible;

    printf("Ingrese el tiempo de produccion total disponible (en horas): ");
    scanf("%f", &tiempo_disponible); 
    while (getchar() != '\n');

    printf("Ingrese la cantidad de aluminio total disponible: ");
    scanf("%f", &recursos_disponibles);
    while (getchar() != '\n');

    printf("Ingrese la cantidad de cobre total disponible: ");
    scanf("%f", &cobre_disponible);
    while (getchar() != '\n');

    printf("\n--- Analisis de Viabilidad ---\n");
    printf("Tiempo total requerido: %.2f horas.\n", tiempo_total_req);
    printf("Aluminio total requerido: %.2f mg.\n", recursos_totales_req);
    printf("Cobre total requerido: %.2f mg.\n", cobre_total_req);
    printf("Tiempo total disponible: %.2f horas.\n", tiempo_disponible);
    printf("Aluminio total disponible: %.2f mg.\n", recursos_disponibles);
    printf("Cobre total disponible: %.2f mg.\n", cobre_disponible);

    if (tiempo_total_req <= tiempo_disponible && recursos_totales_req <= recursos_disponibles && cobre_total_req <= cobre_disponible) {
        printf("\nConclusion: La fabrica PUEDE cumplir con la demanda.\n");
    } else {
        printf("\nConclusion: La fabrica NO PUEDE cumplir con la demanda.\n");
        if (tiempo_total_req > tiempo_disponible) {
            printf("  - Deficit de tiempo: %.2f horas.\n", tiempo_total_req - tiempo_disponible);
        }
        if (recursos_totales_req > recursos_disponibles) {
            printf("  - Deficit de aluminio: %.2f mg.\n", recursos_totales_req - recursos_disponibles);
        }
        if (cobre_total_req > cobre_disponible) {
            printf("  - Deficit de cobre: %.2f mg.\n", cobre_total_req - cobre_disponible);
        }
    }
}