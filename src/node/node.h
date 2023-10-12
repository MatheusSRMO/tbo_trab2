#ifndef _NODE_H_
#define _NODE_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;

/// @brief Cria um nó
/// @param target Id do vértice de destino
/// @param weight Peso da aresta
/// @param next Próximo nó
/// @return Nó
Node *node_contruct(int target, double weight, Node *next);

/// @brief Libera a memória alocada pelo nó
/// @param node Nó
void node_destroy(Node *node);

/// @brief Verifica se o nó é nulo
/// @param node Nó
/// @return Verdadeiro se o nó for nulo, falso caso contrário
bool node_is_null(Node *node);

/// @brief Pega o peso da aresta
/// @param node Nó
/// @return Peso da aresta
double node_get_weight(Node *node);

/// @brief Pega o id do vértice de destino
/// @param node Nó
/// @return Id do vértice de destino
int node_get_target(Node *node);

/// @brief Pega o próximo nó
/// @param node Nó
/// @return Próximo nó
Node* node_get_next(Node *node);

#endif // _NODE_H_