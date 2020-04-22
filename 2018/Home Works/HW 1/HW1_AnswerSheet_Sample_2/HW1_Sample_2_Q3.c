#include <stdio.h>
#include <math.h>

void extract_xy(int [], int[], int[], int);

void double_insertion_sort(int [], int [], int);

void plot_coord(int [], int [], int);

int calc_dist(int x1, int y1, int x2, int y2);

void show_distances(int[], int[], int);

void show_int(int);

int power(int, int);

int len_int(int);


int main(void) {
    int locations[5] = {2535, 1925, 1257, 7348, 5947};
    int len;
    len = 5;
    int x[1000], y[1000];
    extract_xy(locations, x, y, len);
    double_insertion_sort(y, x, len);
    plot_coord(x, y, len);
    show_distances(x, y, len);
    return 0;
}

void extract_xy(int locations[], int x[], int y[], int len) {
    // extract x and y coordinates from locations
    int i;
    for (i = 0; i < len; ++i) {
        int x_1, x_2, y_1, y_2;
        y_2 = locations[i] % 10;
        locations[i] /= 10;
        y_1 = locations[i] % 10;
        locations[i] /= 10;
        x_2 = locations[i] % 10;
        locations[i] /= 10;
        x_1 = locations[i] % 10;
        locations[i] /= 10;
        x[i] = 10 * x_1 + x_2;
        y[i] = 10 * y_1 + y_2;
    }
}

void double_insertion_sort(int a1[], int a2[], int len) {
    // sort two same length arrays with respect to array 1
    if (len < 1) {
        return;
    }
    int i;
    for (i = 1; i < len; ++i) {
        int j, key1, key2;
        key1 = a1[i];
        key2 = a2[i];
        for (j = i - 1; j >= 0 && key1 > a1[j]; --j) {
            a1[j + 1] = a1[j];
            a2[j + 1] = a2[j];
        }
        a1[j + 1] = key1;
        a2[j + 1] = key2;
    }
}

void plot_coord(int x[], int y[], int len) {
    // plot points in grid
    int i, current_pos, upper_bound, lower_bound;
    char symbol;
    symbol = 'A'; // starting symbol
    current_pos = 0;
    upper_bound = (y[0] / 10 + 1) * 10; // upper and lower bound for not plotting excess space
    lower_bound = (y[len - 1] / 10) * 10;
    for (i = upper_bound; i >= lower_bound; --i) {
        int j;
        j = 10;
        while (y[current_pos] == upper_bound && j < 100) {
            if (j == x[current_pos]) {
                putchar(symbol);
                putchar('(');
                putchar(x[current_pos] / 10 + '0');
                putchar(x[current_pos] % 10 + '0');
                putchar(',');
                putchar(y[current_pos] / 10 + '0');
                putchar(y[current_pos] % 10 + '0');
                putchar(')');
                current_pos++;
                symbol++; // change symbol
            }
            else {
                putchar(' ');
            }
            j++;
        }
        upper_bound--; // go down one line
        putchar('\n');
    }

}

int calc_dist(int x1, int y1, int x2, int y2) {
    // calculate euclidean distance of two points
    return (int) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int power(int a, int b) {
    // calculate power of a ^ b
    int res, i;
    res = 1;
    for (i = 0; i < b; ++i) {
        res *= a;
    }
    return res;
}

int len_int(int num) {
    // calculate the length of a number
    int len;
    len = 1;
    while (num / 10 != 0) {
        num /= 10;
        len++;
    }
    return len;
}

void show_int(int number) {
    // show an integer to output stream
    int len, i;
    len = len_int(number);
    for (i = 0; i < len; ++i) {
        int digit;
        digit = number / power(10, len - 1 - i);
        putchar(digit + '0');
        number %= power(10, len - 1 - i);
    }
}

void show_distances(int x[], int y[], int len) {
    // show distances on screen with appropriate symbol
    int i;
    char symbol;
    symbol = 'A'; // starting symbol
    for (i = 0; i < len; ++i) {
        int j;
        for (j = i + 1; j < len; ++j) {
            int dist;
            dist = calc_dist(x[i], y[i], x[j], y[j]); // calculate distance
            putchar(symbol + i); // show distance
            putchar('-');
            putchar(symbol + j);
            putchar(':');
            putchar(' ');
            show_int(dist);
            putchar('\n');
        }
    }
}
