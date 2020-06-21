#include <stdlib.h>
#include "Headers/project_header.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
int lose_flag;
int win_flag;
void move_up(struct need*pos, char obj, int score[], int i) {
    if (obj == character) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y - 1][pos->ops.x] == ' ') {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y - 1][pos->ops.x] = obj;
                pos->ops.y = pos->ops.y - 1;
            }
            else if (game_map[pos->ops.y - 1][pos->ops.x] == target && character == object){
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y-1][pos->ops.x] = character;
                pos->ops.y = pos->ops.y - 1;
                win_flag = 1;
            }else if (game_map[pos->ops.y - 1][pos->ops.x] == point.symbol) {
                score[i] += point.score;
                game_map[pos->ops.y - 1][pos->ops.x] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y - 1][pos->ops.x] = obj;
                pos->ops.y = pos->ops.y - 1;
            } else if (game_map[pos->ops.y - 1][pos->ops.x] == deathblock) {
                lose_flag = 1;

            } else if (game_map[pos->ops.y - 1][pos->ops.x] == moveblock) {
                if (game_map[pos->ops.y - 2][pos->ops.x] == ' ') {
                    game_map[pos->ops.y - 2][pos->ops.x] = moveblock;
                    game_map[pos->ops.y - 1][pos->ops.x] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.y = pos->ops.y - 1;
                }
            } else if (game_map[pos->ops.y - 1][pos->ops.x] == object) {
                if (game_map[pos->ops.y - 2][pos->ops.x] == ' ') {
                    game_map[pos->ops.y - 2][pos->ops.x] = object;
                    game_map[pos->ops.y - 1][pos->ops.x] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.y = pos->ops.y - 1;
                }
                else if (game_map[pos->ops.y - 2][pos->ops.x] == target && object != character) {
                    game_map[pos->ops.y - 2][pos->ops.x] = object;
                    game_map[pos->ops.y - 1][pos->ops.x] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.y = pos->ops.y - 1;
                    win_flag = 1;
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y - 1][pos->ops.x] == ' ') {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y - 1][pos->ops.x] = obj;
                pos->ops.y = pos->ops.y - 1;
            } else if (game_map[pos->ops.y - 1][pos->ops.x] == point.symbol) {
                score[i] += point.score;
                game_map[pos->ops.y - 1][pos->ops.x] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y - 1][pos->ops.x] = obj;
                pos->ops.y = pos->ops.y - 1;
            }else if (game_map[pos->ops.y -1][pos->ops.x] == character && opp.dest == character){
                game_map[pos->ops.y-1][pos->ops.x] = opp.rival;
                game_map[pos->ops.y][pos->ops.x] = ' ';
                lose_flag = 1;
            }
        }
    }
}
void move_down(struct need *pos,char obj,int score[],int i) {
    if (obj == character) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y + 1][pos->ops.x] == ' ') {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y + 1][pos->ops.x] = obj;
                pos->ops.y = pos->ops.y + 1;
            }else if (game_map[pos->ops.y + 1][pos->ops.x] == target && character == object) {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y + 1][pos->ops.x] = character;
                pos->ops.y = pos->ops.y + 1;
                win_flag = 1;
            }
            else if (game_map[pos->ops.y + 1][pos->ops.x] == point.symbol) {
                score[i] += point.score;
                game_map[pos->ops.y + 1][pos->ops.x] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y + 1][pos->ops.x] = obj;
                pos->ops.y = pos->ops.y + 1;
            } else if (game_map[pos->ops.y + 1][pos->ops.x] == deathblock) {
                lose_flag = 1;

            } else if (game_map[pos->ops.y + 1][pos->ops.x] == moveblock) {
                if (game_map[pos->ops.y + 2][pos->ops.x] == ' ') {
                    game_map[pos->ops.y + 2][pos->ops.x] = moveblock;
                    game_map[pos->ops.y + 1][pos->ops.x] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.y = pos->ops.y + 1;
                }
            } else if (game_map[pos->ops.y + 1][pos->ops.x] == object) {
                if (game_map[pos->ops.y + 2][pos->ops.x] == ' ') {
                    game_map[pos->ops.y + 2][pos->ops.x] = object;
                    game_map[pos->ops.y + 1][pos->ops.x] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.y = pos->ops.y + 1;
                } else if (game_map[pos->ops.y + 2][pos->ops.x] == target) {
                    game_map[pos->ops.y + 2][pos->ops.x] = object;
                    game_map[pos->ops.y + 1][pos->ops.x] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.y = pos->ops.y + 1;
                    win_flag = 1;
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y][pos->ops.x] == obj) {
                if (game_map[pos->ops.y + 1][pos->ops.x] == ' ') {
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    game_map[pos->ops.y + 1][pos->ops.x] = obj;
                    pos->ops.y = pos->ops.y + 1;
                } else if (game_map[pos->ops.y + 1][pos->ops.x] == point.symbol) {
                    score[i] += point.score;
                    game_map[pos->ops.y + 1][pos->ops.x] = ' ';
                    random_gen(1, point.symbol);
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    game_map[pos->ops.y + 1][pos->ops.x] = obj;
                    pos->ops.y = pos->ops.y + 1;
                } else if (game_map[pos->ops.y + 1][pos->ops.x] == character && opp.dest == character) {
                    game_map[pos->ops.y+1][pos->ops.x] = opp.rival;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    lose_flag = 1;
                }
            }
        }
    }

}
void move_right(struct need *pos,char obj, int score[],int i) {
    if (obj == character) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y][pos->ops.x + 1] == ' ') {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y][pos->ops.x + 1] = obj;
                pos->ops.x = pos->ops.x + 1;
            } else if (game_map[pos->ops.y][pos->ops.x+1] == target && character == object) {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y][pos->ops.x+1] = character;
                pos->ops.x = pos->ops.x + 1;
                win_flag = 1;
            }else if (game_map[pos->ops.y][pos->ops.x + 1] == point.symbol) {
                score[i] += point.score;
                game_map[pos->ops.y][pos->ops.x + 1] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y][pos->ops.x + 1] = obj;
                pos->ops.x = pos->ops.x + 1;
            } else if (game_map[pos->ops.y][pos->ops.x + 1] == deathblock) {
                lose_flag = 1;

            } else if(game_map[pos->ops.y][pos->ops.x+1] == moveblock){
                if(game_map[pos->ops.y][pos->ops.x+2] == ' '){
                    game_map[pos->ops.y][pos->ops.x+2] = moveblock;
                    game_map[pos->ops.y][pos->ops.x+1] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.x = pos->ops.x+1;
                }
            } else if(game_map[pos->ops.y][pos->ops.x+1] == object){
                if(game_map[pos->ops.y][pos->ops.x+2] == ' '){
                    game_map[pos->ops.y][pos->ops.x+2] = object;
                    game_map[pos->ops.y][pos->ops.x+1] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.x = pos->ops.x+1;
                }
                else if(game_map[pos->ops.y][pos->ops.x+2] == target){
                    game_map[pos->ops.y][pos->ops.x+2] = object;
                    game_map[pos->ops.y][pos->ops.x+1] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.x = pos->ops.x+1;
                    win_flag = 1;
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y][pos->ops.x] == obj) {
                if (game_map[pos->ops.y][pos->ops.x + 1] == ' ') {
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    game_map[pos->ops.y][pos->ops.x + 1] = obj;
                    pos->ops.x = pos->ops.x + 1;
                } else if (game_map[pos->ops.y][pos->ops.x + 1] == point.symbol) {
                    score[i] += point.score;
                    game_map[pos->ops.y][pos->ops.x + 1] = ' ';
                    random_gen(1, point.symbol);
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    game_map[pos->ops.y][pos->ops.x + 1] = obj;
                    pos->ops.x = pos->ops.x + 1;
                } else if (game_map[pos->ops.y][pos->ops.x + 1] == character && opp.dest == character) {
                    game_map[pos->ops.y][pos->ops.x+1] = opp.rival;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    lose_flag = 1;
                }
            }
        }
    }
}
void move_left(struct need *pos, char obj,int score[],int i) {
    if (obj == character) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y][pos->ops.x - 1] == ' ') {
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y][pos->ops.x - 1] = obj;
                pos->ops.x = pos->ops.x - 1;
            } else if (game_map[pos->ops.y][pos->ops.x - 1] == point.symbol) {
                score[i] += point.score;
                game_map[pos->ops.y][pos->ops.x - 1] = ' ';
                random_gen(1, point.symbol);
                game_map[pos->ops.y][pos->ops.x] = ' ';
                game_map[pos->ops.y][pos->ops.x - 1] = obj;
                pos->ops.x = pos->ops.x - 1;
            } else if (game_map[pos->ops.y][pos->ops.x - 1] == deathblock) {
                lose_flag = 1;

            } else if (game_map[pos->ops.y][pos->ops.x - 1] == moveblock) {
                if (game_map[pos->ops.y][pos->ops.x - 2] == ' ') {
                    game_map[pos->ops.y][pos->ops.x - 2] = moveblock;
                    game_map[pos->ops.y][pos->ops.x - 1] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.x = pos->ops.x - 1;
                }
            } else if (game_map[pos->ops.y][pos->ops.x - 1] == object) {
                if (game_map[pos->ops.y][pos->ops.x - 2] == ' ') {
                    game_map[pos->ops.y][pos->ops.x - 2] = object;
                    game_map[pos->ops.y][pos->ops.x - 1] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.x = pos->ops.x - 1;
                } else if (game_map[pos->ops.y][pos->ops.x - 2] == target) {
                    game_map[pos->ops.y][pos->ops.x - 2] = object;
                    game_map[pos->ops.y][pos->ops.x - 1] = obj;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    pos->ops.x = pos->ops.x - 1;
                    win_flag = 1;
                }
            }
        }
    } else if (obj == opp.rival) {
        if (game_map[pos->ops.y][pos->ops.x] == obj) {
            if (game_map[pos->ops.y][pos->ops.x] == obj) {
                if (game_map[pos->ops.y][pos->ops.x - 1] == ' ') {
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    game_map[pos->ops.y][pos->ops.x - 1] = obj;
                    pos->ops.x = pos->ops.x - 1;
                } else if (game_map[pos->ops.y][pos->ops.x - 1] == point.symbol) {
                    score[i] += point.score;
                    game_map[pos->ops.y][pos->ops.x - 1] = ' ';
                    random_gen(1, point.symbol);
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    game_map[pos->ops.y][pos->ops.x - 1] = obj;
                    pos->ops.x = pos->ops.x - 1;
                } else if (game_map[pos->ops.y][pos->ops.x - 1] == character && opp.dest == character) {
                    game_map[pos->ops.y][pos->ops.x-1] = opp.rival;
                    game_map[pos->ops.y][pos->ops.x] = ' ';
                    lose_flag = 1;
                }
            }
        }
    }
}