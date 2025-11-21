# 32 bit ARM7TDMI emulator/VM
### Why?

I was inspired by this great writeup on building a VM for LC3: https://www.jmeiners.com/lc3-vm/

I went through that tutorial and wanted to do something a little bit bigger and more powerful than the LC3. I took an ARM7 course in college some years ago and figured why not try my hand at building an ARM7 VM/emulator/whatever other name it could go by. ARM7 is definitely a step up in complexity compared to LC3 but still approachable due to it being a RISC ISA. Choosing ARM7 probably isn't going to be practical for anything other than learning since it's primarily targeted to MCUs but I didn't feel like making my own ISA (for now...)

Another reason why is that I like low level systems programming and I think virtual machines are cool pieces of software. I also want to use this as a learning exercise for writing in different systems programming languages. I am most familiar with C/C++ but also want to get my feet wet with Zig and Rust. I figure that I can go through the nitty details of ARM7 implementations in languages I'm comfortable in (C/C++) and then by the time I get to Zig and Rust, the challenge will be learning their quirks and syntax instead of learning ARM7 in depth. 

## Plans
**Language Implementations**

| Language | Status  |
| -------- |:-------:|
| C    | In Progress |
| C++  | Not started |
| Zig  | Not started | 
| Rust | Not started |

**Other ideas:**
- Connect a front-end so that the user can interact with the VM dynamically. They should be able to write ARM7 programs, set break points, inspect memory, the usual stuff that a dev environment can do
- Build assembler so that the entire process can be done in this one application. Something like ./arm7-vm -i hello_world.asm
- Build ARM8 VM

I doubt I build those first two ideas in all languages. Ideally I'll just choose a single back-end that I'm most proud of and then write the front-end and assembler in whatever I feel like. Also that will probably be in a seperate repo to keep things nice and organized. 

## Specs
I'm building this to behave according to the following documents:
- https://developer.arm.com/documentation/ddi0027/d/?lang=en (ARM7DI Data Sheet)
- https://developer.arm.com/documentation/ddi0210/c/?lang=en (ARM7TDMI Technical Reference Manual)
