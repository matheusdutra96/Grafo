#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int vert;
    struct elemento *proximo;
}vertice;

typedef struct grafo{
    int num_vert;
    vertice **lista_adj;
}Grafo;

Grafo criaGrafo(int n);
void insereAresta(Grafo *g,int v,int u);
void buscaLargura(Grafo *g,int s);
void buscaProfundidade(Grafo *g,int s);


#endif // GRAFO_H_INCLUDED
