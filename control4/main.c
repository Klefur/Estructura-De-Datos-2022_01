#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void newLine()
{
    printf("\n");
}

FILE *abrirArchivo(char *nombre, char *modo)
{
    FILE *fp = fopen(nombre, modo);
    if (fp == NULL)
        printf("No existe el archivo\n");
    return fp;
}

arbol *leerArbol(FILE *fp)
{
    int n;
    arbol *ar = crearArbol();
    fscanf(fp, "%i", &n);
    int nodos[n];

    for (int i = 0; i < n; ++i)
    {
        fscanf(fp, "%i", &nodos[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (nodos[i] == -1)
        {
            ar->raiz = crearNodo(i);
        }
        else
        {
            insertar(ar->raiz, nodos[i], i);
        }
    }

    return ar;
}

void obtenerNiveles(nodo *n, int **lista, int nivel, int *index, int largo)
{
    if (*index < largo)
    {
        if (n != NULL)
        {
            lista[*index][0] = n->valor;
            lista[*index][1] = nivel;
            ++*index;
            ++nivel;
            obtenerNiveles(n->izq, lista, nivel, index, largo);
            obtenerNiveles(n->der, lista, nivel, index, largo);
        }
    }
}

void ordenarLista(int **lista, int largo)
{
    int *aux;
    for (int i = 0; i < largo; ++i)
    {
        for (int j = i; j < largo; ++j)
        {
            if (lista[j][1] < lista[i][1])
            {
                aux = lista[j];
                lista[j] = lista[i];
                lista[i] = aux;
            }
        }
    }
}

int **listaProfundidad(nodo *n)
{
    int largo = contarNodos(n);
    int **listado = malloc(sizeof(int *) * largo);
    int index = 0;
    for (int i = 0; i < largo; ++i)
    {
        listado[i] = malloc(sizeof(int) * 2);
    }

    obtenerNiveles(n, listado, 0, &index, largo);
    ordenarLista(listado, largo);

    return listado;
}

void ordenNivel(nodo *n)
{
    int largo = contarNodos(n);
    int **listado = malloc(sizeof(int *) * largo);
    int index = 0;
    for (int i = 0; i < largo; ++i)
    {
        listado[i] = malloc(sizeof(int) * 2);
    }

    obtenerNiveles(n, listado, 0, &index, largo);
    ordenarLista(listado, largo);

    for (int i = 0; i <= listado[largo - 1][1]; ++i)
    {
        printf("Nivel %i: ", i);
        for (int j = 0; j < largo; ++j)
        {
            if (i == listado[j][1])
                printf("%i ", j);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    FILE *fp = abrirArchivo(argv[2], "r");

    if (fp == NULL)
        return 0;

    arbol *ar = leerArbol(fp);

    int largo = contarNodos(ar->raiz);

    int **listado = listaProfundidad(ar->raiz);

    for (int i = 0; i < largo; ++i)
    {
        printf("Profundidad del nodo %i: %i\n", listado[i][0], listado[i][1]);
    }

    printf("Recorrido preorden: ");
    preOrden(ar->raiz);
    newLine();
    printf("Recorrido inorden: ");
    inOrden(ar->raiz);
    newLine();
    printf("Recorrido postorden: ");
    postOrden(ar->raiz);
    newLine();

    ordenNivel(ar->raiz);

    return 0;
}
