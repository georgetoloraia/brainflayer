#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// Function to generate a random 66-bit binary number
void generateRandom66BitNumber(uint64_t *high, uint64_t *low) {
    // Seed the random number generator
    srand((unsigned) time(NULL));

    // Generate a random 64-bit number for the lower part
    *low = ((uint64_t) rand() << 32) | rand();

    // Generate a random 2-bit number for the higher part
    *high = rand() & 0x3; // Mask to get only the lower 2 bits
}

int main() {
    uint64_t high, low;

    // Generate the random 66-bit number
    generateRandom66BitNumber(&high, &low);

    // Print the high part (2 bits)
    for (int i = 1; i >= 0; i--) {
        // printf("%llu", (high >> i) & 1);
    }

    // Print the low part (64 bits)
    for (int i = 63; i >= 0; i--) {
        // printf("%llu", (low >> i) & 1);
    }

    // Print the result as hexadecimal with leading zeros
    printf("%048llx%016llx\n", high, low);

    return 0;
}
