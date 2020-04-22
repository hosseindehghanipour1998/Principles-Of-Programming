#include <stdio.h>


int fib (int a ){

    if( a == 0 ){
        return 0 ;
    }
    if ( a == 1 ){
        return 1 ;
    }

    return ( fib(a-1) + fib(a-2) ) ;

}


int factoriel ( int a ){

    if ( a == 1 || a == 0 ){
        return  1 ;
    }

    return factoriel(a-1)*a ;

}

void main(void){

    printf("{%d} {%d}" , fib(5) , factoriel(5));


}
