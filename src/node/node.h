#ifndef _NODE_H_
#define _NODE_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;

Node *node_contruct(int target, double weight, Node *next);


void node_destroy(Node *node);

bool node_is_null(Node *node);

double node_get_weight(Node *node);

int node_get_target(Node *node);

Node* node_get_next(Node *node);

#endif // _NODE_H_