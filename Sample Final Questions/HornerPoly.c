#include <stdio.h> 
  
// returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1] 
int horner(int poly[], int n, int x) { 
    int result = poly[0];  // Initialize result 
    int i;
    // Evaluate value of polynomial using Horner's method 
    for ( i=1; i<n; i++) 
        result = result*x + poly[i]; 
  
    return result; 
} 
  
// Driver program to test above function. 
int main() 
{ 
    // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3 
    int poly[] = {1,0,0}; 
    int x = 3; 
    int n = sizeof(poly)/sizeof(poly[0]);
    int i = 0;
    for(i=0; i<100;i++){
            printf("X = %d ~> Y = %d\n" ,i, horner(poly, n, i));

    }
    return 0; 
} 