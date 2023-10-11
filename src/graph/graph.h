#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../min_heap/min_heap.h"
#include "../item.h"
#include "../node/node.h"

typedef enum graph_type {
    adj_matrix,
    adj_list
} graph_type;

typedef enum graph_direction {
    directed,
    undirected
} graph_direction;


typedef struct graph Graph;

/*
 * Cria um grafo com V vértices e tipo type.
 * param V: número de vértices
 * param type: tipo do grafo
 * return: ponteiro para o grafo criado
 */
Graph *graph_create(int V, graph_type type, graph_direction direction);

Node* graph_get_adjacency_list(Graph *graph, int v);

/*
 * Adiciona uma aresta entre os vértices v e w com peso weight.
 * param graph: grafo
 * param v: vértice v
 * param w: vértice w
 * param weight: peso da aresta
 */
void graph_add_edge(Graph *graph, int v, int w, float weight);

/*
 * Pega o peso da aresta entre os vértices v e w.
 * param graph: grafo
 * param v: vértice v
 * param w: vértice w
 * return: peso da aresta
 */
float graph_get_weight(Graph *graph, int v, int w);

/*
 * Pega o número de vértices do grafo.
 * param graph: grafo
 * return: número de vértices
 */
int graph_get_V(Graph *graph);

/*
 * Pega o número de arestas do grafo.
 * param graph: grafo
 * return: número de arestas
 */
void graph_print(Graph *graph);

/*
 * Pega o tipo do grafo.
 * param graph: grafo
 * return: tipo do grafo
 */
void graph_destroy(Graph *graph);


/*
 * Transforma um grafo em um arquivo .dot.
 * param graph: grafo
 * param filename: nome do arquivo .dot
 */
void graph_to_dot(Graph *graph, char *filename);


void graph_write_dot(Graph *graph, char *file_name, int *path, int size);

#endif