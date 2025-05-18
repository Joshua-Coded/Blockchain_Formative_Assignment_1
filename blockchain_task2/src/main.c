#include "sha256.h"
#include "block.h"
#include "blockchain.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Displays the interactive menu and returns the user's choice.
 */
int display_menu() {
    int choice;
    printf("\n=== Blockchain Simulation Menu ===\n");
    printf("1. Add a new block\n");
    printf("2. Display blockchain\n");
    printf("3. Validate blockchain\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    getchar(); // Clear newline from input buffer
    return choice;
}

/*
 * Prompts the user for block data or uses default data if empty.
 */
void get_block_data(char *data, size_t max_len, uint32_t index) {
    printf("Enter data for block %u (or press Enter for default 'Block %u Data'): ", index, index);
    fgets(data, max_len, stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove trailing newline
    if (strlen(data) == 0) {
        snprintf(data, max_len, "Block %u Data", index);
    }
}

int main() {
    printf("=== Task 2: Simple Blockchain Simulation ===\n");

    // Initialize blockchain
    Blockchain chain;
    init_blockchain(&chain);

    // Add genesis block
    Block genesis;
    init_block(&genesis, 0, "0"); // No previous hash for genesis
    add_block(&chain, &genesis);
    printf("Genesis block added.\n");

    // Interactive menu loop
    while (1) {
        int choice = display_menu();
        switch (choice) {
            case 1: {
                // Add a new block
                Block new_block;
                char data[DATA_SIZE];
                get_block_data(data, DATA_SIZE, chain.size);
                init_block(&new_block, chain.size, chain.blocks[chain.size - 1].hash);
                strncpy(new_block.data, data, DATA_SIZE);
                calculate_block_hash(&new_block); // Recalculate hash with new data
                add_block(&chain, &new_block);
                printf("Block %u added.\n", new_block.index);
                break;
            }
            case 2:
                // Display blockchain
                printf("\nBlockchain Contents:\n");
                display_blockchain(&chain);
                break;
            case 3:
                // Validate blockchain
                printf("\nValidating Blockchain...\n");
                if (validate_blockchain(&chain)) {
                    printf("Blockchain is valid!\n");
                } else {
                    printf("Blockchain is invalid!\n");
                }
                break;
            case 4:
                // Exit
                printf("\nExiting system...\n");
                free_blockchain(&chain);
                printf("Blockchain memory freed. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please enter 1-4.\n");
        }
    }

    return 0;
}
