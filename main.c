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
    min_heap_insert(heap, make_item(3, 3.0));
    min_heap_insert(heap, make_item(1, 1.0));
    min_heap_insert(heap, make_item(7, 7.0));
    min_heap_insert(heap, make_item(2, 2.0));
    min_heap_insert(heap, make_item(4, 4.0));
    min_heap_insert(heap, make_item(5, 5.0));
    min_heap_insert(heap, make_item(6, 0.1));

    Item item = min_heap_remove(heap);
    printf("id: %d, value: %lf\n", id(item), value(item));

    min_heap_write_dot(heap, "heap.dot");

    min_heap_destroy(heap);
    return 0;
}
