#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include ".\Headers\nodo.h"
#include <string.h>

nodo *cargarListaOrdenada(nodo *l);
nodo *insertarNodo(nodo *l, stConsumos c);

int main()
{

    srand(time(NULL));
    nodo *lista;
    lista = inicLista();

    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));
    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));
    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));

    // cargarListaOrdenada(lista);
    // int v = 20;
    // stConsumos cs[20];
    // for (int i = 0; i < v; i++)
    // {
    //     cs[i] = consumoRandom();
    //     mostrarConsumo(cs[i]);
    // }
    // guardarDatos(cs, v);
    // lista = leerDatos(lista);
    // lista = leerDatos(lista);
    lista = cargarListaOrdenada(lista);
    // printf("\n- - - - TERMINA LA CARGA - - - -\n");
    mostrarLista(lista);

    return 0;
}

nodo *cargarListaOrdenada(nodo *l)
{
    FILE *a = fopen("datos.dat", "r+b");

    if (a == NULL)
        return l;

    stConsumos c;
    while (fread(&c, sizeof(c), 1, a) > 0)
    {
        // Cuando la lista esta vacía, le asignamos el primer nodo.
        if (l == NULL)
        {
            l = crearNodo(c);
            continue;
        }

        // Usando la propiedad datosConsumidos, ordenamos los nodos.
        // Si la propiedad datosConsumidos del nodo a ingresar
        // es menor al primer nodo en la lista, entonces lo agregamos al principio
        if (c.datosConsumidos < l->dato.datosConsumidos)
        {
            l = agregarPrincipio(l, crearNodo(c));
        }
        // En caso de no ser menor, buscamos el último nodo en la lista
        // comparamos si es menor al nodo a ingresar
        // y agregamos este último al final de la lista.
        else if (c.datosConsumidos > (buscarUltimo(l)->dato.datosConsumidos))
        {
            l = agregarFinal(l, crearNodo(c));
        }
        // Por último, si el nodo a ingresar corresponde a un lugar dentro de la lista,
        // usamos la función insertarNodo
        else
        {
            l = insertarNodo(l, c);
        }
    }

    fclose(a);

    return l;
}

nodo *insertarNodo(nodo *l, stConsumos c)
{
    nodo *listaAuxiliar;
    listaAuxiliar = inicLista();

    if (l == NULL)
    {
        listaAuxiliar = agregarPrincipio(l, crearNodo(c));
    }
    else
    {
        nodo *seg = l;

        // Mientras que el nodo actual sea menor al nodo que queremos ingresar
        // lo guardamos en una lista auxiliar, para no perder los datos.
        while (seg->dato.datosConsumidos < c.datosConsumidos)
        {
            listaAuxiliar = agregarFinal(listaAuxiliar, crearNodo(seg->dato));
            seg = seg->siguiente;
        }
        // Una vez que encontramos la posición donde corresponde nuestro nodo
        // lo agregamos a la lista
        listaAuxiliar = agregarFinal(listaAuxiliar, crearNodo(c));

        // Si queda al menos un nodo, lo agregamos a la lista
        // Como este nodo incluye los que siguen, no es necesario repetir la función.
        if (seg != NULL)
        {
            listaAuxiliar = agregarFinal(listaAuxiliar, seg);
        }
    }

    return listaAuxiliar;
}