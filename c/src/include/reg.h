#ifndef REG_H
#define REG_H

#include "stdint.h"

typedef enum {
    R0 = 0,
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    R8,
    R9,
    R10,
    R11,
    R12,
    SP,
    LR,
    PC,
    CPSR,
    COUNT // not real register, just fancy way to setup the register array
} e_register;

typedef struct {
    uint32_t M    : 5; // processer mode bits
    uint32_t T    : 1; // Thumb state bit
    uint32_t F    : 1; // FIQ disable bit
    uint32_t I    : 1; // IRQ disabel bit
    uint32_t A    : 1; // imprecise data abort disable bit
    uint32_t E    : 1; // data endianness bit
    uint32_t IT_L : 6; // if-then state bits, split into bits 10-15 and 25-26
    uint32_t GE   : 4; // greater than or equal to bits
    uint32_t DNM  : 4; // do not modify bits
    uint32_t J    : 1; // java sticky bit
    uint32_t IT_U : 2; // if then state bits upper portion (25-26)
    uint32_t Q    : 1; // sticky overflow bit
    uint32_t V    : 1; // overflow bit
    uint32_t C    : 1; // carry/borrow/extend bit
    uint32_t Z    : 1; // zero bit
    uint32_t N    : 1; // negative/less than bit
} s_cpsr;

// making this global accross the project
// will be initialized in main.c
extern uint32_t registers[COUNT];


#endif /* REG_H */
