#include "distance_matrix.h"


DistanceMatrix *distance_matrix_create(Graph *graph, int *set_source, int size_set_source, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, double *dist, MinHeap *heap) {
    DistanceMatrix *distance_matrix = (DistanceMatrix *) malloc(sizeof(DistanceMatrix));

    distance_matrix->size_set_source = size_set_source;
    distance_matrix->size_set_target_a = size_set_target_a;
    distance_matrix->size_set_target_b = size_set_target_b;

    distance_matrix->line_map = (int *) malloc(sizeof(int) * graph_get_V(graph));
    distance_matrix->column_map = (int *) malloc(sizeof(int) * graph_get_V(graph));

    distance_matrix->matrix = (double **) malloc(sizeof(double *) * size_set_source);
    for (int i = 0; i < size_set_source; i++) {
        distance_matrix->matrix[i] = (double *) malloc(sizeof(double) * (size_set_target_a + size_set_target_b));

        int source = set_source[i];
        distance_matrix->line_map[source] = i;
        // printf("source: %d, line: %d\n", source, i);
        
        dijkstra_line(graph, source, distance_matrix->matrix[i], set_target_a, size_set_target_a, set_target_b, size_set_target_b, distance_matrix->column_map, dist, heap);
    }

    return distance_matrix;
}

// void distance_matrix_print(DistanceMatrix *distance_matrix);

void distance_matrix_destroy(DistanceMatrix *distance_matrix) {
    for (int i = 0; i < distance_matrix->size_set_source; i++) {
        free(distance_matrix->matrix[i]);
    }
    free(distance_matrix->matrix);
    free(distance_matrix->line_map);
    free(distance_matrix->column_map);
    free(distance_matrix);
}

double distance_matrix_get_distance(DistanceMatrix *distance_matrix, int source, int target) {
    int line = distance_matrix->line_map[source];
    int column = distance_matrix->column_map[target];
    return distance_matrix->matrix[line][column];
}

