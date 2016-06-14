#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimirGR(TGRAFO *grafinho){
    int a,b;
    for(a = 0;a<grafinho->pontos;a++){
        printf("ponto %d : %d |", a,grafinho->lig[a]);
        for(b=0;b < grafinho->lig[a];b++){
            printf(" (%d, %d horas)",grafinho->Mapa[a][b].ponto, grafinho->Mapa[a][b].peso);
        }
        printf("\n");
    }
}

void AdicionarAresta(TGRAFO *Graf,int X,int Y,int Peso){
    Graf->Mapa[X][Graf->lig[X]].peso = Peso;
    Graf->Mapa[X][Graf->lig[X]].ponto = Y;
    Graf->Mapa[X][Graf->lig[X]].ponto2 = X;
    Graf->lig[X] += 1;
}

void AdicionarArestaEsp(TGRAFO *Graf,int X,int Y,int Peso){
    Graf->Mapa[X][Graf->lig[X]].peso = Peso;
    Graf->Mapa[X][Graf->lig[X]].ponto = Y;
    Graf->Mapa[X][Graf->lig[X]].ponto2 = X;

    Graf->lig[X] += 1;
    Graf->Mapa[Y][Graf->lig[Y]].peso = Peso;
    Graf->Mapa[Y][Graf->lig[Y]].ponto = X;
    Graf->Mapa[X][Graf->lig[X]].ponto2 = Y;
    Graf->lig[Y] += 1;
}

TGRAFO* SetGR(int X){
    TGRAFO *Grafo = (TGRAFO*)malloc(sizeof(TGRAFO));
    Grafo->pontos = X;
    memset(Grafo->lig, 0, X);
    return Grafo;
}
