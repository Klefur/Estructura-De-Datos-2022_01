#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

int main()
{
    Cola *c;
    c = crear_cola();
    printf("%d\n", isEmpty(c));
    encolar(c, 3);
    encolar(c, 6);
    encolar(c, 9);
    encolar(c, 10);
    printf("%d\n", isEmpty(c));
    printf("%d\n", primero(c));
    desencolar(c);
    printf("%d\n", primero(c));
    destruirCola(c);

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