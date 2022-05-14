#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void generar_lista(Lista *l)
{
    insertar_final(l, 64);
    insertar_final(l, 86);
    insertar_final(l, 66);
    insertar_final(l, 22);
    insertar_final(l, 45);
    insertar_final(l, 67);
    insertar_final(l, 56);
    insertar_final(l, 47);
}

Lista *copiar_inicio(Lista *l, int seccion)
{
    int *pos = (int*)malloc(sizeof(int) * seccion);
    int *pos_f = (int*)malloc(sizeof(int) * seccion);
    int medio = (l -> largo / 2);
    int j = 0;
    for(int i = 0; i < seccion; i++)
    {
        pos[i] = valor_pos(l, i);
        insertar_final(l, pos[i]);
    }
    for(int i = 0; i < seccion; i++)
    {
        pos_f[i] = eliminar_pos(l, (l -> largo) - (2 * seccion) + j);
        insertar_pos(l, medio, pos_f[i]);
        medio++;
        j++;
    }
    return l;
}

int main()
{
    Lista *l = crear_lista();
    int k, seccion;

    printf("Ingrese el numero de particiones: ");
    scanf("%d", &k);
    generar_lista(l);
    seccion = l -> largo / k;
    printf("%i\n", l -> largo);
    printf("Lista Inicial:\n");
    imprimir_lista(l);
    l = copiar_inicio(l, seccion);
    printf("\nLista Final:\n");
    imprimir_lista(l);
    return 0;    
}
