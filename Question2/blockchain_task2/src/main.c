#include "blockchain.h"
#include <stdio.h>

int main() {
    printf("=== Task 2: Creating a Blockchain ===\n");

    // Initialize blockchain
    Blockchain chain;
    init_blockchain(&chain);

    // Add blocks
    add_block(&chain, "Genesis Block Data");
    add_block(&chain, "Transaction Data 1");
    add_block(&chain, "Transaction Data 2");

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
