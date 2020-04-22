#include <stdio.h>

int get_num(int numbers[]){

    int c;
    int i = 0;
    int sum = 0;
    while ( (c = getchar()) != EOF){
        if ( c >= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
        else if ( c == '\n'){
            numbers[i++] = sum;
            sum = 0;
        }
    }
    return i;
}

int gcd(int a ,int b){

    if ( b == 0){
        return a;
    }
    else{
        return gcd(b ,a % b);
    }

}

int lcm(int a ,int b){

    int mul ,div;
    int res;
    mul = a * b;
    div = gcd(a ,b);
    res = mul / div;
    return res;
}

int main(void){

    int numbers[100];
    int r ,i;
    i = get_num(numbers);

    int res_gcd ,result_gcd;
    int res_lcm ,result_lcm;

    result_gcd = numbers[0];

    for (r = 1;r < i;++r){
        res_gcd = gcd(result_gcd ,numbers[r]);
        result_gcd = res_gcd;
    }

    result_lcm = numbers[0];
    for (r = 1;r < i;++r){
        res_lcm = lcm(result_lcm, numbers[r]);
        result_lcm = res_lcm;
    }
    printf("GCD: %d\n" ,res_gcd);
    printf("LCM: %d\n" ,res_lcm);
    return 0;
}
