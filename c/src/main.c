#include "include/reg.h"
#include "include/mem.h"
#include "include/instructions.h"

//https://iitd-plos.github.io/col718/ref/arm-instructionset.pdf
int main(void) {
    uint32_t *memory = init_memory();
    
    // set the initial condition starting point in memory
    registers[PC] = 0x3000;

    while (true) {
        uint32_t instruction = mem_at(memory, registers[PC]++);

        // extract the opcode and jump to the correct function
        // also all instruction execute based on conditionals in CPSR
        uint32_t opcode = instruction >> ??;

        switch (opcode) {



        }

    }

    return 0;
}
