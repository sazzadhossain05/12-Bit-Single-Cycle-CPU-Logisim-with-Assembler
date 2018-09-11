# 12-bit Single-Cycle CPU Design

![Platform](https://img.shields.io/badge/Platform-Logisim-blue)
![Language](https://img.shields.io/badge/Assembler-C%2B%2B-orange)
![Course](https://img.shields.io/badge/Course-CSE332%20Computer%20Organization%20and%20Architecture-lightgrey)
![Year](https://img.shields.io/badge/Year-2018-lightgrey)

This project is the design and implementation of a 12-bit single-cycle CPU
built in Logisim. The CPU is inspired by the MIPS architecture and includes
a custom Instruction Set Architecture (ISA), a fully functional datapath,
a control unit, an ALU, and a register file. A C++ assembler is also provided
to convert assembly language programs into machine code that the CPU can execute.

---

## Project Overview

The CPU was designed from the ground up, starting with the ISA specification
and working down through the ALU, register file, control unit, datapath, and
final integration. Each component was designed and tested independently in
Logisim before being connected into the complete processor.

The design process:

```
ISA Design
    |
    v
ALU Design (1-bit -> 4-bit -> 12-bit)
    |
    v
Register File
    |
    v
Control Unit
    |
    v
Datapath
    |
    v
Full CPU (main.circ)
    |
    v
Assembler (C++)
```

---

## Instruction Set Architecture

The CPU uses a 12-bit instruction width with three instruction formats:

### R-Type
```
| 4-bit OP | 4-bit Rs | 4-bit Rt |
```

### I-Type
```
| 4-bit OP | 4-bit Rs | 4-bit Immediate |
```

### J-Type
```
| 4-bit OP | 8-bit Jump Address |
```

### Instruction Table

| Instruction | Type | Opcode | Operation                        |
|-------------|------|--------|----------------------------------|
| add         | R    | 0000   | Rs = Rs + Rt                     |
| sub         | R    | 0001   | Rs = Rs - Rt                     |
| addi        | I    | 0010   | Rs = Rs + Immediate              |
| and         | R    | 0011   | Rs = Rs & Rt                     |
| or          | R    | 0100   | Rs = Rs \| Rt                    |
| sll         | I    | 0101   | Rs = Rs << Immediate             |
| beq         | I    | 0110   | if (Rs == $eqval) jump to L      |
| slt         | R    | 0111   | Rs = (Rs < Rt) ? 1 : 0           |
| jump        | J    | 1000   | PC = jump address                |
| lw          | I    | 1001   | Rs = Memory[$base + 4*Immediate] |
| sw          | I    | 1010   | Memory[$base + 4*Immediate] = Rs |
| in          | I/O  | 1011   | Rs = input                       |
| out         | I/O  | 1100   | display = Rs                     |

---

## Register File

16 registers each 4 bits wide.

| Register | Number | 4-bit Code |
|----------|--------|------------|
| $zero    | 0      | 0000       |
| $t0 - $t4 | 1-5   | 0001-0101  |
| $s0 - $s6 | 6-12  | 0110-1100  |
| $eqval   | 13     | 1101       |
| $base    | 14     | 1110       |
| $one     | 15     | 1111       |

---

## Logisim Circuit Files

Open these files in Logisim. Start with `main.circ` for the full CPU,
or open individual files to inspect each component.

| File                | Description                                      |
|---------------------|--------------------------------------------------|
| main.circ           | Top-level CPU integrating all components         |
| Datapath.circ       | Full datapath connecting ALU, memory, and registers |
| Control Unit.circ   | Generates control signals from opcode            |
| ALU.circ            | Top-level ALU                                    |
| ALU-Opcode.circ     | ALU opcode decoder                               |
| 12 bit ALU.circ     | 12-bit ALU built from 4-bit units                |
| 4 bit ALU.circ      | 4-bit ALU built from 1-bit units                 |
| 1 bit ALU.circ      | 1-bit ALU — basic building block                 |
| Registry File.circ  | 16-register file with read and write ports       |

---

## How to Open in Logisim

1. Download Logisim from http://www.cburch.com/logisim/
2. Open `logisim/main.circ`
3. Logisim will automatically load all referenced sub-circuits
4. Use Simulate menu to run the CPU step by step

---

## Assembler

The assembler converts assembly programs into hexadecimal machine code
for loading into the CPU instruction memory.

### Compile

```bash
g++ -o assembler assembler/Assembler_II.cpp
```

### Run

1. Write your assembly program in `assembler/00_input.txt`
2. Run the assembler:

```bash
./assembler
```

3. Machine code output appears in `assembler/00_output.txt`

### Example Program — Sum of First 10 Odd Numbers

```
addi $t1, 1
addi $t2, 9
addi $t3, 1
beq $t3, 11
addi $t3, 2
add $t1, $t3
jump -3
out $t1
```

---

## Images

Place the following images in the `images/` folder:

| Filename                 | Description                              |
|--------------------------|------------------------------------------|
| isa_design.png           | ISA design document screenshot          |
| 1bit_alu.png             | 1-bit ALU Logisim screenshot            |
| 4bit_alu.png             | 4-bit ALU Logisim screenshot            |
| 12bit_alu.png            | 12-bit ALU Logisim screenshot           |
| control_unit.png         | Control unit Logisim screenshot         |
| registry_file.png        | Register file Logisim screenshot        |
| datapath.png             | Datapath Logisim screenshot             |
| full_cpu.png             | Full CPU (main.circ) screenshot         |

---

## Project Structure

```
12bit-cpu/
├── README.md
├── .gitignore
├── logisim/
│   ├── main.circ
│   ├── Datapath.circ
│   ├── Control Unit.circ
│   ├── ALU.circ
│   ├── ALU-Opcode.circ
│   ├── 12 bit ALU.circ
│   ├── 4 bit ALU.circ
│   ├── 1 bit ALU.circ
│   └── Registry File.circ
├── assembler/
│   ├── Assembler_II.cpp
│   ├── 00_input.txt
│   └── 00_output.txt
├── docs/
│   ├── ISA_and_Control_Signals.md
│   └── assembler_usage.md
├── Documents/
│   └── CSE332_CPU_Design_Report.pdf
└── images/
    ├── isa_design.png
    ├── 1bit_alu.png
    ├── 4bit_alu.png
    ├── 12bit_alu.png
    ├── control_unit.png
    ├── registry_file.png
    ├── datapath.png
    └── full_cpu.png
```

---

## Team

| Name                 | Student ID  |
|----------------------|-------------|
| Sazzad Hossain       | 1610139042  |
| Imran Hasan Bhuiyan  | 1612412042  |
| Md. Rakib Imtiaz     | 1610294642  |
| Nayeem Mohammad      | 1611553042  |

---

## Academic Context

| Detail | Info |
|--------|------|
| Course | CSE332 Computer Organization and Architecture |
| Department | Electrical and Computer Engineering |
| Institution | North South University, Bangladesh |
| Semester | Summer 2018 |

---

## References

- Patterson, D. A. and Hennessy, J. L., Computer Organization and Design: The Hardware/Software Interface, 5th Edition, Elsevier, 2014
- Logisim — Digital Logic Circuit Simulator. http://www.cburch.com/logisim/
- MIPS Green Sheet — MIPS Reference Data
