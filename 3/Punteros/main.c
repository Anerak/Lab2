#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include ".\Headers\nodo.h"
#include <string.h>
// #include ".\Headers\pila.h"

void guardarPersonas();
int main()
{

    srand(time(NULL));

    nodo *lista;
    lista = inicLista();

    leerDatos(&lista);

    mostrarLista(lista);

    return 0;
}

void guardarPersonas()
{
    FILE *a;
    a = fopen("./personas.dat", "w+b");
    if (a)
    {
        for (int i = 0; i < 20; i++)
        {
            stPersona p = personaRandom();
            fwrite(&p, sizeof(stPersona), 1, a);
        }
        fclose(a);
    }
}

int contarSegunEdad(nodo *l, int edadMinima)
{
    if (!l)
        return 0;

    int c = 0;
    nodo *seg = l;
    while (seg->siguiente)
    {
        if (seg->dato.edad >= edadMinima)
        {
            c++;
        }
    }

    return c;
}