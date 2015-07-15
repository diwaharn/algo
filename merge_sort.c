#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_INPUT = 256 };

int input_array[MAX_INPUT];
int merge_array[MAX_INPUT];
int debug = 0;

void init_input()
{
    int idx;

    for (idx = 0; idx < MAX_INPUT; idx++){
        input_array[idx] = rand()%MAX_INPUT;
    }
}

void print_merge()
{
    int idx;

    printf ("Merge Array : ");
    for (idx = 0; idx < MAX_INPUT; idx++){
        printf (" %02d ", merge_array[idx]);
    }
    printf ("\n");
}

void print_input()
{
    int idx;

    printf ("Input Array : ");
    for (idx = 0; idx < MAX_INPUT; idx++){
        printf (" %02d ", idx);
    }
    printf ("\n");

    printf ("            : ");
    for (idx = 0; idx < MAX_INPUT; idx++){
        printf (" %02d ", input_array[idx]);
    }
    printf ("\n");
}

int merge(int input[], int low, int high)
{
    int idx;
    int mid = (low+high)/2;

    if (debug) printf ("Merge Copy : low:%d, mid:%d, high:%d\n", low, mid, high);
    /* Take the copy of array */
    for (idx = low; idx <= mid; idx++){
        merge_array[idx] = input[idx];
    }

    for (idx = mid+1; idx <= high; idx++){
        merge_array[idx] = input[idx];
    }
    if (debug) print_merge();

    if (debug) print_input();
    int i = low;
    int j = mid+1;
    int k;
    if(debug) printf ("\nMerge: low:%d, mid:%d, high:%d\n", low, mid, high);
    for (k = low; k<= high; k++) {
        if(debug) printf ("--->k:%d, i:%d, j:%d, mid:%d, high:%d\n", k, 
                i, j, mid, high);
        if ( i > mid) {
            if(debug) printf ("i > mid");
            input[k] = merge_array[j++];
        }
        else if ( j > high) {
            if(debug) printf (" j>high merge_array[%d] = %d", i, input[i]);
            input[k] = merge_array[i++];
        }
        else if (merge_array[i] < merge_array[j]){
            if(debug) printf ("ma[%d] < merge_array[%d] = %d ", i, j, merge_array[i]);
            input[k]  = merge_array[i++];
        }
        else {
            if(debug) printf ("ma[%d] > ma[%d] = %d ", i, j , merge_array[j]);
            input[k] = merge_array[j++]; 
        }
    }
    if(debug) printf ("\n");
    if (debug) print_input();
}

int merge_sort(int input[], int low, int high)
{
    int idx;
    int mid;

    if (high <= low) return;
    mid  = low + ((high - low)/2);

    merge_sort(input, low, mid);
    merge_sort(input, mid+1, high);

    if (debug) printf ("Merge : low:%d, high:%d\n", low, high);
    merge(input, low, high);
}


int main()
{
    init_input();
    print_input();
    merge_sort(input_array, 0, MAX_INPUT-1);
    print_input();
}

