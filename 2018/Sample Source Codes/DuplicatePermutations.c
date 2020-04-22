#include <stdio.h>
#include <string.h>

int  duplicate_exist(char *array , int start , int end) ;

void main(){

    char a[] = "ABBBA" ;
    int len = strlen(a);
    permute(a , 0 , len);



}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int  duplicate_exist(char array[] , int index , int current){
    int i = 0 ;
    for( i = index ; i < current ; i++){

        if( array[i] == array[current] ){

            return 1 ;
        }

    }

    return 0 ;
}


void permute( char * sentence , int start , int end ){

    if ( start == end ){
        printf("%s\n",sentence);
        return ;
    }

    else{
        int current = 0 ;
        for( current = start ; current < end ; current++){

            if ( duplicate_exist(sentence , start , current ) != 1){

                swap (sentence + start   , sentence + current );
                permute( sentence , start+1 , end);
                swap (sentence + start   , sentence + current );
            }
        }


    }

}
