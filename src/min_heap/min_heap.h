#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../item.h"


typedef struct min_heap MinHeap;

/// @brief Cria um item
/// @param id Id do item
/// @param value Valor do item
/// @return Retorna um item
Item make_item(int id, double value);

/// @brief Cria uma min heap
/// @param capacity Capacidade da min heap
/// @return Retorna uma min heap
MinHeap *min_heap_create(int capacity);

/// @brief Destrói uma min heap
/// @param heap Min heap a ser destruída
void min_heap_destroy(MinHeap *heap);

/// @brief Conserta a min heap para baixo
/// @param heap Min heap a ser consertada
/// @param i Índice do item a ser consertado
void min_heap_heapify(MinHeap *heap, int i);

/// @brief Remove o menor item da min heap
/// @param heap Min heap
/// @return Retorna o menor item da min heap
Item min_heap_remove(MinHeap *heap);

/// @brief Conserta a min heap para cima
/// @param heap Min heap a ser consertada
/// @param i Índice do item a ser consertado
void min_heap_heapup(MinHeap *heap, int i);

/// @brief Insere um item na min heap
/// @param heap Min heap
/// @param item Item a ser inserido
void min_heap_insert(MinHeap *heap, Item item);

/// @brief Diminui o valor de um item da min heap
/// @param heap Min heap
/// @param id Id do item a ser diminuído
/// @param value Novo valor do item
void min_heap_decrease_key(MinHeap *heap, int id, double value);

/// @brief Retorna o menor item da min heap
/// @param heap Min heap
/// @return Retorna o menor item da min heap
Item min_heap_get_min(MinHeap *heap);

/// @brief Verifica se a min heap está vazia
/// @param heap Min heap
/// @return Retorna true se a min heap estiver vazia, caso contrário, retorna false
bool min_heap_is_empty(MinHeap *heap);

/// @brief Retorna o tamanho da min heap
int min_heap_size(MinHeap *heap);

/// @brief Escreve a min heap em um arquivo dot
/// @param heap Min heap
/// @param file_name Nome do arquivo
void min_heap_write_dot(MinHeap *heap, char *file_name);

/// @brief Limpa a min heap
/// @param heap Min heap
void min_heap_clear(MinHeap *heap);

#endif // _MIN_HEAP_H_