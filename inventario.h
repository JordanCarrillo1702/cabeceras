#define Productos 5
#define TamanoNombre 30

void IngresarDatos(char nombres[][TamanoNombre], float precios[]);
float Calculartotal(float precios[]);
int CalcularMax(float precios[]);
int CalcularMin(float precios[]);
float CalcularPromedio(float precios[]);
int sonIguales(char a[], char b[]);
int BuscarProducto(char nombres[][TamanoNombre], char buscado[]);
