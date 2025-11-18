#include <stdio.h>
#include <math.h>

void hipotenusa() {
    float cat1, cat2, h;

    printf("\n Calcular Hipotenusa \n");
    printf("Ingrese cateto 1: ");
    scanf("%f", &cat1);

    printf("Ingrese cateto 2: ");
    scanf("%f", &cat2);

    h = sqrt((cat1 * cat1) + (cat2 * cat2));

    printf("La hipotenusa es: %.2f\n", h);
}

void estacionamiento() {
    int carros = 3;
    float horas[3];
    float cargos[3];
    float totalHoras = 0, totalCargos = 0;

    printf("\n Cálculo de Estacionamiento \n");

    for(int i = 0; i < carros; i++) {
        printf("Ingrese horas del carro %d: ", i+1);
        scanf("%f", &horas[i]);

        // Fórmula sugerida por tu ejemplo
        // Cargo depende de las horas, por ejemplo:
        if (horas[i] <= 1.5) {
            cargos[i] = 2.0;
        } else if (horas[i] <= 4.0) {
            cargos[i] = 2.5;
        } else {
            cargos[i] = 10.0;
        }
        
        totalHoras += horas[i];
        totalCargos += cargos[i];
    }

    printf("\nCarro\tHoras\tCarga\n");
    for(int i = 0; i < carros; i++) {
        printf("%d\t%.1f\t%.1f\n", i+1, horas[i], cargos[i]);
    }

    printf("TOTAL\t%.1f\t%.1f\n", totalHoras, totalCargos);
}
