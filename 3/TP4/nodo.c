#include ".\Headers\nodo.h"
#include ".\Headers\consumo.h"

struct nodo *inicLista()
{
    return NULL;
}

nodo *crearNodo(stConsumos dato)
{
    nodo *n = (nodo *)malloc(sizeof(nodo));
    n->dato = dato;
    n->siguiente = NULL;

    return n;
}

nodo *agregarPrincipio(nodo *l, nodo *n)
{
    n->siguiente = l;
    return n;
    // if (l == NULL)
    // {
    //     l = n;
    // }
    // else
    // {
    //     n->siguiente = l;
    //     l = n;
    // }

    // return l;
}

nodo *agregarFinal(nodo *l, nodo *n)
{
    if (l == NULL)
    {
        l = n;
    }
    else
    {
        nodo *seg = l;
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }

        seg->siguiente = n;
    }

    return l;
}

nodo * final(nodo *l, nodo *n)
{
    if (l == NULL)
    {
        l = n;
    }

    if (l->siguiente != NULL)
    {
        l->siguiente = final(l->siguiente, n);
    }
    else
    {
        l->siguiente = n;
    }

    return l;
}

void mostrarLista(nodo *l)
{
    nodo *seg = l;

    while (seg != NULL)
    {
        mostrarConsumo(seg->dato);
        seg = seg->siguiente;
    }
}

nodo *leerDatos(nodo *l)
{
    FILE *a = fopen("./datos.dat", "r+b");
    stConsumos c;
    if (a == NULL)
        return l;

    while (fread(&c, sizeof(stConsumos), 1, a) > 0)
    {
        l = agregarFinal(l, crearNodo(c));
    }

    fclose(a);
    return l;
}

nodo *buscarUltimo(nodo *l)
{
    nodo *seg = l;
    while (seg->siguiente != NULL)
    {
        seg = seg->siguiente;
    }

    return seg;
}