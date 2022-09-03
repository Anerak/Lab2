#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char NOMBRE_ARCHIVO[11] = "numeros.dat";

int factorial(int);
int potencia(int, int);
void mostrarArreglo(int *, int, int);
void mostrarArregloInverso(int arr[], int validos, int pos);
int arregloCapicua(int arr[], int validos, int pos);
int sumaArreglo(int arr[], int val, int pos);
int buscarMenor(int arr[], int val, int pos);
void escribirNumerosEnArchivo();
int buscarMenorArchivo(int pos);
void invertirArchivo(int pos);
void mostrarArchivoInverso(int pos);
void charInverso();
int buscarArray(int[], int, int, int);
int main()
{

    // int foo[30] = {8, 3, 5, 7};
    int foo[30] = {4, 50, 200, 556};

    printf("%d", buscarArray(foo, 4, 0, 556));
    return 0;
}

int factorial(int x)
{
    int rta;

    if (x == 0)
        rta = 1;
    else
        rta = x * factorial(x - 1);

    return rta;
}

// 2. Calcular la potencia de un número en forma recursiva.

int potencia(int x, int y)
{
    int rta;
    if (y == 0)
        rta = 1;
    else
    {
        rta = x * potencia(x, y - 1);
    }
    return rta;
}

// 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void mostrarArreglo(int arr[], int validos, int pos)
{
    if (pos < validos)
    {
        printf("%d\n", arr[pos]);
        mostrarArreglo(arr, validos, pos + 1);
    }
}

// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).
void mostrarArregloInverso(int arr[], int validos, int pos)
{
    if (pos < validos)
    {
        mostrarArregloInverso(arr, validos, pos + 1);
        printf("%d\n", arr[pos]);
    }
}

// 5. Determinar en forma recursiva si un arreglo es capicúa.

int arregloCapicua(int arr[], int validos, int pos)
{
    int rta = 1;
    if (arr[validos - 1] != arr[pos])
    {
        rta = 0;
    }
    else if (arr[validos - 1] == arr[pos] && validos > pos)
    {
        validos--;
        pos++;
        rta = arregloCapicua(arr, validos, pos);
    }

    return rta;
}

// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

int sumaArreglo(int arr[], int val, int pos)
{
    int rta = 0;

    if (val > pos)
    {
        rta = arr[pos] + sumaArreglo(arr, val, pos + 1);
    }

    return rta;
}

// 7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscarMenor(int arr[], int val, int pos)
{
    int menor = arr[pos];
    int aux;

    if (pos < val - 1)
    {
        aux = buscarMenor(arr, val, pos + 1);

        if (aux < menor)
        {
            menor = aux;
        }
    }

    return menor;
}

// 8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)

void escribirNumerosEnArchivo()
{
    FILE *a = fopen("numeros.dat", "a+b");
    int b[] = {1, 9, 5, 6, 3};
    int i = 0;
    if (a != NULL)
    {
        while (i < 5)
        {
            fwrite(&b[i], sizeof(int), 1, a);
            i++;
        }
        fclose(a);
    }
}

// abrimos archivo, copiamos el valor
// cerramos archivo, llamamos a la función de nuevo
// {1, 9, 5, 6, 3};
int buscarMenorArchivo(int pos)
{
    int menor;
    int aux;
    FILE *a = fopen("numeros.dat", "rb");
    if (a != NULL)
    {
        fseek(a, sizeof(int), SEEK_END);
        int finArchivo = ftell(a) / sizeof(int);

        if (pos < (finArchivo - 1))
        {
            printf("Pos: %d\n", pos);
            fseek(a, sizeof(int) * pos, SEEK_SET);
            fread(&menor, sizeof(int), 1, a);
            fclose(a);
            printf("Numero: %d\n", menor);
            aux = buscarMenorArchivo(pos + 1);
        }
    }

    if (aux < menor)
    {
        menor = aux;
    }

    return menor;
}

// 9. Invertir los elementos de un archivo de números enteros de forma recursiva.  (si no te sale, primero proba con invertir los elementos de un arreglo de int)

void invertirArchivo(int pos)
{
    int num1, num2;
    FILE *a = fopen("numeros.dat", "r+b");
    if (a != NULL)
    {
        fseek(a, sizeof(int), SEEK_END);
        int cantItems = (ftell(a) / sizeof(int)) - 1;
        int posFinal = pos + 1;
        if (pos < (cantItems / 2))
        {

            // Lectura

            fseek(a, sizeof(int) * pos, SEEK_SET);
            fread(&num1, sizeof(int), 1, a);

            fseek(a, sizeof(int) * (posFinal * (-1)), SEEK_END);
            fread(&num2, sizeof(int), 1, a);

            // Escritura

            fseek(a, sizeof(int) * pos, SEEK_SET);
            fwrite(&num2, sizeof(int), 1, a);

            fseek(a, sizeof(int) * (posFinal * (-1)), SEEK_END);
            fwrite(&num1, sizeof(int), 1, a);

            fclose(a);

            invertirArchivo(pos + 1);
            // {1, 9, 5, 6, 3};
        }
    }
}

// 10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.

void mostrarArchivoInverso(int pos)
{
    int num;
    FILE *a = fopen("numeros.dat", "rb");
    if (a != NULL)
    {
        fseek(a, sizeof(int), SEEK_END);
        int finArchivo = ftell(a) / sizeof(int);

        if (pos < (finArchivo - 1))
        {
            fseek(a, sizeof(int) * pos, SEEK_SET);
            fread(&num, sizeof(int), 1, a);
            fclose(a);
            mostrarArchivoInverso(pos + 1);
            printf("Numero: %d | Posicion: %d\n", num, pos);
            // {1, 9, 5, 6, 3};
        }
    }
}

// 11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.

void charInverso()
{
    char c;
    fflush(stdin);
    scanf("%c", &c);

    if (c != '*')
    {
        charInverso();
        printf("%c", c);
    }
}

// 12. Determinar si un arreglo contiene un determinado elemento de forma recursiva. (Pueden intentarlo también con una función void)
int buscarArray(int arreglo[], int validos, int pos, int elem)
{
    int rta = 0;

    if (pos < validos)
    {
        if (arreglo[pos] == elem)
        {
            rta = 1;
        }
        else
        {
            pos++;
            rta = buscarArray(arreglo, validos, pos, elem);
        }
    }
    return rta;
}