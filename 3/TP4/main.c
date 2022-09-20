#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include ".\Headers\nodo.h"

nodo *cargarListaOrdenada(nodo *l, stConsumos c);
nodo *insertarNodo(nodo *l, stConsumos c);
nodo *listaIntercalada(nodo *l1, nodo *l2);
nodo *cargarListaOrdenadaArchivo(nodo *l);
int contarNodos(nodo *l);
int sumarNodos(nodo *l);

int main()
{

    srand(time(NULL));
    nodo *lista;
    lista = inicLista();

    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));
    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));
    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));

    // cargarListaOrdenada(lista);
    int v = 20;
    stConsumos cs[20];
    // printf("- - - - - LISTA FEA - - - - -\n");
    for (int i = 0; i < v; i++)
    {
        lista = cargarListaOrdenada(lista, consumoRandom());
        // cs[i] = consumoRandom();
        // mostrarConsumo(cs[i]);
    }
    // mostrarLista(lista);
    //  guardarDatos(cs, v);
    //  lista = leerDatos(lista);
    //  lista = leerDatos(lista);
    //  lista = cargarListaOrdenada(lista);
    //  printf("\n- - - - TERMINA LA CARGA - - - -\n");

    // printf("- - - - - LISTA BONITA - - - - -\n");

    nodo *listaBonita = inicLista();
    listaBonita = cargarListaOrdenadaArchivo(listaBonita);
    mostrarLista(listaBonita);

    // nodo *nuevaLista = inicLista();
    // nuevaLista = listaIntercalada(listaBonita, lista);
    // printf("- - - - - LISTA INTERCALADA - - - - -\n");
    // mostrarLista(nuevaLista);

    printf("En la lista fea haaaaaaaay: %d\n", contarNodos(lista));

    printf("Cantidad total de datos: %d\n", sumarNodos(listaBonita));

    system("pause");
    return 0;
}

int sumarNodos(nodo *l)
{
    int s = 0;

    nodo *seg = l;

    while (seg->siguiente)
    {
        s += seg->dato.datosConsumidos;
        seg = seg->siguiente;
    }
    s += seg->dato.datosConsumidos;

    return s;
}

int contarNodos(nodo *l)
{
    int s = 0;

    nodo *seg = l;

    while (seg->siguiente)
    {
        s++;
        seg = seg->siguiente;
    }
    s++;

    return s;
}

// Hacer una función que intercale en orden los elementos de dos listas ordenadas generando una nueva lista.
// Se deben redireccionar los punteros, no se deben crear nuevos nodos.

nodo *listaIntercalada(nodo *l1, nodo *l2)
{
    if (l1 != NULL && l2 == NULL)
        return l1;
    if (l1 == NULL && l2 != NULL)
        return l2;
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }

    nodo *aux;
    nodo *seg1 = l1;
    nodo *seg2 = l2;
    nodo *listaAuxiliar;
    listaAuxiliar = inicLista();
    int i = 0;

    while (seg1->siguiente != NULL && seg2->siguiente != NULL)
    {
        printf("SEG %d\n", i++);

        if (seg1->dato.datosConsumidos < seg2->dato.datosConsumidos)
        {
            printf("ACA ME ROMPI 1\n");
            if (listaAuxiliar == NULL)
            {
                printf("AUXILIAR 1\n");
                listaAuxiliar = seg1;
            }
            else
            {
                printf("AUXILIO 1\n");
                listaAuxiliar->siguiente = seg1;
            }
            seg1 = seg1->siguiente;
        }
        else
        {
            if (listaAuxiliar == NULL)
            {
                printf("AUXILIAR 2\n");
                listaAuxiliar = seg2;
            }
            else
            {
                printf("AUXILIO 2\n");
                listaAuxiliar->siguiente = seg2;
            }
            seg2 = seg2->siguiente;
        }
        printf("AAAAAAAAAA\n");
    }

    if (seg1 != NULL)
    {
        listaAuxiliar->siguiente = seg1;
    }
    else if (seg2 != NULL)
    {
        listaAuxiliar->siguiente = seg2;
    }

    return listaAuxiliar;
}

nodo *cargarListaOrdenadaArchivo(nodo *l)
{
    FILE *a = fopen("datos.dat", "r+b");

    if (a == NULL)
        return l;

    stConsumos c;
    while (fread(&c, sizeof(c), 1, a) > 0)
    {
        l = cargarListaOrdenada(l, c);
    }

    fclose(a);

    return l;
}

nodo *cargarListaOrdenada(nodo *l, stConsumos c)
{

    // Cuando la lista esta vacía, le asignamos el primer nodo.
    if (l == NULL)
    {
        l = crearNodo(c);
    }
    // Usando la propiedad datosConsumidos, ordenamos los nodos.
    // Si la propiedad datosConsumidos del nodo a ingresar
    // es menor al primer nodo en la lista, entonces lo agregamos al principio
    else if (c.datosConsumidos < l->dato.datosConsumidos)
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