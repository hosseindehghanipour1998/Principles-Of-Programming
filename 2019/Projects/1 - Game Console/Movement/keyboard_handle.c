#include <conio.h>
#include <Headers/curses.h>
#include <pthread.h>
#include "Headers/project_header.h"
#include "Headers/bass.h"
extern int c, move_key;
extern char up, down, left, right, character, Exit;
extern WINDOW *game_window;
extern int lose_flag;
extern int win_flag;
extern int time_limit_flag;
void *keyboard_handle(void *temp){
    HSTREAM move = BASS_StreamCreateFile(FALSE,"move.mp3", 0, 0, 0);
    HSTREAM attack = BASS_StreamCreateFile(FALSE, "attack.mp3", 0, 0, 0);
    if(c == Exit)
        pthread_exit(0);
    while(1) {
        if(lose_flag || win_flag || time_limit_flag){
            c = Exit;
            break;
        }
        if (kbhit()) {
            c = getch();
            if(c == Exit || c == '\e')
                break;
            else if (c == up || c == down || c == right || c == left) {
                if (c != move_key) {
                    move_key = c;
                    BASS_ChannelPlay(move, FALSE);
                    move_player(move_key);
                }
            } else if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT) {
                BASS_ChannelPlay(attack, FALSE);
                att(c);
            }
            print_map();
        }
    }
    pthread_exit(NULL);
}
