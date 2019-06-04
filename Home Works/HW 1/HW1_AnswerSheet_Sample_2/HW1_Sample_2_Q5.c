#include <stdio.h>

int power(int, int);

void rev_bin_rep(int [], int, int);

void write_subsets(int [], int);


int main(void) {
    int set[4] = {1, 2, 3, 4};
    int len;
    len = 4;
    write_subsets(set, len);
    return 0;
}

int power(int a, int b) {
    // power function
    int res, i;
    res = 1;
    for (i = 0; i < b; ++i) {
        res *= a;
    }
    return res;
}

void rev_bin_rep(int res[], int len, int num) {
    // transform the number to the binary but in reversed format
    int i;
    for (i = 0; i < len; ++i) {
        res[i] = num % 2;
        num /= 2;
    }
}

void write_subsets(int num[], int len) {
    int i, iteration_count;
    int arr[1000];
    iteration_count = power(2, len);
    printf("NULL\n");
    for (i = 1; i < iteration_count; ++i) {
        rev_bin_rep(arr, len, i); // get the reverse binary representation
        int j;
        for (j = 0; j < len; ++j) {
            /* see that if in the reversed binary representation of j
             * there exists a 1 bit then the corresponding element of the number array
             * is present in the subset */

            if (arr[j] == 1) {
                printf("%d ", num[j]);
            }
        }
        putchar('\n');
    }
}