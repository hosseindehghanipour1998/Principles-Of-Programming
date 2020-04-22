void swap(int *a , int *b){

  int temp = *a ;
  *a = *b ;
  *b = temp ;

}

int main(void){

  int num1 = 10 ;
  int num2 = 20 ;

  printf("Num 1 : %d Num2 : %d \n" , num1 , num2);

  swap(&num1 , &num2);
  printf("Num 1 : %d Num2 : %d \n" , num1 , num2);


}
