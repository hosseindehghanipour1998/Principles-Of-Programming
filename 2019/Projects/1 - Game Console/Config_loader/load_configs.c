#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/project_header.h"

char solidblock, deathblock, moveblock, wall, target, object;
char up, down, left, right, character, Exit;
int time_limit, raindb, attack;
struct rpoint point = {0, 0, 0};
struct opponent opp = {0, 0};
struct put dblock = {0, 0, 0};
int load_config(char *directory){
    char map[100] = "map-(";
    char game[100] = "game-(";
    char txt[] = ").txt";
    FILE *map_file, *game_file;
    strcat(map,directory);
    strcat(game,directory);
    strcat(game,txt);
    strcat(map,txt);
    cd(directory);
    map_file = fopen(map, "r");
    game_file = fopen(game, "r");
    if(game_file == NULL || map_file == NULL)
        return 1;
    if(load_settings(game_file))
        return 2;
    fclose(game_file);
    if(load_map(map_file))
        return 3;
    fclose(map_file);
    return 0;
}
