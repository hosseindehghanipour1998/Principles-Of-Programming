#include <stdio.h>
#include <stdlib.h>


int fms ( int a[] , int low , int high , int len );
int fsm2(int a[] , int);


int main(){

    int array[] = {13 , -3 , -25 , 20 , -3 , -16 , -23 , 18 , 20 , -7 , 12 , -5 , -22 , 15 , -4 , 7} ;
    int len = 16 ;
    printf("The Max Summation is : %d \n" , recursive_fms(array,0,len-1 , len));
    printf("The Max Summation is : %d " , nonerecursive_fsm2(array, len));
    return 0 ;
}

//None Recursive
int nonerecursive_fsm2(int a[] , int len ){
    int i , j , this_sum , max_sum ;
    i = j = this_sum = max_sum = 0 ;

    for ( i = 0 ; i < len ; i++){
        this_sum += a[i];
        if(this_sum > max_sum){
            max_sum = this_sum ;
        }
        else if ( this_sum < 0){
            this_sum = 0 ;
        }
    }

    return max_sum ;


}

//Recursive
int overlapped_subarray ( int a[] , int low , int high , int len ){

    int left_sum = -10000 ;
    int right_sum = -1000 ;
    int sum = 0 ;
    int i = 0 ;
    int mid = (high+low)/2 ;

    for (i = mid ; i >= 0  ; i-- ){
        sum += a[i];
        if( sum > left_sum ){
            left_sum = sum ;
        }
    }

    sum = 0 ;
    for ( i = mid+1 ; i < len ; i++){

        sum += a[i];
        if( sum > right_sum ){
            right_sum = sum ;
        }

    }
    if( right_sum > left_sum ){
        return right_sum ;
    }
    return left_sum ;

}

 int recursive_fms ( int a[] , int low , int high , int len) {


    if ( low  == high ){

        return a[ low ] ;
    }

    else {
        int mid = (low + high)/2 ;
        len = len/2 ;

        int right = recursive_fms ( a , low , mid , len);
        int left = recursive_fms ( a , mid+1 , high , len ) ;
        int overlap = overlapped_subarray(a , low , high , len) ;

        if ( ( overlap > right ) && ( overlap > left ) ){

            return overlap ;
        }

        if ( right > left){
            return right ;
        }
        return left ;


    }

 }
