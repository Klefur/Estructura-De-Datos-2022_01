#include <stdio.h>
#include <stdlib.h>
#include "abo.h"

nodo *crearNodo()
{
    nodo *n = malloc(sizeof(nodo *));
    n->der = NULL;
    n->val = NULL;
    n->izq = NULL;

    return n;
}

info *crearInfo(int val)
{
    info *pval = malloc(sizeof(info *));
    pval->pval = val;

    return pval;
}

void insertar(nodo *n, int val)
{
    if(n == NULL)
    {
        n = crearNodo();
    }
    if(n->val = NULL){
        n->val = crearInfo(val);
    }
    else{
        if(n->val->pval > val){
            insertar(n->izq, val);
        }
        else{
            insertar(n->der, val);
        }
    }
}

nodo buscarNodo(nodo *n, int val)
{
}

void inorder(nodo *n)
{
}

void preorder(nodo *n)
{
}

void postorder(nodo *n)
{
}

nodo *buscarMaxEnMin(nodo *n)
{
}

nodo *buscarMinEnMax(nodo *n)
{
}

nodo *eliminar(nodo *n, int val)
{
}

nodo *eliminarArbol(nodo *n)
{
}
