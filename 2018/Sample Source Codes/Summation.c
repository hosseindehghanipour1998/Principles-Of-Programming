#include <stdio.h>
#define STEPS 4
void * resize(void * array , int arr_info[] , int type ){

    int new_size = arr_info[0] + STEPS ;
    arr_info[0] = new_size ;
    printf("**** New Size is : %d **** \n" , new_size);
    return  realloc ( array , type *  new_size );

}

void main(){


  int arr_info[2] ;
  //[0] = total size
  //[1] = allocated size
  int *arr = (int *)malloc(sizeof(int) * 3);
  arr_info[0] = 3 ;
  arr_info[1] = 0 ;

  int num = 0 ;
  while ( num != '\n'){


    if ( arr_info[1] == arr_info[0]){
      printf("**** Total Size = %d && Allocated == %d ****\n" , arr_info[0] , arr_info[1]);
      arr = resize(arr , arr_info , sizeof(int) );

    }
    printf("Enter Num : \n");
    arr_info[1]++;
    scanf("%d",&num );
    *(arr + arr_info[1] - 1) = num ;
  }

  int i = 0 ;
  int sum = 0 ;
  printf("\n\n{%d} out of {%d} is allocated \n" , arr_info[1] , arr_info[0]);
  for ( i = 0 ; i < arr_info[1] ; i++){
    sum += *(arr+i);
  }
    printf("\n\nThe Summation Is : %d \n" , sum );
  return 0 ;






}
