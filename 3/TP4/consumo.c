#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".\Headers\consumo.h"

void mostrarConsumo(stConsumos c)
{
    printf("ID: %d | IdCliente: %d | Anio: %d | Mes:  %d | Dia: %d | Datos consumidos: %d | Baja: %d \n", c.id, c.idCliente, c.anio, c.mes, c.dia, c.datosConsumidos, c.baja);
}

stConsumos consumoRandom()
{

    static int id = 0;

    stConsumos c;
    c.id = id++;

    c.anio = (rand() % 30) + 2000;
    c.datosConsumidos = rand() % 2000;
    c.mes = (rand() % 12) + 1;

    if (c.mes == 2)
    {
        c.dia = (rand() % 28) + 1;
    }
    else if (c.mes == 1 || c.mes == 3 || c.mes == 5 || c.mes == 7 || c.mes == 8 || c.mes == 10 || c.mes == 12)
    {
        c.dia = (rand() % 31) + 1;
    }
    else
    {
        c.dia = (rand() % 30) + 1;
    }

    c.idCliente = rand() % 4;
    c.baja = rand() % 2;

    return c;
}

void guardarDatos(stConsumos cs[], int v)
{
    FILE *a = fopen("./datos.dat", "w+b");
    if (a == NULL)
        return;

    for (int i = 0; i < v; i++)
    {
        fwrite(&cs[i], sizeof(stConsumos), 1, a);
    }

    fclose(a);
}