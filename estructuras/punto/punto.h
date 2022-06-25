struct punto 
{
  float x;
  float y;
};

typedef struct punto Punto;

Punto *crear_punto();

int obtener_cuadrante(Punto *p);

void insertar_punto(Punto *p, float a, float b);

void imprimir_punto(Punto *p);

Punto *desplazar_punto(Punto *p, float a, float b);

float obtener_distancia(Punto *pa, Punto*pb);

Punto *obtener_punto_medio(Punto *pa, Punto *pb);
