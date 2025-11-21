#include "include/instructions.h"
#include "include/reg.h"

uint8_t extract_condition_field(uint32_t instruction) {
    return instruction >> 28;
}

void determine_instruction(uint32_t instruction) {
    // not the prettiest but should get the job done
    
    uint8_t first_three = instruction & 0x0E000000; 
    switch (first_three) {
        case 0:
            // data processing, multiply, or single data swap
            // check bits 7:4 to determine if multiply/swap or data processing
            if (instruction & 0x00000090) == 0x00000090) {
                // bits 7:4 == 0b1001, so either multiply/swap
                // check the bit 24, if 1 then single data swap
                if ((instruction & 0x01000000) == 0x01000000)
                    single_data_swap(instruction);
                else
                    multiply(instruction);
            }
            else {
                data_processing(instruction); // not yet defined
            }
            break;
        case 2: // intentional fall through to three might work here
        case 3:
            // undefined or single data transfer
            // single data transfer can either be 0b010 or 0b011
            // hence why we fall through to this conditional
            // assuming no undefined things so far
            single_data_transfer(instruction);
            break;
        case 4:
            // block data transfer
            block_data_transfer(instruction);
            break;
        case 5:
            // branch
            branch(instruction);
            break;
        case 6:
            // coprocesser data transfer
            coproc_data_transfer(instruction);
            break;
        case 7:
            // coprocessor data operation or coprocessor register transfer
            // or interrupt
            if ((instruction & 0x0F000000) == 0x0F000000)
                // software interrupt
                interrupt();
            else
                coproc_data_op(instruction);
            break;
        default:
            printf("Unknown instruction");
    }
}

void single_data_swap(uint32_t instruction) {

}

void multiply(uint32_t instruction) {

}

void data_processing(uint32_t instruction) {
    // extract opcode, run switch statement on enum values, setup those functions
}

void single_data_transfer(uint32_t instruction) {

}

void block_data_transfer(uint32_t instruction) {

}

void branch(uint32_t instruction) {

}

void coproc_data_transfer(uint32_t instruction) {

}

void coproc_data_op(uint32_t instruction) {

}

void interrupt() {

}
