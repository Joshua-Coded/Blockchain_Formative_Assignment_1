#include "block.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Initializes a block with the given index and previous hash.
 * Sets timestamp and initializes transaction list.
 */
void init_block(Block *block, uint32_t index, const char *previous_hash) {
    block->index = index;
    block->timestamp = time(NULL);
    block->transaction_count = 0;
    memset(block->transactions, 0, MAX_TRANSACTIONS * TRANSACTION_SIZE);
    strncpy(block->previous_hash, previous_hash, SHA256_BLOCK_SIZE * 2 + 1);
    block->next = NULL;
    calculate_block_hash(block);
}

/*
 * Adds a transaction to the block if space is available.
 * Returns 1 on success, 0 if the transaction list is full.
 */
int add_transaction(Block *block, const char *transaction) {
    if (block->transaction_count >= MAX_TRANSACTIONS) {
        printf("Cannot add transaction: Block %u transaction limit reached\n", block->index);
        return 0;
    }
    strncpy(block->transactions[block->transaction_count], transaction, TRANSACTION_SIZE);
    block->transactions[block->transaction_count][TRANSACTION_SIZE - 1] = '\0';
    block->transaction_count++;
    calculate_block_hash(block); // Update hash with new transaction
    return 1;
}

/*
 * Calculates the SHA-256 hash of the block based on its index, timestamp,
 * transactions, and previous hash. Stores the hash as a hexadecimal string.
 */
void calculate_block_hash(Block *block) {
    char buffer[2048];
    int offset = snprintf(buffer, sizeof(buffer), "%u%ld", block->index, block->timestamp);
    for (uint32_t i = 0; i < block->transaction_count; i++) {
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "%s", block->transactions[i]);
    }
    snprintf(buffer + offset, sizeof(buffer) - offset, "%s", block->previous_hash);

    uint8_t hash[SHA256_BLOCK_SIZE];
    sha256(buffer, strlen(buffer), hash);

    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        sprintf(&block->hash[i * 2], "%02x", hash[i]);
    }
    block->hash[SHA256_BLOCK_SIZE * 2] = '\0';
}

/*
 * Displays block details: index, timestamp, transactions, previous hash, and hash.
 */
void display_block(const Block *block) {
    char time_str[26];
    ctime_r(&block->timestamp, time_str);
    time_str[24] = '\0'; // Remove newline
    printf("Block %u:\n", block->index);
    printf("Timestamp: %s\n", time_str);
    printf("Transactions (%u):\n", block->transaction_count);
    for (uint32_t i = 0; i < block->transaction_count; i++) {
        printf("  %u: %s\n", i, block->transactions[i]);
    }
    printf("Previous Hash: %s\n", block->previous_hash);
    printf("Hash: %s\n\n", block->hash);
}

/*
 * Frees a block's memory.
 */
void free_block(Block *block) {
    free(block);
}
