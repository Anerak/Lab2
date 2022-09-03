#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include ".\Headers\nodo.h"
#include <string.h>

nodo *cargarListaOrdenada(nodo *l);
nodo *cortarLista(nodo *l, stConsumos c);

int main()
{

    srand(time(NULL));
    nodo *lista;
    lista = inicLista();

    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));
    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));
    // lista = agregarPrincipio(lista, crearNodo(consumoRandom()));

    // cargarListaOrdenada(lista);

    // stConsumos cs[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     cs[i] = consumoRandom();
    // }

    // guardarDatos(cs, 10);
    // lista = leerDatos(lista);
    lista = cargarListaOrdenada(lista);
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
        if (l == NULL)
        {
            printf("LISTA ES NULA\n");
            mostrarConsumo(c);
            l = crearNodo(c);
            continue;
        }

        // 4
        // 1 3 . 5 7
        // 4 < 1 -> no, al final entonces
        // 4 deberia haber estado después del 3

        // 1 2 3 4 5
        // 4 < 2
        // 4 < 3
        // printf("--------\n");
        // printf("Voy a ingresar este dato: %d\n", c.datosConsumidos);
        // mostrarConsumo(c);
        printf("---LISTA ANTES DE AGREGAR----\n");
        mostrarLista(l);
        printf("--------\n");
        if (c.datosConsumidos < l->dato.datosConsumidos)
        {

            l = agregarPrincipio(l, crearNodo(c));
        }
        else if (c.datosConsumidos > buscarUltimo(l)->dato.datosConsumidos)
        {
            l = agregarFinal(l, crearNodo(c));
        }
        else
        {
            l = cortarLista(l, c);
        }

        // nodo *seg = l;
        // while (seg->siguiente != NULL)
        // {

        //     else
        //     {
        //         seg = seg->siguiente;
        //     }
        // }
        // if (seg->siguiente == NULL)
        // {
        //     if (c.datosConsumidos > seg->dato.datosConsumidos)
        //     {
        //         l = agregarFinal(l, crearNodo(c));
        //     }
        //     else
        //     {
        //         l = agregarPrincipio(l, crearNodo(c));
        //     }
        // }
    }

    fclose(a);

    return l;
}

nodo *cortarLista(nodo *l, stConsumos c)
{
    static int cantVeces = 0;
    printf("\nESTA ES LA VEZ Nº%d QUE SE EJECUTA cortarLista\n", cantVeces);
    cantVeces++;
    nodo *listaAuxiliar;
    listaAuxiliar = inicLista();
    if (l == NULL)
    {
        printf("No deberia estar entrando a esta parte, why?\n");
        listaAuxiliar = agregarPrincipio(l, crearNodo(c));
    }
    else
    {
        int i = 0;
        nodo *seg = l;
        while (seg->siguiente != NULL)
        {
            printf("NO ME ROMPI TODAVIA\n");
            // (1) 2 3 4 9 <- 5
            // 1 2 3 4 5 9

            if (seg->dato.datosConsumidos > c.datosConsumidos)
            {
                printf("ENTRE AL IF\n");
                nodo *nuevo = crearNodo(c);
                // nuevo->siguiente = seg;
                listaAuxiliar = agregarFinal(listaAuxiliar, nuevo);
            }
            printf("Me rompi aca?\n");
            listaAuxiliar = agregarFinal(listaAuxiliar, crearNodo(seg->dato));
            printf("Me rompi aca de nuevo?\n");
            mostrarLista(listaAuxiliar);
            seg = seg->siguiente;

            // 1 2 3 4 5 9 <- 5
            // 1 2 3 4 5 9
            // (5) 9
            // estoy en el 4
            // si el siguiente del 4, es mayor al que yo quiero ingresar
            // entonces, tengo que poner mi valor después del 4 y antes del siguiente del 4
            // if (seg->siguiente != NULL && seg->siguiente->dato.datosConsumidos > c.datosConsumidos)
            // {
            //     printf("Me rompere aca?\n");
            //     nodo *siguienteViejo = seg->siguiente;
            //     nodo *nuevo = crearNodo(c);
            //     seg->siguiente = nuevo;
            //     nuevo->siguiente = siguienteViejo;
            //     listaAuxiliar = agregarFinal(listaAuxiliar, seg);
            // }
            // else
            // {
            //     printf("O aca?\n");
            //     listaAuxiliar = agregarFinal(listaAuxiliar, seg);
            //     mostrarLista(listaAuxiliar);
            //     seg = seg->siguiente;
            // }
            // printf("Lista Auxiliar %d\n", i++);
            // mostrarLista(listaAuxiliar);
        }
    }

    return listaAuxiliar;
}