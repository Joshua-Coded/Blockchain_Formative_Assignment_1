# Simple Blockchain Simulation (Assignment 1, Task 2)

This project implements a blockchain simulation in C for Assignment 1, Task 2 of the Introduction to Blockchain Development course. The program demonstrates cryptographic hashing (SHA-256) to ensure data integrity by linking blocks through hashes and validating the chain’s consistency. It simulates a blockchain by sequentially adding three blocks (Genesis, Block 1, Block 2), validating the chain before each addition, and displaying the results, providing a clear demonstration of blockchain operations.

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
The objective of this task is to create a simple blockchain simulation in C that uses SHA-256 hashing to maintain integrity, as specified in Assignment 1, Task 2. The blockchain consists of blocks, each containing an index, timestamp, data, previous block’s hash, and its own hash. The program sequentially adds three blocks to an array-based blockchain, validating the chain before each addition to ensure no tampering has occurred. This implementation:
- Defines a `Block` structure with required fields.
- Implements functions to calculate block hashes and validate the blockchain.
- Simulates a blockchain starting with a genesis block, followed by two additional blocks with sample data.
- Uses modular code with detailed comments for clarity.

## What the Program Does
The program performs the following:
1. **Blockchain Initialization**: Creates an empty blockchain as a dynamic array of blocks with an initial capacity.
2. **Block Addition**:
   - Adds a genesis block (index 0, data: "Genesis Block Data", previous hash: "0").
   - Validates the chain and adds Block 1 (data: "Transaction Data 1").
   - Validates the chain and adds Block 2 (data: "Transaction Data 2").
3. **Validation**:
   - Before adding each non-genesis block, verifies that all existing blocks’ hashes match their recalculated hashes and that each block’s previous hash matches the prior block’s hash.
   - Validates the chain after each addition and at the end for confirmation.
4. **Display**: Shows the final blockchain, including each block’s index, timestamp, data, previous hash, and hash.
5. **Cleanup**: Frees allocated memory upon completion.

The program ensures integrity using SHA-256’s collision resistance, critical for blockchain security.

## Role in Blockchain
A blockchain is a tamper-evident ledger where blocks are linked through cryptographic hashes:
- **Data Integrity**: Each block’s hash is computed from its contents (index, timestamp, data, previous hash). Any change invalidates the hash.
- **Chain Linkage**: The previous hash field links blocks, forming a chain. Tampering with any block breaks the chain, detectable during validation.
- **Validation**: Checking hashes ensures the blockchain hasn’t been altered, a core feature of systems like Bitcoin.

This simulation mirrors real blockchains by using SHA-256 to hash block data and validate the chain before adding blocks, demonstrating integrity and linkage in a controlled sequence.

## Project Structure
blockchain_task2/
├── src/
│   ├── main.c          # Main program with sequential blockchain simulation
│   ├── sha256.c        # SHA-256 algorithm implementation
│   ├── block.c         # Block structure and functions
│   ├── blockchain.c    # Blockchain management and validation
├── headers/
│   ├── sha256.h        # SHA-256 function declaration
│   ├── block.h         # Block structure and function declarations
│   ├── blockchain.h    # Blockchain structure and function declarations
└── README.md           # This documentation
- **src/main.c**: Runs the simulation, adding three blocks with validation before each addition and displaying the results.
- **src/sha256.c**: Implements SHA-256 (reused from Task 1).
- **src/block.c**: Defines the `Block` structure and functions for initialization, hashing, and display.
- **src/blockchain.c**: Manages the array-based blockchain, including validation and block addition.
- **headers/**: Contains function and structure declarations.
- **README.md**: Explains the program’s functionality and usage.

## Requirements
To compile and run the program, you need:
- **C Compiler**: GCC or any standard C compiler (e.g., `gcc` on Linux/macOS, MinGW on Windows).
- **Operating System**: Linux, macOS, or Windows with a Unix-like environment (e.g., WSL, Cygwin).
- **Standard C Library**: For functions like `malloc`, `realloc`, `free`, `time`, `strncpy`, etc.

## Compile and Run Instructions
1. **Navigate to Project Directory**:
   ```bash
   cd blockchain_task2
Compile the Program:
Use GCC to compile all source files and generate an executable:
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
The program runs the simulation, adding three blocks, validating the chain, and displaying the results.
Clean Up:
Remove the executable if needed:
bash
rm blockchain
On Windows:
bash
del blockchain.exe
Expected Output
Running ./blockchain produces output like:
=== Question 1, Task 2: Simple Blockchain Simulation ===
Adding Genesis Block...
Validating Blockchain...
Blockchain is valid!

Adding Block 1...
Validating Blockchain...
Blockchain is valid!

Adding Block 2...
Validating Blockchain...
Blockchain is valid!

Final Blockchain Contents:
Block 0:
Timestamp: Sun May 18 14:01:00 2025
Data: Genesis Block Data
Previous Hash: 0
Hash: [64-character hex hash]

Block 1:
Timestamp: Sun May 18 14:01:00 2025
Data: Transaction Data 1
Previous Hash: [Block 0’s hash]
Hash: [64-character hex hash]

Block 2:
Timestamp: Sun May 18 14:01:00 2025
Data: Transaction Data 2
Previous Hash: [Block 1’s hash]
Hash: [64-character hex hash]

Final Validation...
Blockchain is valid!
(Note: Timestamps and hashes vary based on execution time. Hashes are 64-character hexadecimal strings.)You can verify a block’s hash manually (e.g., for Block 0) with:
bash
echo -n "0<timestamp>Genesis Block Data0" | sha256sum
Code Explanation
The implementation simulates a blockchain with the following components:
Block Structure
Fields:
index: Block position (0, 1, 2).
timestamp: Creation time (Unix epoch).
data: Fixed data (e.g., "Genesis Block Data", "Transaction Data 1").
previous_hash: Hash of the previous block (hex string, "0" for genesis).
hash: SHA-256 hash of the block’s contents (hex string).
Key Functions
init_block: Initializes a block with index, previous hash, and timestamp; data is set separately.
calculate_block_hash: Computes the SHA-256 hash of a block’s fields (index, timestamp, data, previous hash).
display_block: Prints block details.
init_blockchain: Creates an empty blockchain with a dynamic array (initial capacity: 10 blocks).
add_block: Adds a block with specified data after validating the chain, resizing the array if needed.
validate_blockchain: Checks each block’s hash against its recalculated hash and verifies previous hash linkage.
display_blockchain: Shows all blocks in the array.
free_blockchain: Frees the blockchain’s memory.
Blockchain Logic
Uses SHA-256 (from Task 1) to hash block contents.
Validates the chain before adding non-genesis blocks, ensuring integrity.
Stores blocks in a dynamic array, resized by doubling capacity when full.
Executes a fixed sequence: adds Genesis block, validates, adds Block 1, validates, adds Block 2, validates, displays, and validates again.
The code is modular, with separate files for SHA-256, block, and blockchain logic, enhancing reusability and clarity.
