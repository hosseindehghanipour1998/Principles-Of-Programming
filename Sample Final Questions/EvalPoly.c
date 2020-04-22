#include<stdio.h>
#include<math.h>

int evaluate_polynomial(int arr[], int limit, int x)
{
      int sum = 0, count;
      for(count = limit; count >= 0; count--)
      {
            sum = sum + arr[count]*pow(x, count);
      }
      return sum;
}



int main(){
    int array[30], degree, x_val, count, result;
    printf("\nEnter the Degree of Polynomial:\t");
    scanf("%d", &degree);
    printf("\nEnter the Co - Efficients:\n");
    for(count = degree; count >= 0; count--)
    {
        printf("\nCo - Efficient of A[%d]: \t", count);
        scanf("%d", &array[count]);
    }
    printf("\nThe Polynomial:\n\n");
    for(count = degree; count >= 0; count--)
    {
        if(array[count] != 0)
        {
                printf("%dx^%d + ", array[count], count);
        }
    }
    printf("%d", array[count]);
    /*
    printf("\n\nEnter the Value of X:\t");
    scanf("%d", &x_val);
    result = evaluate_polynomial(array, degree, x_val);
    printf("\nEvaluation of Polynomial:\t%d\n", result);
    */
    int final_result[101];
    int i;
    for(i=0 ; i<100 ; i++){
        final_result[i] = evaluate_polynomial(array,degree,i);
        printf("\nEvaluation of Polynomial:\t%d\n", final_result[i]);
    }
    int j ;
    int flag = 0;
    FILE *fp;
    fp = fopen("test.txt" , "w");
    for( i = 101; i >= 1; --i){
      for(j=0;j <= 101;++j){
        if( i <= final_result[j] && flag == 0){
            putc('*' , fp);
            flag = 1;
        }
        else{
            putc(' ' , fp);
        }
      }
      putc('\n' , fp);
      flag = 0;
    }
      fclose(fp);

    return 0;
}