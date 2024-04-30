#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#### Constants #####
#define MAX 5
// ##### typedefs ####
typedef struct q{
int number;
struct q *next;
struct q *prev;
} REGTYPE;
// ##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);
//###### Main program #######
int main(int argc, char *argv[]){
    printf("Size of REGTYPE: %zu bytes\n", sizeof(REGTYPE));

    int nr=0;
    REGTYPE * sPtr [5];
    REGTYPE *act_post , *head=NULL;
    srand(time(0)); // Random seed
    head=random_list();
    head = add_first(head, 10);
    act_post=head;
    while( act_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, act_post->number);
        act_post=act_post->next;
    }
    // --- Free the allocated memory ---
    while((act_post=head)!=NULL){
        head=act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================
    REGTYPE* random_list(void ){
        int nr, i=0;
        REGTYPE *top, *old, *item;
    top = malloc(sizeof (REGTYPE));
    top->number = rand() % (101);
    top->prev = NULL;
    top->next = NULL;
    old = top;
    for (int j = 0; j < 4; ++j) {
        item = malloc(sizeof (REGTYPE));
        item->number = rand()%(101);
        item->prev = old;
        item->next = NULL;
        old->next = item;
        old = item;
    }

    return(top);
    }
//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
    REGTYPE *newItem = malloc(sizeof (REGTYPE));
    newItem->number = data;
    newItem->next = temp;
    temp->prev = newItem;
    temp = newItem;
    return temp;

}


