#include "round_trip_time.h"

int get_index(int v, int *vertices, int size) {
    for(int i = 0; i < size; i++) {
        if(vertices[i] == v) {
            return i;
        }
    }
    return -1;
}


RoundTripTime* round_trip_time_init(Graph* graph, int *s, int *c, int *m, int size_s, int size_c, int size_m, double *dist, MinHeap *heap) {
    RoundTripTime *rtt = (RoundTripTime*) malloc(sizeof(RoundTripTime));

    rtt->s = distance_matrix_create(graph, s, size_s, c, size_c, m, size_m, dist, heap);
    rtt->c = distance_matrix_create(graph, c, size_c, s, size_s, m, size_m, dist, heap);
    rtt->m = distance_matrix_create(graph, m, size_m, s, size_s, c, size_c, dist, heap);

    rtt->s_set = s;
    rtt->c_set = c;
    rtt->m_set = m;

    rtt->size_s = size_s;
    rtt->size_c = size_c;
    rtt->size_m = size_m;

    return rtt;
}

void round_trip_time_free(RoundTripTime *rtt) {
    distance_matrix_destroy(rtt->s);
    distance_matrix_destroy(rtt->c);
    distance_matrix_destroy(rtt->m);
    free(rtt);
}


double round_trip_time_sc(RoundTripTime *rtt, int u, int v) {
    int index_u = get_index(u, rtt->s_set, rtt->size_s);
    
    // Se u não está em S, troca u por v
    if(index_u == -1) {
        // troca as duas variáveis sem precisar de uma terceira
        u = u + v;
        v = u - v;
        u = u - v;
    }

    double weight_a = distance_matrix_get_distance(rtt->s, u, v);
    double weight_b = distance_matrix_get_distance(rtt->c, v, u);
    return weight_a + weight_b;
}


double round_trip_time_sm(RoundTripTime *rtt, int u, int v) {
    int index_u = get_index(u, rtt->s_set, rtt->size_s);
    
    // Se u não está em S, troca u por v
    if(index_u == -1) {
        // troca as duas variáveis sem precisar de uma terceira
        u = u + v;
        v = u - v;
        u = u - v;
    }

    double weight_a = distance_matrix_get_distance(rtt->s, u, v);
    double weight_b = distance_matrix_get_distance(rtt->m, v, u);
    return weight_a + weight_b;
}

double round_trip_time_cm(RoundTripTime *rtt, int u, int v) {
    int index_u = get_index(u, rtt->c_set, rtt->size_c);
    
    // Se u não está em S, troca u por v
    if(index_u == -1) {
        // troca as duas variáveis sem precisar de uma terceira
        u = u + v;
        v = u - v;
        u = u - v;
    }

    double weight_a = distance_matrix_get_distance(rtt->c, u, v);
    double weight_b = distance_matrix_get_distance(rtt->m, v, u);
    return weight_a + weight_b;
}


double round_trip_time_star(RoundTripTime *rtt, int a, int b, int *m, int size_m) {
    double best = INT_MAX;
    for(int i = 0; i < size_m; i++) {
        double weight = round_trip_time_sm(rtt, a, m[i]) + round_trip_time_cm(rtt, m[i], b);
        if(weight < best) {
            best = weight;
        }
    }
    return best;
}
