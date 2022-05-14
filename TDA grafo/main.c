#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "grafo.h"

int main(){
    grafo *g = crear_grafo(5);
    int **aristas, grado;
    Lista *l2 = crear_lista();

    insertar_arista(g, 0, 1);
    insertar_arista(g, 0, 2);
    insertar_arista(g, 0, 3);
    insertar_arista(g, 2, 3);
    insertar_arista(g, 1, 3);
    insertar_arista(g, 1, 2);
    insertar_arista(g, 4, 2);
    insertar_arista(g, 4, 0);
    insertar_arista(g, 4, 1);
    mostrar_grafo(g);
    remover_arista(g, 1, 2);
    mostrar_grafo(g);
    
    printf("Existe la arista (%i, %i)?: %i\n", 3, 2, existe_arista(g, 3, 2));
    
    aristas = obtener_aristas(g);
    imprimir_aristas(g, aristas);
    
    l2 = obtener_adyacentes_vertice(g, 3);
    imprimir_vertices(l2, 3);

    return 0;
}