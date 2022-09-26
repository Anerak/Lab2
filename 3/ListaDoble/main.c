#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include ".\Headers\nodo.h"

void guardarPersonas();
int contarCondicion(nodo *l, int edadMinima, char genero, char letra);
stPersona *listaArreglo(nodo *l, int *v, int edadMinima, char genero, char letra);

int main()
{

    srand(time(NULL));

    nodo *lista;
    lista = inicLista();

    leerDatos(&lista);

    mostrarLista(lista);

    printf("ESPERO NO ROMPERME: %d\n", contarCondicion(lista, 18, 'f', 'e'));

    int validosArreglo = 0;

    stPersona *arreglo = listaArreglo(lista, &validosArreglo, 18, 'f', 'e');

    for (int i = 0; i < validosArreglo; i++)
    {
        mostrarPersona(arreglo[i]);
    }

    return 0;
}

stPersona *listaArreglo(nodo *l, int *v, int edadMinima, char genero, char letra)
{
    *v = contarCondicion(l, edadMinima, genero, letra);
    stPersona *ps = (stPersona *)malloc(sizeof(stPersona) * (*v));

    nodo *seg = l;

    int i = 0;

    while (seg->siguiente)
    {
        if (seg->dato.edad >= edadMinima && seg->dato.genero == genero && seg->dato.nombre[(strlen(seg->dato.nombre)) - 1] == letra)
        {
            ps[i] = seg->dato;
            i++;
        }
        seg = seg->siguiente;
    }

    return ps;
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

int contarCondicion(nodo *l, int edadMinima, char genero, char letra)
{
    if (!l)
        return 0;

    int c = 0;
    nodo *seg = l;
    while (seg->siguiente)
    {
        if (seg->dato.edad >= edadMinima && seg->dato.genero == genero && seg->dato.nombre[(strlen(seg->dato.nombre)) - 1] == letra)
        {
            c++;
        }
        seg = seg->siguiente;
    }

    return c;
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