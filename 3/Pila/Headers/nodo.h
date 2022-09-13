#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include ".\persona.h"

typedef struct nodo
{
    struct nodo *siguiente;
    stPersona dato;
} nodo;

nodo *inicLista();
nodo *crearNodo(stPersona dato);
nodo *agregarPrincipio(nodo *l, nodo *n);
void mostrarLista(nodo *l);
nodo * final(nodo *l, nodo *n);
nodo *agregarFinal(nodo *l, nodo *n);
nodo *leerDatos(nodo *l);

#endif