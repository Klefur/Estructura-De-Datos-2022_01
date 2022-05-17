#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "grafo.h"

int main(){
    grafo *g = crear_grafo(4);
    int **aristas, grado, *grados, *grados_max;
    Lista *l2 = crear_lista();
    int grafo_tour, grafo_clique, simple;
    int arr[] = {0, 1, 2};

    insertar_arista(g, 0, 1);
    insertar_arista(g, 0, 2);
    insertar_arista(g, 0, 3);
    insertar_arista(g, 1, 2);
    insertar_arista(g, 1, 3);
    insertar_arista(g, 2, 3);
    mostrar_grafo(g);
    remover_arista(g, 1, 2);
    mostrar_grafo(g);
    
    l2 = obtener_adyacentes_vertice(g, 0);
    imprimir_vertices(l2, 0);
    
    printf("Existe la arista (%i, %i)?: %i\n", 3, 2, existe_arista(g, 3, 2));
    
    aristas = obtener_aristas(g);
    imprimir_aristas(g, aristas);
    
    printf("El grafo es %i regular?: %i\n", 2, k_regular(g, 2));
    printf("El grafo es %i regular?: %i\n", 3, k_regular(g, 3));
    
    grados = grado_vertices(g);
    printf("Grado de los vertices:\n");    
    for(int i = 0; i < g -> vertices; ++i){
        printf("Grado de %i: %i\n", i, grados[i]);
    }

    grados_max = grados_extremos(g);
    printf("Grados extremos: menor: %i, mayor: %i", grados_max[0], grados_max[1]);
    printf("\n");

    grafo_tour = tour(g, arr, 3);
    printf("El arreglo {%i, %i, %i} es tour?: %i\n", 0, 1, 2, grafo_tour);
    
    grafo_clique = clique(g, arr, 3);
    printf("El arreglo {%i, %i, %i} es clique?: %i\n", 0, 1, 2, grafo_clique);
    
    simple = grafo_simple(g);
    printf("El grafo es simple?: %i\n", simple);
    
    complemento(g);

    return 0;
}