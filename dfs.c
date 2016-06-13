/*
	Busca em profundidade (DFS) em matriz de adjacencias
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTICES 1000
#define MAX_ARESTAS  1000

#define TRUE  1
#define FALSE 0

char visitado[MAX_VERTICES], arestas[MAX_VERTICES][MAX_VERTICES];
int qtde;

void dfs(int v)
{
	int j;

	visitado[v] = TRUE;
	qtde = qtde + 1;

	for(j = 1; j <= arestas[v][0]; j++)
		if(visitado[arestas[v][j]] == FALSE)
			dfs(arestas[v][j]);
}

int main()
{	int aux,nVert, nAres, l, v1, v2, maior, caso = 0;

	while(scanf("%d %d", &nVert, &nAres) && nVert != 0 && nAres != 0)
	{
		caso++;
		for(l = 0; l < nVert; l++)
			arestas[l][0] = 0;
		for(l = 0; l < nAres; l++)
		{
			scanf("%d %d", &v1, &v2);
			v1--;
			v2--;
			//printf("%d %d\n", v1 , v2);
			arestas[v1][0]++;
			aux = arestas[v1][0];
			arestas[v1][aux] = v2;

			arestas[v2][0]++;
			aux = arestas[v2][0];
			arestas[v2][aux] = v1;
		}

		// printf("*** Lista de adjacencias ***\n");
		// for(l = 0; l < nVert; l++)
		// {
		// 	for(c = 0; c < nVert; c++)
		// 	printf("%d ", arestas[l][c]);
		//
		// 	printf("\n");
		// }
		// printf("*** Fim ***");
		maior = 0;
		for(l = 0; l < nVert; l++)
		{
			memset(visitado,0,nVert);
			qtde = 0;
			dfs(l);
      //l += qtde;
			//printf("Entrou %d\n",l);
			if(qtde > maior)
				maior = qtde;
			//printf("Entrou %d\n",qtde);
		}
		printf("Caso de teste %d\n", caso);
		printf("%d\n\n", maior);
	}

	return 0;
}
