#include <stdio.h>
#include <stdlib.h>
#include "ab.h"

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
    insertar(a->raiz, 'E', 'H');
    preOrden(a->raiz);
    nextLine();
    inOrden(a->raiz);
    nextLine();
    postOrden(a->raiz);
    nextLine();
    printf("cantidad de nodos: %i\n", contarNodos(a->raiz));
    printf("cantidad de hojas: %i\n", contarHojas(a->raiz));
    printf("Profundidad: %i\n", profundidadNodo(a->raiz, 'H'));
    printf("Altura: %i\n", alturaNodo(a->raiz, 'A'));
    printf("padre: %c\n", padre(a->raiz, 'F')->val->dato);
    printf("es completo: %i\n", esCompleto(a->raiz));

    return 0;
}