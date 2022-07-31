typedef struct nodo
{
    int valor;
    struct nodo *izq;
    struct nodo *der;
} nodo;
typedef struct arbol
{
    nodo *raiz;
} arbol;

arbol *crearArbol();
nodo *crearNodo(int val);
void insertar(nodo *n, int padre, int val);
nodo *buscarNodo(nodo *n, int val);
int contarNodos(nodo *n);
void inOrden(nodo *n);
void preOrden(nodo *n);
void postOrden(nodo *n);