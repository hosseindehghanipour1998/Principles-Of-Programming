#include <stdio.h>

void move(int n , char source , char des , char helper){
    if(n == 1){
        printf("(%c , %c)\n" , source , des);
        return;
    }

    move(n-1, source, helper, des); 
    printf("(%c , %c)\n" , source , des);
    move(n-1, helper, des, source); 
    return ;
    
}


void tower_of_hanoi(int n){
    return move(n , 'L' , 'R' , 'C');
}


int main(int argc, char const *argv[]){
    tower_of_hanoi(5);
    return 0;
}


