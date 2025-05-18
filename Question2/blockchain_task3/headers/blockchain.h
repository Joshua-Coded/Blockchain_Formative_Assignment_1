#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"

typedef struct Blockchain {
    Block *head;    // Pointer to the first block (genesis)
    uint32_t size;  // Number of blocks in the chain
} Blockchain;

// Initializes an empty blockchain
void init_blockchain(Blockchain *chain);
// Adds a block to the blockchain
void add_block(Blockchain *chain, Block *block);
// Validates the blockchain's integrity
int validate_blockchain(const Blockchain *chain);
// Displays all blocks in the blockchain
void display_blockchain(const Blockchain *chain);
// Frees the blockchain's memory
void free_blockchain(Blockchain *chain);

#endif
