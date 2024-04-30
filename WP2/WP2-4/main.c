#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void dec2bin(int *dec, int startIndex);
int inputInt [5];
int bin[8];
int main(int argc, char* argv[]) {
    if (argc != 6){
        printf("You need to enter 5 arguments exactly\n");
        return 0;
    }
    for(int i = 1; i <= 5; i++){
        if(!isdigit( argv[i][0])){
            printf("Sorry you entered a non-digit\n");
            return 0;
        }
    }
    for(int j = 0; j < 5; j++){
        inputInt[j] = atoi(&argv[j+1][0]);
    }
    if(inputInt[0] > 1 || inputInt [1] > 4 || inputInt[2] > 2 || inputInt[3] > 1 || inputInt[4] >1){
        printf("One of your arguments is exceeding the maximum value. The maximum code you can enter is 1 4 2 1 1\n");
        return 0;
    }

    for (int k = 0; k < 5; k++) {
        switch (k) {
            case 0:
                if(inputInt[0] == 1){
                    bin[0] = 1;
                } else{
                    bin[0] = 0;
                }
                break;
            case 1:
                dec2bin(&inputInt[1], 1);
                break;
            case 2:
                dec2bin(&inputInt[2],4);
                break;
            case 3:
                if(inputInt[3] == 1){
                    bin[6] = 1;
                } else{
                    bin[6] = 0;
                }
                break;
            case 4:
                if(inputInt[4] == 1){
                    bin[7] = 1;
                } else{
                    bin[7] = 0;
                }
                break;
        }
    }
    for (int z = 0; z <= 7; z=z+4) {
        int output = (int)pow(2,3)*bin[z] + (int)pow(2,2)*bin[z+1] + (int)pow(2,1)*bin[z+2] + (int)pow(2,0)*bin[z+3];
        printf("%lX", output);
    }

}
void dec2bin(int *dec, int startIndex){
        int upperLimit = (startIndex == 1) ? 3 : 2;
        int index = startIndex;
        for (int i = upperLimit-1; i >= 0 ; i--) {
            int mask = (1 << i);
            if(*dec & mask){
                bin[index] = 1;
                index++;
            } else{
                bin[index] = 0;
                index++;
            }
        }
}

