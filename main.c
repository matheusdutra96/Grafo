#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    int i,vertice1=0,vertice2=0,inicio;
    scanf("%d",&i);
    Grafo g=criaGrafo(i);

    while(vertice1!=-1 && vertice2!=-1)
    {
        scanf("%d %d",&vertice1,&vertice2);
        if(vertice1>=0 && vertice2>=0)
        {
            insereAresta(&g,vertice1,vertice2);
            insereAresta(&g,vertice2,vertice1);
        }
    }

    scanf("%d",&inicio);

    printf("Busca em Largura: ");
    buscaLargura(&g,inicio);

    printf("\n");

    printf("Busca em Profundidade: ");
    buscaProfundidade(&g,inicio);

    return 0;
}
