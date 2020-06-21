#include <stdio.h>
#include <stdlib.h>
#include "Headers/project_header.h"
int global_counter = 0;
extern char character;
char **game_map;
struct dimension map_size = {0, 0};
struct need player_pos;
extern struct opponent opp;
struct opp_list *head_op;
int load_map(FILE *map_file){
    int c, i = 0, j = 0;
    struct opp_list *temp;
    head_op = NULL;
    while((c = getc(map_file)) != 'x')
        map_size.x = map_size.x * 10 + c - '0';
    while((c = getc(map_file)) != '\n')
        map_size.y = map_size.y * 10 + c - '0';
    game_map = (char **)malloc(sizeof(char *) * map_size.y);
    for(i = 0; i < map_size.y; i++){
        game_map[i] = (char *)malloc(sizeof(char) * map_size.x);
    }
    i = 0;
    while((c = getc(map_file)) != EOF){
        if(c == opp.rival){
            temp = (struct opp_list *)malloc(sizeof(struct opp_list));
            temp->ops = (struct need *)malloc(sizeof(struct need));
            temp -> ops->ops.y = i;
            temp -> ops->ops.x = j;
            temp->ops->opp_s.flagx_i = 0;
            temp->ops->opp_s.flagy_l = 0;
            temp->ops->opp_s.flagy_j = 0;
            temp->ops->opp_s.flagx_k = 0;
            temp -> next = head_op;
            head_op = temp;
            global_counter++;
        }
        if(c == character){
            player_pos.ops.y = i;
            player_pos.ops.x = j;
        }
        if(c != '\n'){
            game_map[i][j] = c;
            j++;
        }
        else {
            if(j != map_size.x)
                return 1;
            i++;
            j = 0;
        }
    }
    if(i != map_size.y - 1){
        return 1;
    }
    return 0;
}