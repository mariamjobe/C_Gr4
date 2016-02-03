//
//
//85081
//

#include <stdio.h>
#include <string.h>

#define MAX 30

int main(){
    char inp[MAX];
    char reverse[MAX];
    int i = -1, j =0;

    printf("Enter a value to check if it's a palindrome\n");
    scanf("%s", inp);

    // check until it is not the last letter
    while(inp[++i] != '\0');

    // we add the element to the reverse arrat and remove it from the inp array.
    while(i>=0)
        reverse[j++] = inp[--i];

    // to finish the string we add new line
    reverse[j] = '\0';


    if(strcmp(inp,reverse) == 0) {
        printf("The entered word is a palindrome %s, %s\n,", inp, reverse);

    }else{
        printf("The entered word is NOT a palindrome %s, %s \n", inp, reverse);
    }
    return(0);

}
