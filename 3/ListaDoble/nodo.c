#include ".\Headers\nodo.h"
#include ".\Headers\persona.h"

nodo *inicLista()
{
    return NULL;
}

nodo *crearNodo(stPersona dato)
{
    nodo *n = (nodo *)malloc(sizeof(nodo));
    n->dato = dato;
    n->anterior = NULL;
    n->siguiente = NULL;

    return n;
}

void agregarPrincipio(nodo **l, nodo *n)
{
    n->anterior = NULL;
    n->siguiente = (*l);
    (*l) = n;
}

void agregarFinal(nodo **l, nodo *n)
{
    if (*l == NULL)
    {
        *l = n;
    }
    else
    {
        nodo *seg = *l;
        while (seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
        seg->siguiente = n;
        n->anterior = seg;
    }
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

void leerDatos(nodo **l)
{
    FILE *a = fopen("./personas.dat", "r+b");
    stPersona p;
    if (a != NULL)
    {
        while (fread(&p, sizeof(stPersona), 1, a) > 0)
        {
            agregarFinal(l, crearNodo(p));
        }

        fclose(a);
    }
    // return l;
}

stPersona verPrimero(nodo *p)
{
    stPersona d = p->dato;
    return d;
}

nodo *borrarPrimero(nodo *p)
{
    nodo *aux = NULL;

    nodo *aBorrar = p;

    if (p->siguiente != NULL)
    {
        aux = p->siguiente;
    }

    free(aBorrar);

    return aux;
}