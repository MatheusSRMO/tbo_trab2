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

void show_sets(int *s, int size_s, int *c, int size_c, int *m, int size_m) {
    printf("S: ");
    for(int i = 0; i < size_s; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    printf("C: ");
    for(int i = 0; i < size_c; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    printf("M: ");
    for(int i = 0; i < size_m; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");
}

int ratio_compare(const void *a, const void *b) {
    Ratio *ra = (Ratio *) a;
    Ratio *rb = (Ratio *) b;
    if(ra->ratio < rb->ratio) {
        return -1;
    } else if(ra->ratio > rb->ratio) {
        return 1;
    } else {
        return 0;
    }
}

