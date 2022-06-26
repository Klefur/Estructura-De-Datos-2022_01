#include <stdio.h>
#include <stdlib.h>
#include "abo.h"

void nextLine()
{
    printf("\n");
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

    return 0;
}