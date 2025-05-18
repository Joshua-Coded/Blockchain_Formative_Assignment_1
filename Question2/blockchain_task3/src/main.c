#include "blockchain.h"
#include <stdio.h>
#include <stdlib.h> // Added for malloc

int main() {
    printf("=== Task 3: Simulating Transactions ===\n");

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

    // Display blockchain
    printf("Blockchain Contents:\n");
    display_blockchain(&chain);

    // Validate blockchain
    printf("Validating Blockchain...\n");
    if (validate_blockchain(&chain)) {
        printf("Blockchain is valid!\n");
    } else {
        printf("Blockchain is invalid!\n");
    }

    // Clean up
    free_blockchain(&chain);

    return 0;
}
