#ifndef _FILE_HANDLER_H_
#define _FILE_HANDLER_H_

#include "../graph/graph.h"

// Lê o arquivo de entrada e retorna um grafo
// Os vetores serão allocados e preenchidos com os valores lidos do arquivo
Graph *file_handler_read_file(char *file_name, int **s, int *size_s, int **c, int *size_c, int **m, int *size_m);

#endif // _FILE_HANDLER_H_