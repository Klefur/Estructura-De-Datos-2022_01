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

arbol *crearArbol()
{
    arbol *a = malloc(sizeof(arbol *));
    a->raiz = NULL;

    return a;
}

nodo *crearNodo(char val)
{
    nodo *n = malloc(sizeof(nodo *));
    n->val = crearInfo(val);
    n->izq = NULL;
    n->der = NULL;

    return n;
}

info *crearInfo(char val)
{
    info *Info = malloc(sizeof(info *));
    Info->dato = val;

    return Info;
}

void insertar(nodo *n, char padre, char val)
{
    nodo *pad = buscarNodo(n, padre);
    if (pad == NULL)
        printf("No existe\n");
    else
    {
        if (pad->izq == NULL)
            pad->izq = crearNodo(val);
        else if (pad->der == NULL)
            pad->der = crearNodo(val);
        else
            printf("Los 2 nodos ya existen\n");
    }
}

nodo *buscarNodo(nodo *n, char val)
{
    if (n->val->dato == val)
        return n;
    else
    {
        nodo *aux = NULL;
        if (n->izq != NULL)
        {
            aux = buscarNodo(n->izq, val);
        }
        if (aux != NULL && aux->val->dato == val)
        {
            return aux;
        }
        else
        {
            if (n->der != NULL)
            {
                aux = buscarNodo(n->der, val);
                if (aux != NULL && aux->val->dato == val)
                {
                    return aux;
                }
            }
        }

        return aux;
    }
}

void preOrden(nodo *n)
{
    if (n != NULL)
    {
        printf("%c", n->val->dato);
        preOrden(n->izq);
        preOrden(n->der);
    }
}

void inOrden(nodo *n)
{
    if (n != NULL)
    {
        inOrden(n->izq);
        printf("%c", n->val->dato);
        inOrden(n->der);
    }
}

void postOrden(nodo *n)
{
    if (n != NULL)
    {
        postOrden(n->izq);
        postOrden(n->der);
        printf("%c", n->val->dato);
    }
}

nodo *padre(nodo *n, char val)
{
}

int profundidadNodo(nodo *n, char val)
{
}

int alturaNodo(nodo *n, char val)
{
}

int nivelNodo(nodo *n, char val)
{
}

int contarNodos(nodo *n)
{
    int contar = 0;
    if (n != NULL)
        contar = 1 + contarNodos(n->der) + contarNodos(n->izq);

    return contar;
}

int contarHojas(nodo *n)
{
}

int sonSimilares(nodo *n1, nodo *n2)
{
}

int esCompleto(nodo *n)
{
}