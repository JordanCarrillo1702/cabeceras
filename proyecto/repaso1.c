#include <stdio.h>
#define MAX 30
 
void ingresarNotas(int notas[],int *numAlumnos);
void ingresarNotasPregunta(int notas[],int *numAlumnos);
void ingresarNotasIndividual(int notas[],int *numAlumnos);
void imprimirNotas(const int notas[], int numAlumnos);
float promedioCurso(const int notas[], int numAlumnos);
 
int main (int argc, char *argv[]) {

    int notas[MAX];
    int alumnos = 0;

    //invocaciones a las funciones ingresar
    ingresarNotas(notas,&alumnos);
    ingresarNotasIndividual(notas, &alumnos);
    ingresarNotasPregunta(notas,&alumnos);
 
    //invocar al imprimir
    imprimirNotas(notas,alumnos);

    printf("El promedio del curso es: %.2f\n",promedioCurso(notas,alumnos));
 
    return 0;
}


// ----------------------------------------------
void ingresarNotas(int notas[],int *numAlumnos){
    printf("Cuantos estudiantes hay en el curso: ");
    scanf("%d", numAlumnos);   // ← ERROR CORREGIDO: debía ir SIN *
    
    for(int i = 0; i < *numAlumnos; i++){
        printf("Ingrese la nota del estudiante %d: ",i+1);
        scanf("%d",&notas[i]);
    }
}


// ----------------------------------------------
void ingresarNotasPregunta(int notas[],int *numAlumnos){
    int opc;
    do{
        printf("Ingrese la nota del estudiante %d: ",(*numAlumnos)+1);
        scanf("%d",&notas[*numAlumnos]);
        (*numAlumnos)++; // equivale a *numAlumnos = *numAlumnos + 1;

        if(*numAlumnos == MAX){
            printf("Se ha llegado al límite de alumnos\n");
            break;
        }

        printf("1 para ingresar más notas, 0 para salir: ");
        scanf("%d",&opc);

    }while(opc != 0);
}


// ----------------------------------------------
void ingresarNotasIndividual(int notas[],int *numAlumnos){
    if(*numAlumnos < MAX){
        printf("Ingrese la nota del estudiante %d: ",(*numAlumnos)+1);
        scanf("%d",&notas[*numAlumnos]);
        (*numAlumnos)++;
    }else{
        printf("Se ha completado el limite de estudiantes\n");
    }
}


// ----------------------------------------------
void imprimirNotas(const int notas[], int numAlumnos){
    printf("\nListado de notas:\n");
    for(int i = 0; i < numAlumnos; i++){
        printf("Estudiante %d: %d\n", i+1, notas[i]);
    }
}


// ----------------------------------------------
float promedioCurso(const int notas[], int numAlumnos){
    int suma = 0;

    for(int i = 0; i < numAlumnos; i++){
        suma += notas[i];
    }

    return (float)suma / numAlumnos;
}
