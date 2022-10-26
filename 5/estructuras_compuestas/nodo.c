#include ".\Headers\nodo.h"
#include ".\Headers\alumno.h"

struct nodo *inicLista()
{
    return NULL;
}

nodo *crearNodo(notaAlumno dato)
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
        mostrarNotaAlumno(seg->dato);
        seg = seg->siguiente;
    }
}

nodo *leerDatos(nodo *l)
{
    FILE *a = fopen("./datos.dat", "r+b");
    notaAlumno c;
    if (a == NULL)
        return l;

    while (fread(&c, sizeof(notaAlumno), 1, a) > 0)
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

int buscarElemento(nodo *l, notaAlumno dato)
{
    int resultado = 0;
    if (l != NULL)
    {
        nodo *seg = l;

        while (seg->siguiente != NULL)
        {
            if (seg->dato.legajo == dato.legajo)
            {
                resultado = 1;
                mostrarNotaAlumno(seg->dato);
                break;
            }
            seg = seg->siguiente;
        }
    }

    return resultado;
}