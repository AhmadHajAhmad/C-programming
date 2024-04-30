#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dec2bin(int* dec, int number);
int main(int argc, char*argv[]) {
    int firstBin[4];
    int secondBin[4];
    int wholeBinary[8];
    int code[5];
    if (argc < 2) {
        printf("Enter one argument");
        return 0;
    }
    if (argv[1][0] == '\0' || argv[1][1] == '\0') {
        printf("Please Enter two hexa values\n");
        return 0;
    }
    char firstArgument[2] = {argv[1][0], '\0'};
    char secondArgument[2] = {argv[1][1], '\0'};
    int argument1 = (int) strtol(firstArgument, NULL, 16);
    int argument2 = (int) strtol(secondArgument, NULL, 16);

    if (argument1 == 5 || argument1 == 6 || argument1 == 7 || argument1 > 0XC || argument2 > 0XB) {
        printf("The first character should be less than C excluding 5, 6, 7 and the second character should be less than B\n");
        return 0;
    }

    dec2bin(firstBin, argument1);
    dec2bin(secondBin, argument2);

    int indexWholeBin = 0;

    for (int i = 0; i <= 3; ++i) {
        wholeBinary[indexWholeBin] = firstBin[i];
        indexWholeBin++;
    }
    for (int i = 0; i <= 3; ++i) {
        wholeBinary[indexWholeBin] = secondBin[i];
        indexWholeBin++;
    }


    for (int j = 0; j <= 7; ++j) {
        printf("%d", wholeBinary[j]);
    }
    printf("\n");

    for (int k = 0; k <= 7; ++k) {
        if (k == 0) {
            code[0] = wholeBinary[k];
        } else if (k == 6) {
            code[3] = wholeBinary[k];
        } else if (k == 7) {
            code[4] = wholeBinary[k];
        } else if (k == 1) {
            code[1] = (int) pow(2, 2) * wholeBinary[k] + (int) pow(2, 1) * wholeBinary[k + 1] +
                      (int) pow(2, 0) * wholeBinary[k + 2];
        } else if (k == 4) {
            code[2] = (int) pow(2, 1) * wholeBinary[k] + (int) pow(2, 0) * wholeBinary[k + 1];
        }
    }
    for (int i = 0; i <= 4; i++) {
        printf("%d", code[i]);
    }
    printf("\n");
    printf("Name %10c Value\n"
           "-----------------------------\n"
           "engine_on %7d\n"
           "gear_pos %8d\n"
           "key_pos %9d\n"
           "brake1 %10d\n"
           "brake2 %10d\n", ' ', code[0], code[1], code[2], code[3], code[4]);
}
void dec2bin(int* dec, int number){
    int index =0;
    for (int i = 3; i >=0 ; i--) {
        int mask = 1<<i;
        if(number & mask){
            dec[index] = 1;
            index++;
        }else{
            dec[index] = 0;
            index++;
        }
    }
}
