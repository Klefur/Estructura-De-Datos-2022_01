typedef struct info
{
    char dato;
} info;

typedef struct nodo
{
    info *val;
    struct nodo *der;
    struct nodo *izq;
} nodo;

typedef struct arbol
{
    nodo *raiz;
} arbol;

arbol *crearArbol();
nodo *crearNodo(char val);
info *crearInfo(char val);
void insertar(nodo *n, char padre, char val);
nodo *buscarNodo(nodo *n, char val);
void inOrder(nodo *n);
void preOrder(nodo *n);
void postOrder(nodo *n);
nodo *padre(nodo *n, char val);
int profundidadNodo(nodo *n, char val);
int alturaNodo(nodo *n, char val);
int nivelNodo(nodo *n, char val);
int contarNodos(nodo *n);
int contarHojas(nodo *n);
int sonSimilares(nodo *n1, nodo *n2);
int esCompleto(nodo *n);
