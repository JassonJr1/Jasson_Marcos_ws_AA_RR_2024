#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <inttypes.h>  // Para usar a macro PRIu64

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

typedef struct Vertice {
    int cor;
    int d;      // tempo de descoberta
    int f;      // tempo de término
    int pi;     // predecessor
} Vertice;

typedef struct Grafo {
    int V;      // número de vértices
    int **adj;  // matriz de adjacência
    Vertice *vertices;
} Grafo;

int tempo;

void DFS_Visit(Grafo *G, int u) {
    tempo++;
    G->vertices[u].d = tempo;
    G->vertices[u].cor = CINZA;
    
    for (int v = 0; v < G->V; v++) {
        if (G->adj[u][v] == 1 && G->vertices[v].cor == BRANCO) {
            G->vertices[v].pi = u;
            DFS_Visit(G, v);
        }
    }
    
    G->vertices[u].cor = PRETO;
    tempo++;
    G->vertices[u].f = tempo;
}

void DFS(Grafo *G) {
    for (int u = 0; u < G->V; u++) {
        G->vertices[u].cor = BRANCO;
        G->vertices[u].pi = NULO;
    }
    tempo = 0;
    for (int u = 0; u < G->V; u++) {
        if (G->vertices[u].cor == BRANCO) {
            DFS_Visit(G, u);
        }
    }
}

Grafo* criarGrafo(int V) {
    Grafo *G = (Grafo*)malloc(sizeof(Grafo));
    G->V = V;
    G->adj = (int**)malloc(V * sizeof(int*));
    G->vertices = (Vertice*)malloc(V * sizeof(Vertice));

    for (int i = 0; i < V; i++) {
        G->adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            G->adj[i][j] = 0; // Inicializando a matriz de adjacência com 0
        }
    }
    return G;
}

void adicionarAresta(Grafo *G, int u, int v) {
    G->adj[u][v] = 1;
}

void imprimirResultado(Grafo *G) {
    for (int u = 0; u < G->V; u++) {
        printf("Vértice %d: d = %d, f = %d, pi = %d\n", u, G->vertices[u].d, G->vertices[u].f, G->vertices[u].pi);
    }
}

int main() {
    int V = 20000;  // Número de vértices (um grafo gigante)
    Grafo *G = criarGrafo(V);

    // Adicionando muitas arestas para criar um grafo denso
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (rand() % 2) {  // Adiciona uma aresta com 50% de probabilidade
                adicionarAresta(G, i, j);
            }
        }
    }
    
    // Medindo o tempo de execução da DFS usando QueryPerformanceCounter
    LARGE_INTEGER inicio, fim, freq;
    double tempo_execucao;

    QueryPerformanceFrequency(&freq);  // Obtendo a frequência do contador
    QueryPerformanceCounter(&inicio);  // Captura o tempo antes da DFS
    
    DFS(G);

    QueryPerformanceCounter(&fim);  // Captura o tempo após a DFS

    // Calculando o tempo de execução em segundos
    tempo_execucao = (double)(fim.QuadPart - inicio.QuadPart) / freq.QuadPart;

    printf("Tempo de execução da DFS com QueryPerformanceCounter: %f segundos\n", tempo_execucao);

    // Usando GetTickCount para capturar o tempo em milissegundos
    DWORD start = GetTickCount();
    
    DFS(G);
    
    DWORD end = GetTickCount();
    
    printf("Tempo de execução da DFS com GetTickCount: %" PRIu64 " milissegundos\n", (uint64_t)(end - start));

    // Liberando a memória alocada
    for (int i = 0; i < V; i++) {
        free(G->adj[i]);
    }
    free(G->adj);
    free(G->vertices);
    free(G);

    return 0;
}


