#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/project_header.h"
#define NUM_CONFIGS 18

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;

int load_settings(FILE *game_file){
    int c, i = 0, j = 0, wrong_file;
    char **content, *lines;
    char *p1;
    const char exps[NUM_CONFIGS][15] = {"solidblock=", "deathblock=",
                                        "moveblock=","wall=", "target=",
                                        "object=", "up=", "down=",
                                        "left=","right=", "character=",
                                        "Exit=","time=", "opp=",
                                        "raindb=", "attack=", "rpoint=",
                                        "put="};
    lines = (char *)malloc(sizeof(char) * 100);
    content = (char **)malloc(sizeof(char*) * 1000);
    while((c = getc(game_file)) != EOF){
        if(c == '\n'){
            lines[j] = 0;
            content[i] = lines;
            lines = (char *)malloc(sizeof(char) * 100);
            j = 0;
            i++;
        }
        else{
            lines[j] = c;
            j++;
        }
    }
    content[i] = NULL;
    i = 0;
    while(content[i] != NULL){
        wrong_file = 1;
        for(j = 0; j < NUM_CONFIGS; j++){
            if((p1 = strstr(content[i], exps[j])) != NULL){
                wrong_file = 0;
                switch(j){
                    case 0:
                        solidblock = *(p1 + strlen(exps[j]));
                        break;
                    case 1:
                        deathblock = *(p1 + strlen(exps[j]));
                        break;
                    case 2:
                        moveblock = *(p1 + strlen(exps[j]));
                        break;
                    case 3:
                        wall = *(p1 + strlen(exps[j]));
                        break;
                    case 4:
                        target = *(p1 + strlen(exps[j]));
                        break;
                    case 5:
                        object = *(p1 + strlen(exps[j]));
                        break;
                    case 6:
                        up = *(p1 + strlen(exps[j]));
                        break;
                    case 7:
                        down = *(p1 + strlen(exps[j]));
                        break;
                    case 8:
                         left = *(p1 + strlen(exps[j]));
                         break;
                    case 9:
                         right = *(p1 + strlen(exps[j]));
                         break;
                    case 10:
                         character = *(p1 + strlen(exps[j]));
                         break;
                    case 11:
                        Exit = *(p1 + strlen(exps[j]));
                        break;
                    case 12:
                        p1 += strlen(exps[j]);
                        while(*p1 != 0) {
                            time_limit = time_limit * 10 + *p1 - '0';
                            p1++;
                        }
                        break;
                    case 13:
                        opp.rival = *(p1 + strlen(exps[j]));
                        opp.dest  = *(p1 + strlen(exps[j]) + 2);
                        break;
                    case 14:
                        p1 += strlen(exps[j]);
                        while(*p1 != 0) {
                            raindb = raindb * 10 + *p1 - '0';
                            p1++;
                        }
                        break;
                    case 15:
                        p1 += strlen(exps[j]);
                        while(*p1 != 0) {
                            attack = attack * 10 + *p1 - '0';
                            p1++;
                        }
                        break;
                    case 16:
                        p1 += strlen(exps[j]);
                        point.symbol = *p1;
                        p1 += 2;
                        while(*p1 != ','){
                            point.score = point.score * 10 + *p1 - '0';
                            p1++;
                        }
                        p1++;
                        while(*p1 != 0){
                            point.num = point.num * 10 + *p1 - '0';
                            p1++;
                        }
                        break;
                    case 17:
                        p1 += strlen(exps[j]);
                        dblock.key = *p1;
                        p1 += 2;
                        dblock.symbol = *p1;
                        p1 += 2;
                        while(*p1 != 0){
                            dblock.limit = dblock.limit * 10 + *p1 - '0';
                            p1++;
                        }
                        break;
                }
            }
        }
        if(wrong_file)
            return 1;
        i++;
    }
    i = 0;
    while(content[i] != NULL){
        free(content[i]);
        i++;
    }
    free(content);
    return 0;
}
