#ifndef BLOCK_H
#define BLOCK_H

#include "sha256.h"
#include <time.h>
#include <stdint.h>

#define MAX_TRANSACTIONS 10
#define TRANSACTION_SIZE 128
#define DATA_SIZE 256

typedef struct Block {
    uint32_t index;               // Block position in chain
    time_t timestamp;             // Creation time
    char transactions[MAX_TRANSACTIONS][TRANSACTION_SIZE]; // Array of transaction strings
    uint32_t transaction_count;   // Number of transactions
    char previous_hash[SHA256_BLOCK_SIZE * 2 + 1]; // Previous block's hash (hex)
    char hash[SHA256_BLOCK_SIZE * 2 + 1];          // Current block's hash (hex)
    struct Block *next;           // Pointer to next block in linked list
} Block;

// Initializes a block with given index and previous hash
void init_block(Block *block, uint32_t index, const char *previous_hash);
// Adds a transaction to the block
int add_transaction(Block *block, const char *transaction);
// Calculates and sets the block's hash
void calculate_block_hash(Block *block);
// Displays block information, including transactions
void display_block(const Block *block);
// Frees a block (for cleanup)
void free_block(Block *block);

#endif
