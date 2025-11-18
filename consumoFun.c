#include <stdio.h>

void leerConsumo(int consumo[][7], char electrodomestico[][14],const int APARATOS, const int DIAS); //no recibo los enteros que indican el tamaño
//porque tenemos definidos como constantes
void consumoSemanaAparato(const int consumo[][7],int consumo_semanal[],const int APARATOS, const int DIAS);
int totalConsumoSemana(const int consumo_semanal[],const int APARATOS);
void promedioConsumoElectrodomestico(const int consumo_semanal[],const char electrodomestico[][7],const int APARATOS, const int DIAS);
int electrodomesticoMayorConsumo(const int consumo_semanal[],const int APARATOS);
void alerta(const int consumo_semanal[],const int APARATOS);
 
 
int main (int argc, char *argv[]) {

 /*const int APARATOS = 3;
 const int DIAS =7;
 const int MAX = 14;*/

    char electrodomestico[7][14]={"Refrigerador","Lavadora","Televisor"};
    int consumo[3][7];
    int consumo_semana[3];
    float promedio_consumo[3];
   
    leerConsumo(consumo,electrodomestico);
    //obtener el consumo semanal
    consumoSemanaAparato(consumo,consumo_semana);
    printf("El total del consumo semanal por los tres electrodomesticos es %d \n"
        ,totalConsumoSemana(consumo_semana));
 
    promedioConsumoElectrodomestico(consumo_semana,electrodomestico);
    int indice =electrodomesticoMayorConsumo(consumo_semana);
    printf("El electrodomestico que mas consume es %s, con un valor semanal de %d \n"
        ,electrodomestico[indice],consumo_semana[indice]);
         alerta(consumo_semana);
   
    return 0;
}
 
void leerConsumo(int consumo[][7], char electrodomestico[][14],const int APARATOS, const int DIAS){
      //ingreso de datos
    for(int i= 0; i < APARATOS;i++){
        printf("Introduzca el consumo de %s\n",electrodomestico[i]);
        for(int j= 0; j < DIAS; j++){
             printf("Ingrese el consumo del dia %d: ",j+1);
             int valor;
             int cantidad = scanf("%d",&valor);
             while(cantidad != 1 || valor < 0){
                //printf("entra");
                while(getchar() != '\n');
                printf("Ingrese el consumo del %s en el dia %d: ",electrodomestico[i],j+1);
                cantidad = scanf("%d",&valor);
             }
             consumo[i][j] = valor;
        }  
    }
 }
void consumoSemanaAparato(const int consumo[][7],int consumo_semanal[],const int APARATOS, const int DIAS) {
 //calcular el consumo semanal por aparato
    for (int i = 0; i < APARATOS; i++){
      int  suma =0;
        for(int j=0; j< DIAS; j++){
            suma +=consumo[i][j];
        }
        consumo_semanal[i]=suma;
    }
   
 }
int totalConsumoSemana(const int consumo_semanal[],const int APARATOS) {
       //suma total consumo total
    int sumatotal=0;
    for (int i = 0; i < APARATOS; i++){
        sumatotal += consumo_semanal[i];
    }
   
   
 }
void promedioConsumoElectrodomestico(const int consumo_semanal[],const char electrodomestico[][7],const int APARATOS, const int DIAS) {
   //promedio consumo por electrodomestico
    for(int i=0; i<APARATOS; i++){
    printf("El promedio del consumo por el electrodomestico %s es %.2f \n",electrodomestico[i],(consumo_semanal[i]/(float)DIAS));
    }
 }
int electrodomesticoMayorConsumo(const int consumo_semanal[],const int APARATOS) {
   //electrodomestico con mayor consumo
    int mayor;
   mayor=consumo_semanal[0];
    int indice_aparato=0;
    for(int i=1; i<APARATOS; i++){
        if(consumo_semanal[i]>mayor){
        mayor=consumo_semanal[i];
        indice_aparato=i;
        }
    }
    return indice_aparato;
 }
void alerta(const int consumo_semanal[],const int APARATOS) {
      //alerta
     
    if(totalConsumoSemana(consumo_semanal)>150){
        printf("SALVEMOS EL PLANETA, disminuye tu consumo de energia");
    }
   
 }