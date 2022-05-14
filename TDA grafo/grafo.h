typedef struct Grafo grafo;

struct Grafo{
    int aristas;
    int vertices;
    Lista **v;
};

grafo *crear_grafo(int n);
void insertar_arista(grafo *g, int ar1, int ar2);
void mostrar_grafo(grafo *g);
void remover_arista(grafo *g, int ar1, int ar2);
int existe_arista(grafo *g, int ar1, int ar2);
int **obtener_aristas(grafo *g);
int obtener_grado_vertice(grafo *g, int vertice);
Lista *obtener_adyacentes_vertice(grafo *g, int vertice);
void imprimir_aristas(grafo *g, int **aristas);
void imprimir_vertices(Lista *l, int ar1);