#include <stdio.h>
#include <math.h>
#define LEN 9


int solve(int a[LEN][LEN] , int b) ;

int main(){

    int board[9][9] = {
 	            {3, 0, 6, 5, 0, 8, 4, 0, 0},
	            {5, 2, 0, 0, 0, 0, 0, 0, 0},
	            {0, 8, 7, 0, 0, 0, 0, 3, 1},
	            {0, 0, 3, 0, 1, 0, 0, 8, 0},
	            {9, 0, 0, 8, 6, 3, 0, 0, 5},
	            {0, 5, 0, 0, 9, 0, 6, 0, 0},
	            {1, 3, 0, 0, 0, 0, 2, 5, 0},
	            {0, 0, 0, 0, 0, 0, 0, 7, 4},
	            {0, 0, 5, 2, 0, 6, 3, 0, 0}

    };
    double len = 9 ;
    int has_answer = solve(board , len);
    if ( has_answer == 1 ){
         print(board , 9 );
    }
    else{
        printf("Sodoko has no answer to this table ... ");
    }

    return 0 ;

}


int is_safe(int board[LEN][LEN] , int row , int col , int len , int can){

    int i = 0 ;
    int j = 0 ;
    //lets look in the columns for same numbers
    for ( i = 0 ; i < len ; i++){

        if( (board[row][i] == can ) ){

            return 0 ;
            //the number is found , so it's not safe
        }

    }

    //lets look in the rows
    for ( i = 0 ; i < len ; i++){

        if ( ( board[i][col] == can ) ){

            return 0 ;
            //the number is found , so it's not safe
        }

    }

    //let's look in the
    double q = (double) len  ;
    int Sqrt = (int)sqrt(q);
    int boxRowStart = row - (row % Sqrt);
    int boxColStart = col - (col % Sqrt);

    int r , d ;
   for ( r = boxRowStart ; r < boxRowStart + Sqrt ; r++)
    {
        for ( d = boxColStart ;  d < boxColStart + Sqrt ; d++)

        {
            if (board[r][d] == can )
            {
                return 0;
            }
        }
    }

    return 1 ;
}



int solve ( int board[LEN][LEN] , int len){
    int print_again = 1 ;
    int row , col , done ;
    row = col = -1 ;
    done = 1 ; // 0 = false
    int i , j ;

    for ( i = 0 ; i < len ; i++){

        for(j = 0 ; j < len ; j++){

            if ( board[i][j] == 0){

                row = i ;
                col = j ;
                done = 0 ; // there are still empty spots
                break ;
            }

            if( done == 0){
                break ;
            }

        }
     }
    if( done == 1 ){
        return 1 ;
    }

    int candidate ;
    for ( candidate = 1 ; candidate <= len ; candidate++){

        if( is_safe(board , row , col ,len , candidate ) == 1){

            board[row][col] = candidate ;
            if ( solve(board , len) == 1){
                //which means it's all done

                return 1 ;
            }
            else {
                 board[row][col] = 0 ;
            }
        }
    }



    return  0 ;
}

    void print(int board[LEN][LEN] , int len){

        int q =(int) sqrt(len);
        int i , j ;

        for ( i = 0 ; i < len ; i++){
            for(j = 0 ; j < len ; j++){
                printf("%d , " , board[i][j]);
            }
            printf("\n");

            //if( (( i+1)%q ) == 0 ){
              //  printf("");
            //}
        }

        printf("============================\n");


    }




