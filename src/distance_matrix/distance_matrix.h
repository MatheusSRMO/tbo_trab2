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


DistanceMatrix *distance_matrix_create(Graph *graph, int *set_source, int size_set_source, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, double *dist, MinHeap *heap);

void distance_matrix_print(DistanceMatrix *distance_matrix);

void distance_matrix_destroy(DistanceMatrix *distance_matrix);

double distance_matrix_get_distance(DistanceMatrix *distance_matrix, int source, int target);


#endif // _DISTANCE_MATRIX_H_