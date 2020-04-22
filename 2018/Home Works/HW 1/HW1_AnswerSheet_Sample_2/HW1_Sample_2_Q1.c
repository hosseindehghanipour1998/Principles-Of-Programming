#include <stdio.h>

void fill_data(void);

int get_int(void);

int get_name(char [], int);

int get_std_num(int[], int);

int get_scores(float [], int);

float get_avg(float [], int, int);

void copy_arr(float from[], float to[], int len);

void simultaneous_sort(float [], int [], float [], int[], int, int);

int power(int, int);

int len_int(int);

int main(void) {
    fill_data();
    return 0;
}

int get_int(void) {
    // get a single integer until new line
    int c, res;
    res = 0;
    while ((c = getchar()) != '\n' && c >= '0' && c <= '9') {
        res = 10 * res + c - '0';
    }
    return res;
}

int get_name(char names[], int pos_names) {
    // get a name and increase the position by the length of the name
    int c;
    while ((c = getchar()) != '\n') {
        names[pos_names] = c;
        pos_names++;
    }
    names[pos_names] = '\0'; // terminate the name
    pos_names++;
    return pos_names;
}

int get_std_num(int std_num[], int std_num_pos) {
    // get student numbers and return len of the std_num array
    std_num[std_num_pos] = get_int();
    std_num_pos++;
    return std_num_pos;
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

int get_scores(float scores[], int score_pos) {
    // gets scores and returns the number of scores
    int c, dec;
    float res, is_float;
    res = dec = 0;
    is_float = 0;
    while ((c = getchar()) != '\n') {
        if (c != ' ' && c != '\t' && c >= '0' && c <= '9' && !is_float) {
            res = 10 * res + c - '0';
        }
        else if (c == '.') {
            is_float = 1;
        }
        else if (c != ' ' && c != '\t' && c >= '0' && c <= '9' && is_float) {
            dec = 10 * dec + c - '0';
        }
        else {
            scores[score_pos] = res + (float) dec / power(10, len_int(dec));
            score_pos++;
            res = 0;
            dec = 0;
            is_float = 0;
        }
    }
    scores[score_pos] = res + (float) dec / power(10, len_int(dec));
    score_pos++;
    return score_pos;
}

float get_avg(float scores[], int start, int end) {
    // get average of the score from index start to index end
    int i;
    float sum;
    sum = 0;
    for (i = start; i < end; ++i) {
        sum += scores[i];
    }
    return sum / (end - start);
}

void copy_arr(float from[], float to[], int len) {
    int i;
    for (i = 0; i < len; ++i) {
        to[i] = from[i];
    }
}

void simultaneous_sort(float a1[], int a2[], float scores[], int n_scores[], int len, int score_len) {
    float res[1000];
    // sort two same length arrays with respect to array 1
    int index_n_scores[1000], len_index; // an array for index of n_score before sort
    len_index = 0;

    index_n_scores[len_index] = 0; // assume that the 0th index is sort
    len_index++;

    if (len < 1) {
        return;
    }

    // sort a2 and index_n_score based on a1 by insertion sort
    int i;
    for (i = 1; i < len; ++i) {
        index_n_scores[len_index] = i; // add index to end of the array
        len_index++;
        float key1;
        int j, key2, key3;
        key1 = a1[i];
        key2 = a2[i];
        key3 = index_n_scores[i];
        for (j = i - 1; j >= 0 && key1 > a1[j]; --j) {
            a1[j + 1] = a1[j];
            a2[j + 1] = a2[j];
            index_n_scores[j + 1] = index_n_scores[j];
        }
        a1[j + 1] = key1;
        a2[j + 1] = key2;
        index_n_scores[j + 1] = key3;
    }
    // now based on index_n_score fill the res array with scores
    int len_res;
    len_res = 0; // position an the len of res array
    for (i = 0; i < score_len; ++i) {
        int j, lower_bound;
        lower_bound = 0; // starting index in the res array
        for (j = 0; j < index_n_scores[i]; ++j) {
            lower_bound += n_scores[j];
        }
        // fill the res array
        int k;
        for (k = 0; k < n_scores[index_n_scores[i]]; ++k) {
            res[len_res] = scores[lower_bound + k];
            len_res++;
        }
    }
    copy_arr(res, scores, score_len);
}

void fill_data(void) {
    int n;
    char names[1000];  // for names
    float scores[1000]; // for scores
    int n_sc[10000];  // number of each student scores
    int std_num[1000]; // student numbers
    printf("How many students should I take?\n");
    n = get_int();
    int i;
    int pos_names, std_num_pos, scores_pos, n_sc_pos; //position of pointer in names array
    pos_names = std_num_pos = scores_pos = n_sc_pos = 0; // at beginning
    for (i = 1; i <= n; ++i) {
        printf("Ok. What is the name of student %d?\n", i);
        pos_names = get_name(names, pos_names);
        printf("What are his/her scores?\n");
        int last_pos; // for number of scores
        last_pos = scores_pos;
        scores_pos = get_scores(scores, scores_pos);
        n_sc[n_sc_pos] = scores_pos - last_pos;
        n_sc_pos++;
        printf("What is student number?\n");
        std_num_pos = get_std_num(std_num, std_num_pos);
        printf("Done!\n");
    }
    // calculate average of scores
    float avg[1000];
    int j, k;
    for (j = k = 0; j < std_num_pos; ++j) {
        avg[j] = get_avg(scores, k, k + n_sc[j]);
        k += n_sc[j];
    }
    simultaneous_sort(avg, std_num, scores, n_sc, std_num_pos, scores_pos);
    printf("The Result:\n");
    for (j = 0; j < std_num_pos; ++j) {
        printf("%d   %.2f\n", std_num[j], avg[j]);
    }
}