#include <stdio.h>
#include <math.h>

void which_x_y(int find[], int j, int x[], int y[], int len){

    int i;
    for(i = 0;i < len;++i){
        if (j == (100 - y[i])*100 + x[i]){
            find[0] = x[i];
            find[1] = y[i];
        }
    }
}



void find_x_y(int location[], int len){

    int i;
    int j = 65;
    int z;

    int draw[10000] = {32};

    for(i = 1;i < 10000;++i){
        if (i % 100 == 0){
            draw[i] = 10;
        }
    }

    int x[100] = {0};
    int y[100] = {0};

    int find[2];

    for (i = 0;i < len;++i){
        x[i] = location[i] / 100;
        y[i] = location[i] % 100;
        z = (100 - y[i])*100 + x[i];
        draw[z] = j++;
    }
    z = 65;
    for (i = 0, j = 101; j < 10000;++j){
        if ('A' <= draw[j] && draw[j] <= 'Z'){
            which_x_y(find, j, x, y, len);
            putchar(z++);
            putchar(40);                            //to print (
            putchar(find[0]/10 + 48);
            putchar(find[0]%10 + 48);
            putchar(44);                            //to print ,
            putchar(find[1]/10 + 48);
            putchar(find[1]%10 + 48);
            putchar(41);                            //to print )

            ++i;
        }
        else{
            putchar(draw[j]);            //to print a space or a new line
        }
    }
}

void myprintf(int location[], int len){

    int i, j, k;
    int x, y;
    int z ,o;
    int located = 65, loc;
    int sq;
    int print[] = {70, 114, 111, 109, 32, located, 32, 84, 111, 32, loc, 58, 48, 48, 10};    //From 1st to 2nd: distance
    int size = sizeof(print)/4;
    for (i = 0; i < len - 1;++i){
        loc = located + i;
        x = location[i] / 100;
        y = location[i] % 100;
        for (j = i + 1;j < len;++j){
            z = location[j] / 100;
            o = location[j] % 100;
            sq = sqrt(pow(x - z, 2) + pow(y - o, 2));
            print[5] = loc;
            print[9] = located + j;
            print[12] = sq / 10 + 48;
            print[13] = sq%10 + 48;
            for (k = 0;k < size;++k){
                putchar(print[k]);
            }
        }
    }
}



int main(void){

    int location[] = {2535,1925,1257,7348,5947};
    int len = sizeof(location)/4;

    find_x_y(location, len);

    putchar(10);            //to print a new line
    putchar(10);
    putchar(10);

    myprintf(location, len);

    return 0;

}
