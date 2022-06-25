#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "punto.h"

int main()
{
	Punto *pa, *pb, *pm;
    float distancia;
	
    pa = crear_punto();
    pb = crear_punto();

	insertar_punto(pa, -4, 1);
	insertar_punto(pb, 3, 6);

    imprimir_punto(pa);
    imprimir_punto(pb);

    printf("cuandrante pa: %d\n", obtener_cuadrante(pa));
    printf("cuandrante pb: %d\n", obtener_cuadrante(pb));

    pa = desplazar_punto(pa, 2, 4);
    pb = desplazar_punto(pb, 3, 2);

    imprimir_punto(pa);
    imprimir_punto(pb);

    distancia = obtener_distancia(pa, pb);

    printf("distancia: %.4f\n", distancia);

    pm = obtener_punto_medio(pa, pb);

    imprimir_punto(pm);
	
	return 0;
}