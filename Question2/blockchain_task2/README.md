# Blockchain Linked List Implementation (Assignment 1, Question Two, Task 2)

This project implements a blockchain in C using a linked list as part of Assignment 1, Question Two, Task 2. The program demonstrates the core mechanics of a blockchain by managing blocks with SHA-256 hashing to ensure data integrity. It creates a small blockchain, adds blocks with correct previous hash linkage, and validates the chain’s consistency.

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
The objective of this task is to implement a blockchain in C using a linked list to manage blocks, building on the `Block` structure from Task 1. The blockchain links blocks through their hashes and validates the chain’s integrity. This implementation:
- Uses a linked list to store blocks, with each block containing the previous block’s hash.
- Implements functions to add blocks and validate the blockchain.
- Tests the blockchain by creating a three-block chain and verifying its integrity.
- Uses modular code with detailed comments for clarity.

## What the Program Does
The program performs the following:
1. **Blockchain Initialization**: Creates an empty blockchain as a linked list.
2. **Block Addition**:
   - Adds blocks with specified data (e.g., "Genesis Block Data").
   - Sets each block’s previous hash to the hash of the prior block (or "0" for the genesis block).
   - Computes each block’s SHA-256 hash based on its fields.
3. **Chain Validation**:
   - Verifies that each block’s stored hash matches its recalculated hash.
   - Ensures each block’s previous hash matches the actual previous block’s hash.
4. **Display and Test**:
   - Creates a three-block chain (genesis and two additional blocks).
   - Displays all blocks’ details (index, timestamp, data, previous hash, hash).
   - Validates the chain to confirm integrity.
5. **Cleanup**: Frees allocated memory.

The program ensures blockchain integrity using SHA-256’s collision resistance and sensitivity.

## Role in Blockchain
A blockchain is a tamper-evident ledger where blocks are linked through cryptographic hashes:
- **Data Integrity**: Each block’s hash is computed from its contents (index, timestamp, data, previous hash). Any change invalidates the hash.
- **Chain Linkage**: The previous hash field links blocks, forming a chain. Tampering with any block breaks the chain, detectable during validation.
- **Validation**: Checking hashes ensures the blockchain hasn’t been altered, a core feature of systems like Bitcoin.

This implementation simulates a blockchain by linking blocks in a linked list and validating hash consistency, demonstrating core blockchain principles.

## Project Structure
blockchain_task2/
├── src/
│   ├── main.c          # Main program to test the blockchain
│   ├── sha256.c        # SHA-256 algorithm implementation
│   ├── block.c         # Block structure and functions
│   ├── blockchain.c    # Blockchain linked list and functions
├── headers/
│   ├── sha256.h        # SHA-256 function declaration
│   ├── block.h         # Block structure and function declarations
│   ├── blockchain.h    # Blockchain linked list and function declarations
└── README.md           # This documentation

- **src/main.c**: Creates, displays, and validates a three-block blockchain.
- **src/sha256.c**: Implements SHA-256 for hashing (reused from Question One).
- **src/block.c**: Defines the `Block` structure and functions for initialization, hashing, and display.
- **src/blockchain.c**: Manages the blockchain as a linked list, with functions for adding blocks and validation.
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
   cd blockchain_task2
Compile the Program:
Use gcc to compile all source files and generate an executable:
bash
gcc -Wall -g -Iheaders src/main.c src/sha256.c src/block.c src/blockchain.c -o blockchain
-Wall: Enables warnings for robust code.
-g: Includes debugging information.
-Iheaders: Specifies the header file directory.
-o blockchain: Names the output executable blockchain.
Run the Program:
bash
./blockchain
On Windows:
bash
blockchain.exe
The program creates a three-block blockchain, displays it, and validates its integrity.
Clean Up:
Remove the executable if needed:
bash
rm blockchain
On Windows:
bash
del blockchain.exe
Expected Output
Running ./blockchain produces output like:
=== Task 2: Creating a Blockchain ===
Blockchain Contents:
Block 2:
Timestamp: Sun May 18 12:38:00 2025
Data: Transaction Data 2
Previous Hash: b2c3d4e5f6a7... (Block 1’s hash)
Hash: c3d4e5f6a7b8... (64 hex chars)

Block 1:
Timestamp: Sun May 18 12:38:00 2025
Data: Transaction Data 1
Previous Hash: a1b2c3d4e5f6... (Block 0’s hash)
Hash: b2c3d4e5f6a7... (64 hex chars)

Block 0:
Timestamp: Sun May 18 12:38:00 2025
Data: Genesis Block Data
Previous Hash: 0
Hash: a1b2c3d4e5f6... (64 hex chars)

Validating Blockchain...
Blockchain is valid!
(Note: Timestamps and hashes vary based on execution time.)
You can verify hashes with:
bash
echo -n "0<timestamp>Genesis Block Data0" | sha256sum
Code Explanation
The implementation simulates a blockchain using a linked list with the following components:
Block Structure
Fields:
index: Block position (0, 1, 2, ...).
timestamp: Creation time (Unix epoch).
data: Transaction or other data (up to 256 chars).
previous_hash: Hash of the previous block (hex string).
hash: SHA-256 hash of the block’s contents (hex string).
next: Pointer to the next block in the linked list.
Key Functions
init_block: Initializes a block with index, data, previous hash, and timestamp; calculates its hash.
calculate_block_hash: Computes the SHA-256 hash of a block’s fields.
display_block: Prints block details.
init_blockchain: Creates an empty blockchain linked list.
add_block: Adds a block with the given data, linking to the previous block’s hash.
validate_blockchain: Verifies hash integrity and previous hash consistency.
display_blockchain: Shows all blocks.
free_blockchain: Frees memory.
Blockchain Logic
Uses SHA-256 (from Question One) to hash block contents.
Manages blocks in a singly linked list, with new blocks added at the head.
Validates the chain by checking each block’s hash and previous hash linkage.
Tests a three-block chain to demonstrate functionality.
The code is modular, with separate files for SHA-256, block, and blockchain logic, ensuring reusability and clarity.

References
NIST FIPS 180-4: Secure Hash Standard (SHS), defining SHA-256.
C Standard Library documentation for malloc, time, etc.
Course materials on blockchain and linked lists.
For questions or issues, contact the course instructor or TA. This implementation demonstrates a linked list-based blockchain with secure hashing and validation.
```