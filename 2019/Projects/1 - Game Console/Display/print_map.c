#include <stdio.h>
#include <stdlib.h>
#include <Headers/curses.h>
#include <string.h>
#include "Headers/project_header.h"
extern int score[];
struct rpoint point;
struct opponent opp;
extern char **game_map;
extern struct dimension map_size;
extern float t_limit;
extern int time_limit;
extern int global_counter;
extern char character, deathblock, solidblock, wall, target, object;
extern struct put dblock;
extern WINDOW *game_window;
void print_map(){
    int z;
    register int i, j;
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    for(i = 0; i < map_size.y; i++){
        for(j = 0; j < map_size.x; j++) {
            if(game_map[i][j] == opp.rival) {
                wattron(game_window, COLOR_PAIR(3));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(3));
            }
            else if(game_map[i][j] == character){
                wattron(game_window, COLOR_PAIR(1));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(1));
            }
            else if(game_map[i][j] == deathblock){
                wattron(game_window, COLOR_PAIR(3));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(3));
            }
            else if(game_map[i][j] == solidblock || game_map[i][j] == wall){
                wattron(game_window, COLOR_PAIR(5));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(5));
            }
            else if(game_map[i][j] == point.symbol){
                wattron(game_window, COLOR_PAIR(4));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(4));
            }
            else if(game_map[i][j] == target){
                wattron(game_window, COLOR_PAIR(2));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(2));
            }
            else if(game_map[i][j] == object){
                wattron(game_window, COLOR_PAIR(6));
                mvwaddch(game_window, i, j, game_map[i][j]);
                wattroff(game_window, COLOR_PAIR(6));
            }
            else{
                mvwaddch(game_window, i, j, game_map[i][j]);
            }
        }
    }
    wattron(game_window, COLOR_PAIR(2));
    z = map_size.y;
    if (dblock.symbol){
        mvwprintw(game_window, z, 0, "Remaining Death blocks: %d", dblock.limit);
        z++;
    }
    if(time_limit) {
        mvwprintw(game_window, z, 0, "Remaining time: %.1f", t_limit);
        z++;
    }
    if(point.symbol) {
        mvwprintw(game_window, z, 0, "Score: %d", score[0]);
        int c;
        if((c = read_save()) != -1){
            mvwprintw(game_window, z,map_size.x - strlen("Highest Score:\t\t") , "Highest Score: %d", c);
        }
    }
    wattroff(game_window, COLOR_PAIR(2));
    wrefresh(game_window);
    refresh();
}