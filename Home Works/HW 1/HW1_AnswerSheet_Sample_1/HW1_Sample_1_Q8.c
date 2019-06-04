#include <stdio.h>

int get_num(void){

    int c;
    int sum = 0;
    while ( (c = getchar()) != '\n'){
        if ( c>= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
    }
    return sum;
}

int power(int base ,int time){

    int p = 1;
    while(time > 0){
        p *= base;
        --time;
    }
    return p;
}



int last_numbers(int num ,int n){

    int last = power(10 ,n);
    return num%last;

}

int first_numbers(int num ,int n){

    int i;
    for (i = 1;i < n;++i){
        num = num / 10;
    }
    return num;
}


int main(void){

    int Num;
    int N;
    int first ,last;
    Num = get_num();
    N = get_num();
    first = first_numbers(Num ,N);
    printf("%d\n" ,first);
    last = last_numbers(Num ,N);
    printf("%d\n" ,last);
    printf("%d\n" ,first - last);
    return 0;
}
