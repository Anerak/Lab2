#include ".\Headers\pila.h"

void inicPila(nodo **p)
{
    *p = inicLista(p);
}

int pilaVacia(nodo **p)
{
    int respuesta = 0;
    if (*p == NULL)
    {
        respuesta = 1;
    }

    return respuesta;
}

stPersona tope(nodo **p)
{
    stPersona d = (*p)->dato;

    mostrarPersona(d);

    return d;
}

stPersona desapilar(nodo **p)
{
    stPersona d = (*p)->dato;

    if ((*p)->siguiente != NULL)
    {
        *p = (*p)->siguiente;
    }
    else
    {
        *p = NULL;
    }

    return d;
}

void apilar(nodo **p, stPersona d)
{
    *p = agregarPrincipio(*p, crearNodo(d));
}

void leer(nodo **p)
{
    stPersona d = cargarPersona();
    apilar(p, d);
}

void mostrar(nodo **p)
{
    mostrarLista(*p);
}