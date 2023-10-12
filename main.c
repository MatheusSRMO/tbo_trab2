#include <stdio.h>
#include "src/min_heap/min_heap.h"
#include "src/graph/graph.h"
#include "src/item.h"
#include "src/dijkstra/dijkstra.h"
#include "src/round_trip_time/round_trip_time.h"
#include "src/file_handler/file_handler.h"
#include "src/round_trip_time/round_trip_time.h"

typedef struct {
    int a;
    int b;
    double ratio;
} Ratio;

int ratio_compare(const void *a, const void *b) {
    Ratio *ra = (Ratio *) a;
    Ratio *rb = (Ratio *) b;
    if(ra->ratio < rb->ratio) {
        return -1;
    } else if(ra->ratio > rb->ratio) {
        return 1;
    } else {
        return 0;
    }
}

void show_sets(int *s, int size_s, int *c, int size_c, int *m, int size_m) {
    printf("S: ");
    for(int i = 0; i < size_s; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    printf("C: ");
    for(int i = 0; i < size_c; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("M: ");
    for(int i = 0; i < size_m; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");
}


int main() {
    int *s = NULL;
    int *c = NULL;
    int *m = NULL;
    int size_s, size_c, size_m;
    Graph *graph = file_handler_read_file("data/in/N10000_S50_C300_M10.txt", &s, &size_s, &c, &size_c, &m, &size_m);


    MinHeap *heap = min_heap_create(graph_get_V(graph));
    double *dist = (double *) malloc(sizeof(double) * graph_get_V(graph));
    RoundTripTime *rtt = round_trip_time_init(graph, s, c, m, size_s, size_c, size_m, dist, heap);
    Ratio *ratios = (Ratio *) malloc(sizeof(Ratio) * size_s * size_c);


    for(int i = 0; i < size_s; i++) {
        for(int j = 0; j < size_c; j++) {
            double rtt_sc = round_trip_time_sc(rtt, s[i], c[j]);
            double rtt_sm = round_trip_time_star(rtt, s[i], c[j], m, size_m);

            ratios[i * size_c + j].a = s[i];
            ratios[i * size_c + j].b = c[j];
            ratios[i * size_c + j].ratio = rtt_sm / rtt_sc;
        }
    }


    qsort(ratios, size_s * size_c, sizeof(Ratio), ratio_compare);

    for(int i = 0; i < size_s * size_c; i++) {
        printf("%d\t%d\t%lf\n", ratios[i].a, ratios[i].b, ratios[i].ratio);
    }

    round_trip_time_free(rtt);
    /* LABORATORIO MALUCO*/
    free(ratios);
    min_heap_destroy(heap);
    free(dist);
    graph_destroy(graph);
    free(s); free(c); free(m);
    return 0;
}
