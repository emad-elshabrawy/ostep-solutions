# OSTEP Solutions

Implementations, homework solutions, and experiments developed while studying Operating Systems: Three Easy Pieces (OSTEP).

This repository accompanies the textbook through practical work in systems programming. It covers the implementation and investigation of operating-system concepts, with an emphasis on understanding program behavior, testing correctness, and exploring the interfaces between applications and the operating system.

## Repository Structure

```text
ostep-solutions/
├── README.md
├── .gitignore
├── homework/
│   ├── README.md
│   └── chapter-XX/
│       ├── README.md
│       └── ...
└── projects/
    ├── README.md
    └── project-XX-name/
        ├── README.md
        └── ...
```

### Homework

The `homework/` directory contains chapter exercises, solutions, and simulator-based experiments. Each chapter has a separate directory containing the relevant code, instructions, and documentation.

### Projects

The `projects/` directory contains programming projects associated with OSTEP. Each project is maintained independently, with source files, build instructions, tests, and supporting documentation where applicable.

## Development Environment

The primary development environment is Linux. C and Unix/POSIX interfaces are used where appropriate, with Python 3 for simulator-based exercises and other experiments.

## Tools and Technologies

| Technology | Purpose |
|---|---|
| **C** | Systems programming and low-level implementation. |
| **GCC** | Compilation and compiler diagnostics. |
| **GDB** | Debugging programs and inspecting runtime behavior. |
| **Linux** | Development and execution environment. |
| **POSIX / Unix APIs** | Process management, file I/O, and system-level interfaces. |
| **Python 3** | Simulator-based exercises and experiments. |
| **Git & GitHub** | Version control and source-code management. |

**Other tools:** Make, `grep`, `diff`, `cmp`, `xxd`, and other command-line utilities used for building, debugging, and testing where applicable.

The tools used for each exercise depend on its requirements. Project-specific build commands, dependencies, and testing procedures are documented in the corresponding directory.

## Development and Testing

The general workflow is to understand the requirements, implement the solution, compile it, test its behavior, and investigate any discrepancies.

Where applicable, C programs are compiled with strict warnings, for example:

```bash
gcc -Wall -Wextra -Werror -o program program.c
```

Projects may use their supplied test suites, targeted test cases, and standard Unix utilities to verify output and investigate edge cases. Simulator-based exercises are run with the relevant configuration so that scheduling decisions and process behavior can be examined.

Build instructions and other execution details are kept alongside the implementation they describe.

## References

- [OSTEP — Official Website and Textbook](https://pages.cs.wisc.edu/~remzi/OSTEP/)
- [OSTEP Homework Repository](https://github.com/remzi-arpacidusseau/ostep-homework)
- [OSTEP Projects Repository](https://github.com/remzi-arpacidusseau/ostep-projects)

## Disclaimer

This is an independent educational repository maintained while studying *Operating Systems: Three Easy Pieces*. It is not an official OSTEP repository.

The textbook, assignment specifications, and other original materials remain the property of their respective authors and rights holders. The implementations and explanations maintained here are intended for educational purposes.
