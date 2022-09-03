#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct stPersona
{
    char nombre[30];
    char genero;
    int edad;
} stPersona;

void mostrarPersonas(stPersona ps[], int v);
void mostrarPersona(stPersona p);
void cargarArreglo(stPersona ps[], int v);
int contarGenero(stPersona ps[], int v, char genero);
stPersona *copiarArreglo(stPersona ps[], int v, char genero, int *nuevoValidos);
void ordenarArreglo(stPersona ps[], int v);

/*
a. Crear un arreglo estático de 30 elementos de esta estructura y cargarlo mediante una función.
b. Hacer una función que cuente la cantidad de un género determinado.
c. Hacer una función que copie los datos de todos los registros de un género determinado del arreglo anterior en otro arreglo del tamaño justo. Usar malloc dentro de la función y retornarlo o usar dos parámetros de tipo arreglo y crear el arreglo dinámico antes de la invocación.
*/

int main()
{
    int validos = 10;
    stPersona personas[10];
    srand(time(NULL));

    cargarArreglo(personas, validos);
    mostrarPersonas(personas, validos);
    printf("\nCant genero: %d\n", contarGenero(personas, validos, 'f'));

    int nuevoValidos;
    stPersona *unGenero = copiarArreglo(personas, validos, 'f', &nuevoValidos);

    printf("\n---Despues de copiar---\n");
    mostrarPersonas(unGenero, nuevoValidos);

    printf("\n---Ordenado con seleccion---\n");
    ordenarArreglo(unGenero, nuevoValidos);
    mostrarPersonas(unGenero, nuevoValidos);

    return 0;
}

void ordenarArreglo(stPersona ps[], int v)
{
    stPersona aux;

    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            if (ps[j].edad < ps[i].edad)
            {
                aux = ps[i];
                ps[i] = ps[j];
                ps[j] = aux;
            }
        }
    }
}

int posicionMenor(stPersona ps[], int v, int pos)
{
    int posMenor = pos;

    for (int i = pos + 1; i < v; i++)
    {
        if (ps[posMenor].edad > ps[i].edad)
        {
            posMenor = i;
        }
    }

    return posMenor;
}

stPersona *copiarArreglo(stPersona ps[], int v, char genero, int *nuevoValidos)
{
    *nuevoValidos = contarGenero(ps, v, genero);
    printf("\n----\nNuevo validos: %d", *nuevoValidos);

    stPersona *psNuevo = (stPersona *)malloc(sizeof(stPersona) * (*nuevoValidos));

    int j = 0;

    stPersona p;
    for (int i = 0; i < v; i++)
    {
        if (ps[i].genero == genero)
        {
            p.edad = ps[i].edad;
            p.genero = ps[i].genero;
            strcpy(p.nombre, ps[i].nombre);

            psNuevo[j] = p;

            // psNuevo[j].edad = ps[i].edad;
            // psNuevo[j].genero = ps[i].genero;
            // strcpy(psNuevo[j].nombre, ps[i].nombre);
            j++;
        }
    }

    return psNuevo;
}

int contarGenero(stPersona ps[], int v, char genero)
{
    int resultado = 0;

    for (int i = 0; i < v; i++)
    {
        if (ps[i].genero == genero)
        {
            resultado += 1;
        }
    }

    return resultado;
}

void mostrarPersonas(stPersona ps[], int v)
{
    for (int i = 0; i < v; i++)
    {
        mostrarPersona(ps[i]);
    }
}

void mostrarPersona(stPersona p)
{
    printf("\n--------");
    printf("\nNombre: %s", p.nombre);
    printf("\nEdad: %d", p.edad);
    printf("\nGenero: %c", p.genero);
}

void cargarArreglo(stPersona ps[], int v)
{

    char *nombres[] = {"ABC",
                       "DEF",
                       "GHI", "JKL", "MNO", "PQR", "STU", "VWX", "YZ"};

    for (int i = 0; i < v; i++)
    {
        ps[i].edad = rand() % 100;
        if (rand() % 2 == 0)
        {
            ps[i].genero = 'f';
        }
        else
        {
            ps[i].genero = 'm';
        }

        strcpy(ps[i].nombre, nombres[rand() % 8]);
    }
}