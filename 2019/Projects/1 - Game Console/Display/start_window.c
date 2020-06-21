#include <Headers/curses.h>
#include "Headers/bass.h"
#include "Headers/project_header.h"
extern struct dimension map_size;
extern WINDOW *game_window;
extern HSTREAM background_music;
void show_start_window() {
    char mesg3[] = "Game starts in";
    char mesg4[] = "3";
    struct dimension win_size;
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    HSTREAM start = BASS_StreamCreateFile(FALSE, "start.mp3", 0, 0, 0);
    win_size.x = 2 * map_size.x / 3;
    win_size.y = map_size.y / 3 + 1;
    WINDOW *start_win = newwin(win_size.y, win_size.x, map_size.y / 3, map_size.x / 5 - 1);
    box(start_win, 0, 0);
    wattron(start_win, COLOR_PAIR(2));
    mvwprintw(start_win, 1, (win_size.x - strlen(mesg3)) / 2, "%s", mesg3);
    mvwprintw(start_win, win_size.y/2, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    BASS_ChannelPlay(start, FALSE);
    delay(900);
    mesg4[0] = mesg4[0] - 1;
    mvwprintw(start_win, win_size.y/2, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    delay(900);
    mesg4[0] = mesg4[0] - 1;
    mvwprintw(start_win, win_size.y/2, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    delay(900);
    mesg4[0] = mesg4[0] - 1;
    mvwprintw(start_win, win_size.y/2, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wattroff(start_win, COLOR_PAIR(2));
    wrefresh(start_win);
    delwin(start_win);
    BASS_ChannelStop(start);
    BASS_StreamFree(start);
    background_music = BASS_StreamCreateFile(FALSE,"background.mp3", 0, 0, BASS_SAMPLE_LOOP);
    BASS_ChannelPlay(background_music, FALSE);
    werase(game_window);
}