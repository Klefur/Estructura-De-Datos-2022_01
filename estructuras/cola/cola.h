typedef struct nodoc
{
    int valor;
    struct nodoc *next;
}Nodoc;

typedef struct cola
{
    Nodoc *tope;
    Nodoc *fin;
}Cola;

Cola *crear_cola();
Nodoc *crear_nodo(int valor);
int isEmpty(Cola *c);
void encolar(Cola *c, int valor);
void desencolar(Cola *c);
int primero(Cola *c);
void destruirCola(Cola *c);