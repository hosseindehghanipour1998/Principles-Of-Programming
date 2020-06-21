#include "Headers/project_header.h"
int read_save(void){
    FILE *file;
    int number = -1;
    file = fopen("save.txt","r");
    if (file != NULL){
        fscanf(file,"%d",&number);
    }
    return number;
}