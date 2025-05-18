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
 * Adds a block with the given data to the blockchain.
 * Creates a new block, sets its previous hash, and links it.
 */
void add_block(Blockchain *chain, const char *data) {
    Block *new_block = malloc(sizeof(Block));
    if (!new_block) {
        printf("Memory allocation failed\n");
        return;
    }

    uint32_t index = chain->size;
    const char *prev_hash = (chain->head == NULL) ? "0" : chain->head->hash;
    init_block(new_block, index, data, prev_hash);
    
    new_block->next = chain->head;
    chain->head = new_block;
    chain->size++;
}

/*
 * Validates the blockchain by checking:
 * 1. Each block's hash matches its calculated hash.
 * 2. Each block's previous hash matches the actual previous block's hash.
 * Since blocks are added to the head, the list is in reverse order (newest first).
 * Returns 1 if valid, 0 otherwise.
 */
int validate_blockchain(const Blockchain *chain) {
    Block *current = chain->head;
    Block *next = NULL;

    if (current == NULL) {
        return 1; // Empty chain is valid
    }

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
        next = current->next;
        if (next != NULL && strcmp(next->hash, current->previous_hash) != 0) {
            printf("Invalid previous hash for block %u\n", next->index);
            return 0;
        }
        // For genesis block, ensure previous_hash is "0"
        if (current->index == 0 && strcmp(current->previous_hash, "0") != 0) {
            printf("Invalid previous hash for genesis block\n");
            return 0;
        }

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
