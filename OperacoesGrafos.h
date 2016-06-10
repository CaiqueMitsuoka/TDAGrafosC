
void potencia(int K, int *C){
    int a,temp = K;
    for(a=1;a<*C;a++){
        temp = temp * K;
    }
    *C = temp;
}

int dijkstra (int Sair,int Chegar, TGRAFO *graf){
    int distancias[MAX_VERTICES], vertices[MAX_VERTICES], i, j, menor, prox, infinito;
    infinito = (sizeof(int) * 8) - 2;
    potencia(2,&infinito);
    for(i=0;i<graf->pontos;i++){
        vertices[i] = 0;
        distancias[i] = infinito;
    }
    distancias[Sair] = 0;
    for(i=0;i<graf->pontos;i++){
        menor = infinito;
        for(j=0;j<graf->pontos;j++){
            if(vertices[j] == 0 && distancias[j]<menor){
                menor = distancias[j];
                prox = j;
            }
        }
        vertices[prox] = 1;
        for(j=0;j<graf->lig[prox];j++){
            if(graf->Mapa[prox][j].peso + distancias[prox] < distancias[graf->Mapa[prox][j].ponto]){
                distancias[graf->Mapa[prox][j].ponto] = graf->Mapa[prox][j].peso + distancias[prox];
            }
        }
    }
    return distancias[Chegar];
}
