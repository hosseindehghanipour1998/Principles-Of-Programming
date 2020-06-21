#include <Headers/curses.h>
#include "Headers/project_header.h"
#include "Headers/bass.h"

extern char **game_map;
extern struct need player_pos;
extern int attack;
extern char deathblock;
extern struct opponent opp;
extern struct dimension map_size;
void att(int direction){
    int i;
    if(direction == KEY_DOWN){
        for(i = player_pos.ops.y; (i < (player_pos.ops.y + attack)) && (i < map_size.y); i++){
            if((game_map[i][player_pos.ops.x] == deathblock) || (game_map[i][player_pos.ops.x] == opp.rival))
                game_map[i][player_pos.ops.x] = ' ';
        }
    }
    else if(direction == KEY_UP){
        for(i = player_pos.ops.y; (i > (player_pos.ops.y - attack)) && (i > 0); i--){
            if((game_map[i][player_pos.ops.x] == deathblock) || (game_map[i][player_pos.ops.x] == opp.rival))
                game_map[i][player_pos.ops.x] = ' ';
        }
    }
    else if(direction == KEY_RIGHT){
        for(i = player_pos.ops.x; (i < (player_pos.ops.x + attack) )&& (i < map_size.x); i++){
            if((game_map[player_pos.ops.y][i] == deathblock) || (game_map[player_pos.ops.y][i] == opp.rival))
                game_map[player_pos.ops.y][i] = ' ';
        }
    }
    else if(direction == KEY_LEFT){
        for(i = player_pos.ops.x; (i > (player_pos.ops.x - attack)) && (i > 0); i--){
            if((game_map[player_pos.ops.y][i] == deathblock) || (game_map[player_pos.ops.y][i] == opp.rival))
                game_map[player_pos.ops.y][i] = ' ';
        }
    }
}
