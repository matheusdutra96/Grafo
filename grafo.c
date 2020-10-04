#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "fila.h"
#include "pilha.h"

Grafo criaGrafo(int n){
    Grafo g;
    g.lista_adj = (vertice **) malloc(n*(sizeof(vertice)));
    g.num_vert=n;
    int i;
    for(i=0;i<n;i++)
    {
        g.lista_adj[i] = NULL;
    }
    return g;
}

void insereAresta(Grafo *g,int v, int u){
    vertice *novo = (vertice *) malloc(sizeof(vertice));
    vertice **l;

    novo->vert = u;
    novo->proximo = NULL;


    l = &(*g).lista_adj[v];
    while(*l!=NULL)
        l = &(*l)->proximo;
    *l = novo;
}

void buscaLargura(Grafo *g,int s){

    Fila f = criaFila();
    int *visitados = (int *) malloc(g->num_vert*sizeof(int));
    int i,v,j;

    vertice **l;  //ponteiro que vai percorrer a lista de cada vértice.
    for(j=0;j<g->num_vert;j++)
    {
        visitados[j]=0;
    }

    pushFila(&f,s);
    visitados[s]=1;
    printf("%d ",s);

    while(!filaVazia(f)){
        v = popFila(&f);
        l = &(*g).lista_adj[v]; //O ponteiro recebe o endereço do índice que ele vai percorrer.

        while(*l!=NULL)
        {
            i = (*l)->vert;
            if(visitados[i]==0)
            {
                pushFila(&f,i);
                visitados[i]=1;
                printf("%d ",i);
            }
            l = &(*l)->proximo;
        }
    }
    free(visitados);
    visitados=NULL;
}

void buscaProfundidade(Grafo *g,int s){
    Pilha p = criaPilha();
    int i,v,j;

    vertice **l; // ponteiro para percorrer a lista de cada vértice.

    int *visitados = (int *) malloc(g->num_vert*sizeof(int));

    for(j=0;j<g->num_vert;j++)
    {
        visitados[j]=0;
    }

    pushPilha(&p,s);

    while(!pilhaVazia(p))
    {
        v=popPilha(&p);
        l = &(*g).lista_adj[v];
        if(visitados[v]==0)
        {
            visitados[v]=1;
            printf("%d ",v);
            while(*l!=NULL)
            {
                i = (*l)->vert;
                pushPilha(&p,i);
                l = &(*l)->proximo;
            }
        }
    }
    free(visitados);
    visitados=NULL;
}


