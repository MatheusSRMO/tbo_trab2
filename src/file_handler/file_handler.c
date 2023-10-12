#include "file_handler.h"

/*
Format file:
Todas as informac¸oes ser ˜ ao dadas em um arquivo de entrada. Este arquivo vai conter uma descric¸ ˜ ao de todos os ˜
nos, arestas, pesos e conjuntos ´ S, C e M.
A primeira linha do arquivo tera´ |V | e |E|. A segunda linha do arquivo tera os valores de ´ |S|, |C| e |M|. Apos´
isso:
1. as proximas ´ |S| linhas indicam os nos que s ´ ao servidores; ˜
2. as proximas ´ |C| linhas indicam os nos que s ´ ao clientes; ˜
3. as proximas ´ |M| linhas indicam os nos que s ´ ao monitores; ˜
4. cada uma das proximas ´ |E| linhas tera tr ´ es valores, ˆ x, y e z, indicando que ha uma aresta de ´ x para y e que
z e o valor de ´ ω(x, y).
A seguir, o conteudo do arquivo relativo ao exemplo da Figura 1, assumindo que ´ S = {0}, C = {4} e M = {1, 2}.
5 9
1 1 2
0
4
1
2
0 1 10.0
0 3 5.0
1 3 2.0
3 1 3.0
1 2 1.0
3 2 3.0
2 4 4.0
4 2 6.0
4 0 7.0

*/

Graph *file_handler_read_file(char *file_name, int **s, int *size_s, int **c, int *size_c, int **m, int *size_m) {
    int v, e;
    int _s, _c, _m;

    FILE *file = fopen(file_name, "r");

    if(file == NULL) {
        printf("Erro: arquivo não encontrado\n");
        exit(1);
    }

    fscanf(file, "%d %d", &v, &e);
    fscanf(file, "%d %d %d", &_s, &_c, &_m);

    *size_s = _s;
    *size_c = _c;
    *size_m = _m;

    *s = (int *) malloc(sizeof(int) * _s);
    *c = (int *) malloc(sizeof(int) * _c);
    *m = (int *) malloc(sizeof(int) * _m);

    for(int i = 0; i < _s; i++) {
        fscanf(file, "%d", &(*s)[i]);
    }

    for(int i = 0; i < _c; i++) {
        fscanf(file, "%d", &(*c)[i]);
    }

    for(int i = 0; i < _m; i++) {
        fscanf(file, "%d", &(*m)[i]);
    }

    Graph *graph = graph_create(v, adj_list, directed);
    for(int i = 0; i < e; i++) {
        int x, y;
        double z;
        fscanf(file, "%d %d %lf", &x, &y, &z);
        graph_add_edge(graph, x, y, z);
    }

    fclose(file);
    return graph;
}
