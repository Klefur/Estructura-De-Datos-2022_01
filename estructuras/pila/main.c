#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    Pila *p;

    p = crear_pila();
    printf("%d\n", isEmpty(p));
    push(p, 10);
    push(p, 4);
    push(p, 143);
    printf("%d\n", isEmpty(p));
    push(p, 6);
    printf("El tope de la pila es: %d\n", tope(p));
    printf("El elemento popeado es: %d\n", pop(p));\
    destruirPila(p);
    printf("%d\n", isEmpty(p));

    return 0;
}