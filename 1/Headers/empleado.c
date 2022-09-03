#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

// stEmpleado cargarUnEmpleado()
// {
//     stEmpleado e;

//     e.id = idEmpleado();
//     strcpy(e.nombre, "Pepe");
//     strcpy(e.apellido, "Argento");
//     e.edad = 45;

//     return e;
// }

stEmpleado cargarUnEmpleado()
{
    stEmpleado e;

    e.id = idEmpleado();

    printf("Nombre: ");
    gets(e.nombre);
    fflush(stdin);
    printf("Apellido: ");
    gets(e.apellido);
    fflush(stdin);

    printf("Edad: ");
    scanf("%d", &e.edad);

    return e;
}

int idEmpleado()
{
    static int id = 0;
    id++;

    return id;
}

void muestraUnEmpleado(stEmpleado e)
{
    printf("\n ID....................: %d", e.id);
    printf("\n Nombre................: %s", e.nombre);
    printf("\n Apellido..............: %s", e.apellido);
    printf("\n Edad..................: %d", e.edad);
    printf("\n____________________________________________________");
}