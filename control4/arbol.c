#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

arbol *crearArbol()
{
    arbol *ar = malloc(sizeof(arbol));
    ar->raiz = NULL;

    return ar;
}

nodo *crearNodo(int val)
{
    nodo *n = malloc(sizeof(nodo));
    n->valor = val;
    n->izq = NULL;
    n->der = NULL;

    return n;
}

nodo *buscarNodo(nodo *n, int val)
{
    if (n != NULL)
    {
        if (n->valor == val)
            return n;
        else
        {
            nodo *aux = NULL;
            if (n->izq != NULL)
            {
                aux = buscarNodo(n->izq, val);
            }
            if (aux != NULL && aux->valor == val)
            {
                return aux;
            }
            else
            {
                if (n->der != NULL)
                {
                    aux = buscarNodo(n->der, val);
                    if (aux != NULL && aux->valor == val)
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

int contarNodos(nodo *n)
{
    int contar = 0;
    if (n != NULL)
        contar = 1 + contarNodos(n->der) + contarNodos(n->izq);

    return contar;
}

void insertar(nodo *n, int padre, int val)
{
    nodo *aux = buscarNodo(n, padre);
    if (aux == NULL)
        printf("No existe\n");
    else
    {
        if (aux->izq == NULL)
            aux->izq = crearNodo(val);
        else if (aux->der == NULL)
            aux->der = crearNodo(val);
        else
            printf("Los 2 nodos ya existen\n");
    }
}

void preOrden(nodo *n)
{
    if (n != NULL)
    {
        printf("%i ", n->valor);
        preOrden(n->izq);
        preOrden(n->der);
    }
}

void inOrden(nodo *n)
{
    if (n != NULL)
    {
        inOrden(n->izq);
        printf("%i ", n->valor);
        inOrden(n->der);
    }
}

void postOrden(nodo *n)
{
    if (n != NULL)
    {
        postOrden(n->izq);
        postOrden(n->der);
        printf("%i ", n->valor);
    }
}