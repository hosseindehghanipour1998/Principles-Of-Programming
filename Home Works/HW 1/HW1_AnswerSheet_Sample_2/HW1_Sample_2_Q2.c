#include <stdio.h>
#include <string.h>
#include <math.h>

int get_coordinates(int x[], int y[]);

void print_n_vertex(void);

void str_print(char []);

void print_x(void);

void print_y(void);

void print_convex(void);

void print_not_convex(void);

int get_int(void);

void cross_product(int [], int [], int [], int);

int changing_sign(int [], int);

int number_sign(int);

int number_of_changing_sign(int [], int);

int abs(int);

int sum(int [], int);

float calc_area(int [], int);

int is_convex(int [], int);

void print_area(void);

void print_triangle(void);

void print_surface(void);

void menu(void);

void show_int(int);

int power(int, int);

int len_int(int);

float calc_dist(int x1, int y1, int x2, int y2);

float calc_surface(int[], int[], int);

void show_float(float);

int main(void) {
    menu();
    return 0;
}

void str_print(char text[]) {
    // print the given char array by using putchar
    int i;
    for (i = 0; i < strlen(text); ++i) {
        putchar(text[i]);
    }
}

void print_n_vertex(void) {
    char text[] = "Enter The number of the vertex:\n";
    str_print(text);
}

void print_x(void) {
    char text[] = "Enter the X of the vertice\n";
    str_print(text);
}

void print_y(void) {
    char text[] = "Enter the Y of the vertice\n";
    str_print(text);
}


int get_int(void) {
    // read a single integer
    int res, c;
    res = 0;
    while ((c = getchar()) != '\n' && c >= '0' && c <= '9') {
        res = 10 * res + c - '0';
    }
    return res;
}

int get_coordinates(int x[], int y[]) {
    //fill the given arrays with x and y and returns the number of points
    print_n_vertex();
    int n, i;
    n = get_int();
    for (i = 0; i < n; ++i) {
        print_x();
        x[i] = get_int();
        print_y();
        y[i] = get_int();
    }
    return n;
}

void cross_product(int x[], int y[], int res[], int n) {
    // calculate the cross product of x and y and returns the result into the res array
    int i;
    for (i = 0; i < n; ++i) {
        res[i] = x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
    }
}

int changing_sign(int res[], int n) {
    // determine whether the sign is change in the given array
    if (n == 1) {
        return 0;
    }
    int i, sign, current_sign;
    sign = current_sign = res[0];
    for (i = 1; i < n; ++i) {
        current_sign *= res[i];
        if (sign * current_sign < 0) {
            return 1;
        }
    }
    return 0;
}

int number_sign(int n) {
    // sign function
    if (n >= 0) {
        return 1;
    }
    return -1;
}

int number_of_changing_sign(int res[], int n) {
    // count the number of changing the sign
    int i, sign, pos, neg;
    pos = neg = 0;
    sign = number_sign(res[0]); // convert the first element in the 1 of -1
    if (sign == 1) {
        pos++;
    }
    else {
        neg++;
    }
    for (i = 1; i < n; ++i) {
        if (sign != number_sign(res[i])) {
            sign = number_sign(res[i]);
            if (sign == 1) {
                pos++;
            }
            else {
                neg++;
            }
        }
    }
    return pos > neg ? neg : pos;
}

int abs(int n) {
    // absolute function
    if (n < 0) {
        return -n;
    }
    return n;
}

int sum(int arr[], int n) {
    // returns rhe sum of the array
    int i, res;
    res = 0;
    for (i = 0; i < n; ++i) {
        res += arr[i];
    }
    return res;
}

float calc_area(int res[], int n) {
    // calculate the area based on the sum of cross products
    return (float) abs(sum(res, n)) / 2;
}

int is_convex(int res[], int n) {
    // returns whether the given cross product is representing a convex polygon or not
    return !changing_sign(res, n);;
}

void print_convex(void) {
    char text[] = "The Polygon is a convex\n";
    str_print(text);
}

void print_not_convex(void) {
    char text[] = "The Polygon is not a convex\n";
    str_print(text);
}

void print_area(void) {
    char text[] = "The area is: ";
    str_print(text);
}

void print_surface(void) {
    char text[] = "The surface is: ";
    str_print(text);
}

void print_triangle(void) {
    char text[] = "The number of triangle is: ";
    str_print(text);
}

int power(int a, int b) {
    // calculate a to the power of b
    int res, i;
    res = 1;
    for (i = 0; i < b; ++i) {
        res *= a;
    }
    return res;
}

int len_int(int num) {
    // return the number of digits of a integer
    int len;
    len = 1;
    while (num / 10 != 0) {
        num /= 10;
        len++;
    }
    return len;
}

void show_int(int number) {
    // print an integer by putchar
    int len, i;
    len = len_int(number);
    for (i = 0; i < len; ++i) {
        int digit;
        digit = number / power(10, len - 1 - i); // extract the last digit
        putchar(digit + '0');
        number %= power(10, len - 1 - i); // exclude the last digit from the number
    }
}

void show_float(float num) {
    int integer_part = (int) num; // decimal part
    int floating_point_part = (int) ((num - (float) integer_part) * 100); // float part
    show_int(integer_part);
    if (floating_point_part != 0) {
        putchar('.');
        show_int(floating_point_part);
    }
}

float calc_dist(int x1, int y1, int x2, int y2) {
    // calculate euclidean distance of two points
    return (float) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

float calc_surface(int x[], int y[], int len) {
    // calculate the surface of the given coordinate
    float sum = 0;
    int i;
    for (i = 0; i < len; ++i) {
        sum += calc_dist(x[i], y[i], x[(i + 1) % len], y[(i + 1) % len]);
    }
    return sum;

}

void menu(void) {
//    int x[100] = {4, 7, 10, 11, 9, 10};
//    int y[100] = {2, 4, 1, 9, 12, 6};
    int x[1000];
    int y[1000];
    int cross[1000];
    int n;
    n = get_coordinates(x, y);
    cross_product(x, y, cross, n);
    if (is_convex(cross, n)) {
        print_convex();
        print_triangle();
        show_int(n - 2);

    }
    else {
        print_not_convex();
        print_triangle();
        show_int((n - 2) * number_of_changing_sign(cross, n));
    }
    putchar('\n');
    print_area();
    show_float(calc_area(cross, n));
    putchar('\n');
    print_surface();
    show_float(calc_surface(x, y, n));
}