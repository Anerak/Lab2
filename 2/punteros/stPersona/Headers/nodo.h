#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include ".\consumo.h"

typedef struct nodo
{
    struct nodo *siguiente;
    stConsumos dato;
} nodo;

nodo *inicLista();
nodo *crearNodo(stConsumos dato);
nodo *agregarPrincipio(nodo *l, nodo *n);
void mostrarLista(nodo *n);
nodo * final(nodo *l, nodo *n);
nodo *agregarFinal(nodo *l, nodo *n);
nodo *leerDatos(nodo *l);
nodo *buscarUltimo(nodo *l);
int buscarElemento(nodo *l, stConsumos dato);

#endif