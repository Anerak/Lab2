#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include ".\nodo.h"

void inicPila(nodo **p);
int pilaVacia(nodo **p);
stPersona tope(nodo **p);
stPersona desapilar(nodo **p);
void apilar(nodo **p, stPersona d);
void leer(nodo **p);
void mostrar(nodo **p);

#endif