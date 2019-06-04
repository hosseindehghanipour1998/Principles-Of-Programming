#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


int read_a_line(char[], char[], int start);

int search_word(char[], char[]);

int extract_nums(char[], int, char[], int[]);

int append(char[], char[], int);

void data_mining(char[], char[]);

int return_pos(char[], int, char[], int);

int main(void) {
    char a[] = "salam\nAge: 3020\namrir rsdfsdkfnc\n\nAge:290"; // the text for data mining
    char word[] = "Age"; // looking for this word
    data_mining(a, word);
    return 0;
}

int read_a_line(char from[], char to[], int start) {
    // returns the number of character in the line including \0
    int i, j;
    i = start;
    j = 0;
    if (from[start] == '\0' || from[start] == EOF) {
        return -1;
    }
    while (from[i] != '\n' && from[i] != EOF && from[i] != '\0') {
        to[j] = from[i];
        i++;
        j++;
    }
    to[j] = '\0';
    ++j;
    return j;
}

int search_word(char text[], char word[]) {
    // returns whether rhe word exists in text
    int i, j;
    i = j = 0;
    for (; i < strlen(text); ++i) {
        if (j == strlen(word)) {
            return 1;
        }
        if (text[i] == word[j]) {
            j++;
        }
        else {
            j = 0;
        }
    }
    return 0;
}


int append(char from[], char to[], int index) {
    // append "from" to the end of "to"
    int i;
    for (i = 0; i < strlen(from); ++i, ++index) {
        to[index] = from[i];
    }
    to[index] = '\0';
    index++;
    return index;

}

int extract_nums(char line[], int len, char word[], int nums[]) {
    // search line by line in the lines that word is present and get a number
    int i, j, k;
    i = j = 0;
    while ((k = return_pos(line, len, word, i)) != -1) {
        i += k;
        int res, c;
        res = 0;
        c = line[i];
        i++;
        // skip non digits
        while (!(c >= '0' && c <= '9')) {
            c = line[i];
            i++;
        }
        // get numbers
        while (c >= '0' && c <= '9') {
            res = 10 * res + c - '0';
            c = line[i];
            i++;
        }
        // update array
        nums[j] = res;
        j++;
    }
    return j;

}


int return_pos(char text[], int len, char word[], int start) {
    // returns whether rhe word exists in text
    int i, j;
    i = start;
    j = 0;
    for (; text[i] != '\0' && i < len; ++i) {
        if (j == strlen(word)) {
            return i;
        }
        if (text[i] == word[j]) {
            j++;
        }
        else {
            j = 0;
        }
    }
    return -1;

}

void data_mining(char data[], char word[]) {
    int len, start, char_len, len_word_line;
    char line[10000], word_line[10000];
    len = strlen(data);
    len_word_line = 0;
    start = 0;
    while ((char_len = read_a_line(data, line, start)) != -1) {
        // if the word found in the line than append it
        if (search_word(line, word)) {
            len_word_line = append(line, word_line, len_word_line);
            printf("%s\n", line);
        }
        start += char_len;
    }
    // now from extracted lines read the number after the given word and put the results in num
    int nums[1000], len_nums;
    len_nums = extract_nums(word_line, len_word_line, word, nums);
    // print the numbers and calculate their sums
    int i;
    float sum;
    sum = 0;
    for (i = 0; i < len_nums; ++i) {
        printf("%d\n", nums[i]);
        sum += nums[i];
    }
    // show the results
    printf("Number of peoples: %d\n", len_nums);
    printf("sum of their ages: %.2f\n", sum);
    printf("average of their ages: %.2f", sum / len_nums);
}

