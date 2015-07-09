#include <stdio.h>
#include <stdlib.h>

int debug =1;

enum { MAX_INPUT = 160000 };
//enum { MAX_INPUT = 16 };
int input[MAX_INPUT];

void fill_input()
{
    int idx = 0;

    for (idx = 0; idx < MAX_INPUT; idx++){
        input[idx] = rand()%MAX_INPUT;
    }
}

void print_input()
{
    int idx = 0;

    printf ("Array: ");
    for (idx = 0; idx < MAX_INPUT; idx++){
        printf (" %d ", input[idx]);
    }
    printf ("\n");
}

int selection_sort()
{
    int idx1, idx2;
    int min;
    int pos2;
    int tmp;
    printf ("Selection Sort\n");

    for (idx1 = 0; idx1 < MAX_INPUT; idx1++){
        pos2 = idx1;
        min = input[idx1];
        for (idx2 = idx1; idx2 < MAX_INPUT; idx2++){
            if (input[idx2] < min) {
                min = input[idx2]; 
                pos2 = idx2;
            }
        }

        tmp = input[idx1];
        input[idx1] = input[pos2];
        input[pos2] = tmp; 
#if 0
        /* a = a ^ b
         * a = a ^ b
         * b = a ^ b */
        //Will not work when the two pos are same */
        input[idx1] = input[idx1] ^ input[pos2];
        input[idx1] = input[idx1] ^ input[pos2];
        input[pos2] = input[idx1] ^ input[pos2];
#endif
    }
}

void shell_sort()
{
    int idx1, idx2;
    int tmp;
    int inc = 1;

    printf ("Shell Sort\n");

    while (inc < MAX_INPUT/3) {
        inc = (3 * inc) + 1;
    }

    while (inc >= 1) {
        for (idx1 = inc; idx1 < MAX_INPUT; idx1++){
            for (idx2 = idx1; ((idx2 >= inc) && (input[idx2]<input[idx2-inc])); idx2 -= inc){
                tmp = input[idx2];
                input[idx2] = input[idx2-1];
                input[idx2-1] = tmp; 
            }
        }
        inc = inc/3;
    }
}

void insertion_sort()
{
    int idx1, idx2;
    int tmp;

    printf ("Insertion Sort\n");

    for (idx1 = 0; idx1 < MAX_INPUT; idx1++){
        for (idx2 = idx1; ((idx2 > 0) && (input[idx2]<input[idx2-1])); idx2--){
                tmp = input[idx2];
                input[idx2] = input[idx2-1];
                input[idx2-1] = tmp; 
        }

    }
}

int main()
{
    if (MAX_INPUT > 32) debug = 0;
    fill_input();
    if (debug) print_input();
    //selection_sort();
    //insertion_sort();
    shell_sort();
    if (debug) print_input();
}

