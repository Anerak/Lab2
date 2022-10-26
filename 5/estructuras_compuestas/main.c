#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".\Headers\nodo.h"
#define CANT_MATERIAS 20

typedef struct
{
    int nota;
    int legajo;
    char apeNom[40];
    char materia[40];
    int idMateria;
} stRegistroArchivo;

typedef struct
{
    int idMateria;
    char materia[40];
    nodo *listaDeNotas;
} celda;

notaAlumno crearAlumno(int nota, char nombre[], int legajo);
void crearMateria(celda *m, char nombre[], int id);

int pasarDeArchivoToADL(celda arr[], int validos);
void pasarDeADLToArchivoDeAprobados(celda arr[], int v);

int main()
{

    celda arr[CANT_MATERIAS];
    int dim = 0;
    dim = pasarDeArchivoToADL(arr, dim);

    for (int i = 0; i < dim; i++)
    {
        printf("ID: %d | Nombre: %s\n", arr[i].idMateria, arr[i].materia);
        mostrarLista(arr[i].listaDeNotas);
    }

    // pasarDeADLToArchivoDeAprobados(arr, dim);

    system("pause");

    return 0;
}

// Se pide desarrollar un sistema que administre y gestione las notas de la carrera TUP, a partir de un archivo que fue cargado con los datos “mezclados”.

// A fin de realizar esto, codifique las funciones necesarias para administrar la lista y el Arreglo de Listas (similar a las que figuran en el prezi y las que considere necesarias).

// Luego, cargue el archivo utilizando la estructura “registroArchivo” y muéstrelo por pantalla para asegurar la carga de datos.

// Utilizando la información en el archivo, realice las siguientes funciones:

// … pasarDeArchivoToADL(…) ---> esta función recorrerá el archivo y pasará la información al arreglo de listas (utilizando las funciones necesarias que usted ya codificó).

// Desarrolle un main para probar todo el funcionamiento del sistema.

int posMateria(celda arr[], int v, char nombre[])
{
    int res = -1;
    int i = 0;
    while (i < v && res == -1)
    {
        if (strcmp(arr[i].materia, nombre) == 0)
        {
            res = i;
        }
        i++;
    }

    return res;
}

notaAlumno crearAlumno(int nota, char nombre[], int legajo)
{
    notaAlumno a;
    a.nota = nota;
    strcpy(a.nombreApe, nombre);
    a.legajo = legajo;

    return a;
}

void crearMateria(celda *m, char nombre[], int id)
{
    strcpy(m->materia, nombre);
    m->idMateria = id;
    m->listaDeNotas = inicLista();
}

int alta(stRegistroArchivo reg, celda arr[], int v)
{
    if (v == CANT_MATERIAS)
        return v;

    int pos = posMateria(arr, v, reg.materia);
    if (pos == -1)
    {
        pos = v;
        v += 1;
        crearMateria(&arr[pos], reg.materia, reg.idMateria);
    }

    nodo *n = crearNodo(crearAlumno(reg.nota, reg.apeNom, reg.legajo));
    arr[pos].listaDeNotas = agregarFinal(arr[pos].listaDeNotas, n);

    return v;
}

int pasarDeArchivoToADL(celda arr[], int validos)
{
    int v = validos;
    FILE *a = fopen("./aprobados.dat", "r+b");
    if (a)
    {
        stRegistroArchivo aux;
        while (fread(&aux, sizeof(stRegistroArchivo), 1, a) > 0)
        {

            // printf("%d %d %d %s %s\n", aux.idMateria, aux.legajo, aux.nota, aux.apeNom, aux.materia);

            // acá van las funciones que necesitamos codificar.
            v = alta(aux, arr, v);
        }

        fclose(a);
    }

    return v;
}

// … pasarDeADLToArchivoDeAprobados (…) ---> esta función pasará del arreglo de listas a un nuevo archivo las notas mayores o iguales a 6.

void pasarDeADLToArchivoDeAprobados(celda arr[], int v)
{
    FILE *a = fopen("./aprobados.dat", "a+b");
    if (a)
    {
        stRegistroArchivo reg;

        // crear un arreglo de notas por materia
        // para eso, necesitamos saber cuántas notas hay en la lista de la materia.

        for (int i = 0; i < v; i++)
        {
            celda m = arr[i];
            if (m.listaDeNotas)
            {

                nodo *seg = m.listaDeNotas;

                while (seg)
                {
                    if (seg->dato.nota >= 6)
                    {
                        reg.idMateria = m.idMateria;
                        strcpy(reg.materia, m.materia);
                        strcpy(reg.apeNom, seg->dato.nombreApe);
                        reg.legajo = seg->dato.legajo;
                        reg.nota = seg->dato.nota;
                        fwrite(&reg, sizeof(stRegistroArchivo), 1, a);
                    }
                    seg = seg->siguiente;
                }
            }
        }
        fclose(a);
    }
}