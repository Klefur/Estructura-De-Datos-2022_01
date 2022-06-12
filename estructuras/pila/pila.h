typedef struct nodop
{
    int valor;
    struct nodop *next;
}Nodop;

typedef struct pila
{
    Nodop *tope;
}Pila;

Pila *crear_pila();
Nodop *crear_nodo(int valor);
int isEmpty(Pila *p);
void push(Pila *p, int valor);
int pop(Pila *p);
int tope(Pila *p);
void destruirPila(Pila *p);