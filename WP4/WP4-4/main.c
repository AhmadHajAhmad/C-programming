#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int search_number(int number, int tab[], int size); // Define the function that will search for numbers
void sort (int size, int tab []); // Define the function that will sort the array based on bubble sort algorithm
int main(){ // The beginning of the main function
    int test [] = {1, 2, 34, 5, 67, 3, 23, 2, 13, 10}; // The pre-defined array
    char input [100]; // The array that will take input from the user
    printf("Enter the number you are searching for: ");
    scanf("%99s", input); // Use scanf to take the input from the user
    int inValid = 0; // Declare the variable inValid
    for (int i = 0; i < strlen(input); ++i){ //Iterate over the input
        if(!isdigit((char)input[i])){ // If one of the character is not a digit
            inValid = 1; // Will change the invalid to 1
            break; // Exit the loop
        }
    }
    if (inValid){ // if the inValid is true or equal to 1
        printf("Please enter a number\n");
        return 0; // Stop the program
    }else{ // If the input characters are digits
        int inputInteger = (int)strtol(input,NULL, 10); // Convert the array to of characters to integer
        int size = sizeof (test)/ sizeof (test[0]); // calculate the size of the test array
        int index = search_number(inputInteger, test, size); // Assign the return from the search_number function
        printf("The index is %d\n", index);
        sort(size, test); // Call the sort function
        for(int i=0; i<size; i++){ // For loop that will iterate over the sorted test array
            printf("%d ", test[i]);
        }
        return 0; // Stop the program
    }
}
int search_number(int number, int tab[], int size){ // The beginning of the function
    for (int i = 0; i < size; ++i) { // For loop that will iterate of the tab = test array
        if (number == tab[i]){ // If the number tha we are searching for is found in the array, return the index
            return i; // return the index of element
        }
    }
    return -1; // If nothing is found, return -1
}
void sort (int size, int tab []){ // The beginning of the bubble sort algorithm
    printf("The size is %d\n", size);
    for (int i = 0; i < size; i++) { // The first for loop that will count the number of laps
        for (int j = 0; j< size-i-1; j++){ // The inner for loop
            if (tab[j]>tab[j+1]){ // if the element at j is greater than the element st j+1
                int temp = tab[j]; // create a temp variable that will hold the value at j
                tab[j] = tab[j+1]; // assign the value for index j to the value of index j+1
                tab[j+1] = temp; // assign the index j+1 to the temp value
            }
        }
    }
}
