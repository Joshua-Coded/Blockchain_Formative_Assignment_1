# Blockchain Persistence Implementation (Assignment 1, Question Two, Task 4)

This project implements blockchain persistence in C as part of Assignment 1, Question Two, Task 4. The program extends the transaction-enabled blockchain from Task 3 to include functions for saving the blockchain to a file and loading it back, ensuring integrity through hash validation. It creates a blockchain with transactions, saves it, loads it, and validates the loaded chain.

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
The objective of this task is to add persistence to the blockchain by implementing functions to save it to a file and load it back, ensuring the loaded chain’s integrity through validation. The program builds on Task 3, using a linked list to manage blocks with transactions and SHA-256 hashing for integrity. This implementation:
- Adds functions to save and load the blockchain to/from a text file.
- Validates the loaded blockchain to ensure hash consistency.
- Tests persistence with a three-block chain containing transactions.
- Uses modular code with detailed comments for clarity.

## What the Program Does
The program performs the following:
1. **Blockchain Creation**:
   - Creates a three-block chain with transactions (2, 3, and 1 transaction, respectively).
   - Links blocks via previous hashes and computes SHA-256 hashes.
2. **Display and Validation**:
   - Displays the original blockchain and validates its integrity.
3. **Persistence**:
   - Saves the blockchain to `blockchain.dat` in a text format.
   - Clears the blockchain and loads it back from the file.
   - Displays the loaded blockchain and re-validates it.
4. **Cleanup**: Frees allocated memory.

The program ensures integrity by validating hashes after loading, detecting any tampering or file corruption.

## Role in Blockchain
A blockchain is a tamper-evident ledger where blocks store transactions and are linked through cryptographic hashes. Persistence is critical for real-world blockchains:
- **Data Storage**: Saving to a file ensures the blockchain persists across program runs.
- **Integrity**: Validating hashes after loading detects tampering or corruption.
- **Recovery**: Loading allows the blockchain to be restored without re-computing.

This implementation simulates persistence by saving/loading a blockchain and validating its integrity, mimicking real-world blockchain storage.

## Project Structure
blockchain_task4/
├── src/
│   ├── main.c          # Main program to test blockchain persistence
│   ├── sha256.c        # SHA-256 algorithm implementation
│   ├── block.c         # Block structure with transactions and functions
│   ├── blockchain.c    # Blockchain linked list, persistence, and functions
├── headers/
│   ├── sha256.h        # SHA-256 function declaration
│   ├── block.h         # Block structure and function declarations
│   ├── blockchain.h    # Blockchain linked list and function declarations
└── README.md           # This documentation

- **src/main.c**: Creates, saves, loads, displays, and validates a blockchain with transactions.
- **src/sha256.c**: Implements SHA-256 for hashing (reused from Question One).
- **src/block.c**: Defines the `Block` structure with transaction support and functions.
- **src/blockchain.c**: Manages the blockchain with persistence and validation functions.
- **headers/**: Contains function and structure declarations.
- **README.md**: Explains the program’s functionality and usage.

## Requirements
To compile and run the program, you need:
- **C Compiler**: GCC or any standard C compiler (e.g., `gcc` on Linux/macOS, MinGW on Windows).
- **Operating System**: Linux, macOS, or Windows with a Unix-like environment (e.g., WSL, Cygwin).
- **Standard C Library**: For functions like `malloc`, `fopen`, `time`, etc.

## Compile and Run Instructions
1. **Navigate to Project Directory**:
   ```bash
   cd blockchain_task4
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
The program creates, saves, loads, and validates a blockchain, creating blockchain.dat.
Clean Up:
Remove the executable and data file if needed:
bash
rm blockchain blockchain.dat
On Windows:
bash
del blockchain.exe blockchain.dat
Expected Output
Running ./blockchain produces output like:
=== Task 4: Blockchain Persistence ===
Original Blockchain Contents:
Block 2:
Timestamp: Sun May 18 13:15:00 2025
Transactions (1):
  0: Alice sends 2 BTC to Frank
Previous Hash: 68071c05bcaa10576041801a4723b0998d57e42ef6b6debbd4305ce493909a4f
Hash: b11d5c331b1382a0d1a5f6507cb8abb47b5dd5301788819e9d64c241d3fe846d

Block 1:
Timestamp: Sun May 18 13:15:00 2025
Transactions (3):
  0: Charlie sends 3 BTC to Dave
  1: Dave sends 1 BTC to Eve
  2: Eve sends 0.5 BTC to Alice
Previous Hash: 5c6af6bba3f14faf770a76e2161105c1cfda1d72e47656dd7930699761f02c7f
Hash: 68071c05bcaa10576041801a4723b0998d57e42ef6b6debbd4305ce493909a4f

Block 0:
Timestamp: Sun May 18 13:15:00 2025
Transactions (2):
  0: Alice sends 10 BTC to Bob
  1: Bob sends 5 BTC to Charlie
Previous Hash: 0
Hash: 5c6af6bba3f14faf770a76e2161105c1cfda1d72e47656dd7930699761f02c7f

Validating Original Blockchain...
Original blockchain is valid!
Saving blockchain to blockchain.dat...
Blockchain saved successfully!
Loading blockchain from blockchain.dat...
Blockchain loaded successfully!
Loaded Blockchain Contents:
Block 2:
Timestamp: Sun May 18 13:15:00 2025
Transactions (1):
  0: Alice sends 2 BTC to Frank
Previous Hash: 68071c05bcaa10576041801a4723b0998d57e42ef6b6debbd4305ce493909a4f
Hash: b11d5c331b1382a0d1a5f6507cb8abb47b5dd5301788819e9d64c241d3fe846d

Block 1:
Timestamp: Sun May 18 13:15:00 2025
Transactions (3):
  0: Charlie sends 3 BTC to Dave
  1: Dave sends 1 BTC to Eve
  2: Eve sends 0.5 BTC to Alice
Previous Hash: 5c6af6bba3f14faf770a76e2161105c1cfda1d72e47656dd7930699761f02c7f
Hash: 68071c05bcaa10576041801a4723b0998d57e42ef6b6debbd4305ce493909a4f

Block 0:
Timestamp: Sun May 18 13:15:00 2025
Transactions (2):
  0: Alice sends 10 BTC to Bob
  1: Bob sends 5 BTC to Charlie
Previous Hash: 0
Hash: 5c6af6bba3f14faf770a76e2161105c1cfda1d72e47656dd7930699761f02c7f

Validating Loaded Blockchain...
Loaded blockchain is valid!
(Note: Timestamps and hashes vary based on execution time.)
You can verify hashes with:
bash
echo -n "0$(date -d '2025-05-18 13:15:00' +%s)Alice sends 10 BTC to BobBob sends 5 BTC to Charlie0" | shasum -a 256
Code Explanation
The implementation adds persistence to the transaction-enabled blockchain:
Block Structure
Fields: Includes index, timestamp, transactions (array of strings), transaction_count, previous_hash, hash, and next.
Key Functions
init_block, add_transaction, calculate_block_hash, display_block, free_block: Handle block creation and transactions.
init_blockchain, add_block, validate_blockchain, display_blockchain, free_blockchain: Manage the blockchain linked list, with validate_blockchain handling reverse-ordered list.
save_blockchain: Writes the blockchain to blockchain.dat, with each block’s fields on separate lines.
load_blockchain: Reads the blockchain from the file, reconstructs blocks, and validates the loaded chain.
File Format
Text-based: Each block is stored as:
<index>
<timestamp>
<transaction_count>
<transaction_1>
...
<transaction_n>
<previous_hash>
<hash>
Example:
0
1747655700
2
Alice sends 10 BTC to Bob
Bob sends 5 BTC to Charlie
0
5c6af6bba3f14faf770a76e2161105c1cfda1d72e47656dd7930699761f02c7f
Blockchain Logic
Uses SHA-256 for hashing.
Manages blocks in a reverse-ordered linked list (newest first).
Saves and loads the blockchain, validating loaded data.
Tests persistence by creating, saving, loading, and validating a three-block chain.
The code is modular, with persistence functions in blockchain.c, ensuring reusability and clarity.
