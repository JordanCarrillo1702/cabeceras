//¿Cuál es la salida del siguiente código?

#include <stdio.h> // Se necesita solo stdio.h para printf
#include <string.h> 

int main() { // <-- ESTO ES NECESARIO
    int arr[] = {5, 10, 15, 20};
    int *ptr = arr + 1;
    
    printf("%d", ptr[2]); // <-- AHORA ESTÁ DENTRO DE main()
    
    return 0;
}