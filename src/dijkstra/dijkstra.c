#include "dijkstra.h"

int is_in(int v, int *vertices, int size) {    
    for(int i = 0; i < size; i++) {        
        if(vertices[i] == v) {            
            return i;
        }
    }    
    return -1;
}

void print_vector(int *vector, int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", vector[i]);
        if(i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("\n");
}

// Função dijkstra que retorna a linha, dada um s e um conjunto C
void dijkstra_line(Graph *graph, int source, double *line, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, int *map, double *dist, MinHeap *heap) {
    // Inicializa o vetor de distâncias com infinito
    for (int i = 0; i < graph_get_V(graph); i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Limpa a min heap (Pois a mesma é usada em todas as iterações do algoritmo)
    min_heap_clear(heap);

    // Insere todos os vértices dentro da min heap.
    for (int i = 0; i < graph_get_V(graph); i++) {
        min_heap_insert(heap, make_item(i, dist[i]));
    }

    while (!min_heap_is_empty(heap)) {
        Item item = min_heap_remove(heap);
        int u = id(item);

        // Verifica se o vértice u está no conjunto A
        int index = is_in(u, set_target_a, size_set_target_a);
        if (index != -1) {
            // Se estiver, armazena a distância na linha correspondente
            line[index] = dist[u];
            // Mapa para relacionar o id do vértice com a coluna correspondente na matriz
            map[u] = index;
        }

        // Verifica se o vértice u está no conjunto B
        int _index = is_in(u, set_target_b, size_set_target_b);
        if (_index != -1) {
            // Calcula o índice da coluna correspondente na matriz, sabendo que o conjunto B vem depois do conjunto A
            int target = _index + size_set_target_a;
            // Se estiver, armazena a distância na linha correspondente
            line[target] = dist[u];
            // Mapa para relacionar o id do vértice com a coluna correspondente na matriz
            map[u] = target;
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
}

