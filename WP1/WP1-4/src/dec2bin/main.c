#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isDecimal(const char *str) {
    if (str == NULL || *str == '-') {
        return 0;
    }
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int countBit(int bits) {
    int count = 0, i;
    if (bits == 0) return 0; // If the number is 0, exit as no bits are needed

    for (i = 0; i < 64; i++) { // Iterate through each bit position (up to 64 bits)
        if ((1 << i) & bits) // Check if the bit at position 'i' is set, shifting bits
            count = i; // Update count to the current bit position
    }

    return ++count; // Return the position of the highest set bit plus one
}
// Inspiration from https://www.scaler.com/topics/decimal-to-binary-in-c/
// The function for converting decimal to its binary representation
// It takes in the number we provided which then converts to a char binarystr
void binaryConversion(long number, char *binaryStr, int bits) {
    int index = 0;

    // Fill the string with leading zeros based on the required number of bits
    for (int i = bits - 1; i >= 0; i--) {
        binaryStr[index++] = (number & (1L << i)) ? '1' : '0';
    }

    binaryStr[index] = '\0'; // Null-terminate the string
}
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("provide a number for conversion\n");
        return 2;
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("Enter a decimal number to convert to its binary and hexdecimal representation.\n");
        return 0;
    }
    if (isDecimal(argv[1])) {
        long number = strtol(argv[1], NULL, 10);
        long numberCopy = number;
        int binaryArray[128];
        int bits = countBit(number); // Use countBit to determine the number of bits required
        char binaryStr[33];
        binaryConversion(number, binaryStr, bits);
        int counter = 0;
        while (numberCopy > 0)
        {
            binaryArray[counter] = numberCopy % 2;
            numberCopy = numberCopy / 2;
            counter++;
        }
        int zeros = (8 - (counter % 8));
        for (int i = 0; i < zeros; i++)
        {
            printf("0");
        }
        for (int j = counter - 1; j >= 0; j--)
        {
            printf( "%d", binaryArray[j]);
        }printf("\n");
        // printf("%s\n", binaryStr);
        return 0;
    } else {
        printf("Unsuccessful conversion\n");
        return 2;
    }
}