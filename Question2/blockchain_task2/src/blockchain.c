#include "blockchain.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Initializes an empty blockchain.
 */
void init_blockchain(Blockchain *chain) {
    chain->head = NULL;
    chain->size = 0;
}

/*
 * Adds a block to the blockchain with the given data.
 * Links the new block to the previous block's hash.
 */
void add_block(Blockchain *chain, const char *data) {
    Block *new_block = malloc(sizeof(Block));
    if (!new_block) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Determine previous hash
    char *prev_hash = chain->size == 0 ? "0" : chain->head->hash;
    init_block(new_block, chain->size, data, prev_hash);

    // Add to linked list
    new_block->next = chain->head;
    chain->head = new_block;
    chain->size++;
}

/*
 * Validates the blockchain by checking:
 * 1. Each block's hash matches its calculated hash.
 * 2. Each block's previous hash matches the actual previous block's hash.
 * Returns 1 if valid, 0 otherwise.
 */
int validate_blockchain(const Blockchain *chain) {
    Block *current = chain->head;
    Block *prev = NULL;

    while (current != NULL) {
        // Verify current block's hash
        char current_hash[SHA256_BLOCK_SIZE * 2 + 1];
        strcpy(current_hash, current->hash);
        calculate_block_hash(current);
        if (strcmp(current_hash, current->hash) != 0) {
            printf("Invalid hash for block %u\n", current->index);
            return 0;
        }

        // Verify previous hash
        if (prev != NULL && strcmp(current->previous_hash, prev->hash) != 0) {
            printf("Invalid previous hash for block %u\n", current->index);
            return 0;
        }

        prev = current;
        current = current->next;
    }
    return 1;
}

/*
 * Displays all blocks in the blockchain.
 */
void display_blockchain(const Blockchain *chain) {
    Block *current = chain->head;
    while (current != NULL) {
        display_block(current);
        current = current->next;
    }
}

/*
 * Frees the blockchain's memory.
 */
void free_blockchain(Blockchain *chain) {
    Block *current = chain->head;
    while (current != NULL) {
        Block *temp = current;
        current = current->next;
        free_block(temp);
    }
    chain->head = NULL;
    chain->size = 0;
}
