#ifndef INSTRUCTION_H
#define INSTRUCTION_H

// need to redo this to match up the correct op code values
// for example AND == 0b000
// EOR == 0b0001
typedef enum {
    ADC = 0, // add with carry
    ADD,     // add
    AND,     // and
    B,       // branch
    BIC,     // bit clear
    BL,      // branch with link
    BX,      // branch and exchange
    CDP,     // coprocesser data processing
    CMN,     // compare negative
    CMP,     // compare
    EOR,     // exclusive or
    LDC,     // load coprocesser from memory
    LDM,     // load multiple registers
    LDR,     // load register from memory
    MCR,     // move cpu register to coprocesser reg
    MLA,     // multiply accumulate
    MOV,     // move register or constant
    MRC,     // move from coprocesser reg to cpu reg
    MRS,     // move psr status/flags to reg
    MSR,     // move register to psr status/flags
    MUL,     // multiply
    MVN,     // move negative number
    ORR,     // or
    RSB,     // reverse subtract
    RSC,     // reverse subtract with carry
    SBC,     // subtract with carry
    STC,     // store coprocesser to memory
    STM,     // store multiple
    STR,     // store register to memory
    SUB,     // subtract
    SWI,     // software interrupt
    SWP,     // swap register with memory
    TEQ,     // test bitwise equality
    TST      // test bits
} e_opcodes;

#endif /* INSTRUCTION_H */
