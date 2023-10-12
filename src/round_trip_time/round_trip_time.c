#include "round_trip_time.h"

RoundTripTime* round_trip_time_init(Graph* graph, int *s, int *c, int *m, int size_s, int size_c, int size_m, double *dist, MinHeap *heap) {
    RoundTripTime *rtt = (RoundTripTime*) malloc(sizeof(RoundTripTime));

    // Cria as matrizes de distâncias (calcula todas as distancias dos vértices de origem S para os vértices de destino C e M)
    rtt->s = distance_matrix_create(graph, s, size_s, c, size_c, m, size_m, dist, heap);

    // Cria as matrizes de distâncias (calcula todas as distancias dos vértices de origem C para os vértices de destino S e M)
    rtt->c = distance_matrix_create(graph, c, size_c, s, size_s, m, size_m, dist, heap);

    // Cria as matrizes de distâncias (calcula todas as distancias dos vértices de origem M para os vértices de destino S e C)
    rtt->m = distance_matrix_create(graph, m, size_m, s, size_s, c, size_c, dist, heap);

    rtt->s_set = s; // Conjunto de Servidores
    rtt->c_set = c; // Conjunto de Clientes
    rtt->m_set = m; // Conjunto de Monitores

    rtt->size_s = size_s; // Tamanho do conjunto de Servidores
    rtt->size_c = size_c; // Tamanho do conjunto de Clientes
    rtt->size_m = size_m; // Tamanho do conjunto de Monitores

    return rtt;
}

void round_trip_time_free(RoundTripTime *rtt) {
    distance_matrix_destroy(rtt->s);
    distance_matrix_destroy(rtt->c);
    distance_matrix_destroy(rtt->m);
    free(rtt);
}


double round_trip_time_sc(RoundTripTime *rtt, int u, int v) {
    int index_u = get_index_binary(u, rtt->s_set, rtt->size_s);
    
    // Se u não está em S, troca u por v
    if(index_u == -1) {
        // troca as duas variáveis
        u = u + v;
        v = u - v;
        u = u - v;
    }

    double weight_a = distance_matrix_get_distance(rtt->s, u, v);
    double weight_b = distance_matrix_get_distance(rtt->c, v, u);
    return weight_a + weight_b;
}

// Calcula o tempo de ida e volta entre um servidor e um monitor
double round_trip_time_sm(RoundTripTime *rtt, int u, int v) {
    int index_u = get_index_binary(u, rtt->s_set, rtt->size_s);
    
    // Se u não está em S, troca u por v
    if(index_u == -1) {
        // troca as duas variáveis
        u = u + v;
        v = u - v;
        u = u - v;
    }

    double weight_a = distance_matrix_get_distance(rtt->s, u, v);
    double weight_b = distance_matrix_get_distance(rtt->m, v, u);
    return weight_a + weight_b;
}

// Calcula o tempo de ida e volta entre um cliente e um monitor
double round_trip_time_cm(RoundTripTime *rtt, int u, int v) {
    int index_u = get_index_binary(u, rtt->c_set, rtt->size_c);
    
    // Se u não está em S, troca u por v
    if(index_u == -1) {
        // troca as duas variáveis
        u = u + v;
        v = u - v;
        u = u - v;
    }

    double weight_a = distance_matrix_get_distance(rtt->c, u, v);
    double weight_b = distance_matrix_get_distance(rtt->m, v, u);
    return weight_a + weight_b;
}


double round_trip_time_star(RoundTripTime *rtt, int a, int b, int *m, int size_m) {
    // Initializa o melhor peso com o maior inteiro possível
    double best = INT_MAX;
    // Para cada monitor
    for(int i = 0; i < size_m; i++) {
        // Calcula o tempo de ida e volta entre o servidor e o monitor e entre o cliente e o monitor
        double weight = round_trip_time_sm(rtt, a, m[i]) + round_trip_time_cm(rtt, m[i], b);
        
        // Se o peso calculado for menor que o melhor peso, atualiza o melhor peso
        if(weight < best) {
            best = weight;
        }
    }
    // Retorna o melhor peso
    return best;
}
