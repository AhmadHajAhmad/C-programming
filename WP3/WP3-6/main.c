#include <stdio.h>
#include <string.h>
void copyString( char * src, char * dest, int size); // decleration of the copyString function
int main(int argc, char * argv[]) {
    char input [1024]; // Array to contain the input
    char result1[21]; // Define the array that will be used for the strcpy function
    char result2[21]; // Define the array that will be used for copyString function
    fgets(input, sizeof (input), stdin); // Get the input from the user or from the file
    input[strcspn(input, "\n")] = '\0'; // Remove the new line character from the input and replace it with null terminator
    if(strlen(input) > 20){ // Chekc if the input is greater than 20 characters
        printf("Too many characters");
        return 0;
    }
    strcpy(result1, input); // Use the strcpy function to copy the strings from input to result1
    int length = strlen(input); // Calculate the length of the input
    copyString(input, result2, length); // Call the copyString function and pass it the input, result2, and the length
    printf("The original string is %s \n", input); // print the input the user entered
    printf("The copied string by using strcpy is %s\n", result1); // print result1 by using strcpy
    printf("The copied string by using customized function is %s", result2); // print result2 by using copyString
    return 0;
}
void copyString (char * src, char * dest, int size){
    int i = 0; // Declare the integer i
    for ( ; i<size; i++){ // for loop that iterate until it reaches the size which is equal the length of the input
        dest[i] = src[i]; // Assign value from the src(input) to dest(result2)
    }
    dest[size] = '\0'; // Make sure to add the null terminator at the end
}
