#include <stdio.h>

int is_over(int);

int get_input(void);

int num_length(int);

int power_10(int);

int first_n_digit(int, int);

int last_n_digit(int, int);

int main(void) {
    // get numbers
    int N, n, diff;
    printf("Enter the number: ");
    N = get_input();
    printf("Enther the number of digits: ");
    n = get_input();
    diff = first_n_digit(N, n) - last_n_digit(N, n);
    printf("The difference between first and last %d digit of the number %d is: %d", n, N, diff);
    return 0;
}

int is_over(int c) {
    // determine whether it is stream is over
    return c == EOF || c == ' ' || c == '\t' || c == '\n';
}

int get_input(void) {
    // get an input
    int res, c, is_neg;
    res = 0;
    is_neg = 1;
    c = getchar();
    if (c == '-') {
        is_neg = -1;
        c = getchar();
    }
    while (!is_over(c) && c >= '0' && c <= '9') {
        res = 10 * res + c - '0';
        c = getchar();
    }
    return is_neg * res;
}

int num_length(int num) {
    // return the length of the number
    int i;
    i = 1;
    while (num / 10 != 0) {
        ++i;
        num /= 10;
    }
    return i;
}

int power_10(int n) {
    int i, res;
    res = 1;
    for (i = 0; i < n; ++i) {
        res *= 10;
    }
    return res;
}

int first_n_digit(int num, int count) {
    // return the first n digits
    int i, res;
    res = 0;
    for (i = 0; i < count; ++i) {
        res = 10 * res + (num / power_10(num_length(num) - 1)); // extract the first digit
        num %= power_10(num_length(num) - 1); // cut the number
    }
    return res;
}

int last_n_digit(int num, int count) {
    // calculates the remainder and return the last n digit of the number
    return num % power_10(count);
}
