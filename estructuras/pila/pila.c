#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

Pila *crear_pila()
{
    Pila *p;
    p = (Pila*)malloc(sizeof(Pila));
    p -> tope = NULL;
    return p;
}

Nodop *crear_nodo(int valor)
{
    Nodop *n;
    n = (Nodop*)malloc(sizeof(Nodop));
    n -> valor = valor;
    n -> next = NULL;
    return n;
}

int isEmpty(Pila *p)
{
    if(p -> tope == NULL)
    {
        return 1;
    }
    return 0;
}

void push(Pila *p, int valor)
{
    Nodop *n;
    n = crear_nodo(valor);
    if(isEmpty(p) == 1)
    {
        p -> tope = n;
    }
    else
    {
        n -> next = p -> tope;
        p -> tope = n;
    }
}

int pop(Pila *p)
{
    int popeado;
    if(isEmpty(p) == 1)
    {
        printf("Pila vacia\n");
        return 0;
    }
    Nodop *aux;
    aux = p -> tope;
    p -> tope = aux -> next;
    popeado = aux -> valor;
    free(aux);
    return popeado;
}

int tope(Pila *p)
{
    int tope_p;
    tope_p = p -> tope -> valor;
    return tope_p;
}

void destruirPila(Pila *p)
{
    while(p -> tope != NULL)
    {
        pop(p);
    }
    printf("Pila destruida\n");
}
