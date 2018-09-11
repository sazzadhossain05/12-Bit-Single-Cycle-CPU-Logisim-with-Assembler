#!/bin/bash
# =============================================================
# Backdated Git History — 12-Bit Single-Cycle CPU Design
# Run this in Git Bash from inside:
#   D:\GitToGithub\cse 332 project
# =============================================================

echo "Setting up backdated git history..."

git config --global user.email "sazzad.hossain.cs@gmail.com"
git config --global user.name "sazzadhossain05"

git init
git checkout -b main
git rm -rf --cached . > /dev/null 2>&1

# COMMIT 1 — August 1, 2018 — ISA design
git add "ISA-Instruction Set Architecture/ISA-Design.docx"

export GIT_AUTHOR_DATE="2018-08-01T10:20:00"
export GIT_COMMITTER_DATE="2018-08-01T10:20:00"
git commit -m "Add ISA design document"

# COMMIT 2 — August 8, 2018 — 1-bit and 4-bit ALU
git add "CSE332 Project 12 bit Datapath--open with logisim/1 bit ALU.circ"
git add "CSE332 Project 12 bit Datapath--open with logisim/4 bit ALU.circ"

export GIT_AUTHOR_DATE="2018-08-08T14:35:00"
export GIT_COMMITTER_DATE="2018-08-08T14:35:00"
git commit -m "Add 1-bit and 4-bit ALU circuits"

# COMMIT 3 — August 15, 2018 — 12-bit ALU and ALU opcode
git add "CSE332 Project 12 bit Datapath--open with logisim/12 bit ALU.circ"
git add "CSE332 Project 12 bit Datapath--open with logisim/ALU-Opcode.circ"
git add "CSE332 Project 12 bit Datapath--open with logisim/ALU.circ"

export GIT_AUTHOR_DATE="2018-08-15T11:10:00"
export GIT_COMMITTER_DATE="2018-08-15T11:10:00"
git commit -m "Add 12-bit ALU and ALU opcode decoder"

# COMMIT 4 — August 22, 2018 — Register file and control unit
git add "CSE332 Project 12 bit Datapath--open with logisim/Registry File.circ"
git add "CSE332 Project 12 bit Datapath--open with logisim/Control Unit.circ"
git add "CSE332 Project 12 bit Datapath--open with logisim/control.docx"

export GIT_AUTHOR_DATE="2018-08-22T16:45:00"
export GIT_COMMITTER_DATE="2018-08-22T16:45:00"
git commit -m "Add register file and control unit"

# COMMIT 5 — August 30, 2018 — Datapath and main circuit
git add "CSE332 Project 12 bit Datapath--open with logisim/Datapath.circ"
git add "CSE332 Project 12 bit Datapath--open with logisim/main.circ"

export GIT_AUTHOR_DATE="2018-08-30T13:25:00"
export GIT_COMMITTER_DATE="2018-08-30T13:25:00"
git commit -m "Add datapath and top-level CPU circuit"

# COMMIT 6 — September 6, 2018 — Assembler
git add "Assembler/Assembler_II.cpp"

export GIT_AUTHOR_DATE="2018-09-06T10:50:00"
export GIT_COMMITTER_DATE="2018-09-06T10:50:00"
git commit -m "Add C++ assembler for 12-bit ISA"

# COMMIT 7 — September 11, 2018 — Final cleanup
git add .

export GIT_AUTHOR_DATE="2018-09-11T17:15:00"
export GIT_COMMITTER_DATE="2018-09-11T17:15:00"
git commit -m "Final project submission" 2>/dev/null || echo "Nothing left to commit"

unset GIT_AUTHOR_DATE
unset GIT_COMMITTER_DATE

git remote remove origin 2>/dev/null
git remote add origin https://github.com/sazzadhossain05/12-Bit-Single-Cycle-CPU-Logisim-with-Assembler.git
git push -u origin main --force

echo ""
echo "Done. Check your repository at:"
echo "https://github.com/sazzadhossain05/12-Bit-Single-Cycle-CPU-Logisim-with-Assembler"
