#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include "../graph/graph.h"
#include "../utils/utils.h"

// Lê o arquivo de entrada e retorna um grafo
// Os vetores serão allocados e preenchidos com os valores lidos do arquivo
/// @brief Lê o arquivo de entrada e retorna um grafo
/// @param file_name Nome do arquivo
/// @param s Vetor de vértices de Servidores (allocado dentro da função)
/// @param size_s Tamanho do vetor de vértices de origem
/// @param c Vetor de vértices de Clientes (allocado dentro da função)
/// @param size_c Tamanho do vetor de vértices de destino A
/// @param m Vetor de vértices de Monitores (allocado dentro da função)
/// @param size_m Tamanho do vetor de vértices de destino B
/// @return Grafo
Graph *file_handler_read_file(char *file_name, int **s, int *size_s, int **c, int *size_c, int **m, int *size_m);


void file_handler_write_file(char *file_name, Ratio *ratios, int size);

#endif // _FILE_HANDLER_H_