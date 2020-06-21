#include <time.h>
#include <Headers/curses.h>
#include "Headers/project_header.h"
#include "Headers/bass.h"

extern char solidblock, deathblock, moveblock, wall, target, object;
extern char up, down, left, right, character, Exit;
extern int time_limit, raindb, attack;
extern struct rpoint point;
extern struct opponent opp;
extern struct put dblock;
extern struct dimension map_size;
extern char **game_map;
int randomness;
WINDOW *game_window;
HSTREAM background_music;
struct dimension default_term_size;
extern HSTREAM main_background;
void initialization(){
    //Terminal initializations
        initscr();
        default_term_size.x = 110;
        default_term_size.y = 27;
        resize_term(default_term_size.y, default_term_size.x);
        start_color();
        use_default_colors();
        clear();
        keypad(stdscr, TRUE);
    //
    //Sound initialization
        BASS_Init(-1, 44100, 0, 0, NULL);
        main_background = BASS_StreamCreateFile(FALSE,"background.mp3", 0, 0, BASS_SAMPLE_LOOP);
}

void ingame_init(){
    curs_set(0);
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    resize_term(map_size.y+3, map_size.x+1);
    game_window = newwin(map_size.y+3, map_size.x+1, 0, 0);
    randomness = time(0);
    if(point.symbol)
        random_gen(point.num, point.symbol);
}