#include <stdio.h>
#include <stdlib.h>

int main() {
    char binary[33]; // Buffer to hold the input binary number

    // We read the binary input from another program
    // %32s tells scanf to read up to 32 characters to prevent buffer overflow
    if (scanf("%32s", binary) != 1) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Convert the binary string to a number, nr 2 in the argument is the base for conversion
    // this is where string gets converted to a decimal nr.
    long int binaryNumber = strtol(binary, NULL, 2);

    // Print the number in hexadecimal format, lX is used for printing uppercase hexadecimal nr.
    // this is where we go from a decimal nr to a hexa.
    printf("%lX\n", binaryNumber);

    return 0;
}
