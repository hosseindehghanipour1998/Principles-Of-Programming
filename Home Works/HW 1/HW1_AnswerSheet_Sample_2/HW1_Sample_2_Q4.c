#include <stdio.h>

#define ENCRYPT '1'
#define DECRYPT '2'


void cryptography(void);

int get_input(void);

int read_a_char(void);

void enc_mode_1(char [], int, int);

void dec_mode_1(char [], int, int);

void enc_mode_2(char [], char [], int, int);

void dec_mode_2(char [], char [], int, int);

int fill_array(char []);

void mode_1(int);

void mode_2(int);

void mode_3(int, int);

int main(void) {
    cryptography();
    return 0;
}

void cryptography(void) {
    int c, key1, key2;
    printf("1. mode 1\n2. mode 2\n3. mode 3\n");
    printf("Enter a number: ");
    c = read_a_char(); // read user choice
    if (c == '1') {
        printf("Please enter a key: ");
        key1 = get_input();
        mode_1(key1);
    }
    else if (c == '2') {
        printf("Please enter a key: ");
        key1 = get_input();
        mode_2(key1);
    }
    else if (c == '3') {
        printf("Please enter the first key: ");
        key1 = get_input();
        printf("Please enter the second key: ");
        key2 = get_input();
        mode_3(key1, key2);
    }
    else {
        printf("Invalid input!");
    }
}

int get_input(void) {
    // read a single integer from input stream
    int res, c;
    res = 0;
    while ((c = getchar()) != '\n' && c >= '0' && c <= '9') {
        res = 10 * res + c - '0';
    }
    return res;
}

int read_a_char(void) {
    // reads a single character from input stream and clear buffer
    int c;
    c = getchar(); // read a character
    while (getchar() != '\n'); // clear buffer
    return c;
}

void enc_mode_1(char text[], int len, int key) {
    // given a text add each cell value by number key
    int i;
    for (i = 0; i < len; ++i) {
        text[i] += key;
    }
}

void dec_mode_1(char text[], int len, int key) {
    // given a text subtract each cell value by number key
    int i;
    for (i = 0; i < len; ++i) {
        text[i] -= key;
    }
}

int fill_array(char txt[]) {
    // fill a given array from input stream and returns number of characters read
    int op, len_txt;
    len_txt = 0;
    while ((op = getchar()) != '\n') {
        txt[len_txt] = op;
        len_txt++;
    }
    txt[len_txt] = '\0'; // terminate the character array
    return len_txt;
}

void mode_1(int key) {
    int op;
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter a number: ");
    op = read_a_char(); // read the user choice
    if (op == ENCRYPT) {
        printf("Enter the raw text: ");
        char text[1000];
        int len_text;
        len_text = fill_array(text);
        enc_mode_1(text, len_text, key); // encrypt the given text
        printf("encrypted text: ");
        printf("%s", text);

    }
    else if (op == DECRYPT) {
        printf("Enter encrypted text: ");
        char text[1000];
        int len_text;
        len_text = fill_array(text);
        dec_mode_1(text, len_text, key); // decrypt the given text
        printf("raw text: ");
        printf("%s", text);
    }
    else {
        printf("Invalid input!");
    }
}

void enc_mode_2(char text[], char res[], int len, int key) {
    int j; // value for remainders
    int counter; //counts the number for filled values
    counter = 0;
    for (j = 0; j < key; ++j) {
        int k;
        for (k = 0; k < len; ++k) {
            // if k is divisible by key then result array will be filled
            if (k % key == j) {
                res[counter] = text[k];
                counter++;
            }
        }
    }
    res[counter] = '\0'; // terminate result array
}

void dec_mode_2(char text[], char res[], int len_txt, int key) {
    int j, m; // j for the first cell m for the cell in text
    for (j = m = 0; j < key; ++j) {
        int k; // move key step from j cell
        for (k = j; k < len_txt; k += key, m++) {
            res[k] = text[m];
        }
    }
    res[len_txt] = '\0'; // terminate result array
}

void mode_2(int key) {
    int op;
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter a number: ");
    op = read_a_char(); // read the user choice
    if (op == ENCRYPT) {
        printf("Enter the raw text: ");
        char text[1000];
        int len_txt;
        len_txt = fill_array(text);
        printf("encrypted text: ");
        char res[1000]; // result array
        enc_mode_2(text, res, len_txt, key);
        printf("%s", res);

    }
    else if (op == DECRYPT) {
        printf("Enter the encrypted text: ");
        char text[1000];
        int len_txt;
        len_txt = fill_array(text);
        printf("raw text: ");
        char res[1000]; // result array
        dec_mode_2(text, res, len_txt, key);
        printf("%s", res);
    }
    else {
        printf("Invalid input!");
    }
}

void mode_3(int key1, int key2) {
    int op;
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter a number: ");
    op = read_a_char(); // read the user choice
    if (op == ENCRYPT) {
        // first encrypt with mode 1 and then mode 2
        printf("Enter the raw text: ");
        char text[1000], res[1000];
        int len_txt;
        len_txt = fill_array(text);
        printf("encrypted text: ");
        enc_mode_1(text, len_txt, key1);
        enc_mode_2(text, res, len_txt, key2);
        printf("%s", res);
    }
    else if (op == DECRYPT) {
        // first decrypt with mode 2 and then mode 1
        printf("Enter the encrypted text: ");
        char text[1000], res[1000];
        int len_txt;
        len_txt = fill_array(text);
        printf("raw text: ");
        dec_mode_2(text, res, len_txt, key2);
        dec_mode_1(res, len_txt, key1);
        printf("%s", res);
    }
    else {
        printf("Invalid input!");
    }

}