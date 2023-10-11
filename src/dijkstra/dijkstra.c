#include "dijkstra.h"

// Dijkstra's algorithm.
// Complexity: O(V + ElogV)
int dijkstra(Graph *graph, int source, int target, int *dist, MinHeap *heap) {
    // Initialize the dist vector with INT_MAX.
    for (int i = 0; i < graph_get_V(graph); i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Clear the min heap.
    min_heap_clear(heap);

    // Insert all vertices into the min heap.
    for (int i = 0; i < graph_get_V(graph); i++) {
        min_heap_insert(heap, make_item(i, dist[i]));
    }

    while (!min_heap_is_empty(heap)) {
        Item item = min_heap_remove(heap);
        int u = id(item);

        // Verify if we found the target.
        if (u == target) {
            break; // Stop the loop if the target is found.
        }

        Node *node = graph_get_adjacency_list(graph, u);
        while (!node_is_null(node)) {
            int v = node_get_target(node);
            if (dist[v] > dist[u] + node_get_weight(node)) {
                dist[v] = dist[u] + node_get_weight(node);
                min_heap_decrease_key(heap, v, dist[v]);
            }
            node = node_get_next(node);
        }
    }

    int weight = dist[target];

    return weight; // Return the weight of the path.
}


int dijkstra_path(Graph *graph, int source, int target, int *path, int *size) {
    int *dist = (int *) malloc(sizeof(int) * graph_get_V(graph));
    int *prev = (int *) malloc(sizeof(int) * graph_get_V(graph));
    for (int i = 0; i < graph_get_V(graph); i++) {
        dist[i] = INT_MAX;
        prev[i] = -1; // Initializes the previous node vector with -1.
    }
    dist[source] = 0;

    MinHeap *heap = min_heap_create(graph_get_V(graph));
    for (int i = 0; i < graph_get_V(graph); i++) {
        min_heap_insert(heap, make_item(i, dist[i]));
    }

    while (!min_heap_is_empty(heap)) {
        Item item = min_heap_remove(heap);
        int u = id(item);

        // Verifica se encontramos o alvo
        if (u == target) {
            break; // Encerra o loop se o alvo for encontrado
        }

        Node *node = graph_get_adjacency_list(graph, u);
        while (!node_is_null(node)) {
            int v = node_get_target(node);
            if (dist[v] > dist[u] + node_get_weight(node)) {
                dist[v] = dist[u] + node_get_weight(node);
                prev[v] = u;
                min_heap_decrease_key(heap, v, dist[v]);
            }
            node = node_get_next(node);
        }
    }

    min_heap_destroy(heap);

    // Now let's build the path array from target to source.
    int *path_array = (int *) malloc(sizeof(int) * graph_get_V(graph));
    int index = target;
    int path_size = 0;

    while (index != source) {
        path_array[path_size++] = index;
        index = prev[index];
    }

    path_array[path_size++] = source;

    // Reverses the path array to be in the correct order (from source to target).
    for (int i = 0; i < path_size; i++) {
        path[i] = path_array[path_size - i - 1];
    }

    int weight = dist[target];

    free(dist);
    free(prev);
    free(path_array);
    *size = path_size;
    return weight; // Retorna o peso do caminho.
}

