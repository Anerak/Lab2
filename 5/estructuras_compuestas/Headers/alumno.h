#include <stdio.h>
#include <stdlib.h>

#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
} notaAlumno;

void mostrarNotaAlumno(notaAlumno a);

#endif