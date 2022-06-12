#include "cola.h"
#include <stdlib.h>
#include <stdio.h>

Cola *crear_cola()
{
    Cola *c;
    c = (Cola*)malloc(sizeof(Cola));
    c -> tope = NULL;
    c -> fin = NULL;
    return c;
}

Nodoc *crear_nodo(int valor)
{
    Nodoc *n;
    n = (Nodoc*)malloc(sizeof(Nodoc));
    n -> valor = valor;
    n -> next = NULL;
    return n;
}

int isEmpty(Cola *c)
{
    if(c -> tope == NULL)
    {
        return 1;
    }
    return 0;
}

void encolar(Cola *c, int valor)
{
    Nodoc *n;
    n = crear_nodo(valor);
    if(isEmpty(c) == 1)
    {
        c -> tope = n;
        c -> fin = n;
    }
    else
    {
        c -> fin -> next = n;
        c -> fin = n;
    }
}

void desencolar(Cola *c)
{
    if(isEmpty(c) == 1)
    {
        printf("Cola vacia\n");
        return;
    }
    Nodoc *aux;
    aux = c -> tope;
    c -> tope = aux -> next;
    free(aux);
}

int primero(Cola *c)
{
    int first;
    first = c -> tope -> valor;
    return first;
}

void destruirCola(Cola *c)
{
    while(c -> tope != NULL)
    {
        desencolar(c);
    }
    printf("Cola destruida\n");
}