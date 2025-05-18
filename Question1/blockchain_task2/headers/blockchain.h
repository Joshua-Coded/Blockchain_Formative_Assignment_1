#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"

typedef struct Blockchain {
    Block *blocks;         // Dynamic array of blocks
    uint32_t size;         // Current number of blocks
    uint32_t capacity;     // Allocated capacity
} Blockchain;

// Initializes an empty blockchain
void init_blockchain(Blockchain *chain);
// Adds a block to the blockchain after validation
void add_block(Blockchain *chain, Block *block);
// Validates the entire blockchain
int validate_blockchain(const Blockchain *chain);
// Displays all blocks in the blockchain
void display_blockchain(const Blockchain *chain);
// Frees blockchain memory
void free_blockchain(Blockchain *chain);

#endif
