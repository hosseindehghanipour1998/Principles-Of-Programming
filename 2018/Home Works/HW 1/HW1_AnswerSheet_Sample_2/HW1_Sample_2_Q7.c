#include <stdio.h>

int gcd(int, int);

int abs(int);

int lcm(int, int);

void calc_gcd_lcd(void);

int is_num(int c);

int is_space(int c);

int main(void) {
    calc_gcd_lcd();
    return 0;
}

int is_num(int c) {
    // whether the character is digit
    return c >= '0' && c <= '9';
}

int is_space(int c) {
    // whether the character is space
    return c == '\t' || c == '\n' || c == ' ';
}

int gcd(int p, int q) {
    // calculate the greatest common divisor
    if (p < 0) {
        return gcd(-p, q);
    }
    if (q < 0) {
        return gcd(p, -q);
    }
    if (q == 0) {
        return p;
    }
    return gcd(q, p % q);
}

int abs(int p) {
    return p > 0 ? p : -p;
}

int lcm(int p, int q) {
    return abs(p * q) / gcd(p, q);
}

void calc_gcd_lcd(void) {
    int c, res, neg, total_gcd, total_lcd;
    res = 0;
    neg = 1;
    // initialize values
    total_gcd = 0;
    total_lcd = 1;
    printf("Enter the numbers: ");
    c = getchar();
    while (c != '\n') {
        while (is_space(c)){
            c = getchar();
        }
        neg = 1;
        if (c == '-') {
            // determine whether the number is negative
            neg = -1;
            c = getchar();
        }
        // save the number
        res = 0;
        while (c != EOF && !is_space(c) && is_num(c)) {
            res = 10 * res + c - '0';
            c = getchar();
        }
        // update values
        total_gcd = gcd(total_gcd, res * neg);
        total_lcd = lcm(total_lcd, res * neg);
    }
    // update for the last value
    total_gcd = gcd(total_gcd, res * neg);
    total_lcd = lcm(total_lcd, res * neg);
    printf("gcd: %d\nlcd: %d", total_gcd, total_lcd);
}