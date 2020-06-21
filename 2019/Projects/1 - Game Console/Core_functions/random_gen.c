#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers/project_header.h"
extern char deathblock;
extern int randomness;
struct dimension map_size;
extern char **game_map;
extern int rain_x,rain_y;
unsigned bit;
void random_gen(int n,char b){
    int flag = 0;
    int counter1 = 0,ran_x,ran_y;
    randomness++;
    int core = time(NULL);
    srand(core+randomness);
    if (deathblock == b) {
        while (counter1<n) {
            ran_x = (rand() % (map_size.x - 2)) + 1;
            if (game_map[1][ran_x] == ' ') {
                game_map[1][ran_x] = b;
                rain_x = ran_x;
                rain_y = 1;
                counter1++;
                flag = 1;
            } else {
                if(randomness == RAND_MAX || flag == 0)
                    randomness = time(0)%101;
                else
                    randomness++;
                //srand(randomness);
                flag = 0;
            }
        }
        return;
    }else {
        while (counter1<n){
            ran_x = (rand() % (map_size.x - 2)) + 1;
            ran_y = (rand() % (map_size.y - 2)) + 1;
            if (game_map[ran_y][ran_x] == ' ') {
                game_map[ran_y][ran_x] = b;
                counter1++;
            } else {
                //srand(randomness);
                if(randomness == RAND_MAX)
                    randomness = time(0)%100;
                else
                    randomness++;
            }
        }
    }
}
