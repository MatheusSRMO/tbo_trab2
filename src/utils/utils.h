#ifndef _UTILS_H_
#define _UTILS_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
    double ratio;
} Ratio;

/// @brief Compara duas razões
/// @param a Primeira razão
/// @param b Segunda razão
/// @return Retorna -1 se a < b, 1 se a > b e 0 se a == b
int ratio_compare(const void *a, const void *b);

/// @brief Compara dois inteiros
/// @param a Primeiro inteiro
/// @param b Segundo inteiro
/// @return Retorna -1 se a < b, 1 se a > b e 0 se a == b
int int_compare(const void *a, const void *b);

/// @brief Imprime os conjuntos S, C e M
/// @param s Conjunto S
/// @param size_s Tamanho do conjunto S
/// @param c Conjunto C
/// @param size_c Tamanho do conjunto C
/// @param m Conjunto M
/// @param size_m Tamanho do conjunto M
void show_sets(int *s, int size_s, int *c, int size_c, int *m, int size_m);

/// @brief Busca o indice de um vértice em um vetor de vértices ordenado
/// @param v Vértice a ser buscado
/// @param vertices Vetor de vértices ordenado
/// @param size Tamanho do vetor de vértices
/// @return Retorna o indice do vértice no vetor de vértices, caso o vértice não esteja no vetor, retorna -1
int get_index_binary(int v, int *vertices, int size);

/// @brief Mostra um vetor de inteiros
/// @param vector Vetor de inteiros
/// @param size Tamanho do vetor
void print_vector(int *vector, int size);

/// @brief Busca o indice de um vértice em um vetor de vértices ordenado
/// @param v Vértice a ser buscado
/// @param vertices Vetor de vértices ordenado
/// @param size Tamanho do vetor de vértices
/// @return Retorna o indice do vértice no vetor de vértices, caso o vértice não esteja no vetor, retorna -1
int get_index_binary(int v, int *vertices, int size);

#endif // _UTILS_H_
