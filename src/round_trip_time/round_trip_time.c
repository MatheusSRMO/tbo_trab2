#include "round_trip_time.h"

// RTT(a, b) = D(a, b) + D(b, a)
// Complexity: O(V + ElogV)
int round_trip_time(Graph* graph, int u, int v, int *dist, MinHeap *heap) {
    int weight_a = dijkstra(graph, u, v, dist, heap); // Complexity: O(V + ElogV)
    int weight_b = dijkstra(graph, v, u, dist, heap); // Complexity: O(V + ElogV)
    return weight_a + weight_b;
}

/*
RTT∗ (a, b) = min(RTT(a, m) + RTT(m, b)) | m∈M

RTT∗ (0, 4) = min{RTT(0, 1) + RTT(1, 4), RTT(0, 2) + RTT(2, 4)}
            = min{20 + 20, 19 + 10}
            = min{40, 29}
            = 29.

*/
int round_trip_time_star(Graph* graph, int a, int b, int *m, int size_m, int *dist, MinHeap *heap) {
    int min = INT_MAX;

    for(int k = 0; k < size_m; k++) {
        int _m = m[k];
        int weight = round_trip_time(graph, a, _m, dist, heap) + round_trip_time(graph, _m, b, dist, heap);
        printf("RTT(%d, %d) + RTT(%d, %d) = %d\n", a, _m, _m, b, weight);
        if(weight < min) {
            min = weight;
        }
    }

    return min;
}