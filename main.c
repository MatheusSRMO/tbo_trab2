#include <stdio.h>
#include "src/min_heap/min_heap.h"
#include "src/graph/graph.h"
#include "src/item.h"
#include "src/dijkstra/dijkstra.h"
#include "src/round_trip_time/round_trip_time.h"

int main() {
    Graph *graph = graph_create(5, adj_list, directed);

    // um exemplo de grafo direcionado (Especificação)
    graph_add_edge(graph, 0, 1, 10);
    graph_add_edge(graph, 0, 3, 5);
    graph_add_edge(graph, 1, 2, 1);
    graph_add_edge(graph, 1, 3, 2);
    graph_add_edge(graph, 2, 4, 4);
    graph_add_edge(graph, 3, 1, 3);
    graph_add_edge(graph, 3, 2, 3);
    graph_add_edge(graph, 4, 2, 6);
    graph_add_edge(graph, 4, 0, 7);

    // graph_print(graph);
    
    MinHeap *heap = min_heap_create(graph_get_V(graph));
    int *dist = (int *) malloc(sizeof(int) * graph_get_V(graph));


    int rtt_star = round_trip_time_star(graph, 0, 4, (int[]){1, 2}, 2, dist, heap);
    printf("round_trip_time_star(0, 4) = %d\n", rtt_star);


    min_heap_destroy(heap);
    free(dist);
    graph_destroy(graph);
    return 0;
}
