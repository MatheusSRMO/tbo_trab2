#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "item.h"


typedef struct min_heap MinHeap;

MinHeap *min_heap_create(int capacity);

void min_heap_destroy(MinHeap *heap);

void min_heap_heapify(MinHeap *heap, int i);

Item min_heap_remove(MinHeap *heap);

void min_heap_heapup(MinHeap *heap, int i);

void min_heap_insert(MinHeap *heap, Item item);

void min_heap_decrease_key(MinHeap *heap, int id, double value);

Item min_heap_get_min(MinHeap *heap);

bool min_heap_is_empty(MinHeap *heap);

int min_heap_size(MinHeap *heap);

void min_heap_write_dot(MinHeap *heap, char *file_name);

#endif // _MIN_HEAP_H_