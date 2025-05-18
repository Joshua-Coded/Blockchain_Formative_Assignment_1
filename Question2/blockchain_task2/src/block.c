#include "block.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Initializes a block with the given index, data, and previous hash.
 * Sets timestamp to current time and calculates the block's hash.
 */
void init_block(Block *block, uint32_t index, const char *data, const char *previous_hash) {
    block->index = index;
    block->timestamp = time(NULL);
    strncpy(block->data, data, DATA_SIZE);
    block->data[DATA_SIZE - 1] = '\0'; // Ensure null-termination
    strncpy(block->previous_hash, previous_hash, SHA256_BLOCK_SIZE * 2 + 1);
    block->next = NULL;
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
    char time_str[26];
    ctime_r(&block->timestamp, time_str);
    time_str[24] = '\0'; // Remove newline
    printf("Block %u:\n", block->index);
    printf("Timestamp: %s\n", time_str);
    printf("Data: %s\n", block->data);
    printf("Previous Hash: %s\n", block->previous_hash);
    printf("Hash: %s\n\n", block->hash);
}

/*
 * Frees a block's memory.
 */
void free_block(Block *block) {
    free(block);
}
