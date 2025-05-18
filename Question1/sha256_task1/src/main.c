#include "sha256.h"
#include <stdio.h>
#include <string.h>

void test_sha256(const char *input) {
    uint8_t hash[SHA256_BLOCK_SIZE];
    sha256(input, strlen(input), hash);
    printf("Input: %s\n", input);
    printf("SHA-256 Hash: ");
    for (int i = 0; i < SHA256_BLOCK_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main() {
    printf("=== Task 1: SHA-256 Hashing ===\n");
    test_sha256("Blockchain Cryptography");
    return 0;
}
