typedef struct stPersona
{
    char nombre[30];
    char genero;
    int edad;
} stPersona;

void mostrarPersonas(stPersona ps[], int v);
void mostrarPersona(stPersona p);
void cargarArreglo(stPersona ps[], int v);
int contarGenero(stPersona ps[], int v, char genero);
stPersona *copiarArreglo(stPersona ps[], int v, char genero, int *nuevoValidos);
void ordenarArreglo(stPersona ps[], int v);