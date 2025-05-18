#include "blockchain.h"
#include <stdio.h>

int main() {
    printf("=== Question 1, Task 2: Simple Blockchain Simulation ===\n");

    // Initialize blockchain
    Blockchain chain;
    init_blockchain(&chain);

    // Add genesis block
    printf("Adding Genesis Block...\n");
    add_block(&chain, "Genesis Block Data");
    printf("Validating Blockchain...\n");
    if (validate_blockchain(&chain)) {
        printf("Blockchain is valid!\n");
    } else {
        printf("Blockchain is invalid!\n");
        free_blockchain(&chain);
        return 1;
    }

    // Add block 1
    printf("\nAdding Block 1...\n");
    add_block(&chain, "Transaction Data 1");
    printf("Validating Blockchain...\n");
    if (validate_blockchain(&chain)) {
        printf("Blockchain is valid!\n");
    } else {
        printf("Blockchain is invalid!\n");
        free_blockchain(&chain);
        return 1;
    }

    // Add block 2
    printf("\nAdding Block 2...\n");
    add_block(&chain, "Transaction Data 2");
    printf("Validating Blockchain...\n");
    if (validate_blockchain(&chain)) {
        printf("Blockchain is valid!\n");
    } else {
        printf("Blockchain is invalid!\n");
        free_blockchain(&chain);
        return 1;
    }

    // Display final blockchain
    printf("\nFinal Blockchain Contents:\n");
    display_blockchain(&chain);

    // Final validation
    printf("\nFinal Validation...\n");
    if (validate_blockchain(&chain)) {
        printf("Blockchain is valid!\n");
    } else {
        printf("Blockchain is invalid!\n");
    }

    // Clean up
    free_blockchain(&chain);
    return 0;
}
