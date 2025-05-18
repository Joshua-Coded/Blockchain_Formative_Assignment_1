#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "block.h"

typedef struct Blockchain {
    Block *blocks;    // Array of blocks
    uint32_t size;    // Number of blocks
    uint32_t capacity; // Allocated capacity
} Blockchain;

void init_blockchain(Blockchain *chain);
void add_block(Blockchain *chain, const char *data);
int validate_blockchain(const Blockchain *chain);
void display_blockchain(const Blockchain *chain);
void free_blockchain(Blockchain *chain);
#endif
