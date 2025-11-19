#define Productos 10 // Cuantos productos va a manejar el usuario
#define TamanoNombre 30 // Tamaño maximo de cada articulo 

void IngresarDatos(char nombres[][TamanoNombre], float precios[]); // Funcion que permite ingresar los datos
float Calculartotal(float precios[]);//Calcular el total de los precios
int CalcularMax(float precios[]);// Devuelve el producto mas caro
int CalcularMin(float precios[]);// Devuelve el producto mas barato
float CalcularPromedio(float precios[]); // Calcula el promedio de todos los precios
int sonIguales(char a[], char b[]); //Compara dos cadenas
int BuscarProducto(char nombres[][TamanoNombre], char buscado[]); //Busca el nombre del arreglo

