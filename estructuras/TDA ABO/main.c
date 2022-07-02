#include <stdio.h>
#include <stdlib.h>
#include "abo.h"

void nextLine()
{
    printf("\n");
}

void obtenerNiveles(nodo *n, int **lista, int nivel, int *index, int largo)
{
    if (*index < largo)
    {
        if (n != NULL)
        {
            lista[*index][0] = n->val->dato;
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



int main()
{
    arbol *a = crearArbol();
    a->raiz = crearNodo('A');
    insertar(a->raiz, 'A', 'B');
    insertar(a->raiz, 'A', 'C');
    insertar(a->raiz, 'B', 'D');
    insertar(a->raiz, 'B', 'E');
    insertar(a->raiz, 'C', 'F');
    insertar(a->raiz, 'C', 'G');
    preOrden(a->raiz);
    nextLine();
    inOrden(a->raiz);
    nextLine();
    postOrden(a->raiz);
    nextLine();
    printf("%i\n", contarNodos(a->raiz));

    nodo *pad = padre(a->raiz, 'D');
    printf("%c", pad->val->dato);

    return 0;
}