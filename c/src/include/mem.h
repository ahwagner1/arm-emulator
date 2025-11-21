#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MEM_SIZE (64 * 1024 * 1024) // 64 MB
#define MEM_MAX_WORDS (MEM_SIZE / sizeof(uint32_t))

uint32_t *init_memory();

uint32_t mem_at(uint32_t *memory, uint32_t index);

#endif /* MEM_H */
