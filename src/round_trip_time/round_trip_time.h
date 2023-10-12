#ifndef _ROUND_TRIP_TIME_H_
#define _ROUND_TRIP_TIME_H_

#include "../graph/graph.h"
#include "../dijkstra/dijkstra.h"

typedef struct {
    int m;
    int n;
    double **matrix;
} DistanceMatrix;

// verifica se o vértice v está no vetor de vértices, retorna o índice se estiver, -1 caso contrário
int is_in(int v, int *vertices, int size);

double round_trip_time(Graph* graph, int u, int v, double *dist, MinHeap *heap);

double round_trip_time_star(Graph* graph, int a, int b, int *m, int size_m, double *dist, MinHeap *heap);

#endif // _ROUND_TRIP_TIME_H_