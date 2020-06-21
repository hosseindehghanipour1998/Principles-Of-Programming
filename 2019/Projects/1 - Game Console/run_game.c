#include <pthread.h>
#include <Headers/curses.h>
#include <string.h>
#include <dirent.h>
#include "Headers/bass.h"
#include "Headers/project_header.h"
int score[2];
extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
float t_limit;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern char **game_map;
extern struct need player_pos;
extern struct dimension map_size;
extern struct opp_list *head_op;
int c = 0;
int move_key = 0;
extern WINDOW *game_window;
extern int lose_flag;
extern int win_flag;
int time_limit_flag;
extern HSTREAM background_music;
void run_game() {
    c = 0;
    register int i;
    struct dimension player_last_pos;
    struct opp_list *temp;
    pthread_t thread[100], keyboard_thread;
    t_limit = time_limit + 0.001;
    print_map();
    show_start_window();
    print_map();
    pthread_create(&keyboard_thread, NULL, keyboard_handle, NULL);
    while (c != Exit && t_limit > 0) {
        if(lose_flag)
            break;
        player_last_pos.y = player_pos.ops.y;
        player_last_pos.x = player_pos.ops.x;
        move_player(move_key);
        if (c == '\e') {
            show_pause_window();
            if(c == Exit)
                break;
            pthread_create(&keyboard_thread, NULL, keyboard_handle, NULL);
        }
        if(c == dblock.key) {
            if(player_last_pos.y != player_pos.ops.y || player_last_pos.x != player_pos.ops.x)
                put_dblock(player_last_pos);
            c = 0;
        }
        i = 0;
        temp = head_op;
        while(temp != NULL){
            pthread_create(&thread[i], NULL, move_computer, temp ->ops);
            temp = temp -> next;
            i++;
        }
        while(i > 0) {
            pthread_join(thread[i], NULL);
            i--;
        }
        rain_db();
        print_map();
        delay(200);
        if(time_limit)
            t_limit -= 0.2;
    }
    BASS_ChannelStop(background_music);
    BASS_StreamFree(background_music);
    if(t_limit <= 0){
        time_limit_flag = 1;
        time_limit_reached();
    }
    pthread_join(keyboard_thread, NULL);
    if(lose_flag){
        lose_flag = 0;
        game_over();
    }
    else if(win_flag){
        win_flag = 0;
        win();
    }
    save_score();
    time_limit_flag = 0;
    chdir("..");
    chdir("..");
    delwin(game_window);
}
