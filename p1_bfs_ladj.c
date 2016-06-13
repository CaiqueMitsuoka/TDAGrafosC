/*
	BFS em LISTA DE ADJACENCIAS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TRUE  1
#define FALSE 0

#define QTD_EST 1000

char vertices[QTD_EST];
int arestas[QTD_EST][QTD_EST];

int bfs( int, int );

int main()
{	int E, L, i, j, X, Y, qtde, maior, Caso = 0;


	while( scanf( "%d %d", &E, &L ) && !( E==0 && L==0 ) )
	{	for( i=0; i<E; i++ )
			arestas[i][0] = 0;

		for( i=0; i<L; i++ )
		{	scanf( "%d %d", &X, &Y );

			arestas[X-1][++arestas[X-1][0]] = Y;
			arestas[Y-1][++arestas[Y-1][0]] = X;
		}

		maior = 0;
		for( j=0; j<E; j++ )
		{	for( i=0; i<E; i++ )
				vertices[i] = FALSE;

			qtde = bfs( j, E );

			if( qtde>maior ) maior = qtde;
		}

		printf( "Caso de teste %d\n%d\n\n", ++Caso, maior );
	}


	return 0;
}

int bfs( int v, int qtEstrelas )
{	int n,				/* Contador de proposito geral */
		c, 				/* Contador de proposito geral */
		qtde, 			/* Qtde de estrelas atingidas */
		fila[QTD_EST], 	/* Vetor para a ordem dos vertices a visitar */
		i=0, 			/* Indicador do inicio da fila */
		f=0;			/* Indicador do final da fila */

	/* Processando o vertice de origem do percurso */
	vertices[v] = TRUE;		/* Marcando o vertice v como já visitado */
	fila[f++] = v;			/* Colocando o vértice v na fila */
	qtde = 1;				/* Contabilizando o vértice v no total de estrelas
								da constelação atual */

	while( f != i )			/* Enqto houver elementos na fila */
	{	n = fila[i++];
		for( c=1; c<=arestas[n][0]; c++ )
		{	if( vertices[arestas[n][c]-1] == FALSE )
			{	fila[f++] = arestas[n][c]-1;
				vertices[arestas[n][c]-1] = TRUE;
				qtde = qtde + 1;
			}
		}
	}

	return qtde;
}
