#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./Headers/arbol.h"

nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *crearNodoArbol(stPersona dato)
{
    nodoArbol *n = (nodoArbol *)malloc(sizeof(nodoArbol));
    n->dato = dato;
    n->izq = NULL;
    n->der = NULL;
}

nodoArbol *agregarNodo(nodoArbol *t, stPersona dato)
{
    if (t == NULL)
    {
        t = crearNodoArbol(dato);
    }
    else
    {

        if (t->dato.id < dato.id)
        {
            t->der = agregarNodo(t->der, dato);
        }
        else
        {
            t->izq = agregarNodo(t->izq, dato);
        }
    }

    return t;
}

nodoArbol *agregarNodoPorDni(nodoArbol *t, stPersona dato)
{
    if (t == NULL)
    {
        t = crearNodoArbol(dato);
    }
    else
    {
        if (t->dato.dni < dato.dni)
        {
            t->der = agregarNodoPorDni(t->der, dato);
        }
        else
        {
            t->izq = agregarNodoPorDni(t->izq, dato);
        }
    }

    return t;
}

void preOrden(nodoArbol *t)
{
    if (t)
    {
        mostrarPersona(t->dato);
        preOrden(t->izq);
        preOrden(t->der);
    }
}

void inOrden(nodoArbol *t)
{
    if (t)
    {
        inOrden(t->izq);
        mostrarPersona(t->dato);
        inOrden(t->der);
    }
}

void postOrden(nodoArbol *t)
{
    if (t)
    {
        postOrden(t->izq);
        postOrden(t->der);
        mostrarPersona(t->dato);
    }
}

nodoArbol *buscarNodoArbol(nodoArbol *t, int id)
{
    nodoArbol *n = NULL;

    if (t->dato.id == id)
    {
        n = t;
    }
    else
    {
        if (id > t->dato.id)
        {
            n = buscarNodoArbol(t->der, id);
        }
        else
        {
            n = buscarNodoArbol(t->izq, id);
        }
    }

    return n;
}

nodoArbol *buscarNodoArbolPorDni(nodoArbol *t, int dni)
{
    nodoArbol *n = NULL;

    if (t->dato.dni == dni)
    {
        n = t;
    }
    else
    {
        if (dni > t->dato.dni)
        {
            n = buscarNodoArbolPorDni(t->der, dni);
        }
        else
        {
            n = buscarNodoArbolPorDni(t->izq, dni);
        }
    }

    return n;
}

nodoArbol *buscarNodoArbolPorDni(nodoArbol *t, char n[])
{
    nodoArbol *n = NULL;

    if (strcmpi(t->dato.nombre, n) == 0)
    {
        n = t;
    }
    else
    {
        n = buscarNodoArbolPorDni(t->der, n);
        if (n == NULL)
        {
            n = buscarNodoArbolPorDni(t->izq, n);
        }
    }

    return n;
}
