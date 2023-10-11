#include <stdio.h>
#include "src/min_heap/min_heap.h"
#include "src/item.h"

Item make_item(int id, double value) {
    Item t;
    id(t) = id;
    value(t) = value;
    return t;
}

int main() {
    MinHeap *heap = min_heap_create(10);
    
    // inserindo alguns elementos na PQ
    min_heap_insert(heap, make_item(1, 10.0));
    min_heap_insert(heap, make_item(6, 5.0));
    min_heap_insert(heap, make_item(3, 3.0));
    min_heap_insert(heap, make_item(4, 4.0));
    min_heap_insert(heap, make_item(7, 7.0));
    min_heap_insert(heap, make_item(2, 1.0));

    // alterando a prioridade de alguns elementos
    min_heap_decrease_key(heap, 4, 0.5); // agora o nó 4 tem valor 0.5, sua posição no heap deve mudar
    min_heap_decrease_key(heap, 6, 0.1); // agora o nó 6 tem valor 0.1, sua posição no heap deve mudar

    min_heap_write_dot(heap, "heap.dot");

    min_heap_destroy(heap);
    return 0;
}
