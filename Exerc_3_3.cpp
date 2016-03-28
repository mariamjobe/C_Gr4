/* ====================================
File name: exerc_3_3.cpp
Date: 2016-02-10
Group Number: 4
Members that contributed:
Mariam Mahoob
Mariam Jobe
Linhang Nie
Demonstration code: [<12424>]
Important, No code no bonus! Mariam
====================================== */

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
REGTYPE* add_first(REGTYPE* head, int data);

//###### Main program #######
int main(int argc, char *argv[]) {
	int nr = 0;
	REGTYPE *current_node, *head = NULL;

	srand(time(0)); // Random seed
	head = random_list();
	current_node = head->next;
	while (current_node != NULL) {
        REGTYPE next_node = *(current_node->next);
        if(next_node.next == NULL)
            break;
        printf("\n Post nr %2d : %d", nr++, current_node->number);
		current_node = current_node->next;
	}

	printf("\n adding to head:");

	head = add_first(head, 100);
	current_node = head->next;
	nr = 0;
	while (current_node != NULL) {
        REGTYPE next_node = *(current_node->next);
        if(next_node .next == NULL)
            break;
		printf("\n Post nr %2d : %d", nr++, current_node->number);
		current_node = current_node->next;
	}

// --- Free of allocated memory ---
	while ((current_node = head) != NULL) {
		head = current_node->next;
		free(current_node);
	}
//---------------------------------
	return 0;
}
// ==== End main =========================================
REGTYPE* newNode(int x){
    REGTYPE* newNode = (REGTYPE*)malloc(sizeof(REGTYPE));
    newNode->number = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}
REGTYPE* insert(REGTYPE* prenode, REGTYPE* postnode, int data){
    REGTYPE* current = newNode(data);

    current->prev = prenode;
    current->next = postnode;
    prenode->next = current;
    postnode->prev= current;

    return current;
}

REGTYPE* add_first(REGTYPE* head, int data) {
    REGTYPE *next_node = head->next;
    insert(head, next_node, data);
    return head;
}

REGTYPE* add_end(REGTYPE* end, int data) {
    REGTYPE *pre_node = end->prev;
    insert(pre_node, end, data);
}

REGTYPE* random_list(void) {
    REGTYPE *head = newNode(0);
    REGTYPE *end = newNode(0);
    head->next = end;
    end->prev = head;

    for(int i = 0; i <= MAX; i++){
        int data = rand()%(NUMBER+1);
        add_end(end, data);
    }

    return (head);
}