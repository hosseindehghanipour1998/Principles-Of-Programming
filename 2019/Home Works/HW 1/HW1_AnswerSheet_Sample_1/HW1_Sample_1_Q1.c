#include <stdio.h>

int get_num(void){

    int c;
    int sum = 0;
    while ( (c = getchar()) != '\n'){
        if ( c >= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
    }
    return sum;
}

int get_name(char std[], int i){

    int c, j = 0;
    while((c = getchar()) != '\n'){
        std[i++] = c;
        ++j;
    }
    return j;
}

int get_score(int scores[], int i){

    int c, j = 0;
    int sum = 0;
    while ( (c = getchar()) != '\n'){
        if ( c >= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
        if ( c == ' '){
            scores[i++] = sum;
            sum = 0;
            ++j;
        }
    }
    scores[i++] = sum;
    return ++j;
}

void get_student_number(int students[], int i){

    int c;
    int flag = 1;
    int trash[1];
    while((c = getchar()) != '\n'){
        if(flag <= 3){
            students[i++] = c - '0';
            ++flag;
        }
        else{
            trash[0] = c;
        }
    }
}

void sort_student_number(int swapped[], int student_number[], int n){

    int i, j;
    int k, index;
    int helper[100] = {0};
    for(i = 0;i < n;++i){
        k = swapped[i];
        index = 3*(n - i);
        for(j = 3*k;j <= 3*k + 2;++j){
            helper[--index] = student_number[j];
        }
    }
    for(i = 0, j = 3*n - 1;j > i;++i, --j){
        k = helper[i];
        helper[i] = helper[j];
        helper[j] = k;
    }

    for(i = 0;i < 3*n ;++i){
        student_number[i] = helper[i];
    }
}

void sort_names(int swapped[], char students[], int names[], int n){

    int helper[100] = {0};
    int i, j, k;
    int begin = 0;
    int z = 0;
    for(i = n - 1;i >= 0;--i){
        j = swapped[i];
        for(k = 0;k < j;++k){
            begin += names[k];
        }
        for(k = begin;k < begin + names[j];++k){
            helper[z++] = students[k];
        }
        begin = 0;
    }
    for (i = 0;i < z;++i){
        students[i] = helper[i];
    }
    for(i = 0;i < n;++i){
        j = swapped[i];
        helper[n - 1 - i] = names[j];
    }
    for(i = 0;i < n;++i){
        names[i] = helper[i];
    }

    //Now the names are sorted based on the average


}


void get_average(float average[], int std_num, int how_many_score[], int scores[]){

    float grade = 0;
    float ave;
    int i ,j, k;

    j = 0;
    for (i = 0;i < std_num;++i){
        k = how_many_score[i];
        while (k > 0){
            grade += scores[j++];
            --k;
        }
        ave = grade / how_many_score[i];
        grade = 0;
        average[i] = ave;
    }
}

void bubble_sort(int swapped[], float average[],int student_number[], int n, int name[]){

    int i ,j;
    int swap, swap_first, swap_second;
    for (i = 0 ; i < n; i++){
        for (j = 0 ; j < n - i - 1; j++){
            if (average[j] > average[j+1]){
                swap = swapped[j];
                swapped[j] = swapped[j+1];
                swapped[j+1] = swap;
                swap = average[j];
                average[j] = average[j+1];
                average[j+1] = swap;
            }
        }
    }
    sort_student_number(swapped, student_number, n);
}


void sort_numbers(int swapped[], int scores[], int how_many_score[], int std_num){

    int helper[100] = {0};
    int i, j, k;
    int begin = 0;
    int z = 0;
    for(i = std_num - 1;i >= 0;--i){
        j = swapped[i];
        for(k = 0;k < j;++k){
            begin += how_many_score[k];
        }
        for(k = begin;k < begin + how_many_score[j];++k){
            helper[z++] = scores[k];
        }
        begin = 0;
    }
    for (i = 0, j = z - 1;i < z, j >= 0;++i, --j){
        scores[i] = helper[j];
    }

    //Now the scores are sorted based on the average

}

void process(int std_num){

    char students[1000];
    int name[100] = {0};
    int student_number[100] = {0};

    int scores[1000] = {0};
    int how_many_score[100] = {0};
    float average[100] = {0.0};

    int i, j = 0, k = 0;
    int z;

    for (i = 0;i < std_num;i++){
        printf("Ok.what's the name of student %d?\n", i + 1);
        name[i] = get_name(students ,j);
        j += name[i];
        //name process

        printf("Ok.What are his/her score?\n");
        how_many_score[i] = get_score(scores, k);
        k += how_many_score[i];
        //scores process

        printf("Student Number?\n");
        get_student_number(student_number, i*3);
        //student number process

        printf("Done!\n");
    }

    get_average(average, std_num, how_many_score, scores);

    int swapped[100] = {0};

    for ( i = 0;i < 100; ++i){
        swapped[i] = i;
    }

    bubble_sort(swapped, average, student_number, std_num, name);

    sort_numbers(swapped, scores, how_many_score, std_num);

    printf("The results:\nSTDNo\tAvg\n");
    for (i = std_num - 1;i >= 0 ;--i){
        //k = swapped[i];
        printf("%d%d%d", student_number[3*i], student_number[3*i+1], student_number[3*i+2]);
        printf("\t%.2f\n", average[i]);
    }

    sort_names(swapped, students, name, std_num);
    /* To print the names
    int c = 0;
    for (j =0;j < std_num;++j){
        for (i = 0;i < name[j]; ++i){
            printf("%c", students[c++]);
        }
        printf("\n");
    }*/
}



int main(void){

    printf("How Many Students should I take?\n");
    int std_num = get_num();
    process(std_num);
    return 0;
}
