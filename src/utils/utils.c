#include "utils.h"


int is_in(int v, int *vertices, int size) {    
    for(int i = 0; i < size; i++) {        
        if(vertices[i] == v) {            
            return i;
        }
    }    
    return -1;
}


void print_vector(int *vector, int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", vector[i]);
        if(i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("\n");
}

// pega indice busca binaria
int get_index_binary(int v, int *vertices, int size) {
    int left = 0;
    int right = size - 1;
    while(left <= right) {
        int middle = (left + right) / 2;
        if(vertices[middle] == v) {
            return middle;
        } else if(vertices[middle] < v) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}
