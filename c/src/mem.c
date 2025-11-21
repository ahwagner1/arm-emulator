#include "include/mem.h"

uint32_t *init_memory() {
    uint32_t *mem = malloc(MEM_SIZE);

    if (mem == NULL) {
        printf("Error allocating memory for VM");
        return NULL;
    }

    return mem;
}

uint32_t mem_at(uint32_t *memory, uint32_t index) {
    if (index < MEM_MAX_WORDS)
        return memory[index];

    printf("Index out of bounds. Max possible index %d, passed index %d",
        MEM_MAX_WORDS, index);
}
