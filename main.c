#include <stdio.h>
#include "src/min_heap/min_heap.h"
#include "src/graph/graph.h"
#include "src/item.h"
#include "src/dijkstra/dijkstra.h"

int main() {
    MinHeap *heap = min_heap_create(10);
    
    // inserindo alguns elementos na PQ
    min_heap_insert(heap, make_item(1, 10.0));
    min_heap_insert(heap, make_item(6, 5.0));
    min_heap_insert(heap, make_item(3, 3.0));
    min_heap_insert(heap, make_item(4, 4.0));
    min_heap_insert(heap, make_item(7, 7.0));
    min_heap_insert(heap, make_item(2, 1.0));

    // alterando a prioridade de alguns elementos
    min_heap_decrease_key(heap, 4, 0.5); // agora o nó 4 tem valor 0.5, sua posição no heap deve mudar
    min_heap_decrease_key(heap, 6, 0.1); // agora o nó 6 tem valor 0.1, sua posição no heap deve mudar

    min_heap_write_dot(heap, "heap.dot");

    min_heap_destroy(heap);


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

    graph_print(graph);
    

    int weight;

    weight = dijkstra(graph, 0, 4);

    printf("weight: %d\n", weight);


    // graph_write_dot(graph, "graph.dot", path, size);

    graph_destroy(graph);

    return 0;
}
