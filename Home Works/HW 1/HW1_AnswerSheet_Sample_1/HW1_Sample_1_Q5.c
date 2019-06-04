#include <stdio.h>

int power(int base ,int times){

    int p = 1;
    while(times > 0){
        p *= base;
        --times;
    }
    return p;
}

void binary_form(int binary[], int num){

    int mod;
    int i = 0;
    while(num != 0){
        mod = num%2;
        num /= 2;
        binary[i++] = mod;
    }
}


void power_set(int set[] ,int len){

    int size = power(2, len);
    int binary[100] = {0};
    int flag = 0;

    int i, j;
    printf("{");
    for (i = 0;i < size;++i){
        printf("{");
        binary_form(binary, i);
        for (j = 0;j < len;++j){
            if (binary[j] == 1){
                if (flag == 1){
                    printf(", %d", set[j]);
                }
                else{
                    printf("%d", set[j]);
                    flag = 1;
                }
            }

        }
        flag = 0;
        if (i == size - 1){
            printf("}");
        }
        else{
            printf("},");
        }
    }
    printf("}");

}


int main(void){

    int set[] = {1, 2 ,3};
    int length = sizeof(set)/4;
    power_set(set ,length);
    return 0;

}
