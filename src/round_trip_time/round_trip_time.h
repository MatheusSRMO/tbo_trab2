#ifndef _ROUND_TRIP_TIME_H_
#define _ROUND_TRIP_TIME_H_

#include "../graph/graph.h"
#include "../dijkstra/dijkstra.h"

int round_trip_time(Graph* graph, int u, int v, int *dist, MinHeap *heap);

int round_trip_time_star(Graph* graph, int a, int b, int *m, int size_m, int *dist, MinHeap *heap);

#endif // _ROUND_TRIP_TIME_H_