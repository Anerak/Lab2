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
void agregarPrincipio(nodo **l, nodo *n);
void mostrarLista(nodo *l);
void agregarFinal(nodo **l, nodo *n);
void leerDatos(nodo **l);
stPersona verPrimero(nodo *p);
nodo *borrarPrimero(nodo *p);

#endif