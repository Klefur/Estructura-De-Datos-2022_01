#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{
    Lista *l;

    l = crear_lista();
    insertar_inicio(l, 10);
    insertar_final(l, 30);
    insertar_pos(l, 1, 50);
    insertar_pos(l, 2, 40);
    printf("El valor inicial es: %d\n", valor_inicial(l));
    printf("El valor final es: %d\n", valor_final(l));
    printf("El valor numero %d es: %d\n", 1, valor_pos(l, 1));
    return 0;
}