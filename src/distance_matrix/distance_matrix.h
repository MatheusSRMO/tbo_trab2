#ifndef _DISTANCE_MATRIX_H_
#define _DISTANCE_MATRIX_H_
#include <stdio.h>
#include <stdlib.h>

#include "../graph/graph.h"
#include "../dijkstra/dijkstra.h"

typedef struct {
    int size_set_source;
    int size_set_target_a;
    int size_set_target_b;

    int *line_map; // relacionar o indice da linha com o id do vertice
    int *column_map; // relacionar o indice da coluna com o id do vertice

    double **matrix;
} DistanceMatrix;

/// @brief Cria uma matriz de distâncias entre um conjunto de origem e dois conjuntos de destino
/// @param graph Grafo
/// @param set_source Conjunto de origem
/// @param size_set_source Tamanho do conjunto de origem
/// @param set_target_a Conjunto de destino A
/// @param size_set_target_a Tamanho do conjunto de destino A
/// @param set_target_b Conjunto de destino B
/// @param size_set_target_b Tamanho do conjunto de destino B
/// @param dist Vetor de distâncias alocado com tamanho igual ao número de vértices do grafo
/// @param heap Heap alocado com tamanho igual ao número de vértices do grafo
/// @return Matriz de distâncias
DistanceMatrix *distance_matrix_create(Graph *graph, int *set_source, int size_set_source, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, double *dist, MinHeap *heap);

/// @brief Liberar a memória alocada pela matriz de distâncias
/// @param distance_matrix 
void distance_matrix_destroy(DistanceMatrix *distance_matrix);

/// @brief Pegar a distância entre o vértice de origem e o vértice de destino
/// @param distance_matrix Matriz de distâncias
/// @param source Id do vértice de origem
/// @param target Id do vértice de destino
/// @return Distância entre o vértice de origem e o vértice de destino
double distance_matrix_get_distance(DistanceMatrix *distance_matrix, int source, int target);


#endif // _DISTANCE_MATRIX_H_