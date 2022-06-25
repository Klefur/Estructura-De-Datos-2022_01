#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "punto.h"

Punto *crear_punto()
{
	Punto *p;
	p = (Punto*) malloc(sizeof(Punto));
	p -> x = 0;
	p -> y = 0;
	return p;
}

void insertar_punto(Punto *p,float a, float b)
{
	p -> x = a;
	p -> y = b;
}

int obtener_cuadrante(Punto *p)
{
    float eje_x, eje_y;

    eje_x = p -> x;
    eje_y = p -> y;

    if(eje_x > 0 && eje_y > 0)
    {
        return 1;
    }
    else if(eje_x < 0 && eje_y > 0)
    {
        return 2;
    }
    else if(eje_x < 0 && eje_y < 0)
    {
        return 3;
    }
    else if(eje_x > 0 && eje_y < 0)
    {
        return 4;
    }

}

void imprimir_punto(Punto *p)
{
    printf("x: %.4f e y: %.4f\n", p -> x, p -> y);
}

Punto *desplazar_punto(Punto *p, float a, float b)
{
    p -> x += a;
	p -> y += b;

    return p;
}

float obtener_distancia(Punto *pa, Punto*pb)
{
    float dx, dy, d;
    float pa_ejex, pa_ejey;
    float pb_ejex, pb_ejey;

    pa_ejex = pa -> x;
    pa_ejey = pa -> y;
    
    pb_ejex = pb -> x;
    pb_ejey = pb -> y;

    dx = (pb_ejey) - (pa_ejey);
    dy = (pb_ejex) - (pa_ejex);

    d = sqrt(dx * dx + dy * dy);

    return d;
}

Punto *obtener_punto_medio(Punto *pa, Punto *pb)
{
    float px, py;
    Punto *punto_2;
    punto_2 = (Punto*) malloc(sizeof(Punto));

    px = (pa -> x) + (pb -> x);
    py = (pa -> y) + (pb -> y);

    punto_2 -> x = (px / 2);
    punto_2 -> y = (py / 2);

    return punto_2;
}