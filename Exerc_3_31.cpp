#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter #####
#define MAX 5
#define NUMBER 100

// ##### Typedefs ####
typedef struct q {
    int number;
    struct q *prev;
    struct q *next;
} REGTYPE;

//#####Function declarations #####

REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main(int argc, char *argv[]) {
    int nr = 0;
    REGTYPE *akt_post, *head = NULL;

    srand(time(0)); // Random seed
    head = random_list();
    akt_post = head;
    while (akt_post != NULL) {
        printf("\n Post nr %2d : %d", nr++, akt_post->number);
        akt_post = akt_post->next;
    }

    printf("\n");

    //add the new function
    head = add_first(head, 100);
    akt_post = head;
    nr = 0;
    while (akt_post != NULL) {
        printf("\n Post nr %2d : %d", nr++, akt_post->number);
        akt_post = akt_post->next;
    }

// --- Free of allocated memory ---
    while ((akt_post = head) != NULL) {
        head = akt_post->next;
        free(akt_post);
    }
//---------------------------------
    return 0;
}
// ==== End main =========================================

REGTYPE* random_list(void) {
    int i = 0;
    REGTYPE *top, *old, *item;

    item = (REGTYPE*)malloc(sizeof(REGTYPE));

    item->number = rand()%(NUMBER+1);
    item->prev = NULL;
    item->next = NULL;

    top = item;

    while(i < MAX-1){
        old = item;
        item = (REGTYPE*)malloc(sizeof(REGTYPE));
        item->number = rand()%(NUMBER+1);
        item->prev = old;
        item->next = NULL;

        old->next = item;

        i++;
    }

    return (top);
}
//==========================================================

REGTYPE* add_first(REGTYPE* temp, int data) {
// Adds a record first in list and set the field number to data
    REGTYPE* item = (REGTYPE*)malloc(sizeof(REGTYPE));
    item->number = data;
    item->prev = NULL;
    item->next = temp;

    temp->prev = item;

    return item;
}