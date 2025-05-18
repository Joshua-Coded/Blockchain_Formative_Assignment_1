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
 * Adds a pre-initialized block to the blockchain.
 */
void add_block(Blockchain *chain, Block *block) {
    block->next = chain->head;
    chain->head = block;
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
        char current_hash[SHA256_BLOCK_SIZE * 2 + 1];
        strcpy(current_hash, current->hash);
        calculate_block_hash(current);
        if (strcmp(current_hash, current->hash) != 0) {
            printf("Invalid hash for block %u\n", current->index);
            return 0;
        }

        next = current->next;
        if (next != NULL && strcmp(next->hash, current->previous_hash) != 0) {
            printf("Invalid previous hash for block %u\n", next->index);
            return 0;
        }
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
 * Saves the blockchain to a text file.
 * Format: One block per section, fields separated by newlines.
 * Returns 1 on success, 0 on failure.
 */
int save_blockchain(const Blockchain *chain, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s for writing\n", filename);
        return 0;
    }

    Block *current = chain->head;
    while (current != NULL) {
        fprintf(file, "%u\n", current->index);
        fprintf(file, "%ld\n", current->timestamp);
        fprintf(file, "%u\n", current->transaction_count);
        for (uint32_t i = 0; i < current->transaction_count; i++) {
            fprintf(file, "%s\n", current->transactions[i]);
        }
        fprintf(file, "%s\n", current->previous_hash);
        fprintf(file, "%s\n", current->hash);
        current = current->next;
    }

    fclose(file);
    return 1;
}

/*
 * Loads the blockchain from a text file.
 * Assumes the same format as save_blockchain.
 * Returns 1 on success, 0 on failure.
 */
int load_blockchain(Blockchain *chain, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s for reading\n", filename);
        return 0;
    }

    // Clear existing blockchain
    free_blockchain(chain);
    init_blockchain(chain);

    char line[TRANSACTION_SIZE];
    while (fgets(line, sizeof(line), file)) {
        Block *block = malloc(sizeof(Block));
        if (!block) {
            printf("Memory allocation failed\n");
            fclose(file);
            free_blockchain(chain);
            return 0;
        }

        // Read index
        block->index = atoi(line);

        // Read timestamp
        if (!fgets(line, sizeof(line), file)) break;
        block->timestamp = atol(line);

        // Read transaction count
        if (!fgets(line, sizeof(line), file)) break;
        block->transaction_count = atoi(line);

        // Read transactions
        for (uint32_t i = 0; i < block->transaction_count; i++) {
            if (!fgets(line, sizeof(line), file)) break;
            line[strcspn(line, "\n")] = '\0'; // Remove newline
            strncpy(block->transactions[i], line, TRANSACTION_SIZE);
            block->transactions[i][TRANSACTION_SIZE - 1] = '\0';
        }

        // Read previous hash
        if (!fgets(line, sizeof(line), file)) break;
        line[strcspn(line, "\n")] = '\0';
        strncpy(block->previous_hash, line, SHA256_BLOCK_SIZE * 2 + 1);

        // Read hash
        if (!fgets(line, sizeof(line), file)) break;
        line[strcspn(line, "\n")] = '\0';
        strncpy(block->hash, line, SHA256_BLOCK_SIZE * 2 + 1);

        block->next = NULL;
        add_block(chain, block);
    }

    fclose(file);

    // Validate loaded blockchain
    if (!validate_blockchain(chain)) {
        printf("Loaded blockchain is invalid\n");
        free_blockchain(chain);
        return 0;
    }

    return 1;
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
