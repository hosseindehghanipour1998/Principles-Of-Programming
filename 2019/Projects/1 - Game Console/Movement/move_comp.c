#include "Headers/project_header.h"
extern char up,down,left,right;
extern struct opponent opp;
extern int score[2];
void *move_computer(void *op){
    char c = FindCloseFood((struct need *)op);
    if (c == up) {
        move_up(op, opp.rival, score, 1);
    }
    else if (c == down) {
        move_down(op, opp.rival, score, 1);
    }
    else if (c == left) {
        move_left(op, opp.rival, score, 1);
    }
    else if (c == right) {
        move_right(op, opp.rival, score, 1);
    }
    return NULL;
}
