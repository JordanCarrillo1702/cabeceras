#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Verificar si enviaron exactamente 2 números
    if (argc != 3) {
        printf("Uso correcto: %s num1 num2\n", argv[0]);
        return 1;
    }

    // Convertir los argumentos (que son texto) a enteros
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    
    int suma = a + b;

    printf("La suma de %d + %d = %d\n", a, b, suma);

    return 0;
}
