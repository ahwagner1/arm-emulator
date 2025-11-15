#include "include/mem.h"

uint32_t *init_memory() {
    uint32_t *mem = malloc(MEM_SIZE);

    if (mem == NULL) {
        perror("Error allocating memory for VM");
        return NULL;
    }

    return mem;
}
