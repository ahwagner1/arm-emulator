#include "include/instructions.h"

uint8_t extract_condition_field(uint32_t instruction) {
    return instruction >> 28;
}

e_instructions determine_instruction(uint32_t instruction) {
    // not sure the best way to extract the instruction type other than going from 
    // longest to shortest opcode

    uint8_t condition = extract_condition_field(instruction);
    
    // easier to "discard" the condition flags for now
    // which leaves 4 zeros on the end of the instruction now
    instruction = instruction << 4;

}
