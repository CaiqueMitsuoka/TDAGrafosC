#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_ARESTAS  1000

typedef struct{
    int ponto;
    int peso;
}T_Aresta;

typedef struct{
    int pontos;
    int lig[MAX_VERTICES];
    T_Aresta Mapa[MAX_VERTICES][MAX_ARESTAS];
}TGRAFO;

void imprimir(TGRAFO *grafinho){
    int a,b;
    for(a = 0;a<grafinho->pontos;a++){
        printf("ponto %d : %d |", a,grafinho->lig[a]);
        for(b=0;b < grafinho->lig[a];b++){
            printf(" (%d, %d horas)",grafinho->Mapa[a][b].ponto, grafinho->Mapa[a][b].peso);
        }
        printf("\n");
    }
}

void potencia(int K, int *C){
    int a,temp = K;
    for(a=1;a<*C;a++){
        temp = temp * K;
    }
    *C = temp;
}

int dijkstra (int Sair,int Chegar, TGRAFO *graf){
    int distancias[MAX_VERTICES], vertices[MAX_VERTICES], i, j, menor, prox, infinito;
    // definindo quanto vai ser infinito como o numero maximo do inteiro padrão
    infinito = (sizeof(int) * 8) - 2;
    potencia(2,&infinito);
    // printf("%d\n",infinito);
    // colocando falso para todos os pontos(nenhum foi visitado ainda)
    // distancia até todos é infinito agora, e eu vou baixando nos conformes
    for(i=0;i<graf->pontos;i++){
        vertices[i] = 0;
        distancias[i] = infinito;
    }
    // aqui eu ja seto a distancia para o ponto de origem como 0, assim no primeiro loop ele ja vai pega
    // esse valor como menos e atualizar as distancias em relação a ele
    distancias[Sair] = 0;
    // aquele for que anda todos os pontos TLG
    for(i=0;i<graf->pontos;i++){
        // seto o menor para infinito, assim sempre que ele achar qualquer zica ta de boas
        menor = infinito;
        // mais um DAQUELES
        for(j=0;j<graf->pontos;j++){
            // sempre que p cara não for visitado e as distancia até ele for a menor,
            // eu salvo quem ele é e atualizo o menos
            if(vertices[j] == 0 && distancias[j]<menor){
                menor = distancias[j];
                prox = j;
            }
        }
        // coloco aqui que o cara ja foi visitado pra quando eu for voltar pra ele no for de cima
        vertices[prox] = 1;
        // aqui não é um daqueles, mas ele anda o numero de ligações que o pontos marcado(prox) tem
        for(j=0;j<graf->lig[prox];j++){
            // se a distancia do ponto inicial dele for menos for menor que a distancia que ja ta la
            // ele atualiza
            if(graf->Mapa[prox][j].peso + distancias[prox] < distancias[graf->Mapa[prox][j].ponto]){
                distancias[graf->Mapa[prox][j].ponto] = graf->Mapa[prox][j].peso + distancias[prox];
            }
        }
    }
    // vamos retonar a distancia RIGHT?
    return distancias[Chegar];
}

int main(){
    TGRAFO Graf;
    int NumeroDePontos,NumeroDeLigacoes,cont,X,Y,Horas,De,Ate;
    scanf("%d %d", &NumeroDePontos, &NumeroDeLigacoes);
    while(NumeroDePontos != 0 && NumeroDeLigacoes != 0){
        Graf.pontos = NumeroDePontos;
        //zerando as ligações
        for(cont = 0 ; cont < NumeroDePontos ; cont++){
            Graf.lig[cont] = 0;
        }
        for(cont = 0; cont < NumeroDeLigacoes; cont++ ){
            scanf("%d %d %d", &X, &Y, &Horas);
            X--;
            Y--;
            Graf.Mapa[X][Graf.lig[X]].peso = Horas;
            Graf.Mapa[X][Graf.lig[X]].ponto = Y;
            Graf.Mapa[Y][Graf.lig[Y]].peso = Horas;
            Graf.Mapa[Y][Graf.lig[Y]].ponto = X;
            Graf.lig[Y]++;
            Graf.lig[X]++;
        }

        imprimir(&Graf);

        printf("De: ");
        scanf("%d", &De);
        printf("Ate: ");
        scanf("%d", &Ate);
        printf("Do ponto %d, até o ponto %d, o menor caminho é de %d\n",De,Ate,dijkstra(De-1,Ate-1,&Graf));
        scanf("%d %d", &NumeroDePontos, &NumeroDeLigacoes);
    }
    return 0;
}
