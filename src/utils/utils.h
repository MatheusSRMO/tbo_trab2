#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h>

/// @brief Busca o indice de um vértice em um vetor de vértices ordenado
/// @param v Vértice a ser buscado
/// @param vertices Vetor de vértices ordenado
/// @param size Tamanho do vetor de vértices
/// @return Retorna o indice do vértice no vetor de vértices, caso o vértice não esteja no vetor, retorna -1
int get_index_binary(int v, int *vertices, int size);

void print_vector(int *vector, int size);

int get_index_binary(int v, int *vertices, int size);

#endif // _UTILS_H_
