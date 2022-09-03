#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".\Headers\persona.h"

void mostrarPersona(stPersona p)
{
    printf("%s | %d | %c\n", p.nombre, p.edad, p.genero);
}

stPersona personaRandom()
{

    static int id = 0;

    stPersona p;
    p.id = id++;

    char *nombres[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZ"};

    p.edad = rand() % 100;
    p.genero = (rand() % 2 == 0) ? 'f' : 'm';

    // strcpy(p.nombre, nombres[rand() % 8]);
    strcpy(p.nombre, "Pepe");

    return p;
}