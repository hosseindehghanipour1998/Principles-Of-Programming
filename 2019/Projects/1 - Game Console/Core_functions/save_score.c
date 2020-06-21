#include "Headers/project_header.h"
extern struct rpoint point;
extern int score[2];
void save_score(void){
    if(point.symbol) {
        FILE *file;
        int bigest_score = score[0];
        file = fopen("save.txt", "r");
        if(file != NULL) {
            fscanf(file, "%d", &bigest_score);
            if (score[0] > bigest_score)
                bigest_score = score[0];
        }
        fclose(file);
        file = fopen("save.txt","w");
        fprintf(file, "%d", bigest_score);
        fclose(file);
    }
}
