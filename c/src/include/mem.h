#ifndef MEM_H
#define MEM_H

#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define MEM_SIZE (64 * 1024 * 1024) // 64 MB
#define MEM_SIZE_WORDS (MEM_SIZE / sizeof(uint32_t)) // max number of memory units we can use

uint32_t *init_memory();

#endif /* MEM_H */
