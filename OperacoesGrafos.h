
void potencia(int K, int *C){
    int a,temp = K;
    for(a=1;a<*C;a++){
        temp = temp * K;
    }
    *C = temp;
}

int comp(const void *p1, const void *p2)
{	T_Aresta *i = (T_Aresta *)p1, *j = (T_Aresta *)p2;

	if(i->peso > j->peso)
		return 1;
	else
		if(i->peso < j->peso)
			return -1;
		else
			return 0;
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

TGRAFO* kruskal (TGRAFO *grafinho , int nVertices){
   TGRAFO *ArvGerMinima = NULL;
   T_Aresta pesos[MAX_ARESTAS];
   ArvGerMinima = SetGR(nVertices);
   int i , j , qtArestas , grupo1 , grupo2 , vertices[MAX_VERTICES];
   for(i=qtArestas=0;i<nVertices;i++){
     for(j=0;j < grafinho->lig[i];j++){
          pesos[qtArestas].ponto = i;
          pesos[qtArestas].ponto2 = grafinho->Mapa[i][j].ponto;
          pesos[qtArestas].peso = grafinho->Mapa[i][j].peso;
          qtArestas++;
     }
   }
   qsort(pesos,qtArestas,sizeof(T_Aresta),comp);
   for(i=0;i<nVertices;i++)
      vertices[i] = i;
   for(i=0;i<qtArestas;i++){
       if(vertices[pesos[i].ponto] != vertices[pesos[i].ponto2]){
         if (vertices[pesos[i].ponto] < vertices[pesos[i].ponto2]){
           grupo1 = vertices[pesos[i].ponto];
           grupo2 = vertices[pesos[i].ponto2];
         }else{
           grupo1 = vertices[pesos[i].ponto2];
           grupo2 = vertices[pesos[i].ponto];
         }
         AdicionarAresta(ArvGerMinima , pesos[i].ponto , pesos[i].ponto2 , pesos[i].peso);
        }

        for (j = 0; j < nVertices; j++)
  				if(vertices[j] == grupo2)
  					vertices[j] = grupo1;
   }
   return ArvGerMinima;
}

int bfs(TGRAFO *Grafo, int origem){
    int n, c, qtde,	fila[MAX_ARESTAS], vertices[MAX_VERTICES], i=0, f=0;

	origem--;
	memset(vertices, FALSE, Grafo->pontos);

	vertices[origem] = TRUE;
	fila[f++] = origem;
	qtde = 1;

	while( f != i ){
		n = fila[i++];
		for( c=0; c<Grafo->lig[n]; c++ ){
			if( vertices[Grafo->Mapa[n][c-1].ponto] == FALSE ){
				fila[f++] = Grafo->Mapa[n][c-1].ponto;
				vertices[Grafo->Mapa[n][c-1].ponto] = TRUE;
				qtde = qtde + 1;
			}
		}
	}

	return qtde;
}
//
// void fdfs(TGRAFO *Grafo,int pivo, char visitado[], int *qtde)
// {
//     int j;
//
//     visitado[pivo] = TRUE;
//     *qtde = *qtde + 1;
//
//     for(j = 0; j < Grafo->lig[pivo]; j++){
//         if(visitado[Grafo->Mapa[pivo][j].ponto] == FALSE){
//             fdfs(Grafo, Grafo->Mapa[pivo][j].ponto, visitado, qtde);
//         }
//     }
// }

int dfs(TGRAFO *Grafo, int origem){
    char visitado[MAX_VERTICES];
    int qtde = 0;

    void fdfs(TGRAFO *Grafo,int pivo)
    {
        int j;

        visitado[pivo] = TRUE;
        qtde = qtde + 1;

        for(j = 0; j < Grafo->lig[pivo]; j++){
            if(visitado[Grafo->Mapa[pivo][j].ponto] == FALSE){
                fdfs(Grafo, Grafo->Mapa[pivo][j].ponto);
            }
        }
    }
    origem--;
    memset(visitado,0,Grafo->pontos);
    fdfs(Grafo, origem/*, visitado, &qtde*/);
    return qtde;
}
