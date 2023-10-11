#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../graph/graph.h"
#include "../min_heap/min_heap.h"
#include "../item.h"


int dijkstra(Graph *graph, int source, int target, int *dist, MinHeap *heap);

int dijkstra_path(Graph *graph, int source, int target, int *path, int *size);

#endif // _DIJKSTRA_H_