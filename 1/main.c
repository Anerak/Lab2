#include <stdio.h>
#include <stdlib.h>
#include "./Headers/pilaEmpleados.h"

void mostrarPila(PilaEmpleados *);
void cargarMultiplesEmpleados(PilaEmpleados *);
void guardarPila(PilaEmpleados *, char[]);

int main()
{
    PilaEmpleados p;
    inicPilaEmpleados(&p);
    char archivo[] = "pila.bin";

    cargarMultiplesEmpleados(&p);
    mostrarPila(&p);
    guardarPila(&p, archivo);
    return 0;
}

void guardarPila(PilaEmpleados *p, char nombre[])
{
    FILE *fp;
    PilaEmpleados a;
    fp = fopen(nombre, "w+b");
    if (fp != NULL)
    {
        fwrite(&p, sizeof(a), 1, fp);

        fclose(fp);
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }
}