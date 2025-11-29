#define MAX_PRODUCTOS 5
#define MAX_NOMBRE 50

void ingresarDatos(char nombres[][MAX_NOMBRE], float tiempos[], float recursos[], float cobre[], int demandas[], int* cantidad_productos);
void mostrarProductos(const char nombres[][MAX_NOMBRE], const float tiempos[], const float recursos[], const float cobre[], const int demandas[], int cantidad_productos);
void editarProducto(char nombres[][MAX_NOMBRE], float tiempos[], float recursos[], float cobre[], int demandas[], int cantidad_productos);
void eliminarProducto(char nombres[][MAX_NOMBRE], float tiempos[], float recursos[], float cobre[], int demandas[], int* cantidad_productos);
void calcularTotales(const char nombres[][MAX_NOMBRE], const float tiempos[], const float recursos[], const float cobre[], const int demandas[], int cantidad_productos);
void verificarViabilidad(const char nombres[][MAX_NOMBRE], const float tiempos[], const float recursos[], const float cobre[], const int demandas[], int cantidad_productos);
int buscarProducto(const char nombres[][MAX_NOMBRE], int cantidad_productos, const char* nombre_buscar);

