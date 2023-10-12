#ifndef _ROUND_TRIP_TIME_H_
#define _ROUND_TRIP_TIME_H_

#include "../graph/graph.h"
#include "../dijkstra/dijkstra.h"
#include "../distance_matrix/distance_matrix.h"
#include "../utils/utils.h"


typedef struct {
    DistanceMatrix *s; // a = c; b = m    Size: |S| x |C + M| * 8 bytes
    DistanceMatrix *c; // a = s; b = m    Size: |C| x |S + M| * 8 bytes
    DistanceMatrix *m; // a = s; b = c    Size: |M| x |S + C| * 8 bytes

    int *s_set; // Conjunto de Servidores
    int *c_set; // Conjunto de Clientes
    int *m_set; // Conjunto de Monitores

    int size_s; // Tamanho do conjunto de Servidores
    int size_c; // Tamanho do conjunto de Clientes
    int size_m; // Tamanho do conjunto de Monitores
} RoundTripTime;


/// @brief Inicializa a estrutura de dados RoundTripTime
/// @param graph Grafo
/// @param s Conjunto S
/// @param c Conjunto C
/// @param m Conjunto M
/// @param size_s Tamanho do conjunto S
/// @param size_c Tamanho do conjunto C
/// @param size_m Tamanho do conjunto M
/// @param dist Vetor de distâncias alocado com tamanho igual ao número de vértices do grafo
/// @param heap Heap alocado com tamanho igual ao número de vértices do grafo
/// @return Estrutura de dados RoundTripTime
RoundTripTime* round_trip_time_init(Graph* graph, int *s, int *c, int *m, int size_s, int size_c, int size_m, double *dist, MinHeap *heap);

/// @brief Libera a memória alocada pela estrutura de dados RoundTripTime
/// @param rtt Estrutura de dados RoundTripTime
void round_trip_time_free(RoundTripTime *rtt);

/// @brief Calcula o tempo de ida e volta entre dois vértices
/// @param rtt Estrutura de dados RoundTripTime
/// @param u Id do primeiro vértice em S
/// @param v Id do segundo vértice em C
/// @return Valor do tempo de ida e volta entre os vértices
double round_trip_time_sc(RoundTripTime *rtt, int u, int v);

/// @brief Calcula o tempo de ida e volta entre dois vértices
/// @param rtt Estrutura de dados RoundTripTime
/// @param a Id do primeiro vértice
/// @param b Id do primeiro vértice
/// @param m Conjunto de monitores
/// @param size_m Tamanho do conjunto de monitores
/// @return RTT aproximado entre os vértices
double round_trip_time_star(RoundTripTime *rtt, int a, int b, int *m, int size_m);

#endif // _ROUND_TRIP_TIME_H_