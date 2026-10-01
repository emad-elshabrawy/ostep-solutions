# OSTEP Solutions

A structured collection of my solutions, implementations, experiments, and study notes developed while working through **Operating Systems: Three Easy Pieces (OSTEP)**.

The repository is intended to document my practical study of operating-system concepts through reading, implementation, testing, debugging, and experimentation.

> **Status:** Work in progress — continuously updated as I progress through OSTEP.

---

## Table of Contents

- [About](#about)
- [Objectives](#objectives)
- [Repository Structure](#repository-structure)
- [Projects](#projects)
- [Homework](#homework)
- [Notes](#notes)
- [Development Practices](#development-practices)
- [Toolchain](#toolchain)
- [Progress](#progress)
- [Attribution](#attribution)

---

## About

**Operating Systems: Three Easy Pieces (OSTEP)** is an operating-systems textbook covering fundamental concepts such as virtualization, concurrency, and persistence.

This repository contains my work as I study those concepts and implement the accompanying programming projects.

The emphasis is on **understanding through implementation** rather than simply completing assignments. For each project or exercise, I aim to understand the underlying operating-system concepts, implement the required behavior, test the implementation, investigate failures, and document relevant lessons.

---

## Objectives

The main objectives of this repository are to:

- Build a strong foundation in operating-system concepts.
- Develop practical systems-programming skills in C.
- Understand Unix and POSIX interfaces through implementation.
- Practice reasoning about processes, memory, concurrency, and persistence.
- Become comfortable working with low-level data representations.
- Develop disciplined debugging and testing habits.
- Maintain a clear, reproducible record of my progress through OSTEP.

---

## Repository Structure

```text
ostep-solutions/
│
├── projects/
│   ├── project-01-unix-utilities/
│   │   ├── wcat/
│   │   ├── wgrep/
│   │   ├── wzip/
│   │   └── wunzip/
│   │
│   ├── project-02-...
│   └── ...
│
├── homework/
│   ├── chapter-01/
│   ├── chapter-02/
│   └── ...
│
├── notes/
│   ├── chapter-01/
│   ├── chapter-02/
│   └── ...
│
├── .gitignore
└── README.md
```
projects/
Contains implementations of the programming projects associated with OSTEP.
Each project is kept in its own directory and includes the relevant source code, tests, documentation, and supporting files where appropriate.
homework/
Contains my solutions to OSTEP homework and exercises, organized by chapter or topic.
notes/
Contains personal study notes, explanations, observations, and technical references developed while studying the book.
Projects
Project 1 — Unix Utilities
Status: Completed
Implemented four Unix-style utilities in C:
Utility	Description
wcat	Reads and writes file contents, including standard input
wgrep	Searches text for matching patterns
wzip	Compresses data using run-length encoding
wunzip	Decompresses the binary run-length encoding format


The implementations were developed incrementally and tested against the supplied project test suites.
The project also provided practical experience with:
- C file I/O
- Standard streams
- Command-line arguments
- Binary data
- fread() / fwrite()
- String processing
- Run-length encoding
- Error handling
- Exit statuses
- Unix command-line behavior
- GCC warnings and strict compilation
Homework
Homework solutions will be organized according to the corresponding OSTEP chapters and topics.
The goal is to use the homework as a way to verify conceptual understanding rather than simply record answers.
Example structure:
```text
homework/
├── chapter-01/
├── chapter-02/
├── chapter-03/
└── ...
```
Notes
The notes/ directory contains personal explanations and observations developed while studying OSTEP.
Topics may include:
- CPU virtualization
- Processes
- Process states
- Scheduling
- Address spaces
- Memory virtualization
- Paging
- Concurrency
- Threads
- Locks
- Synchronization
- Persistence
- File systems
- I/O
- System calls
- Unix process management
These notes are intended to record my understanding and may evolve as I encounter new material or refine previous explanations.
Development Practices
I aim to follow a consistent development process throughout the repository:
```text
Read
  ↓
Understand the requirements
  ↓
Design the solution
  ↓
Implement
  ↓
Compile with strict warnings
  ↓
Test
  ↓
Debug
  ↓
Verify behavior
  ↓
Document what was learned
```
Where applicable, C programs are compiled with:
gcc -Wall -Werror

Project-provided test suites are used to verify required behavior.
Generated build artifacts and temporary files are excluded through .gitignore.
Toolchain
The repository primarily uses:
- C — systems programming and project implementations
- GCC — compilation
- Linux — development environment
- POSIX / Unix interfaces — systems programming interfaces
- Git — version control
- GitHub — repository hosting
Additional command-line tools are used when appropriate for testing and debugging, including utilities such as:
diff
cmp
xxd

Progress
Area	Status
Project 1 — Unix Utilities	Completed
Homework	In progress
Study Notes	In progress
Remaining Projects	Planned


This section will be updated as the repository grows.
Attribution
This repository contains my own implementations, solutions, experiments, and study notes developed while working through Operating Systems: Three Easy Pieces (OSTEP).
OSTEP and its original educational materials are the work of their respective authors and contributors. This repository is an independent study repository and is not an official OSTEP repository.
Original OSTEP resources:
- https://pages.cs.wisc.edu/~remzi/OSTEP/
- https://github.com/remzi-arpacidusseau/ostep-projects
This repository does not claim ownership of the original OSTEP textbook, project specifications, or other original materials.
Disclaimer
The code and notes in this repository represent my learning process and may change as my understanding develops.
The purpose of this repository is educational: to document my progress, practice systems programming, and develop a deeper understanding of operating systems.
