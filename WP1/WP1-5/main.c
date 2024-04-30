// Include sections
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 // Defines the maximum number of the values in the table
#define MAXNUMBER 5 // Defines the maximum value of random numbers
// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab ){
    int randomNumber; // Variable of the random number
    //This for loop will generate a random number between zero and MAXNUMBER and then the random number to into the array
    for(int i = 0; i < MAX; i++){
        randomNumber = rand() % (MAXNUMBER + 1); // The logic of generating the  random number
        tab[i] = randomNumber; // Assigning the array index to the random number
    }
    printf("table[]={");
    for (int j = 0; j < MAX; ++j) {  // This for loop will print out the array
        if (j !=MAX-1){ //The idea of the if-statement to not add a comma (",") after the last integer
            printf("%d,", tab[j]);
        }else{
            printf("%d}", tab[j]);
        }
    }
}
// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ){
    printf("\n");
    for (int i = 0; i <= MAXNUMBER ; ++i) { // This for loop will set all values in the freq array to zero
        freq[i] = 0; // Assigning each index to zero before starting to draw the histogram
    }
    for(int i = 0; i < MAX; ++i){
        // In this line, the index of the freq array will be the value of the tab array. The counter will be incremented
        // by 1 each time the index of the freq is encountered again. if the tab[0] = 5, freq[5] = freq[5] + 1 = 0+1
        freq[tab[i]] = freq[tab[i]] +1;
    }
}
// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ) {
    printf("\n");
    for (int i = 0; i <=MAXNUMBER; ++i) {     //For loop to draw the histogram
        if (freq[i] > 0) {  //This if-statement will make sure that we print out numbers that has frequency zero
            if (i < 10) {   // To have a proper alignment, if the number is less than 10, an extra space will be printed
                printf("%d    ", i);
            } else {
                printf("%d   ", i);
            }
            for (int j = 1; j <= freq[i]; j++) { // This for loop will print the "x" between 1 and the frequency value
                printf("x");
            }
            printf("\n");
        }
    }
}
// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){
    srand(time(NULL)); // Initializes the random number generator with a seed that changes over time
    int table[MAX], n ; // Defining the table size
    create_random(table); // Generating random numbers in the table array
    int frequency[MAXNUMBER];  // Define the maximum number value in the frequency array
    count_frequency(table, frequency); // Creating the frequency of each number in the table array in the frequency array
    draw_histogram(frequency); // Taking the frequency array to draw the histogram
}
