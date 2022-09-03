#include ".\Headers\nodo.h"
#include ".\Headers\persona.h"

struct nodo *inicLista()
{
    return NULL;
}

nodo *crearNodo(stPersona dato)
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

    nodo *seg = l;
    while (seg->siguiente != NULL)
    {
        seg = seg->siguiente;
    }

    seg->siguiente = n;

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
        mostrarPersona(seg->dato);
        seg = seg->siguiente;
    }
    // if (n != NULL)
    // {
    //     mostrarPersona(n->dato);
    //     mostrarLista(n->siguiente);
    // }
}