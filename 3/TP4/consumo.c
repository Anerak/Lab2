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
    c.dia = (rand() % 31) + 1;
    c.mes = (rand() % 12) + 1;
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