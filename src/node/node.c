#include "node.h"

struct node {
    unsigned short int target;
    double weight;
    struct node *next;
};

// Cria um novo nó
Node *node_contruct(int target, double weight, Node *next) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->target = target;
    new_node->weight = weight;
    new_node->next = next;
    return new_node;
}

// Destroi um nó
void node_destroy(Node *node) {
    free(node);
}

bool node_is_null(Node *node) {
    return node == NULL;
}

int node_get_target(Node *node) {
    return node->target;
}

double node_get_weight(Node *node) {
    return node->weight;
}

Node* node_get_next(Node *node) {
    return node->next;
}