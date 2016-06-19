#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "I_OGraph.h"
#include "OperacoesGrafos.h"

int main(){
    char option[5];
    int X,Y,Peso;
    TGRAFO *Grafo;
    printf("Tipo abstrado de dados: Grafos - FATEC-SO 1Sem/2016\n");
    printf("Insira quantos pontos podem haver no grafico?\n");
    scanf("%d", &X);
    Grafo = SetGR(X);
    while(1){
        printf("\n\nMENU:\nComando    Ação\n   I      Inserir\n   R      Remover\n   E      Inserir Espelhado\n   P      Imprimir\n   X      Parar\n   D      Dijkstra\n");
        scanf("%s",option);
        switch (option[0]){
            case 'I':
                printf("de: ");
                scanf("%d", &X);
                printf("ate: ");
                scanf("%d", &Y);
                printf("peso: ");
                scanf("%d", &Peso);
                AdicionarAresta(Grafo,X-1,Y-1,Peso);
            break;
            case 'E':
                printf("de: ");
                scanf("%d", &X);
                printf("ate: ");
                scanf("%d", &Y);
                printf("peso: ");
                scanf("%d", &Peso);
                AdicionarArestaEsp(Grafo,X-1,Y-1,Peso);
            break;
            case 'P':
                ImprimirGR(Grafo);
            break;
            case 'D':
                printf("de: ");
                scanf("%d", &X);
                printf("ate: ");
                scanf("%d", &Y);
                printf("menor distancia: %d\n", dijkstra(X-1,Y-1,Grafo));
            break;
            case 'R':
                printf("de: ");
                scanf("%d", &X);
                printf("ate: ");
                scanf("%d", &Y);
                RemoverAresta(Grafo,X,Y);
            break;
            case 'K':
                ImprimirGR(kruskal(Grafo, Grafo->pontos));
            break;
            case 'X':
                exit(0);
            break;
        }
    }
}
