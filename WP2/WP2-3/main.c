#include "stdio.h"
#include <string.h>
#include <stdbool.h>
// -----typedefs -------
    typedef struct {
        char firstname[20]; // The first name Attribute than can hold 19 characters + null terminator
        char famname[20]; // The family name Attribute than can hold 19 characters + null terminator
        char pers_number[13]; // The swedish personal number that holds 12 numbers YYYYMMDDXXXX + null terminator
    } PERSON;
    FILE *fptr; // Creating a pointer to a file
    char charLine [1024]; //Characters array for each line in the text file
    void write_new_file(PERSON *inrecord); //The prototype of creating a new file and insert a dummy input
    bool search_by_firstname(char *name); //The prototype of searching either first name or family name
    void append_file(PERSON *inrecord); //The prototype of adding a new person to the file
    void printFile(void); //The prototype of printing all people in the file
    int main(void){ // The begining of the main function
        int menuInput; //The declaration of the menu input that should be between 1 and 5
        PERSON ppost; // The declaration of creating the ppost
        while (menuInput!=5){ // The beginning of the while loop
            printf("1 Create a new and delete the old file.\n"
                                    "2 Add a new person to the file.\n"
                                    "3 Search for a person in the file.\n"
                                    "4 Print out all in the file.\n"
                                    "5 Exit the program.\n"
                                    "option: ");
            scanf("%d", &menuInput); // Scan function will take the menu option
            if(menuInput == 1){ // If the menu option is equal to 1
                strcpy(ppost.firstname, "Harry"); // Assign the dummy person this first name
                strcpy(ppost.famname, "Potter"); // Assign the dummy person this first name
                strcpy(ppost.pers_number,"19950527"); // Assign the dummy person this personal number
                fptr = fopen("Ahmadtext", "wb"); // Assign the pointer to file "Ahmadtext" with reading binary mode
                write_new_file(&ppost); // Calling the create new file function and pass the first address of ppost
                ppost.firstname[0] = '\0'; // Reset the first name
                ppost.famname[0] = '\0'; // Reset the family name
                ppost.pers_number[0] = '\0'; // Reset the personal number
            }else if(menuInput == 2){ // If the menu option is equal to 2
                printf("Enter the first name: ");
                scanf("%s", ppost.firstname); // Assign the first name for ppost
                printf("Enter the family name: ");
                scanf("%s", ppost.famname); // Assign the family name for ppost
                printf("Enter the personal Number: ");
                scanf("%s", ppost.pers_number); // Assign the personal number for ppost
                append_file(&ppost); // Call the append function and pass the first address of ppost
            }else if(menuInput == 3){ // If the menu option equal 3
                while (true){ // The beginning of the while loop
                    fptr = fopen("Ahmadtext", "rb"); // The pointer is pointing to a file in read binary mode
                    if(fptr==NULL){ // Check if the file exists
                        printf("Failed to open the file.\n");
                        continue; // If the file does not exist, leave option 3
                    }
                    printf("Enter the name or press e to exit this option: ");
                    scanf("%s", &ppost.firstname); // Assign the first name to the ppost
                    if(ppost.firstname[0]=='e' && strlen(ppost.firstname)){ // Check if the character the user entered is "e" to exit option 3
                        break; // Exit the while loop of option 3
                    }
                    bool res = search_by_firstname(&ppost.firstname); // Call the function of searching for a name and pass it the address of the first name
                    if(res == true){ // If the name is found exit the while loop, if not, the user can insert the name again
                        break; // Exit the while loop
                    }
                }
            }else if(menuInput==4){ // If the menu option is 4
                fptr = fopen("Ahmadtext", "rb"); // The pointer fptr is pointing to the file in read binary mode
                if(fptr==NULL){ // If the file does not exist, print a statement and jump over this iteration
                    printf("Failed to open the file.\n");
                    continue; // Jump over the iteration
                }
                printFile(); // If the file exists, call the function printFile() to print all records
            }else if(menuInput !=5 && (menuInput<1 || menuInput>5)){ // if the user entered a menu option outside the menu boundries
                printf("Choose between option 1 and 5\n");
            }
            fclose(fptr); // close to what the poinster is pointing to
        }
        return(0);
    }
    void write_new_file(PERSON *inrecord){ // The function to create a new file and add a record
        // Write to the file first name of the person
        fwrite(inrecord->firstname, sizeof (char), strlen(inrecord->firstname), fptr);
        char space = ' '; // decleration of a space
        char enter = '\n'; // decleration of a new line character
        fwrite(&space, sizeof(char), 1, fptr); // Write to the file an empty space
        // Write to the file family name of the person
        fwrite(inrecord->famname, sizeof (char), strlen(inrecord->famname), fptr);
        // Write to the file an empty space
        fwrite(&space, sizeof(char), 1, fptr);
        // Write to the file the personal number of the person
        fwrite(inrecord->pers_number, sizeof (char), strlen(inrecord->pers_number), fptr);
        // Write to the file new Line character
        fwrite(&enter, sizeof(char), 1, fptr);
    }
    void append_file(PERSON *inrecord){
        fptr = fopen("Ahmadtext", "ab"); // The pointer to a file in appending with binary mode
        write_new_file(inrecord); // call the write new file function. I did this to avoid repeating the whole logic again
    }
    bool search_by_firstname(char *name){ // This function is to search either for the first name or family name
        // Assigning a temp array of size 255 characters + null terminator. This will used for the first name
        char temp[256];
        // // Assigning a temp2 array of size 255 characters + null terminator. This will used for the family name
        char temp2[256];
        int noResult=1; // A boolean to indicate whether there is an output or not
        // This while function will do as follow: 1- Read the whole line. 2- The first sscanf will copy the everything
        // before the first space; which is the first name. 3- Copy the first name characters to the temp array.
        // 4-Copy all character after the first space which is the first character of the family name to the second space
        // which is basically the end of the family name to temp2. Compare the name you are searching for with temp1 and
        // temp2. Everytime the name you are searching for matches either the first name or family name, print the whole line
        while (fgets(charLine, sizeof (charLine), fptr)!=NULL){
            sscanf(charLine,"%255s", temp); // Copy the first name from text file to the temp characters array
            sscanf(charLine, "%*s %255s", temp2); // Copy the family name from the text file to the temp2 characters array
            // Check if there is a match between the name and the first name or family name
            if (strcasecmp(temp, name) == 0 || strcasecmp(temp2, name) == 0){
                noResult=0; // Change the status of the boolean value
                printf("%s", charLine);// If a match is found, print the entire line
            }
        }
        if(noResult){ // If the boolean value is still True(Did not find a line the previous step), print the following
            printf("No result found with the provided name\n");
            return false; // return false
        }
        printf("\n"); // Print a new line character to have a better reading for the user
        return true; // If there is output, return true
    }
    void printFile(void) { // This function will print all records in the file
        int isEmpty=1; // Decleration a boolean to check if there is an output
        // This while loop will iterate over each line
        while (fgets(charLine, sizeof(charLine), fptr) != NULL) {
                isEmpty=0; // Change the boolean value if a line is found
                printf("%s", charLine);
        }
        if(isEmpty){ // If the boolean is not changed that means no line found which will print the following statement
            printf("The file is empty.\n");
        }
        printf("\n"); // Print the new line
    }
