#include <stdio.h>
#include <math.h>

typedef struct cords{

    int x , y ;
    float (*distance)(int x , int y);
    // Tells us the pointer to the function with it's arguments ( int x , int y )
    float dis ;
}Cords ;

//Body of the function we are going to pass to the pointer of structure
float calculate(int x , int y){

    int X = pow(x,2);
    int Y = pow(y,2);
    return ( sqrt(X+Y));

}

void main(void){

    Cords c1 ;
    c1.x = 3 ;
    c1.y = 4 ;
    c1.distance = calculate ;// Passing The function to the pointer in the structure
    c1.dis = c1.distance( c1.x , c1.y);//calling the function of the structure

    printf("%f",c1.dis);



}
