#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>
#include <stddef.h>

#define SHA256_BLOCK_SIZE 32

// Computes SHA-256 hash of input string
void sha256(const char *input, size_t len, uint8_t output[SHA256_BLOCK_SIZE]);

#endif
