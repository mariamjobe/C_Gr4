//
// Created by Mariam Jobe on 2016-02-01.
//
#include <stdio.h>
#include <string.h>

int compNoLib(char *, char *);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("\tToo few arguments!\n");

    }else{
        if (compNoLib(argv[1], argv[2]))
            printf("Values are equal, compare without lib function\n");
        else
            printf("Values are NOT equal\n");

        printf("\n");
        printf("Compare with strcomp()\n");
        if (strcmp(argv[1], argv[2]) == 0)
            printf("Values are equal\n");
        else
            printf("Values are NOT equal\n");
        printf("\n");

    }
        return(0);


}

int compNoLib(char *val1, char *val2) {
    int i = 0;
    // if length och values are the same
    if(strlen(val1) == strlen(val2)) {

    //check length is bigger than or equal to zero and if the element are the same
        // we add one to i and continue iterating

        while(strlen(val1) >= i) {
            if(*(val1 + i) == *(val2 + i))
                i++;
            else
                // If the values aren't the same return 0;
                return 0;
        }
        // if the length is the same
        if(strlen(val1) == i)
            return 1;
    }
    else
        return 0;
}