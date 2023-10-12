#ifndef _ROUND_TRIP_TIME_H_
#define _ROUND_TRIP_TIME_H_

#include "../graph/graph.h"
#include "../dijkstra/dijkstra.h"
#include "../distance_matrix/distance_matrix.h"


typedef struct {
    DistanceMatrix *s; // a = c; b = m    Size: |S| x |C + M| * 8 bytes
    DistanceMatrix *c; // a = s; b = m    Size: |C| x |S + M| * 8 bytes
    DistanceMatrix *m; // a = s; b = c    Size: |M| x |S + C| * 8 bytes

    int *s_set;
    int *c_set;
    int *m_set;

    int size_s;
    int size_c;
    int size_m;
} RoundTripTime;

RoundTripTime* round_trip_time_init(Graph* graph, int *s, int *c, int *m, int size_s, int size_c, int size_m, double *dist, MinHeap *heap);

void round_trip_time_free(RoundTripTime *rtt);


double round_trip_time_sc(RoundTripTime *rtt, int u, int v);

double round_trip_time_star(RoundTripTime *rtt, int a, int b, int *m, int size_m);



#endif // _ROUND_TRIP_TIME_H_