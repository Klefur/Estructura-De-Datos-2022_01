#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "grafo.h"

grafo *crear_grafo(int n){
    grafo *g = malloc(sizeof(grafo*));
    g -> aristas = 0;
    g -> vertices = n;
    g -> v = malloc(sizeof(Lista**) * n);
    for(int i = 0; i < n; i++){
        g -> v[i] = crear_lista();
    }
    return g;
}

void insertar_arista(grafo *g, int ar1, int ar2){
    insertar_final(g -> v[ar1], ar2);
    insertar_final(g -> v[ar2], ar1);
    g -> aristas += 2;
}

void mostrar_grafo(grafo *g){
    printf("Grafo:\n");
    for(int i = 0; i < g -> vertices; i++){
        if(g -> v[i] -> largo != 0){
            printf("%i: ", i);
            for(int j = 0; j < g -> v[i] -> largo; j++){
                printf("%i ", valor_pos(g -> v[i], j));
            }
            printf("\n");
        }
    }
}

void remover_arista(grafo *g, int ar1, int ar2){
    int indice = -1;
    int indice2 = -1;
    if(g -> v[ar1] -> largo != 0){
        for(int j = 0; j < g -> v[ar1] -> largo; j++){
            if(valor_pos(g -> v[ar1], j) == ar2){
                indice = j;
            }
        }
        for(int j = 0; j < g -> v[ar2] -> largo; j++){
            if(valor_pos(g -> v[ar2], j) == ar1){
                indice2 = j;
            }
        }
        if(indice != -1)
        {
            eliminar_pos(g -> v[ar1], indice);
            eliminar_pos(g -> v[ar2], indice2);
            g -> aristas -= 2;
        }
    }
}

int existe_arista(grafo *g, int ar1, int ar2){
    if(g -> v[ar1] -> largo != 0){
        for(int j = 0; j < g -> v[ar1] -> largo; j++){
            if(valor_pos(g -> v[ar1], j) == ar2){
                return 1;
            }
        }
    }
    return 0;
}

int **obtener_aristas(grafo *g){
    int **aristas = malloc(sizeof(int**) * (g -> aristas / 2));
    for(int i = 0; i < g -> aristas / 2; i++){
        aristas[i] = malloc(sizeof(int*) * 2);
        aristas[i][0] = -1;
        aristas[i][1] = -1;
    }
    int x = 0;
    
    for(int i = 0; i < g -> vertices; i++){
        if(g -> v[i] -> largo != 0){
            for(int j = 0; j < g -> v[i] -> largo; j++){
                if(valor_pos(g -> v[i], j) > i){
                    aristas[x][0] = i;       
                    aristas[x][1] = valor_pos(g -> v[i], j);
                    ++x;  
                }
            }
        }       
    }
    return aristas;
}

int obtener_grado_vertice(grafo *g, int vertice){
    int grado = 0;
    if(g -> v[vertice] -> largo != 0){
        for(int j = 0; j < g -> v[vertice] -> largo; j++){
            grado+=1;
        }
    }
    return grado;
}

Lista *obtener_adyacentes_vertice(grafo *g, int vertice){
    Lista *l = crear_lista();
    if(g -> v[vertice] -> largo != 0){
        for(int j = 0; j < g -> v[vertice] -> largo; j++){
            insertar_final(l, valor_pos(g -> v[vertice], j));
        }
    }
    return l;
}

void imprimir_aristas(grafo *g, int **aristas){
    printf("Aristas: ");
    for(int j = 0; j < g -> aristas / 2; j++){
        printf("(%i, %i) ", aristas[j][0], aristas[j][1]);
    }
    printf("\n");
}

void imprimir_vertices(Lista *l, int ar1){
     printf("Vertices Adyacentes a %i: ", ar1);
    for(int j = 0; j < l -> largo; j++){
        printf("%i ", valor_pos(l, j));
    }
    printf("\n");
}