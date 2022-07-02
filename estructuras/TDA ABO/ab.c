#include <stdio.h>
#include <stdlib.h>
#include "abo.h"

arbol *crearArbol()
{
    arbol *a = malloc(sizeof(arbol));
    a->raiz = NULL;

    return a;
}

nodo *crearNodo(char val)
{
    nodo *n = malloc(sizeof(nodo));
    n->val = crearInfo(val);
    n->izq = NULL;
    n->der = NULL;

    return n;
}

info *crearInfo(char val)
{
    info *Info = malloc(sizeof(info));
    Info->dato = val;

    return Info;
}

void insertar(nodo *n, char padre, char val)
{
    nodo *pad = buscarNodo(n, padre);
    if (pad == NULL)
        printf("No existe\n");
    else
    {
        if (pad->izq == NULL)
            pad->izq = crearNodo(val);
        else if (pad->der == NULL)
            pad->der = crearNodo(val);
        else
            printf("Los 2 nodos ya existen\n");
    }
}

nodo *buscarNodo(nodo *n, char val)
{
    if (n != NULL)
    {
        if (n->val->dato == val)
            return n;
        else
        {
            nodo *aux = NULL;
            if (n->izq != NULL)
            {
                aux = buscarNodo(n->izq, val);
            }
            if (aux != NULL && aux->val->dato == val)
            {
                return aux;
            }
            else
            {
                if (n->der != NULL)
                {
                    aux = buscarNodo(n->der, val);
                    if (aux != NULL && aux->val->dato == val)
                    {
                        return aux;
                    }
                }
            }

            return aux;
        }
    }
    else
        return NULL;
}

void preOrden(nodo *n)
{
    if (n != NULL)
    {
        printf("%c", n->val->dato);
        preOrden(n->izq);
        preOrden(n->der);
    }
}

void inOrden(nodo *n)
{
    if (n != NULL)
    {
        inOrden(n->izq);
        printf("%c", n->val->dato);
        inOrden(n->der);
    }
}

void postOrden(nodo *n)
{
    if (n != NULL)
    {
        postOrden(n->izq);
        postOrden(n->der);
        printf("%c", n->val->dato);
    }
}

nodo *padre(nodo *n, char val)
{
    if (n != NULL)
    {
        if ((n->der != NULL && n->der->val->dato == val) || (n->izq != NULL && n->izq->val->dato == val))
            return n;
        else
        {
            nodo *aux = NULL;
            if (n->izq != NULL)
            {
                aux = padre(n->izq, val);
            }
            if(aux != NULL){
                if ((aux->der != NULL && aux->der->val->dato == val) || (aux->izq != NULL && aux->izq->val->dato == val))
                {
                    return aux;
                }
            }
            else
            {
                if (n->der != NULL)
                {
                    aux = padre(n->der, val);
                    if (aux != NULL)
                    {
                        if ((aux->der != NULL && aux->der->val->dato == val) || (aux->izq != NULL && aux->izq->val->dato == val))
                        {
                            return aux;
                        }
                    }
                }
            }

            return aux;
        }
    }
    else
        return NULL;
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

int profundidadNodo(nodo *n, char val)
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

    for (int i = 0; i < largo; ++i)
    {
        if (val == (char)listado[i][0])
        {
            return listado[i][1];
        }
    }
}

int alturaNodo(nodo *n, char val)
{
    nodo *aux = buscarNodo(n, val);
    int largo = contarNodos(aux);
    int **listado = malloc(sizeof(int *) * largo);
    int index = 0;
    for (int i = 0; i < largo; ++i)
    {
        listado[i] = malloc(sizeof(int) * 2);
    }

    obtenerNiveles(aux, listado, 0, &index, largo);
    ordenarLista(listado, largo);

    return listado[largo-1][1];
}

int nivelNodo(nodo *n, char val)
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

    for (int i = 0; i < largo; ++i)
    {
        if (val == (char)listado[i][0])
        {
            if (buscarNodo(n, (char)listado[i][0])->izq == NULL && buscarNodo(n, (char)listado[i][0])->der == NULL)
                return 0;
            return listado[i][1];
        }
    }
}

int contarNodos(nodo *n)
{
    int contar = 0;
    if (n != NULL)
        contar = 1 + contarNodos(n->der) + contarNodos(n->izq);

    return contar;
}

int contarHojas(nodo *n)
{
    int contar = 0;
    if (n != NULL)
    {
        if (n->der == NULL && n->izq == NULL)
            ++contar;
        else
        {
            contar = contarHojas(n->izq) + contarHojas(n->der);
        }
    }

    return contar;
}

int sonSimilares(nodo *n1, nodo *n2)
{
}

int esCompleto(nodo *n)
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

    for (int i = 0; i < listado[largo - 1][1]; ++i)
    {
    }
}