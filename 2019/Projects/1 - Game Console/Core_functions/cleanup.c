#include <stdlib.h>
#include <Headers/curses.h>
#include "Headers/bass.h"
#include "Headers/project_header.h"
extern char character;
extern char **game_map;
extern int score[2];
extern struct dimension map_size;
extern struct need player_pos;
extern struct opponent opp;
struct opp_list *head_op;
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct put dblock;
extern struct dimension default_term_size;
extern int c;
extern int move_key;
extern HSTREAM background_music;
void cleanup(){
    int i, j;
    for(i = 0; i < map_size.y; i++){
        free(game_map[i]);
    }
    free(game_map);
    struct opp_list *temp;
    while(head_op != NULL){
        temp = head_op -> next;
        free(head_op->ops);
        free(head_op);
        head_op = temp;
    }
    //Terminal restoration
        resize_term(default_term_size.y, default_term_size.x);
        curs_set(1);
        nocbreak();
        echo();
    //
    map_size.x = 0;
    map_size.y = 0;
    point.symbol = 0;
    point.score = 0;
    point.num = 0;
    opp.rival = 0;
    opp.dest = 0;
    dblock.symbol = 0;
    dblock.key = 0;
    dblock.limit = 0;
    deathblock = 0;
    moveblock = 0;
    time_limit = 0;
    target = 0;
    object = 0;
    Exit = 0;
    raindb = 0;
    player_pos.ops.x = 0;
    player_pos.ops.y = 0;
    up = 0;
    down = 0;
    left = 0;
    right = 0;
    solidblock = 0;
    score[0] = 0;
    score[1] = 0;
    c = 0;
    move_key = 0;
}