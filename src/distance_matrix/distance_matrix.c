#include "distance_matrix.h"

// Complexidade: O(|SetSource| * (|V| + |E|log|V|))
DistanceMatrix *distance_matrix_create(Graph *graph, int *set_source, int size_set_source, int *set_target_a, int size_set_target_a, int *set_target_b, int size_set_target_b, double *dist, MinHeap *heap) {
    // Aloca a estrutura de dados
    DistanceMatrix *distance_matrix = (DistanceMatrix *) malloc(sizeof(DistanceMatrix));

    // Armazena os tamanhos dos conjuntos
    distance_matrix->size_set_source = size_set_source;
    distance_matrix->size_set_target_a = size_set_target_a;
    distance_matrix->size_set_target_b = size_set_target_b;

    // Aloca os vetores de mapeamento, com tamanho igual ao número de vértices do grafo, para mapear os ids dos vértices para as linhas e colunas da matriz (sabendo que os ids dos vértices são sequenciais onde vão de 0 até |V|-1)
    distance_matrix->line_map = (int *) malloc(sizeof(int) * graph_get_V(graph));
    distance_matrix->column_map = (int *) malloc(sizeof(int) * graph_get_V(graph));

    // Aloca a matriz de distâncias
    distance_matrix->matrix = (double **) malloc(sizeof(double *) * size_set_source);
    
    // Para cada linha da matriz, executa o algoritmo de Dijkstra e armazena as distâncias na linha correspondente
    for (int i = 0; i < size_set_source; i++) {
        // Aloca a linha da matriz
        distance_matrix->matrix[i] = (double *) malloc(sizeof(double) * (size_set_target_a + size_set_target_b));

        // Mapeia o id do vértice de origem para a linha correspondente na matriz
        int source = set_source[i];
        distance_matrix->line_map[source] = i;
        
        // Executa o algoritmo de Dijkstra para cada vértice de origem, armazenando os dados na linha correspondente de source
        dijkstra_line(graph, source, distance_matrix->matrix[i], set_target_a, size_set_target_a, set_target_b, size_set_target_b, distance_matrix->column_map, dist, heap);
    }

    // Retorna a estrutura de dados com todas as distancias calculadas do conjunto de origem para os conjuntos de destino
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

// Dada a matriz que relaciona as distancias de um conjunto de origem para um conjunto de destino, retorna a distancia entre dois vértices. 
// Complexidade: O(1)
// source = id do vértice de origem
// target = id do vértice de destino
// Restrição: source deve pertencer ao conjunto de origem e target deve pertencer ao conjunto de destino
double distance_matrix_get_distance(DistanceMatrix *distance_matrix, int source, int target) {
    int line = distance_matrix->line_map[source];
    int column = distance_matrix->column_map[target];
    return distance_matrix->matrix[line][column];
}

