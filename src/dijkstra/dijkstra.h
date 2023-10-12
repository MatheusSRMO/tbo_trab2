#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../graph/graph.h"
#include "../min_heap/min_heap.h"
#include "../item.h"


double dijkstra(Graph *graph, int source, int target, double *dist, MinHeap *heap);

int dijkstra_path(Graph *graph, int source, int target, int *path, int *size);

void dijkstra_line(Graph *graph, int source, double *line, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, int *map, double *dist, MinHeap *heap);

#endif // _DIJKSTRA_H_