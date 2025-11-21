#ifndef INSTRUCTION_H
#define INSTRUCTION_H

/*
    Need to rethink how this is structured, in ARM7 only data processing instructions
    contain traditional set opcodes. Everything else has it's own opcode, but those are
    variable in length. One thing that is constant are the condition fields. Bits 31:28 
    are always the condition field from the CPSR register for this ISA (ARM7TDMI-S)

    Essentially the instructions with set opcodes are:
        AND = 0b0000
        EOR = 0b0001
        SUB = 0b0010
        RSB = 0b0011
        ADD = 0b0100
        ADC = 0b0101
        SBC = 0b0110
        RSC = 0b0111
        TST = 0b1000
        TEQ = 0b1001
        CMP = 0b1010
        CMN = 0b1011
        ORR = 0b1100
        MOV = 0b1101
        BIC = 0b1110
        MVN = 0b1111

    Bits 27:... are how we determine the other instructions, it's probably smart to start
    with the higher opcodes and work our way shorter
    For example: if bits 27:26 == 0b00, then the instruction is a data processing type
                 at the same time, 6 other instructions also have 27:26 as 0b00

    There is one special form we want to be away of
    if 27:24 == 0b1111 this signifies a software interrupt
*/

typedef enum {
    AND = 0,
    EOR,
    SUB,
    RSB,
    ADD,
    ADC,
    SBC,
    RSC,
    TST,
    TEQ,
    CMP,
    CMN,
    ORR,
    MOV,
    BIC,
    MNV
} e_data_processing_opcodes;

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
} e_instructions;

uint8_t extract_condition_field(uint32_t instruction);
e_instructions determine_instruction(uint32_t instruction);

#endif /* INSTRUCTION_H */
