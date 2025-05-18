#include "block.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Initializes a block with the given index and previous hash.
 * Sets timestamp to current time, generates sample data, and calculates hash.
 */
void init_block(Block *block, uint32_t index, const char *previous_hash) {
    block->index = index;
    block->timestamp = time(NULL);
    snprintf(block->data, DATA_SIZE, "Block %u Data", index);
    strncpy(block->previous_hash, previous_hash, SHA256_BLOCK_SIZE * 2 + 1);
    calculate_block_hash(block);
}

/*
 * Calculates the SHA-256 hash of the block based on its index, timestamp,
 * data, and previous hash. Stores the hash as a hexadecimal string.
 */
void calculate_block_hash(Block *block) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%u%ld%s%s",
             block->index, block->timestamp, block->data, block->previous_hash);

    uint8_t hash[SHA256_BLOCK_SIZE];
    sha256(buffer, strlen(buffer), hash);

    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        sprintf(&block->hash[i * 2], "%02x", hash[i]);
    }
    block->hash[SHA256_BLOCK_SIZE * 2] = '\0';
}

/*
 * Displays block details: index, timestamp, data, previous hash, and hash.
 */
void display_block(const Block *block) {
    printf("Block %u:\n", block->index);
    printf("Timestamp: %ld\n", block->timestamp);
    printf("Data: %s\n", block->data);
    printf("Previous Hash: %s\n", block->previous_hash);
    printf("Hash: %s\n\n", block->hash);
}
