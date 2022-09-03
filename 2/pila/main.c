#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pila
{
    int v;
    int *valores;
    int posTope; // posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;

void inicPila(Pila *p);
void apilar(Pila *p, int valor);
int desapilar(Pila *p);
int tope(Pila *p);
int pilavacia(Pila *p);
void mostrar(Pila *p);
void leer(Pila *p);
void relleno(Pila *p, int amount);
int buscarMenorPila(Pila *p);
void ordenarPila(Pila *);

void inicPila(Pila *p)
{
    p->valores = (int *)malloc(sizeof(int) * 100);
    p->v = 0;
}

void apilar(Pila *p, int valor)
{
    p->valores[p->v] = valor;
    p->posTope = p->v;
    p->v++;
}

int desapilar(Pila *p)
{
    p->posTope = p->v - 1;
    return p->valores[p->v--];
}

int tope(Pila *p)
{
    return p->valores[p->posTope];
}

int pilavacia(Pila *p)
{
    return p->v <= 0;
}

void mostrar(Pila *p)
{
    printf("\n- - - - - - - - - - - - -\n");
    for (int i = 0; i < p->v; i++)
    {
        printf("| %d ", p->valores[i]);
    }
    printf("\n- - - - - - - - - - - - -\n");
}

void leer(Pila *p)
{
    int x = 0;
    scanf("%d", &x);
    apilar(p, x);
}

void relleno(Pila *p, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        apilar(p, rand() % 1000);
    }
}

int main()
{
    srand(time(NULL));

    Pila a, b;
    inicPila(&a);
    relleno(&a, 5);
    inicPila(&b);
    relleno(&b, 5);

    printf("\nMenor A: %d\n", buscarMenorPila(&a));
    mostrar(&a);
    // ordenarPila(&a);
    // mostrar(&a);

    return 0;
}

int buscarMenorPila(Pila *p)
{
    if (pilavacia(p))
    {
        return 0;
    }

    int menor;

    Pila aux;
    inicPila(&aux);

    mostrar(p);

    while (!pilavacia(p))
    {
        if (pilavacia(&aux))
        {
            printf("AUX vacio\n");
            menor = tope(p);
        }

        if (tope(p) < menor)
        {
            menor = tope(p);
        }

        apilar(&aux, desapilar(p));
    }

    while (!pilavacia(&aux))
    {
        apilar(p, desapilar(&aux));
    }

    return menor;
}

void ordenarPila(Pila *p)
{
    if (pilavacia(p))
        return;

    Pila aux, tmp;
    inicPila(&aux);
    inicPila(&tmp);

    int menor;

    while (!pilavacia(p))
    {
        menor = buscarMenorPila(p);
        while (!(tope(p) == menor))
        {
            apilar(&aux, desapilar(p));
        }
        apilar(&tmp, desapilar(&aux));
        while (!pilavacia(&aux))
        {
            apilar(p, desapilar(&aux));
        }
    }

    printf("\n- - - - - TMP - - - - -\n");
    mostrar(&tmp);

    // while (!pilavacia(p))
    // {
    //     menor = buscarMenorPila(p);
    //     while (tope(p) != menor)
    //     {
    //         printf("%d == %d\n", menor, tope(p));
    //         apilar(&aux, desapilar(p));
    //     }
    //     apilar(&tmp, desapilar(p));

    //     printf("\nAUX\n");
    //     mostrar(&aux);
    //     while (!pilavacia(&aux))
    //     {
    //         apilar(p, desapilar(&aux));
    //     }
    // }

    while (!pilavacia(&tmp))
    {
        apilar(p, desapilar(&tmp));
    }
}

Pila *unirPilas(Pila *a, Pila *b)
{
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    inicPila(pila);
}

/*

4. Dadas dos pilas (como las anteriores) que se supone que tienen sus datos ordenados, generar una tercer pila que
contenga los datos de las dos anteriores intercalados, de forma tal que queden ordenados.

5. Función insertar orden en un arreglo.

6. Algoritmo de ordenamiento por inserción.

7. Función eliminar un elemento de un arreglo. (ver por desplazamiento si es ordenado)
*/

/*8. Sistema de notas. Se tiene que administrar un sistema para un curso con 20 alumnos que cursan 5 materias
diferentes. Se deben almacenar los datos de los alumnos y las notas que obtuvieron en el examen final de cada materia.
Para ello se utilizarán las siguientes estructuras:

typedef struct {
  int matricula;
  char nombre[30];
} Alumno;
typedef struct {
  int codigo;
  char nombreMat[20];
} Materia ;
typedef struct {
  int matricula;
  int codigo;
  int nota;
} Nota;

Y las siguientes variables:
Alumno alus[20]; // para almacenar los datos de los 20 alumnos.
Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias.
Nota notas[100]; // para almacenar todas las notas de los alumnos.

Las notas se almacenan en forma desordenada para todos los alumnos.
Se deben hacer las siguientes funciones:
1. Cargar el arreglo de Materia
2. Agregar un Alumno
3. Agregar una Nota, validando que exista “matrícula” y “código”. La función debe retornar 1 si la operación fue exitosa y 0 (cero) en caso contrario.
4. Hacer una función que muestre por pantalla el nombre del alumno y la lista de materias con sus
respectivas notas. La función debe recibir como parámetro el nombre del alumno. Estrategia: con el
nombre del alumno se busca su matrícula en el arreglo alus, luego se recorre el arreglo notas filtrandolo
por matrícula, y con el código se accede al nombre de la materia revisando el arreglo mats.

*/