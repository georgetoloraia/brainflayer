#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random hexadecimal number starting with 2 or 3
void generate_random_hex(char *hex) {
    // Set the first digit to 2 or 3
    hex[0] = '2' + (rand() % 2);

    // Generate the remaining 15 hexadecimal digits
    for (int i = 1; i < 17; i++) {
        int r = rand() % 16;
        if (r < 10) {
            hex[i] = '0' + r;
        } else {
            hex[i] = 'a' + (r - 10);
        }
    }

    // Null-terminate the string
    hex[17] = '\0';
}

int main() {
    // srand(time(NULL));  // Initialize random seed based on current time

    char hex[17];  // Buffer for hexadecimal string (16 characters + '\0')
    bool run = true;

    while (run) {
        // Generate a random hexadecimal number
        generate_random_hex(hex);

        // Print the random hexadecimal number
        printf("00000000000000000000000000000000000000000000000%s\n", hex);

        // You can add a condition here to stop generating numbers based on some criteria
        // For example, press Ctrl+C to stop the program
    }

    return 0;
}
