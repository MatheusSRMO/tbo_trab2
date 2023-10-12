#include <stdio.h>
#include "src/min_heap/min_heap.h"
#include "src/graph/graph.h"
#include "src/item.h"
#include "src/dijkstra/dijkstra.h"
#include "src/round_trip_time/round_trip_time.h"
#include "src/file_handler/file_handler.h"
#include "src/round_trip_time/round_trip_time.h"
#include "src/utils/utils.h"


int main(int argc, char const *argv[]) {
    // Verifica se os argumentos foram passados corretamente
    if(argc < 3) {
        printf("Usage: %s <file_path_in> <file_path_out>\n", argv[0]);
        return 1;
    }


    // Pega os caminhos dos arquivos de entrada e saída
    char *file_path_in = (char *) argv[1];
    char *file_path_out = (char *) argv[2];


    // Vetores para armazenar os conjuntos S, C e M e seus respectivos tamanhos
    int *s = NULL, *c = NULL, *m = NULL;
    int size_s, size_c, size_m;


    // Lê o arquivo, armazenando os conjuntos S, C e M e retornando o grafo
    Graph *graph = file_handler_read_file(file_path_in, &s, &size_s, &c, &size_c, &m, &size_m);


    // Ordena os conjuntos S, C e M (para facilitar a busca binária)
    qsort(s, size_s, sizeof(int), int_compare);
    qsort(c, size_c, sizeof(int), int_compare);
    qsort(m, size_m, sizeof(int), int_compare);


    // Cria a Min Heap que será usada no algoritmo de Dijkstra
    MinHeap *heap = min_heap_create(graph_get_V(graph));


    // Aloca o vetor de distâncias que será usado no algoritmo de Dijkstra
    double *dist = (double *) malloc(sizeof(double) * graph_get_V(graph));


    // Inicializa (e calcula as matrizes de distancias) o Round Trip Time (RTT)
    RoundTripTime *rtt = round_trip_time_init(graph, s, c, m, size_s, size_c, size_m, dist, heap);


    // Estrutura auxiliar para armazenar os valores de S, C e a razão entre os RTTs (para posterior ordenação)
    Ratio *ratios = (Ratio *) malloc(sizeof(Ratio) * size_s * size_c);


    // Calcula os RTTs e armazena na estrutura auxiliar
    for(int i = 0; i < size_s; i++) {
        for(int j = 0; j < size_c; j++) {
            double rtt_sc = round_trip_time_sc(rtt, s[i], c[j]);
            double rtt_sm = round_trip_time_star(rtt, s[i], c[j], m, size_m);

            ratios[i * size_c + j].a = s[i];
            ratios[i * size_c + j].b = c[j];
            ratios[i * size_c + j].ratio = rtt_sm / rtt_sc;
        }
    }


    // Ordena a estrutura auxiliar
    qsort(ratios, size_s * size_c, sizeof(Ratio), ratio_compare);


    // Escreve o arquivo de saída
    file_handler_write_file(file_path_out, ratios, size_s * size_c);


    // Libera a memória de todas as estruturas alocadas
    round_trip_time_free(rtt);
    min_heap_destroy(heap);
    graph_destroy(graph);
    free(s); free(c); free(m); free(dist); free(ratios);
    return 0;
}
