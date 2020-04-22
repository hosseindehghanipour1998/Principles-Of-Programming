#include <stdio.h>

int get_data(char datas[]){

    int c, i = 0;
    while ((c = getchar()) != EOF){
        datas[i++] = c;
    }
    return i;
}

int elimination(char data_base[], char eliminated_data[], int amount){

    int i;
    int j = 0;
    for(i = 0;i <= amount;++i){
        if (data_base[i] == 'A' && data_base[i + 1] == 'g' && data_base[i + 2] == 'e'){
            while (data_base[i] != '\n'){
                eliminated_data[j++] = data_base[i++];
            }
            eliminated_data[j++] = '\n';
        }
    }
    return j;
}

void print_eliminated_age(char eliminated_data[], int last_eliminated){

    int i;
    for (i = 0;i < last_eliminated;++i){
        printf("%c", eliminated_data[i]);
    }
    printf("\n");
}

int eliminate_age(char eliminated_data[], int ages[], int last_eliminatd){

    int i;
    int j = 0;
    int sum = 0;
    for (i = 0;i < last_eliminatd;++i){
        if (eliminated_data[i] >= '0' && eliminated_data[i] <= '9'){
            sum = sum * 10 + eliminated_data[i] - '0';
        }
        if (eliminated_data[i] == '\n'){
            ages[j++] = sum;
            sum = 0;
        }
    }
    return j;
}

void print_eliminated_age_number(int ages[], int num){

    int i;
    for (i = 0;i < num;++i){
        printf("%d\n", ages[i]);
    }
    printf("\n");
}

void process(int num, int ages[]){

    printf("Number of Poeple: %d\n", num);
    int i, sum = 0;
    for (i = 0;i < num;++i){
        sum += ages[i];
    }
    printf("Sum of the Ages: %d\n", sum);

    printf("Average of their Ages: %d\n", sum/num);

}


int main(void){

    int i;
    char data_base[1000];
    char eliminated_data[1000];
    int ages[100];
    int amount = get_data(data_base);

    int last_eliminatd = elimination(data_base, eliminated_data, amount);
    print_eliminated_age(eliminated_data, last_eliminatd);

    int num = eliminate_age(eliminated_data, ages, last_eliminatd);
    print_eliminated_age_number(ages, num);

    process(num, ages);
    return 0;
}
