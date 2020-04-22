#include <stdio.h>
#include <math.h>

void putchar_number(int num){

    int number[100] = {0};
    int i = 0, j;
    if(num == 0){
        putchar(48);
    }
    while(num != 0){
        number[i++] = num%10;
        num = num / 10;
    }
    for(j = i - 1;j >= 0;--j){
        putchar(number[j] + 48);
    }
}

void my_putchar(int lst[], int len){

    int i;
    for(i = 0;i < len;++i){
        putchar(lst[i]);
    }
}

void print_the_float_number(int num){

    int i = 0;
    int j;
    int number[100];
    while(num != 0){
        number[i++] = num%10;
        num /= 10;
    }
    for (j = i - 1;j >= 0;--j){
        if(j == 1){
            putchar(46);
            putchar(number[j] + 48);
        }
        else{
            putchar(number[j] + 48);
        }
    }
    putchar(10);

}


void how_to_print(int num){

    if (num == 0){
        int lst[] = {69, 110, 116, 101, 114, 32, 116, 104, 101,
        32, 110, 117, 109, 98, 101, 114, 32, 111, 102, 32, 118,
        101, 114, 116, 105, 99, 101, 115, 58, 10};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 1){
        int lst[] = {69, 110, 116, 101, 114, 32, 116, 104, 101, 32, 88, 32, 118, 101, 114, 116, 105, 99, 101, 58, 10};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 2){
        int lst[] = {69, 110, 116, 101, 114, 32, 116, 104, 101, 32, 89, 32, 118, 101, 114, 116, 105, 99, 101, 58, 10};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 3){
        int lst[] = {78, 111, 119, 32, 116, 104, 101, 32, 112, 111,
        105, 110, 116, 115, 32, 119, 101, 32, 119, 97, 110, 110, 97,
        32, 99, 104, 101, 99, 107, 32, 105, 102, 32, 105, 116, 39, 115,
        32, 99, 111, 110, 118, 101, 120, 32, 111, 114, 32, 110, 111, 116, 58, 10};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 4){
        int lst[] = {116, 104, 101, 32, 88, 58, 10};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 5){
        int lst[] = {116, 104, 101, 32, 89, 58, 10};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 6){
        int lst[] = {99, 111, 110, 118, 101, 120};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 7){
        int lst[] = {110, 111, 116, 32, 99, 111, 110, 118, 101, 120};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 8){
        int lst[] = {10, 10, 115, 117, 114, 102, 97, 99, 101, 58, 32};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 9){
        int lst[] = {10, 10, 65, 114, 101, 97, 58, 32};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }
    if (num == 10){
        int lst[] = {10, 84, 114, 105, 97,110, 103, 108, 101, 115, 58, 32};
        int len = sizeof(lst)/4;
        my_putchar(lst, len);
    }

}

int get_num(void){

    int c;
    int sum = 0;
    while((c = getchar()) != '\n'){
        if (c >= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
    }
    return sum;
}


void make_line(float line[], float qulty[]){

    qulty[0] = (line[3] - line[1])/(line[2] - line[0]);      //to find the lone slope
    qulty[1] = (line[1] - (qulty[0]*line[0]));               //to find Width from origin

}

void surface(float poly[], int num){

    int i;
    float line[4];
    int j = 2* num - 2;
    float sum = 0;
    int polygon_surface[100];
    int k;
    for(i = 0;i < 2 * num;i += 2){
        k = 0;
        line[k++] = poly[i];
        line[k++] = poly[i + 1];
        line[k++] = poly[j];
        line[k] = poly[j + 1];
        j = i;
        sum += sqrt(pow((line[0] - line[2]), 2) + pow((line[1]- line[3]), 2));
    }
    how_to_print(8);            //printf("\n\nsurface: );
    print_the_float_number((int)sum * 100);
}

void area(float poly[], int num){

    int sum = 0;
    int second_sum = 0;
    float ply_area;
    int i;
    for(i = 0;i < num * 2;i += 2){
        sum += poly[i] * poly[i + 3];
    }
    for(i = 1;i < 2* num;i += 2){
        second_sum += poly[i]*poly[i + 1];
    }
    ply_area = abs(sum - second_sum)/2.0;
    how_to_print(9);                                      //printf("Area: );
    print_the_float_number((int)(ply_area * 100));        //printf("%.2f", ply_area);

}



float find_x(float firstline[], float second_line[]){

    float x;
    x = (firstline[1] - second_line[1])/(second_line[0] - firstline[0]);
    return x;

}

int check_convexity(float x, float y, float line[]){

    if (x > line[0] && x < line[2]){
        if (y > line[1] && y < line[3]){
            return 0;
        }
        else if (y < line[1] && y > line[3]){
            return 0;
        }
    }
    else if (x < line[0] && x > line[2]){
        if (y > line[1] && y < line[3]){
            return 0;
        }
        else if (y < line[1] && y > line[3]){
            return 0;
        }
    }
    return 1;
}

void last_line(float second_line[], float ply[], int num){

    second_line[0] = ply[0];
    second_line[1] = ply[1];
    second_line[2] = ply[2*num - 2];
    second_line[3] = ply[2*num - 1];

}


int checkpoly(float ply[], float line[], int num){

    int i, j, k;
    int check;
    float x, y;
    float second_line[4] = {0};
    float line_quality[2] = {0};
    float ply_quality[2] = {0};

    make_line(line, line_quality);

    for(i = 0;i < 2*num;i += 2){
        for (k = 0,j = i;j < i + 4;++j, ++k){
            second_line[k] = ply[j];
        }
        make_line(second_line, ply_quality);
        x = find_x(line_quality, ply_quality);
        y = line_quality[0]*x + line_quality[1];
        check = check_convexity(x, y, line);
        if (check == 0){
            return 0;
        }
    }

    last_line(second_line, ply, num);
    make_line(second_line, ply_quality);
    x = find_x(line_quality, ply_quality);
    y = line_quality[0]*x + line_quality[1];
    check = check_convexity(x, y, line);
    if (check == 0){
        return 0;
    }

    return 1;
}


int polyconv(int num, float ply[]){

    int i, j = 0;
    int x, y;
    int answer;

    float line[4] = {0};
    for (i = 0;i < num;++i){
        how_to_print(1);            //printf("Enter the X vertice\n");
        x = get_num();
        how_to_print(2);            //printf("Enter the Y vertice\n");
        y = get_num();
        ply[j++] = x;
        ply[j++] = y;
    }
    how_to_print(3);            //printf("Now the points we wanna check if it's convex or not:\n");
    for (i = 0, j = 0;i < 2;++i){
        how_to_print(4);        //printf("the X\n");
        x = get_num();
        how_to_print(5);        //printf("the Y\n");
        y = get_num();
        line[j++] = x;
        line[j++] = y;
    }

    surface(ply, num);
    area(ply, num);

    answer = checkpoly(ply, line, num);
    return answer;

}

int polygon_changes(int first[], int second[]){

    int answer = (first[0] * second[1]) - (first[1] * second[0]);
    if (answer < 0){
        return 0;
    }
    else{
        return 1;
    }

}


int triangles_in_polygon(int ply[], int num){

    int A[2], B[2], C[2];
    int first[2], second[2];
    int i;
    int flag = 0, null;
    int changes = 1;
    int triangles;

    for(i = 0;i < 2*num ;i += 2){
        if (i == 2*(num - 1)){
            A[0] = ply[i];
            A[1] = ply[i+1];
            B[0] = ply[0];
            B[1] = ply[1];
            C[0] = ply[2];
            C[1] = ply[3];
        }
        else if(i == 2*(num - 2)){
            A[0] = ply[i];
            A[1] = ply[i+1];
            B[0] = ply[i+2];
            B[1] = ply[i+3];
            C[0] = ply[0];
            C[1] = ply[1];
        }
        else{
            A[0] = ply[i];
            A[1] = ply[i+1];
            B[0] = ply[i+2];
            B[1] = ply[i+3];
            C[0] = ply[i+4];
            C[1] = ply[i+5];
        }
        first[0] = B[0] - A[0];
        first[1] = B[1] - A[1];
        second[0] = C[0] - B[0];
        second[1] = C[1] - B[1];
        null = polygon_changes(first, second);
        if (null != flag){
            changes += 1;
            flag = null;
        }
    }
    triangles = (num - 2)*(changes);
    return triangles;
}

int main(void){

    int answer;
    float ply[100] = {0};
    how_to_print(0);        //printf("Enter the number of vertices:\n");
    int num = get_num();
    answer = polyconv(num, ply);
    if (answer == 1)
        how_to_print(6);    //printf("convex");
    if (answer == 0)
        how_to_print(7);    //printf("not convex");

    int triangles = triangles_in_polygon(ply, num);
    how_to_print(10);        //printf(\nTriangles: );

    putchar_number(triangles);  //print the number of triangles

    return 0;

}
