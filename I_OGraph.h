#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

void ImprimirGR(TGRAFO *grafinho){
    int a,b;
    for(a = 0;a<grafinho->pontos;a++){
        printf("ponto %d : %d |", a+1,grafinho->lig[a]);
        for(b=0;b < grafinho->lig[a];b++){
            printf(" (%d, %d horas)",grafinho->Mapa[a][b].ponto, grafinho->Mapa[a][b].peso);
        }
        printf("\n");
    }
}


void AdicionarAresta(TGRAFO *Graf,int X,int Y,int Peso){
    Graf->Mapa[X][Graf->lig[X]].peso = Peso;
    Graf->Mapa[X][Graf->lig[X]].ponto = Y;
    Graf->lig[X] += 1;
}

TGRAFO* SetGR(int X){
    TGRAFO *Grafo = (TGRAFO*)malloc(sizeof(TGRAFO));
    int a;
    Grafo->pontos = X;
    for(a=0;a<X;a++){
        Grafo->lig[a] = 0;
    }
    return Grafo;
}
