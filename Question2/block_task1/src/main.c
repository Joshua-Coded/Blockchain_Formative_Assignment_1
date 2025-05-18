#include "block.h"
#include <stdio.h>

int main() {
    printf("=== Task 1: Defining the Block Structure ===\n");

    // Create and initialize a test block
    Block block;
    init_block(&block, 0, "Genesis Block Data", "0"); // Genesis block with no previous hash

    // Display block information
    printf("Test Block:\n");
    display_block(&block);

    return 0;
}
