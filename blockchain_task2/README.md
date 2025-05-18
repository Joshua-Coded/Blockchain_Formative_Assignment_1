# Simple Blockchain Simulation (Assignment 1, Task 2)

This project implements a dynamic blockchain simulation in C as part of Assignment 1, Task 2. The program demonstrates how cryptographic hashing (SHA-256) ensures data integrity in a blockchain by linking blocks through hashes and validating the chain’s consistency. It features an interactive menu that allows users to add blocks, display the blockchain, validate the chain, or exit, providing a hands-on simulation of blockchain operations.

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
The objective of this task is to create a simple blockchain simulation in C that uses SHA-256 hashing to maintain integrity. The blockchain consists of blocks, each containing an index, timestamp, data, previous block’s hash, and its own hash. The program uses an interactive menu to let users dynamically manage the blockchain, validating the chain before adding new blocks to ensure no tampering has occurred. This implementation:
- Defines a `Block` structure with required fields.
- Implements functions to calculate block hashes and validate the blockchain.
- Simulates a blockchain with user-driven operations, starting with a genesis block.
- Uses modular code with detailed comments for clarity.

## What the Program Does
The program performs the following:
1. **Blockchain Initialization**: Creates an empty blockchain as a dynamic array of blocks and adds a genesis block (index 0, no previous hash).
2. **Interactive Menu**: Offers users four options:
   - **Add a new block**: Prompts for custom data (or uses default "Block X Data"), links to the previous block’s hash, and adds after chain validation.
   - **Display blockchain**: Shows all blocks’ details (index, timestamp, data, previous hash, hash).
   - **Validate blockchain**: Checks hash integrity and chain linkage.
   - **Exit**: Frees memory and terminates the program.
3. **Block Creation**:
   - Generates blocks with user-specified or default data.
   - Calculates each block’s SHA-256 hash based on its fields.
4. **Chain Management**:
   - Adds blocks after validating the existing chain.
   - Ensures each block’s previous hash matches the prior block’s hash.
5. **Validation**:
   - Verifies that each block’s stored hash matches its recalculated hash.
   - Checks that each block’s previous hash corresponds to the actual previous block’s hash.
6. **Cleanup**: Frees allocated memory upon exit.

The program ensures integrity using SHA-256’s collision resistance and sensitivity, critical for blockchain security.

## Role in Blockchain
A blockchain is a tamper-evident ledger where blocks are linked through cryptographic hashes:
- **Data Integrity**: Each block’s hash is computed from its contents (index, timestamp, data, previous hash). Any change invalidates the hash.
- **Chain Linkage**: The previous hash field links blocks, forming a chain. Tampering with any block breaks the chain, detectable during validation.
- **Validation**: Checking hashes ensures the blockchain hasn’t been altered, a core feature of systems like Bitcoin.

This simulation mirrors real blockchains by using SHA-256 to hash block data and validate the chain, with user interaction to demonstrate dynamic blockchain management.

## Project Structure
blockchain_task2/
├── src/
│   ├── main.c          # Main program with interactive blockchain simulation
│   ├── sha256.c        # SHA-256 algorithm implementation
│   ├── block.c         # Block structure and functions
│   ├── blockchain.c    # Blockchain management and validation
├── headers/
│   ├── sha256.h        # SHA-256 function declaration
│   ├── block.h         # Block structure and function declarations
│   ├── blockchain.h    # Blockchain structure and function declarations
└── README.md           # This documentation

- **src/main.c**: Runs the interactive simulation with a menu for adding blocks, displaying, validating, and exiting.
- **src/sha256.c**: Implements SHA-256 (reused from Task 1).
- **src/block.c**: Defines the `Block` structure and functions for initialization, hashing, and display.
- **src/blockchain.c**: Manages the blockchain, including validation and block addition.
- **headers/**: Contains function and structure declarations.
- **README.md**: Explains the program’s functionality and usage.

## Requirements
To compile and run the program, you need:
- **C Compiler**: GCC or any standard C compiler (e.g., `gcc` on Linux/macOS, MinGW on Windows).
- **Operating System**: Linux, macOS, or Windows with a Unix-like environment (e.g., WSL, Cygwin).
- **Standard C Library**: For functions like `malloc`, `memcpy`, `time`, `scanf`, etc.

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
The program starts with a genesis block and presents a menu for user interaction.
Clean Up:
Remove the executable if needed:
bash
rm blockchain
On Windows:
bash
del blockchain.exe
Expected Output
Running ./blockchain produces output like:
=== Task 2: Simple Blockchain Simulation ===
Genesis block added.

=== Blockchain Simulation Menu ===
1. Add a new block
2. Display blockchain
3. Validate blockchain
4. Exit
Enter your choice (1-4): 1
Enter data for block 1 (or press Enter for default 'Block 1 Data'): Transaction Data
Block 1 added.

=== Blockchain Simulation Menu ===
1. Add a new block
2. Display blockchain
3. Validate blockchain
4. Exit
Enter your choice (1-4): 2

Blockchain Contents:
Block 0:
Timestamp: 1747654321
Data: Block 0 Data
Previous Hash: 0
Hash: a1b2c3d4e5f6... (64 hex chars)

Block 1:
Timestamp: 1747654322
Data: Transaction Data
Previous Hash: a1b2c3d4e5f6... (Block 0’s hash)
Hash: b2c3d4e5f6a7... (64 hex chars)

=== Blockchain Simulation Menu ===
1. Add a new block
2. Display blockchain
3. Validate blockchain
4. Exit
Enter your choice (1-4): 3

Validating Blockchain...
Blockchain is valid!

=== Blockchain Simulation Menu ===
1. Add a new block
2. Display blockchain
3. Validate blockchain
4. Exit
Enter your choice (1-4): 4

Exiting system...
Blockchain memory freed. Goodbye!
(Note: Timestamps and hashes vary based on execution time.)
You can verify hashes with:
bash
echo -n "0<timestamp>Block 0 Data0" | sha256sum
Code Explanation
The implementation simulates a blockchain with the following components:
Block Structure
Fields:
index: Block position (0, 1, 2, ...).
timestamp: Creation time (Unix epoch).
data: User-specified or default data (e.g., "Block X Data").
previous_hash: Hash of the previous block (hex string).
hash: SHA-256 hash of the block’s contents (hex string).
Key Functions
init_block: Initializes a block with index, previous hash, timestamp, and data; calculates its hash.
calculate_block_hash: Computes the SHA-256 hash of a block’s fields.
display_block: Prints block details.
init_blockchain: Creates an empty blockchain with dynamic array storage.
add_block: Adds a block after validating the chain.
validate_blockchain: Checks each block’s hash and previous hash for consistency.
display_blockchain: Shows all blocks.
free_blockchain: Frees memory.
display_menu: Shows the interactive menu.
get_block_data: Prompts for user data or uses default.
Blockchain Logic
Uses SHA-256 (from Task 1) to hash block contents.
Validates the chain before adding blocks, ensuring integrity.
Stores blocks in a dynamic array, resized as needed.
Provides a menu-driven interface for dynamic user interaction.
The code is modular, with separate files for SHA-256, block, and blockchain logic, enhancing reusability and clarity.
Submission Compliance
This project meets all requirements for Assignment 1, Task 2:
Block Structure: Includes index, timestamp, data, previous hash, and current hash.
Functions: Implements calculate_block_hash and validate_blockchain.
Simulation: Supports dynamic block addition with validation via an interactive menu.
Structure: Organized with src and headers directories, with detailed comments.


References
NIST FIPS 180-4: Secure Hash Standard (SHS), defining SHA-256.
C Standard Library documentation for malloc, time, scanf, etc.
Course materials on blockchain and cryptographic hashing.
For questions or issues, contact the course instructor or TA. This dynamic simulation demonstrates blockchain integrity using SHA-256 hashing with user interaction.
```