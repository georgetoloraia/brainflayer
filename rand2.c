#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


// Function to generate a random 66-bit binary number
unsigned long long generate_random_66bit() {
    unsigned long long num = 0;

    // Generate the lower 32 bits
    num |= (unsigned long long)rand() & 0xFFFFFFFF;
    num <<= 32;

    // Generate the upper 34 bits
    num |= (unsigned long long)rand() & 0x3FFFFFFFF;

    return num;
}

// Function to convert a number to hexadecimal string
void to_hexadecimal(unsigned long long num, char *hex) {
    sprintf(hex, "%016llx", num);
}

int main() {
    // srand(time(NULL));  // Initialize random seed based on current time

    char hex[17];  // Buffer for hexadecimal string (16 characters + '\0')
    bool run = true;

    while (run) {
        // Generate a random 66-bit number
        unsigned long long random_num = generate_random_66bit();

        // Convert to hexadecimal
        to_hexadecimal(random_num, hex);

        // Print the random 66-bit number in hexadecimal format
        printf("000000000000000000000000000000000000000000000002%s\n", hex);

        // You can add a condition here to stop generating numbers based on some criteria
        // For example, press Ctrl+C to stop the program
    }

    return 0;
}
