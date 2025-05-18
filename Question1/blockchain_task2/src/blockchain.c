#include "blockchain.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * Initializes an empty blockchain with initial capacity.
 */
void init_blockchain(Blockchain *chain) {
    chain->size = 0;
    chain->capacity = 10;
    chain->blocks = malloc(chain->capacity * sizeof(Block));
    if (!chain->blocks) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

/*
 * Adds a block to the blockchain after validating the current chain.
 * Resizes the block array if necessary.
 */
void add_block(Blockchain *chain, Block *block) {
    if (!validate_blockchain(chain)) {
        printf("Cannot add block: Blockchain is invalid\n");
        return;
    }

    if (chain->size >= chain->capacity) {
        chain->capacity *= 2;
        chain->blocks = realloc(chain->blocks, chain->capacity * sizeof(Block));
        if (!chain->blocks) {
            printf("Memory reallocation failed\n");
            exit(1);
        }
    }
    chain->blocks[chain->size++] = *block;
}

/*
 * Validates the blockchain by checking:
 * 1. Each block's hash matches its calculated hash.
 * 2. Each block's previous hash matches the actual previous block's hash.
 * Returns 1 if valid, 0 otherwise.
 */
int validate_blockchain(const Blockchain *chain) {
    for (uint32_t i = 0; i < chain->size; i++) {
        Block *block = &chain->blocks[i];
        char current_hash[SHA256_BLOCK_SIZE * 2 + 1];
        strcpy(current_hash, block->hash);
        calculate_block_hash(block);
        if (strcmp(current_hash, block->hash) != 0) {
            printf("Invalid hash for block %u\n", block->index);
            return 0;
        }
        if (i > 0 && strcmp(block->previous_hash, chain->blocks[i-1].hash) != 0) {
            printf("Invalid previous hash for block %u\n", block->index);
            return 0;
        }
    }
    return 1;
}

/*
 * Displays all blocks in the blockchain.
 */
void display_blockchain(const Blockchain *chain) {
    for (uint32_t i = 0; i < chain->size; i++) {
        display_block(&chain->blocks[i]);
    }
}

/*
 * Frees the blockchain's memory.
 */
void free_blockchain(Blockchain *chain) {
    free(chain->blocks);
    chain->blocks = NULL;
    chain->size = chain->capacity = 0;
}
