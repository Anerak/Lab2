#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include ".\Headers\nodo.h"
#include <string.h>

void guardarPersonas();

void mostrarListaInvertida(nodo *l);
int sumarEdades(nodo *l);
void mostrarPar(nodo *l, int c);
nodo *borrarNodo(nodo *l, int id);
nodo *insertarRecursivo(nodo *l, nodo *n);
nodo *invertirLista(nodo *l);

int main()
{

    srand(time(NULL));
    nodo *lista;
    lista = inicLista();
    lista = agregarPrincipio(lista, crearNodo(personaRandom()));
    lista = agregarPrincipio(lista, crearNodo(personaRandom()));
    lista = agregarPrincipio(lista, crearNodo(personaRandom()));
    // lista = insertarRecursivo(lista, crearNodo(personaRandom()));
    // lista = insertarRecursivo(lista, crearNodo(personaRandom()));
    // lista = insertarRecursivo(lista, crearNodo(personaRandom()));

    mostrarLista(lista);
    printf("- - - - - - - - - - - - -\n");
    // mostrarListaInvertida(lista);
    // printf("La suma total de las edades es...%d\n", sumarEdades(lista));
    // mostrarPar(lista, 0);

    // lista = borrarNodo(lista, -5);
    // lista = insertarRecursivo(lista, crearNodo(personaRandom()));
    lista = invertirLista(lista);
    mostrarLista(lista);

    return 0;
}

// 1. Recorrer una lista y mostrarla en forma invertida.

void mostrarListaInvertida(nodo *l)
{
    if (l)
    {
        mostrarListaInvertida(l->siguiente);
        mostrarPersona(l->dato);
    }
}

// 2. Sumar los elementos de una lista.

int sumarEdades(nodo *l)
{
    int suma = 0;

    if (l)
    {
        suma = l->dato.edad + sumarEdades(l->siguiente);
    }

    return suma;
}

// 3. Mostrar los elementos de una lista ubicados en una posición par.

void mostrarPar(nodo *l, int c)
{
    if (l)
    {
        if ((c % 2) == 0)
        {
            mostrarPersona(l->dato);
        }
        mostrarPar(l->siguiente, c + 1);
    }
}

// 4. Borrar un nodo de una lista (buscado por un dato específico).

nodo *borrarNodo(nodo *l, int id)
{
    nodo *aux = NULL;
    if (l)
    {
        if (l->dato.id == id)
        {
            aux = l;
            l = l->siguiente;
            free(aux);
        }
        else
        {
            l->siguiente = borrarNodo(l->siguiente, id);
        }
    }

    return l;
}

// 5. Insertar un nodo o dato en una lista simplemente enlazada en forma recursiva (manteniendo el orden de forma creciente).

nodo *insertarRecursivo(nodo *l, nodo *n)
{
    if (l == NULL)
    {
        l = n;
    }
    else
    {
        if (l->dato.edad < n->dato.edad)
        {
            // l es el mismo
            // lo que cambia es el que sigue
            // 1 2 4 <- 3
            // l: 1 | n: 3 | se congela l con valor 1
            // l: 2 | n: 3 | se congela l con valor 2
            // l: 4 | n: 3 | el siguiente de n es l
            // aca vuelve a donde comenzó
            l->siguiente = insertarRecursivo(l->siguiente, n);
        }
        else
        {
            // 1 2 3 <- 0
            // 1 < 0 ? N-O
            // 0 1
            // n l

            n->siguiente = l; // l: 4

            l = n; // l: 3 y l.siguiente es 4
        }
    }

    return l;
}

//  6. Invertir una lista cambiando los vínculos.
nodo *invertirLista(nodo *l)
{
    nodo *aux = NULL;
    if (l->siguiente)
    {
        aux = l;
        l = invertirLista(l->siguiente);

        aux->siguiente = NULL;
        l = agregarFinal(l, aux);
    }

    return l;
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