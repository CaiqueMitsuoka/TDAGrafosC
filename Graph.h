#define MAX_VERTICES 10000
#define MAX_ARESTAS  10000

typedef struct{
    int ponto;
    int peso;
}T_Aresta;

typedef struct{
    int pontos;
    int lig[MAX_VERTICES];
    T_Aresta Mapa[MAX_VERTICES][MAX_ARESTAS];
}TGRAFO;
