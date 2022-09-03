#include <stdio.h>
#include <stdlib.h>
#include "pilaEmpleados.h"

void inicPilaEmpleados(PilaEmpleados *p)
{
    p->dim = 50;
    p->v = 0;
    p->e = (stEmpleado *)malloc(sizeof(stEmpleado) * p->dim);
}

void apilarEmpleados(PilaEmpleados *p, stEmpleado e)
{
    if (p->v == p->dim)
    {
        p->dim += 50; /// p->dim = p->dim +50
        p->e = (stEmpleado *)realloc(p->e, sizeof(stEmpleado) * p->dim);
    }
    p->e[p->v] = e;
    p->v++; // p->=p->+1
}

stEmpleado desapilarEmpleados(PilaEmpleados *p)
{
    stEmpleado empleado = p->e[p->v - 1];
    p->v--;
    return empleado;
}

stEmpleado topeEmpleados(PilaEmpleados *p)
{
    return p->e[p->v - 1];
}

int pilavaciaEmpleados(PilaEmpleados *p)
{
    return (p->v == 0) ? 1 : 0;
}

void cargarMultiplesEmpleados(PilaEmpleados *p)
{
    char continuar = 'n';

    do
    {
        apilarEmpleados(p, cargarUnEmpleado());
        fflush(stdin);
        printf("Desea cargar otro empleado?\n");
        scanf("%c", &continuar);
        fflush(stdin);
    } while (continuar == 's');
}

void mostrarPila(PilaEmpleados *p)
{
    PilaEmpleados aux;
    inicPilaEmpleados(&aux);

    while (!pilavaciaEmpleados(p))
    {
        muestraUnEmpleado(topeEmpleados(p));
        apilarEmpleados(&aux, desapilarEmpleados(p));
    }

    while (!pilavaciaEmpleados(&aux))
    {
        apilarEmpleados(p, desapilarEmpleados(&aux));
    }
}