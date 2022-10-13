#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include ".\Headers\arbol.h"
#include ".\Headers\nodo.h"

nodo *treeToList(nodoArbol *, nodo *);

void pasarListaInOrden(nodoArbol *t, nodo **l);
int main()
{

    srand(time(NULL));
    nodoArbol *tree = inicArbol();

    tree = agregarNodoPorDni(tree, personaRandom());
    tree = agregarNodoPorDni(tree, personaRandom());
    tree = agregarNodoPorDni(tree, personaRandom());
    tree = agregarNodoPorDni(tree, personaRandom());
    tree = agregarNodoPorDni(tree, personaRandom());

    printf("ESTE ES EL ARBOLITO DE LA SUERTE\n");
    inOrden(tree);

    // printf("ESTA ES LA LISTA DE GATITOS\n");
    // nodo *l = inicLista();
    // pasarListaInOrden(tree, &l);

    // mostrarLista(l);

    int d = 0;
    printf("DNI: ");
    fflush(stdin);
    scanf("%d", &d);

    mostrarPersona(buscarNodoArbolPorDni(tree, d)->dato);

    return 0;
}

void pasarListaInOrden(nodoArbol *t, nodo **l)
{
    if (t)
    {
        pasarListaInOrden(t->izq, l);
        *l = agregarFinal(*l, crearNodo(t->dato));
        pasarListaInOrden(t->der, l);
    }
}