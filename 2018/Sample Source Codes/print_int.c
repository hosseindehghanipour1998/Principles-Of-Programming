#include <stdio.h>

int power(int paye, int tavan){
    int res = 1;
    while( tavan>0  ){

        res=res*paye;
        tavan--;
    }
    return res;
}
int tedad_ragham(int num){
    int counter=0;
    while( num != 0 ){
        counter++;
        num = num / 10;
    }
    return counter;
}
void print(int num){
    int c=0;
    int tavan=tedad_ragham(num)-1;
    while(tavan>=0){
            c=(num/power(10,tavan));
            num=num-(c*power(10,tavan));
            putchar(c + '0');
            tavan--;

    }

}
int main(void){
    print(1034560);

    return 0;
}
