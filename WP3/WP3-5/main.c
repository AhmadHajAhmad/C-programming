#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
void printNumbers(int * ptr);
void multiplications(int * ptr);
int main() {
    srand(time(NULL));
    int input [MAX];
    for (int i = 0; i < MAX; ++i) {
        input[i] = 1+ (rand() % 99);
    }
    printf("The value of the address of the array (pointer) is: %lx\n", &input[0]);
    printf("First integer in the array is (array[0]): %d\n", input[0]);
    printf("The last integer in the array is: %d\n", input[MAX-1]);
    printf("The size of an integer (number of bytes) is: %d\n", sizeof (int ));
    printf("The size of the whole array in bytes is: %d\n", sizeof (input));

    int * ptr = input;
    printNumbers(ptr);
    multiplications(ptr);
    return 0;
}
void printNumbers(int * ptr){
    for (int i = 1; i <= MAX; ++i) {
        printf("The value of the %d element is %d\n",i, *ptr);
        ptr++;
    }
}
void multiplications (int *  ptr){
    for (int i = 1; i <= MAX; ++i) {
        printf("The doubled value of the %d element is %d\n",i, *ptr*2);
        ptr++;
    }
}
