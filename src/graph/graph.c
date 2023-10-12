#include "graph.h"

void g_swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Grafo não direcionado para lista de adjacência (lista de listas encadeadas) e matriz de adjacência (triangular)
struct graph {
    int V;                      // Número de vértices
    int E;                      // Número de arestas
    double **adjacency_matrix;   // Matriz de adjacência
    Node **adjacency_list;      // Lista de adjacência
    graph_type type;            // Tipo do grafo
    graph_direction direction;  // Se é direcionado ou não
};

// Cria um grafo com V vértices, tipo type e se é direcionado ou não, caso for, a matriz de adjacência não é triangular
Graph *graph_create(int V, graph_type type, graph_direction direction) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->type = type;
    graph->direction = direction;

    // Se for um grafo não direcionado
    if (direction == undirected && type == adj_matrix) {
        // Se for uma matriz de adjacência, aloca uma matriz triangular
        graph->adjacency_matrix = (double **) malloc(sizeof(double *) * V);
        for (int i = 0; i < V; i++) {
            graph->adjacency_matrix[i] = (double *) malloc(sizeof(double) * i);
            for (int j = 0; j < i; j++) {
                graph->adjacency_matrix[i][j] = 0;
            }
        }
        graph->adjacency_list = NULL;
    }
    // Se for um grafo direcionado
    else if (direction == directed && type == adj_matrix) {
        // Se for uma matriz de adjacência, aloca uma matriz quadrada
        graph->adjacency_matrix = (double **) malloc(sizeof(double *) * V);
        for (int i = 0; i < V; i++) {
            graph->adjacency_matrix[i] = (double *) malloc(sizeof(double) * V);
            for (int j = 0; j < V; j++) {
                graph->adjacency_matrix[i][j] = 0;
            }
        }
        graph->adjacency_list = NULL;
    }
    // Se for uma lista de adjacência, não importa se é direcionado ou não
    else {
        graph->adjacency_list = (Node **) malloc(sizeof(Node *) * V);
        for (int i = 0; i < V; i++) {
            graph->adjacency_list[i] = NULL;
        }
        graph->adjacency_matrix = NULL;
    }
    return graph;
}

Node* graph_get_adjacency_list(Graph *graph, int v) {
    return graph->adjacency_list[v];
}

void graph_add_edge(Graph *graph, int v, int w, double weight) {
    // Se for um grafo não direcionado, a matriz de adjacência é triangular
    if (graph->direction == undirected && graph->type == adj_matrix) {
        if(v < w) g_swap(&v, &w);
        // Se a aresta não existir
        if (graph->adjacency_matrix[v][w] == 0) {
            graph->adjacency_matrix[v][w] = weight;
            graph->E++;
        }
    }
    // Se for um grafo direcionado, a matriz de adjacência não é triangular
    else if (graph->direction == directed && graph->type == adj_matrix) {
        // Se a aresta não existir
        if (graph->adjacency_matrix[v][w] == 0) {
            graph->adjacency_matrix[v][w] = weight;
            graph->E++;
        }
    }
    // Se for uma lista de adjacência
    else {
        // Se a aresta não existir
        graph->adjacency_list[v] = node_contruct(w, weight, graph->adjacency_list[v]);
        graph->E++;
    }
}

double graph_get_weight(Graph *graph, int v, int w) {
    // Se for um grafo não direcionado, a matriz de adjacência é triangular
    if (graph->direction == undirected && graph->type == adj_matrix) {
        if(v < w) g_swap(&v, &w);
        return graph->adjacency_matrix[v][w];
    }
    // Se for um grafo direcionado, a matriz de adjacência não é triangular
    else if (graph->direction == directed && graph->type == adj_matrix) {
        return graph->adjacency_matrix[v][w];
    }
    // Se for uma lista de adjacência
    Node *node = graph->adjacency_list[v];
    while (!node_is_null(node)) {
        if (node_get_target(node) == w) {
            return node_get_weight(node);
        }
        node = node_get_next(node);
    }
    return 0;
}

int graph_get_V(Graph *graph) {
    return graph->V;
}

void graph_print(Graph *graph) {
    // Se for um grafo não direcionado, a matriz de adjacência é triangular
    if (graph->direction == undirected && graph->type == adj_matrix) {
        for(int i = 0; i < graph->V; i++) {
            printf("\t%d", i);
        }
        printf("\n");
        for (int i = 0; i < graph->V; i++) {
            printf("%d\t", i);
            for (int j = 0; j < i; j++) {
                printf("%.2f\t", graph->adjacency_matrix[i][j]);
            }
            printf("\n");
        }
    }
    // Se for um grafo direcionado, a matriz de adjacência não é triangular
    else if (graph->direction == directed && graph->type == adj_matrix) {
        for(int i = 0; i < graph->V; i++) {
            printf("\t%d", i);
        }
        printf("\n");
        for (int i = 0; i < graph->V; i++) {
            printf("%d\t", i);
            for (int j = 0; j < graph->V; j++) {
                printf("%.2f\t", graph->adjacency_matrix[i][j]);
            }
            printf("\n");
        }
    }
    // Se for uma lista de adjacência
    else {
        for (int i = 0; i < graph->V; i++) {
            printf("%d: ", i);
            Node *node = graph->adjacency_list[i];
            while (!node_is_null(node)) {
                printf("%d(%.2f) ", node_get_target(node), node_get_weight(node));
                node = node_get_next(node);
            }
            printf("\n");
        }
    }
}

void graph_destroy(Graph *graph) {
    // Se for um grafo não direcionado, a matriz de adjacência é triangular
    if (graph->direction == undirected && graph->type == adj_matrix) {
        for (int i = 0; i < graph->V; i++) {
            free(graph->adjacency_matrix[i]);
        }
        free(graph->adjacency_matrix);
    }
    // Se for um grafo direcionado, a matriz de adjacência não é triangular
    else if (graph->direction == directed && graph->type == adj_matrix) {
        for (int i = 0; i < graph->V; i++) {
            free(graph->adjacency_matrix[i]);
        }
        free(graph->adjacency_matrix);
    }
    // Se for uma lista de adjacência
    else {
        for (int i = 0; i < graph->V; i++) {
            Node *node = graph->adjacency_list[i];
            while (!node_is_null(node)) {
                Node *aux = node;
                node = node_get_next(node);
                node_destroy(aux);
            }
        }
        free(graph->adjacency_list);
    }
    free(graph);
}


// Escreve um arquivo .dot, recebe um grafo
void graph_write_dot(Graph *graph, char *file_name, int *path, int size) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    fprintf(file, "digraph {\n");
    fprintf(file, "\tgraph [overlap=false, splines=true]\n");
    fprintf(file, "\tnode [shape=circle]\n");
    fprintf(file, "\tedge [color=black]\n");
    for (int i = 0; i < graph->V; i++) {
        Node *node = graph->adjacency_list[i];
        while (!node_is_null(node)) {
            bool is_in_path = false;
            for (int j = 0; j < size - 1; j++) {
                if (i == path[j] && node_get_target(node) == path[j + 1]) {
                    is_in_path = true;
                    break;
                }
            }
            if (graph->direction == undirected && i < node_get_target(node)) {
                if (is_in_path) {
                    fprintf(file, "\t%d -- %d [color=red, label=\"%.2f\"]\n", i, node_get_target(node), node_get_weight(node));
                }
                else {
                    fprintf(file, "\t%d -- %d [label=\"%.2f\"]\n", i, node_get_target(node), node_get_weight(node));
                }
            }
            else if (graph->direction == directed) {
                if (is_in_path) {
                    fprintf(file, "\t%d -> %d [color=red, label=\"%.2f\"]\n", i, node_get_target(node), node_get_weight(node));
                }
                else {
                    fprintf(file, "\t%d -> %d [label=\"%.2f\"]\n", i, node_get_target(node), node_get_weight(node));
                }
            }
            node = node_get_next(node);
        }
    }

    fprintf(file, "}");
    fclose(file);

    system("dot -Tpng graph.dot -o graph.png");
    // remove("graph.dot");
}
