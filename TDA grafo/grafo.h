#include "lista.h"

typedef struct Grafo grafo;

struct Grafo{
    int aristas;
    int vertices;
    Lista **v;
};

grafo *crear_grafo(int n);
void insertar_arista(grafo *g, int ar1, int ar2);
void mostrar_grafo(grafo *g);
int *remover_arista(grafo *g, int ar1, int ar2);
int existe_arista(grafo *g, int ar1, int ar2);
Lista *obtener_aristas(grafo *g, int vertice);
int obtener_grado_vertice(grafo *g, int vertice);
Lista *obtener_adyacentes_vertice(grafo *g, int vertice);