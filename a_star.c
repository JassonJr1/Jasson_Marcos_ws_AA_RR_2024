#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>

typedef struct {
    int vertex;
    int cost;
} Node;

typedef struct {
    Node** adj;
    int V;
} Grafo;

Grafo* criarGrafo(int V) {
    Grafo* G = (Grafo*)malloc(sizeof(Grafo));
    G->V = V;
    G->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        G->adj[i] = (Node*)malloc(V * sizeof(Node));
        for (int j = 0; j < V; j++) {
            G->adj[i][j].vertex = -1;
            G->adj[i][j].cost = INT_MAX;
        }
    }
    return G;
}

void adicionarAresta(Grafo *G, int u, int v, int cost) {
    G->adj[u][v].vertex = v;
    G->adj[u][v].cost = cost;
    G->adj[v][u].vertex = u;  // Se for um grafo não dirigido
    G->adj[v][u].cost = cost;
}

int heuristic(int u, int goal) {
    return abs(goal - u);
}

void aStar(Grafo *G, int start, int goal) {
    int *dist = (int *)malloc(G->V * sizeof(int));
    int *prev = (int *)malloc(G->V * sizeof(int));
    int *visited = (int *)malloc(G->V * sizeof(int));
    for (int i = 0; i < G->V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    int *openSet = (int *)malloc(G->V * sizeof(int));
    int openSetSize = 0;
    openSet[openSetSize++] = start;

    while (openSetSize > 0) {
        int minIndex = 0;
        for (int i = 1; i < openSetSize; i++) {
            if (dist[openSet[i]] + heuristic(openSet[i], goal) < dist[openSet[minIndex]] + heuristic(openSet[minIndex], goal)) {
                minIndex = i;
            }
        }
        int u = openSet[minIndex];
        openSet[minIndex] = openSet[--openSetSize];

        if (u == goal) {
            break;
        }

        if (visited[u]) {
            continue;
        }

        visited[u] = 1;

        for (int v = 0; v < G->V; v++) {
            if (!visited[v] && G->adj[u][v].vertex != -1) {
                int alt = dist[u] + G->adj[u][v].cost;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    openSet[openSetSize++] = v;
                }
            }
        }
    }

    free(dist);
    free(prev);
    free(visited);
    free(openSet);
}

int main() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER startTime, endTime;

    // Inicializar o contador de frequência
    QueryPerformanceFrequency(&frequency);

    int V = 20000;
    Grafo *G = criarGrafo(V);

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (rand() % 2) {
                adicionarAresta(G, i, j, 1);
            }
        }
    }

    // Medir o tempo de execução do algoritmo A*
    QueryPerformanceCounter(&startTime);
    aStar(G, 0, 100);
    QueryPerformanceCounter(&endTime);

    // Calcular o tempo decorrido
    double elapsedTime = (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;
    printf("%f\n", elapsedTime);  // Exibir apenas o tempo de execução

    for (int i = 0; i < V; i++) {
        free(G->adj[i]);
    }
    free(G->adj);
    free(G);

    return 0;
}