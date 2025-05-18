#ifndef BLOCK_H
#define BLOCK_H

#include "sha256.h"
#include <time.h>
#include <stdint.h>

#define DATA_SIZE 256

typedef struct Block {
    uint32_t index;               // Block position in chain
    time_t timestamp;             // Creation time
    char data[DATA_SIZE];         // Block data (e.g., transactions)
    char previous_hash[SHA256_BLOCK_SIZE * 2 + 1]; // Previous block's hash (hex)
    char hash[SHA256_BLOCK_SIZE * 2 + 1];          // Current block's hash (hex)
} Block;

// Initializes a block with given index and previous hash
void init_block(Block *block, uint32_t index, const char *previous_hash);
// Calculates and sets the block's hash
void calculate_block_hash(Block *block);
// Displays block information
void display_block(const Block *block);

#endif
