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
    if(existe_arista(g, ar1, ar2) == 0){
        insertar_final(g -> v[ar1], ar2);
        insertar_final(g -> v[ar2], ar1);
        g -> aristas += 2;
    }
    else{
        printf("arista ya agregada\n");
    }
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
    int indice1 = -1;
    int indice2 = -1;
    if(g -> v[ar1] -> largo != 0){
        for(int j = 0; j < g -> v[ar1] -> largo; j++){
            if(valor_pos(g -> v[ar1], j) == ar2){
                indice1 = j;
            }
        }
        for(int i = 0; i < g -> v[ar2] -> largo; i++){
            if(valor_pos(g -> v[ar2], i) == ar1){
                indice2 = i;
            }
        }
        if(indice1 != -1 && indice2 != -1){
            printf("Arista (%i, %i), (%i, %i) eliminada\n", ar1, ar2, ar2, ar1);
            eliminar_pos(g -> v[ar1], indice1);
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
    int **aristas = malloc(sizeof(int**) * g -> aristas);
    for(int i = 0; i < g -> aristas; i++){
        aristas[i] = malloc(sizeof(int*) * 2);
        aristas[i][0] = -1;
        aristas[i][1] = -1;
    }
    int x = 0;
    
    for(int i = 0; i < g -> vertices; i++){
        if(g -> v[i] -> largo != 0){
            for(int j = 0; j < g -> v[i] -> largo; j++){
                aristas[x][0] = i;       
                aristas[x][1] = valor_pos(g -> v[i], j);
                ++x;  
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

int k_regular(grafo *g, int k){
    int *grad_vertices = grado_vertices(g);
    for(int i = 1; i < g -> vertices; ++i){
        if(grad_vertices[i] != k){
            return 0;
        }
    }
    return 1;
}

int *grado_vertices(grafo *g){
    int *grd_vertices = malloc(sizeof(int*) * g -> vertices);

    for(int i = 0; i < g -> vertices; ++i){
        grd_vertices[i] = obtener_grado_vertice(g, i);
    }

    return grd_vertices;
}

int *grados_extremos(grafo *g){
    int *grados_extr = malloc(sizeof(int*) * 2);
    int aux1, aux2, *grad_vertices;

    grad_vertices = grado_vertices(g);
    aux1 = grad_vertices[0], aux2 = grad_vertices[0];
    for(int i = 1; i < g -> vertices; ++i){
        if(aux1 > grad_vertices[i]){
            aux1 = grad_vertices[i];
        }
        if(aux2 < grad_vertices[i]){
            aux2 = grad_vertices[i];
        }
    }
    grados_extr[0] = aux1, grados_extr[1] = aux2;

    return grados_extr;
}

int grafo_simple(grafo *g){
    int contador;
    Lista *adj;
    for(int i = 0; i < g -> vertices; ++i){
        adj = obtener_adyacentes_vertice(g, i);
        for(int j = 0; j < adj -> largo; ++j){
            contador = 0;
            for(int k = 0; k < adj -> largo; ++k){
                if(valor_pos(adj, j) == valor_pos(adj, k)){
                    ++contador;
                }
            }
            if(contador > 1){
                printf("%i \n", contador);
                return 0;
            }
        }
    }
    return 1;
}


int clique(grafo *g, int *vertices, int largo){
    Lista *adj;
    if(largo > 2 && largo < g -> vertices){
        for (int i = 0; i < largo; ++i){
            for(int j = 1; j < largo; ++j){
                if(existe_arista(g, vertices[i], vertices[j]) == 0 && j != i){
                    return 0;
                }
            }            
        }
        if(existe_arista(g, vertices[0], vertices[largo - 1]) == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

int tour(grafo *g, int *vertices, int largo){
    if(largo < g -> vertices){
        for(int i = 0; i < largo - 1; ++i){
                if(existe_arista(g, vertices[i], vertices[i + 1]) == 0){
                    return 0;
                }
            }
        return 1;
    }
    return 0;
}

void complemento(grafo *g){
    FILE *fp = fopen("Complemento.txt", "w");
    fprintf(fp, "%i\n", g -> vertices);
    for(int i = 0; i < g -> vertices; ++i){
        for(int j = 0; j < g -> vertices; ++j){
            if(existe_arista(g, i, j) == 0 && i < j){
                fprintf(fp, "%i %i\n", i, j);
            }
        }   
    }
    printf("Archivo grafo complemento creado\n");
}

void imprimir_aristas(grafo *g, int **aristas){
    printf("Aristas: ");
    for(int j = 0; j < g -> aristas; j++){
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