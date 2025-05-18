markdown
# Block Structure Implementation (Assignment 1, Question Two, Task 1)

This project implements a `Block` structure in C as part of Assignment 1, Question Two, Task 1. The program demonstrates the core data structure of a blockchain by defining a block with attributes essential for maintaining data integrity. It creates and displays a single block to test the implementation, using SHA-256 hashing to compute the block's hash.

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
The objective of this task is to implement a `Block` structure in C that serves as the basic unit of a blockchain. The block includes attributes critical for blockchain integrity, and the program tests the structure by creating and displaying a single block. This implementation:
- Defines a `Block` structure with index, timestamp, data, previous hash, and current hash.
- Implements a function to display block information.
- Tests the structure with a genesis block.
- Uses modular code with detailed comments for clarity.

## What the Program Does
The program performs the following:
1. **Block Creation**:
   - Initializes a block with index 0, sample data ("Genesis Block Data"), and a placeholder previous hash ("0").
   - Sets the timestamp to the current time.
   - Computes the block’s SHA-256 hash based on its fields.
2. **Block Display**:
   - Prints the block’s index, timestamp, data, previous hash, and current hash in a readable format.
3. **Test Case**:
   - Creates a single genesis block and displays its information to verify the implementation.

The program demonstrates the foundational role of a block in a blockchain, using SHA-256 for secure hashing.

## Role in Blockchain
A block is the fundamental unit of a blockchain, storing data and linking to other blocks to form a tamper-evident chain:
- **Data Storage**: Holds transaction or other data (e.g., "Genesis Block Data").
- **Integrity**: The block’s hash, computed from its contents, ensures any alteration is detectable.
- **Linkage**: The previous hash links to the prior block, enabling chain formation in a full blockchain.

This implementation provides the building block for a blockchain, showcasing how SHA-256 hashing secures data integrity.

## Project Structure
block_task1/
├── src/
│   ├── main.c          # Main program to test the block
│   ├── sha256.c        # SHA-256 algorithm implementation
│   ├── block.c         # Block structure and functions
├── headers/
│   ├── sha256.h        # SHA-256 function declaration
│   ├── block.h         # Block structure and function declarations
└── README.md           # This documentation

- **src/main.c**: Creates and displays a test block.
- **src/sha256.c**: Implements SHA-256 for hashing (reused from Question One).
- **src/block.c**: Defines the `Block` structure and functions for initialization, hashing, and display.
- **headers/**: Contains function and structure declarations.
- **README.md**: Explains the program’s functionality and usage.

## Requirements
To compile and run the program, you need:
- **C Compiler**: GCC or any standard C compiler (e.g., `gcc` on Linux/macOS, MinGW on Windows).
- **Operating System**: Linux, macOS, or Windows with a Unix-like environment (e.g., WSL, Cygwin).
- **Standard C Library**: For functions like `malloc`, `memcpy`, `time`, etc.

## Compile and Run Instructions
1. **Navigate to Project Directory**:
   ```bash
   cd block_task1
Compile the Program:
Use gcc to compile all source files and generate an executable:
bash
gcc -Wall -g -Iheaders src/main.c src/sha256.c src/block.c -o block
-Wall: Enables warnings for robust code.
-g: Includes debugging information.
-Iheaders: Specifies the header file directory.
-o block: Names the output executable block.
Run the Program:
bash
./block
On Windows:
bash
block.exe
The program creates and displays a single block.
Clean Up:
Remove the executable if needed:
bash
rm block
On Windows:
bash
del block.exe
Expected Output
Running ./block produces output like:
=== Task 1: Defining the Block Structure ===
Test Block:
Block 0:
Timestamp: Sun May 18 12:16:00 2025
Data: Genesis Block Data
Previous Hash: 0
Hash: 5a6b7c8d9e0f... (64 hex chars)
(Note: Timestamp and hash vary based on execution time.)
You can verify the hash with:
bash
echo -n "0<timestamp>Genesis Block Data0" | sha256sum
Code Explanation
The implementation focuses on the Block structure and its operations:
Block Structure
Fields:
index: Block position (e.g., 0 for genesis).
timestamp: Creation time (Unix epoch).
data: Transaction or other data (up to 256 chars).
previous_hash: Hash of the previous block (hex string).
hash: SHA-256 hash of the block’s contents (hex string).
Key Functions
init_block: Initializes a block with index, data, previous hash, and timestamp; calculates its hash.
calculate_block_hash: Computes the SHA-256 hash of the block’s fields (index, timestamp, data, previous hash).
display_block: Prints block details in a human-readable format.
Program Logic
Uses SHA-256 (from Question One) to hash block contents.
Creates a single block with sample data and displays it.
Ensures modularity with separate files for SHA-256 and block logic.
The code is simple, well-documented, and focused on the block structure, laying the foundation for a blockchain.


References
NIST FIPS 180-4: Secure Hash Standard (SHS), defining SHA-256.
C Standard Library documentation for malloc, time, etc.
```