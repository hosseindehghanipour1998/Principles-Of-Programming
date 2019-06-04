#include <stdio.h>

int get_num(void){

    int c;
    int sum = 0;
    while ((c = getchar()) != '\n'){
        if ( c >= '0' && c <= '9'){
            sum = sum * 10 + c - '0';
        }
    }
    return sum;
}

void first_mode_encrypt(int key){

    int c;
    int msg[1000];
    int i = 0;

    printf("\nENTER RAW TEXT: ");
    while ((c = getchar()) != '\n'){
        msg[i++] = c + key;
    }

    printf("\nENCRYPTED TEXT: ");
    for (c = 0; c < i;++c){
        printf("%c", msg[c]);
    }
}

void first_mode_decrypt(int key){

    int c;
    int msg[1000];
    int i = 0;

    printf("\nENTER RAW TEXT: ");
    while ((c = getchar()) != '\n'){
        msg[i++] = c - key;
    }

    printf("\nDECRYPTED TEXT: ");
    for (c = 0; c < i;++c){
        printf("%c", msg[c]);
    }
}


void first_mode(void){

    printf("\nPlease, Enter the Key: ");
    int key = get_num();
    printf("1. Encrypt\n2. Decrypt\n");
    printf("\nEnter a number: ");
    int number = get_num();
    while (number != 1 && number != 2){
        printf("WRONG NUMBER!\n");
        printf("1. Encrypt\n2. Decrypt\n");
        printf("\nEnter a number: ");
        number = get_num();
    }
    if (number == 1)
        first_mode_encrypt(key);

    if (number == 2)
        first_mode_decrypt(key);
}

void second_mode_encrypt(int key){

    int c;
    int msg[1000];
    int i = 0;
    int j;

    printf("\nENTER RAW TEXT: ");
    while ((c = getchar()) != '\n'){
        msg[i++] = c;
    }

    printf("\nENCRYPTED TEXT: ");
    for (j = 0;j < key;++j){
        for(c = 0;c < i;++c){
            if (c % key == j){
                printf("%c", msg[c]);
            }
        }
    }
}

void second_mode_decrypt(int key){

    int c;
    int msg[1000];
    int de_msg[1000];
    int i = 0;
    int j = 0, k;

    printf("\nENTER RAW TEXT: ");
    while ((c = getchar()) != '\n'){
        msg[i++] = c;
    }
    k = 0;
    for (c = 0;c < key;++c){
        for (j = c;j < i;j+= key){
            de_msg[j] = msg[k++];
        }
    }


    printf("\nDECRYPTED TEXT: ");
    for (c = 0; c < i;++c){
        printf("%c", de_msg[c]);
    }
}

void second_mode(void){

    printf("\nPlease, Enter the Key: ");
    int key = get_num();
    printf("1. Encrypt\n2. Decrypt\n");
    printf("\nEnter a number: ");
    int number = get_num();
    while (number != 1 && number != 2){
        printf("WRONG NUMBER!\n");
        printf("1. Encrypt\n2. Decrypt\n");
        printf("\nEnter a number: ");
        number = get_num();
    }
    if (number == 1)
        second_mode_encrypt(key);

    if (number == 2)
        second_mode_decrypt(key);
}

void third_mode_encrypt(int first_key, int second_key){

    int c;
    int i = 0, j;
    int msg[1000];

    printf("\nENTER RAW TEXT: ");
    while ((c = getchar()) != '\n'){
        msg[i++] = c + first_key;
    }

    printf("\nENCRYPTED TEXT: ");
    for (j = 0;j < second_key;++j){
        for(c = 0;c < i;++c){
            if (c % second_key == j){
                printf("%c", msg[c]);
            }
        }
    }
}

void third_mode_decrypt(int first_key, int second_key){

    int c;
    int msg[1000];
    int de_msg[1000];
    int i = 0;
    int j = 0, k;

    printf("\nENTER RAW TEXT: ");
    while ((c = getchar()) != '\n'){
        msg[i++] = c;
    }
    k = 0;
    for (c = 0;c < second_key;++c){
        for (j = c;j < i;j+= second_key){
            de_msg[j] = msg[k++] - first_key;
        }
    }

    printf("\nDECRYPTED TEXT: ");
    for (c = 0; c < i;++c){
        printf("%c", de_msg[c]);
    }

}

void third_mode(void){

    printf("Please Enter the First Key: ");
    int first_key = get_num();
    printf("Please Enter the Second Key: ");
    int second_key = get_num();
    printf("1. Encrypt\n2. Decrypt\n");
    printf("\nEnter a number: ");
    int number = get_num();
    while (number != 1 && number != 2){
        printf("WRONG NUMBER!\n");
        printf("1. Encrypt\n2. Decrypt\n");
        printf("\nEnter a number: ");
        number = get_num();
    }
    if (number == 1)
        third_mode_encrypt(first_key, second_key);

    if (number == 2)
        third_mode_decrypt(first_key, second_key);

}


int main(void){

    printf("1. Mode 1\n2. Mode 2\n3. Mode 3\n");
    printf("\nEnter the Mode number: ");
    int num = get_num();
    while (num != 1 && num != 2 && num != 3){
        printf("WRONG NUMBER!\n");
        printf("1. Mode 1\n2. Mode 2\n3. Mode 3\n");
        printf("\nEnter the Mode number: ");
        num = get_num();
    }
    if (num == 1)
        first_mode();
    if (num == 2)
        second_mode();
    if (num == 3){
        third_mode();
    }
    return 0;

}
