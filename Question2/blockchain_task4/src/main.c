#include "blockchain.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== Task 4: Blockchain Persistence ===\n");

    // Initialize blockchain
    Blockchain chain;
    init_blockchain(&chain);

    // Create and add genesis block
    Block *genesis = malloc(sizeof(Block));
    init_block(genesis, 0, "0");
    add_transaction(genesis, "Alice sends 10 BTC to Bob");
    add_transaction(genesis, "Bob sends 5 BTC to Charlie");
    add_block(&chain, genesis);

    // Create and add second block
    Block *block1 = malloc(sizeof(Block));
    init_block(block1, 1, genesis->hash);
    add_transaction(block1, "Charlie sends 3 BTC to Dave");
    add_transaction(block1, "Dave sends 1 BTC to Eve");
    add_transaction(block1, "Eve sends 0.5 BTC to Alice");
    add_block(&chain, block1);

    // Create and add third block
    Block *block2 = malloc(sizeof(Block));
    init_block(block2, 2, block1->hash);
    add_transaction(block2, "Alice sends 2 BTC to Frank");
    add_block(&chain, block2);

    // Display original blockchain
    printf("Original Blockchain Contents:\n");
    display_blockchain(&chain);

    // Validate original blockchain
    printf("Validating Original Blockchain...\n");
    if (validate_blockchain(&chain)) {
        printf("Original blockchain is valid!\n");
    } else {
        printf("Original blockchain is invalid!\n");
    }

    // Save blockchain to file
    printf("Saving blockchain to blockchain.dat...\n");
    if (save_blockchain(&chain, "blockchain.dat")) {
        printf("Blockchain saved successfully!\n");
    } else {
        printf("Failed to save blockchain\n");
    }

    // Clear blockchain
    free_blockchain(&chain);

    // Load blockchain from file
    printf("Loading blockchain from blockchain.dat...\n");
    if (load_blockchain(&chain, "blockchain.dat")) {
        printf("Blockchain loaded successfully!\n");
    } else {
        printf("Failed to load blockchain\n");
    }

    // Display loaded blockchain
    printf("Loaded Blockchain Contents:\n");
    display_blockchain(&chain);

    // Validate loaded blockchain
    printf("Validating Loaded Blockchain...\n");
    if (validate_blockchain(&chain)) {
        printf("Loaded blockchain is valid!\n");
    } else {
        printf("Loaded blockchain is invalid!\n");
    }

    // Clean up
    free_blockchain(&chain);

    return 0;
}
