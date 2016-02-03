//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

// To test the functionality you need first to create an array of integers (Table [MAX]) with MAX number of random
// numbers between 0 and MAXNUMBER.Then you should write a function that for each possible number between 0 – MAXNUMBER
// calculates how many times the number exists in the field. The result is stored in a new field (frequency []).
// Finally, you write a function that given field frequency [] draw the histogram as followed example:
// You should use the function and its function declaration below.


//------Functiondeclaration ----------
    void create_random( int *tab);
    void count_frequency(int *tab, int *freq);
    void draw_histogram(int *freq);


    int main(void) {
        int table[MAX], n;
        int frequency[MAXNUMBER];

        create_random(table);
        // set values of frequency array to 0
        for(int n = 0; n < MAXNUMBER; n++){
            frequency[n] = 0;
        }

        count_frequency(table, frequency);
        draw_histogram(frequency);
    }

       void create_random(int *tab) {
            // Initialize random operator
            srand(time(NULL));
            // assign the array with random numbers between 0 and 20
            for (int i = 0; i < MAX; i++) {
                tab[i] = rand() % MAXNUMBER;
                printf("%d,", tab[i]);


            }
           printf("\n");
        }

        void count_frequency(int *tab,int *freq) {
            for (int i = 0; i < MAX; i++){
                // add elements from table in frequency
                freq[tab[i]]++;
            }
        }

        void draw_histogram(int *freq){
            for (int i = 0; i < MAXNUMBER; i++) {
                // if element is not new line
                if (freq[i] != '\0') {
                    // print element
                    printf("%d    ", i);
                    // loop as many times as the frequency of this element has occured
                for ( int j = 0; j < freq[i]; j++) {
                    printf("x");
                }
                printf("\n");
            }
        }

    }


