#include "min_heap.h"

struct min_heap {
    Item *items;
    int size;
    int capacity;
};

MinHeap *min_heap_create(int capacity) {
    MinHeap *heap = malloc(sizeof(MinHeap));
    heap->items = malloc(sizeof(Item) * (capacity + 1));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void min_heap_destroy(MinHeap *heap) {
    free(heap->items);
    free(heap);
}

// Função recursiva para manter a propriedade de heap mínimo ao inserir um item
void min_heap_heapify(MinHeap *heap, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= heap->size && less(heap->items[left], heap->items[smallest])) {
        smallest = left;
    }
    if (right <= heap->size && less(heap->items[right], heap->items[smallest])) {
        smallest = right;
    }
    if (smallest != i) {
        Item temp = heap->items[i];
        heap->items[i] = heap->items[smallest];
        heap->items[smallest] = temp;
        min_heap_heapify(heap, smallest);
    }
}

Item min_heap_remove(MinHeap *heap) {
    Item item = heap->items[1];
    heap->items[1] = heap->items[heap->size--];
    min_heap_heapify(heap, 1);
    return item;
}

// Função recursiva para manter a propriedade de heap mínimo ao subir um item
void min_heap_heapup(MinHeap *heap, int i) {
    if (i > 1 && less(heap->items[i], heap->items[i / 2])) {
        Item temp = heap->items[i];
        heap->items[i] = heap->items[i / 2];
        heap->items[i / 2] = temp;
        min_heap_heapup(heap, i / 2);
    }
}

void min_heap_insert(MinHeap *heap, Item item) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->items = realloc(heap->items, sizeof(Item) * (heap->capacity + 1));
    }
    heap->items[++heap->size] = item;
    min_heap_heapup(heap, heap->size);
}


// Muda a chave de um item e o reposiciona na heap, podendo subir ou descer
// void min_heap_decrease_key(MinHeap *heap, int id, double value) {
    
// }

Item min_heap_get_min(MinHeap *heap) {
    return heap->items[1];
}

bool min_heap_is_empty(MinHeap *heap) {
    return heap->size == 0;
}

int min_heap_size(MinHeap *heap) {
    return heap->size;
}

void min_heap_write_dot(MinHeap *heap, char *file_name) {
    FILE *file = fopen(file_name, "w");
    fprintf(file, "digraph G {\n");
    fprintf(file, "    node [shape=circle]\n");
    fprintf(file, "    edge [dir=none]\n");
    for (int i = 1; i <= heap->size; i++) {
        fprintf(file, "    %d [label=\"%d/%.2f\"]\n", i, heap->items[i].id, heap->items[i].value);
        if (2 * i <= heap->size) {
            fprintf(file, "    %d -> %d\n", i, 2 * i);
        }
        if (2 * i + 1 <= heap->size) {
            fprintf(file, "    %d -> %d\n", i, 2 * i + 1);
        }
    }
    fprintf(file, "}\n");
    fclose(file);

    const char *format = "dot -Tpng %s -o %s.png";
    char command[strlen(format) + strlen(file_name) * 2];
    sprintf(command, format, file_name, file_name);
    system(command);
    remove(file_name);
}
