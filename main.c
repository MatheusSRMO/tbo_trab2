#include <stdio.h>
#include "src/min_heap/min_heap.h"
#include "src/graph/graph.h"
#include "src/item.h"
#include "src/dijkstra/dijkstra.h"
#include "src/round_trip_time/round_trip_time.h"
#include "src/file_handler/file_handler.h"

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



int main() {
    int *s = NULL;
    int *c = NULL;
    int *m = NULL;
    int size_s, size_c, size_m;
    Graph *graph = file_handler_read_file("data/in/N10000_S50_C300_M10.txt", &s, &size_s, &c, &size_c, &m, &size_m);
    MinHeap *heap = min_heap_create(graph_get_V(graph));
    double *dist = (double *) malloc(sizeof(double) * graph_get_V(graph));


    Ratio *ratios = (Ratio *) malloc(sizeof(Ratio) * size_s * size_c);
    int index = 0;
    for(int i = 0; i < size_s; i++) {
        int a = s[i];
        for(int j = 0; j < size_c; j++) {
            int b = c[j];
            double rtt_star = round_trip_time_star(graph, a, b, m, size_m, dist, heap);
            double rtt = round_trip_time(graph, a, b, dist, heap);
            
            double ratio = rtt_star / rtt;
            // printf("%d\t%d\t%lf\n", a, b, ratio);
            ratios[index].a = a;
            ratios[index].b = b;
            ratios[index].ratio = ratio;
            index++;
        }
    }

    qsort(ratios, index, sizeof(Ratio), ratio_compare);

    for(int i = 0; i < index; i++) {
        printf("%d\t%d\t%lf\n", ratios[i].a, ratios[i].b, ratios[i].ratio);
    }


    free(ratios);    
    min_heap_destroy(heap);
    free(dist);
    graph_destroy(graph);
    free(s); free(c); free(m);
    return 0;
}
