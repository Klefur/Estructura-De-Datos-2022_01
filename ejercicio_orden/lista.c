#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

Lista *crear_lista()
{
    Lista *l;
    l = (Lista*)malloc(sizeof(Lista));
    l -> inicio = NULL;
    l -> largo = 0;
    return l;
}

Nodol *crear_nodoL(int valor)
{
    Nodol *n;
    n = (Nodol*)malloc(sizeof(Nodol));
    n -> valor = valor;
    n -> next = NULL;
    return n;
}

int isEmptyL(Lista *l)
{
    if(l -> inicio == NULL)
    {
        return 1;
    }
    return 0;
}

void insertar_inicio(Lista *l, int valor)
{
    Nodol *n;
    n = crear_nodoL(valor);
    if(isEmptyL(l) == 1)
    {
        l -> inicio = n;
    }
    else
    {
        n -> next = l -> inicio;
        l -> inicio = n;
    }
    l -> largo += 1;
}

void insertar_final(Lista *l, int valor)
{
    Nodol *n;
    n = crear_nodoL(valor);
    if(isEmptyL(l) == 1)
    {
        l -> inicio = n;
    }
    else
    {
        Nodol *aux = l -> inicio;
        while(aux -> next != NULL)
        {
            aux = aux -> next;
        }
        aux -> next = n;
    }
    l -> largo += 1;
}

void insertar_pos(Lista *l, int pos, int valor)
{
    Nodol *n, *aux1, *aux2;
    n = crear_nodoL(valor);
    if(isEmptyL(l) == 1)
    {
        l -> inicio = n;
        l -> largo += 1;
    }
    else
    {
        
        if(pos > l -> largo)
        {
            printf("Posicion no valida");
        }
        else if(pos == 0)
        {
            insertar_inicio(l, valor);
            l -> largo += 1;
        }
        else
        {
            aux1 = l -> inicio;
            aux2 = l -> inicio -> next;
            for(int i = 1; i < pos; i++)
            {
                aux1 = aux1 -> next;
                aux2 = aux2 -> next;
            }
            aux1 -> next = n;
            n -> next = aux2;
            l -> largo += 1;
        }    
    }
}

int valor_inicial(Lista *l)
{
    int inicial;
    inicial = l -> inicio -> valor;
    return inicial;
}

int valor_final(Lista *l)
{    
    int final;
    Nodol *aux = l -> inicio;
    while(aux -> next != NULL)
    {
        aux = aux -> next;
    }
    final = aux -> valor;
    return final;
}

int valor_pos(Lista *l, int pos)
{
    int posi;
    Nodol *aux;
    if(pos > l -> largo)
    {
        posi = -1;
    }
    else if(pos == 0)
    {
        posi = valor_inicial(l);
    }
    else
    {
        aux = l -> inicio;
        for(int i = 1; i <= pos; i++)
        {
            aux = aux -> next;
        }
        posi = aux -> valor;    
    }
    return posi;
}

int eliminar_inicio(Lista *l)
{
    int inicio;
    if(isEmptyL(l) == 1)
    {
        printf("lista vacia");
        inicio = -1;
        return inicio;
    }
    else
    {
        Nodol *aux = l -> inicio;
        l -> inicio = aux -> next;
        inicio = aux -> valor;
        free(aux);
        return inicio;
    }
}

int eliminar_final(Lista *l)
{
    int final;
    if(isEmptyL(l) == 1)
    {
        printf("lista vacia");
        final = -1;
        return final;
    }
    else
    {
        Nodol *aux1 = l -> inicio;
        Nodol *aux2 = l -> inicio -> next;
        while(aux2 -> next != NULL)
        {
            aux1 = aux1 -> next;
            aux2 = aux2 -> next;
        }
        final = aux2 -> valor;
        aux1 -> next = NULL;
        free(aux2);
        return final;
    }
}

int eliminar_pos(Lista *l, int pos)
{
    int posi;
    Nodol *aux1, *aux2;   
    if(pos > l -> largo || isEmptyL(l) == 1)
    {
        printf("Posicion no valida");
        posi = -1;
        return posi;
    }
    else
    {
        aux1 = l -> inicio;
        aux2 = l -> inicio -> next;
        for(int i = 1; i < pos; i++)
        {
            aux1 = aux1 -> next;
            aux2 = aux2 -> next;
        }
        aux1 -> next = aux2 -> next;
        posi = aux2 -> valor;
        free(aux2);
        l -> largo -= 1;
    }
    return posi;
}

void imprimir_lista(Lista *l)
{
    Nodol *aux = l -> inicio;
    int i = 1;
    if(isEmptyL(l) == 1)
    {
        printf("Lista vacia");
    }
    else
    {
        for(int i = 1; i <= l -> largo; i++)
        {
            printf("%2.d: %d\n", i, aux -> valor);
            aux = aux -> next;
        }
    }
}