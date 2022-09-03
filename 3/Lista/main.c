#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include ".\Headers\nodo.h"
#include <string.h>

int main()
{

    srand(time(NULL));
    nodo *lista;
    lista = inicLista();
    lista = agregarPrincipio(lista, crearNodo(personaRandom()));
    lista = agregarPrincipio(lista, crearNodo(personaRandom()));
    lista = agregarPrincipio(lista, crearNodo(personaRandom()));

    // mostrarLista(lista);
    stPersona p;
    p.edad = 22;
    p.genero = 'f';
    strcpy(p.nombre, "Test");

    lista = final(lista, crearNodo(p));
    // lista = agregarFinal(lista, crearNodo(p));
    mostrarLista(lista);

    return 0;
}
