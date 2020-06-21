#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Headers/project_header.h"
extern int score[2];
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
extern struct need player_pos;

void put_dblock(struct dimension player_last_pos){
    if(dblock.symbol && dblock.limit > 0){
        if(player_last_pos.x == player_pos.ops.x&& player_last_pos.y == player_pos.ops.y)
            ;//game_over();
        else {
            game_map[player_last_pos.y][player_last_pos.x] = dblock.symbol;
            dblock.limit--;
        }
    }
}