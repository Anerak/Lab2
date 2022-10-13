#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "./persona.h"

typedef struct _nodoArbol
{
    stPersona dato;
    struct _nodoArbol *izq;
    struct _nodoArbol *der;
} nodoArbol;

nodoArbol *inicArbol();
nodoArbol *crearNodoArbol(stPersona);
nodoArbol *agregarNodo(nodoArbol *, stPersona);
nodoArbol *agregarNodoPorDni(nodoArbol *, stPersona);
void preOrden(nodoArbol *);
void inOrden(nodoArbol *);
void postOrden(nodoArbol *);
nodoArbol *buscarNodoArbol(nodoArbol *, int);
nodoArbol *buscarNodoArbolPorDni(nodoArbol *, int);
#endif