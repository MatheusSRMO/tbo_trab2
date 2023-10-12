#include "file_handler.h"

/*
Format file:
Todas as informações serão dadas em um arquivo de entrada. Este arquivo vai conter uma descricção de todos os nós, arestas, pesos e conjuntos  S, C e M.
A primeira linha do arquivo terá |V | e |E|. A segunda linha do arquivo tera os valores de |S|, |C| e |M|. Apos isso:
1. as proximas |S| linhas indicam os nos que são servidores;
2. as proximas |C| linhas indicam os nos que são clientes;
3. as proximas |M| linhas indicam os nos que são monitores;
4. cada uma das proximas |E| linhas tera trés valores, x, y e z, indicando que ha uma aresta de x para y e que z e o valor de ω(x, y).
A seguir, o conteudo do arquivo relativo ao exemplo da Figura 1, assumindo que S = {0}, C = {4} e M = {1, 2}.
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
    // Inicializa os vetores
    int v, e;
    int _s, _c, _m;

    // Abre o arquivo
    FILE *file = fopen(file_name, "r");

    // Verifica se o arquivo foi aberto corretamente
    if(file == NULL) {
        printf("Erro: arquivo não encontrado\n");
        exit(1);
    }

    // Lê os valores de |V| e |E|
    fscanf(file, "%d %d", &v, &e);

    // Lê os valores de |S|, |C| e |M|
    fscanf(file, "%d %d %d", &_s, &_c, &_m);

    // Armazena os tamanhos dos conjuntos
    *size_s = _s;
    *size_c = _c;
    *size_m = _m;

    // Aloca os conjuntos
    *s = (int *) malloc(sizeof(int) * _s);
    *c = (int *) malloc(sizeof(int) * _c);
    *m = (int *) malloc(sizeof(int) * _m);

    // Lê os valores dos conjuntos
    for(int i = 0; i < _s; i++) {
        fscanf(file, "%d", &(*s)[i]);
    }

    for(int i = 0; i < _c; i++) {
        fscanf(file, "%d", &(*c)[i]);
    }

    for(int i = 0; i < _m; i++) {
        fscanf(file, "%d", &(*m)[i]);
    }

    // Cria o grafo
    Graph *graph = graph_create(v, adj_list, directed);
    
    // Lê as arestas
    for(int i = 0; i < e; i++) {
        int x, y;
        double z;
        fscanf(file, "%d %d %lf", &x, &y, &z);
        graph_add_edge(graph, x, y, z);
    }

    fclose(file);
    return graph;
}

void file_handler_write_file(char *file_name, Ratio *ratios, int size) {
    FILE *file = fopen(file_name, "w");
    for(int i = 0; i < size; i++) {
        fprintf(file, "%d %d %.16lf\n", ratios[i].a, ratios[i].b, ratios[i].ratio);
    }
    fclose(file);
}
