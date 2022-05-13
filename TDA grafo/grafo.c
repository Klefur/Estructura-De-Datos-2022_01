#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "grafo.h"

grafo *crear_grafo(int n){
    grafo *g = malloc(sizeof(grafo*));
    g -> aristas = 0;
    g -> vertices = 0;
    g -> v = malloc(sizeof(Lista**) * n);
    for(int i = 0; i < n; i++){
        g -> v[i] = crear_lista();
    }
    return g;
}

void insertar_arista(grafo *g, int ar1, int ar2){
    insertar_final(g -> v[ar1], ar2);
    insertar_final(g -> v[ar2], ar1);
}

void mostrar_grafo(grafo *g){
        for(int i = 0; i < g -> vertices; i++){
            if(g -> v[i] -> largo != 0){
                for(int j = 0; j < g -> v[i] -> largo; j++){
                    print("%i ", valor_pos(g -> v[i], j));
                }
                printf("\n");
            }
        }
}

int *remover_arista(grafo *g, int ar1, int ar2){

}

int existe_arista(grafo *g, int ar1, int ar2){

}

Lista *obtener_aristas(grafo *g, int vertice){

}

int obtener_grado_vertice(grafo *g, int vertice){

}

Lista *obtener_adyacentes_vertice(grafo *g, int vertice){

}