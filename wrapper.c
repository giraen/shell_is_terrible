#include "wrapper.h"

#define EXIT_FAILURE 1

void *mem_alloc(size_t size) {
    void *ptr;

    if (size == 0) {
        return NULL;
    }
    ptr = malloc(size);

    if (ptr == NULL) {
        perror(RED"A memory allocation error has occurred"RST);
        exit(EXIT_FAILURE);
    }

    return ptr;
}