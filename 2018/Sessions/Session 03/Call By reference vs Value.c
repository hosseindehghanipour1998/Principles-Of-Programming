#include <stdio.h>
#include <string.h>

void getName(char a[]);
void printName(char b[]);
void changeValue(int);
int main(void){

    //Variable Declarations :
    int a = 5 ;
    char name[100] ;


    // Call by Value :
    changeValue(a) ;
    printf("%d\n",a);


    //Call By References ( that's wrong anyway ) :
    printf("Enter Your Sentence : ") ;
    getName(name);
    printName(name);

    //End of The Program
    return 0 ;
}


void changeValue(int a ){

    a = a + 10 ; // AKA : a+= 10
}

void getName(char inputName[]){

    int c = 0 ;
    int i = 0 ;

    while ( ( c = getchar()) != '\n'){
        inputName[i++] = c ;
    }
    inputName[i] = '\0' ;
}


 printName(char name[]){

    printf("Printing By Method I :\n");

    int len = strlen(name);
    int i = 0 ;
    for ( i = 0 ; i < len ; i++){
        putchar(name[i]);
    }

    putchar('\n');
    //OR

    printf("Printing By Method II \n");
    i = 0 ;
    while ( name[i] != '\0'){
        putchar(name[i++]);
    }
}
