#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../graph/graph.h"
#include "../min_heap/min_heap.h"
#include "../item.h"
#include "../utils/utils.h"


/// @brief Calcula a distancia de um vértice de origem para todos os outros vértices do grafo e armazena na linha correspondente
/// @param graph Grafo
/// @param source Id do vértice de origem (ordenado)
/// @param line Vetor de distâncias alocado com tamanho igual ao tamanho da soma dos conjuntos de destino
/// @param set_target_a Conjunto de destino A (ordenado)
/// @param size_set_target_a Tamanho do conjunto de destino A
/// @param set_target_b Conjunto de destino B (ordenado)
/// @param size_set_target_b Tamnho do conjunto de destino B
/// @param map Vetor de mapeamento alocado com tamanho igual ao número de vértices do grafo
/// @param dist Vetor de distâncias alocado com tamanho igual ao número de vértices do grafo
/// @param heap Heap alocado com tamanho igual ao número de vértices do grafo
void dijkstra_line(Graph *graph, int source, double *line, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, int *map, double *dist, MinHeap *heap);

#endif // _DIJKSTRA_H_