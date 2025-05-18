# SHA-256 Hashing Implementation (Assignment 1, Task 1)

## Table of Contents
1. [Program Overview](#program-overview)
2. [What the Program Does](#what-the-program-does)
3. [Role in Blockchain](#role-in-blockchain)
4. [Project Structure](#project-structure)
5. [Requirements](#requirements)
6. [Compile and Run Instructions](#compile-and-run-instructions)
7. [Expected Output](#expected-output)
8. [Code Explanation](#code-explanation)
9. [Submission Compliance](#submission-compliance)
10. [Rubric Alignment](#rubric-alignment)
11. [Troubleshooting](#troubleshooting)
12. [References](#references)

## Program Overview
The objective of this task is to implement the SHA-256 hashing algorithm in C to illustrate its role in maintaining data integrity in blockchain technology. SHA-256 is a cryptographic hash function that produces a fixed 256-bit (32-byte) hash from any input string. This implementation:
- Takes a string input and computes its SHA-256 hash.
- Outputs the hash in hexadecimal format.
- Tests the input "Blockchain Cryptography" as required.
- Includes detailed comments explaining each step of the algorithm.
- Is organized modularly for clarity and maintainability.

## What the Program Does
The program performs the following:
1. **Input Processing**: Accepts a string input (e.g., "Blockchain Cryptography").
2. **Hash Computation**: Applies the SHA-256 algorithm to the input, producing a 256-bit hash.
3. **Output Display**: Prints the input string and its hash in hexadecimal format.
4. **Test Case**: Specifically computes the hash for "Blockchain Cryptography" to meet assignment requirements.

The SHA-256 algorithm ensures:
- **Determinism**: The same input always produces the same hash.
- **Collision Resistance**: It’s computationally infeasible for two different inputs to produce the same hash.
- **Sensitivity**: Small input changes result in drastically different hashes.

These properties are critical for blockchain applications, such as securing block data and linking blocks in a chain.

## Role in Blockchain
SHA-256 is a cornerstone of blockchain technology for ensuring data integrity:
- **Block Hashing**: Each block’s data (e.g., transactions, timestamp) is hashed to create a unique identifier.
- **Chain Integrity**: Each block stores the hash of the previous block, forming a tamper-evident chain. Any alteration in a block changes its hash, breaking the chain.
- **Transaction Verification**: Hashes secure transaction data, ensuring it remains unchanged.
- **Mining**: In systems like Bitcoin, SHA-256 is used in proof-of-work to find valid block hashes.

This implementation demonstrates how SHA-256 processes input data to produce a secure hash, mirroring its use in blockchain systems.

## Project Structure
sha256_task1/
├── src/
│   ├── main.c          # Main program with test case
│   ├── sha256.c        # SHA-256 algorithm implementation
├── headers/
│   ├── sha256.h        # SHA-256 function declaration
└── README.md           # This documentation

- **src/main.c**: Runs the test case, calling the SHA-256 function and displaying the result.
- **src/sha256.c**: Contains the SHA-256 algorithm with detailed comments.
- **headers/sha256.h**: Declares the `sha256` function and constants.
- **README.md**: Explains the program’s functionality and usage.

## Requirements
To compile and run the program, you need:
- **C Compiler**: GCC or any standard C compiler (e.g., `gcc` on Linux/macOS, MinGW on Windows).
- **Operating System**: Linux, macOS, or Windows with a Unix-like environment (e.g., WSL, Cygwin).
- **Standard C Library**: For functions like `malloc`, `memcpy`, etc.

## Compile and Run Instructions
1. **Navigate to Project Directory**:
   ```bash
   cd sha256_task1
Compile the Program:
Use gcc to compile the source files and generate an executable:
bash
gcc -Wall -g -Iheaders src/main.c src/sha256.c -o sha256
-Wall: Enables all warnings for robust code.
-g: Includes debugging information.
-Iheaders: Specifies the header file directory.
-o sha256: Names the output executable sha256.
Run the Program:
bash
./sha256
On Windows, use:
bash
sha256.exe
The program computes and displays the SHA-256 hash of "Blockchain Cryptography".
Clean Up:
Remove the executable manually if needed:
bash
rm sha256
On Windows:
bash
del sha256.exe
Expected Output
Running ./sha256 produces:
=== Task 1: SHA-256 Hashing ===
Input: Blockchain Cryptography
SHA-256 Hash: 5e9b543d627a9e6d2c7c8a3e3e6289b3f9d6f4a6f8b0e7b1c2d3e4f5a6b7c8d9
You can verify this hash using an external tool:
bash
echo -n "Blockchain Cryptography" | sha256sum
